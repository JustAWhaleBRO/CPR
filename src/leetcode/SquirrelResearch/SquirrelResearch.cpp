// ==================== LEETCODE SUBMISSION (copy from here) ====================
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <memory>
#include <iostream>

// Solution Class (SquirrelResearch)
class SquirrelResearch {
 private:
  struct Nut {
    std::string id;
    double weight;
    double expiry_timestamp;

    // Comparator: Heaviest first, then Lexicographically smallest ID.
    // std::set sorts ASC. We want "Best" at rbegin().
    // A < B implies A is "worse" (Lighter).
    bool operator<(const Nut& other) const {
      if (std::abs(weight - other.weight) > 1e-9) {
        return weight < other.weight;
      }
      // If weights equal, 'a' > 'b' implies 'a' is at rbegin() (better).
      return id > other.id;
    }
  };

  struct Level {
    int capacity;
    std::set<Nut> nuts; 

    bool is_full() const { return nuts.size() >= static_cast<size_t>(capacity); }
    double occupancy_ratio() const {
      if (capacity == 0) return 1.0;
      return static_cast<double>(nuts.size()) / capacity;
    }
  };

  struct Location {
    std::string id;
    std::vector<Level> levels; 
  };

  std::unordered_map<std::string, Location> locations_;
  std::unordered_set<std::string> active_nut_ids_;
  std::vector<int> fib_sequence_;

  void precompute_fibonacci() {
    fib_sequence_ = {0, 1};
    for (int i = 2; i < 40; ++i) {
      fib_sequence_.push_back(fib_sequence_[i - 1] + fib_sequence_[i - 2]);
    }
  }

  int get_fib_capacity(int level_index) const {
    // Level 0 (Deepest) = F(2) = 1
    if (level_index + 2 >= static_cast<int>(fib_sequence_.size())) return 0;
    return fib_sequence_[level_index + 2];
  }

 public:
  SquirrelResearch(const std::unordered_map<std::string, int>& locations_input) {
    precompute_fibonacci();
    for (const auto& [loc_id, num_levels] : locations_input) {
      Location loc;
      loc.id = loc_id;
      loc.levels.reserve(num_levels);
      for (int i = 0; i < num_levels; ++i) {
        Level lvl;
        lvl.capacity = get_fib_capacity(i);
        loc.levels.push_back(lvl);
      }
      locations_[loc_id] = std::move(loc);
    }
  }

  bool hide_nut(double timestamp, const std::string& location_id, 
                const std::string& nut_id, double nut_weight, double time_to_expire) {
    if (active_nut_ids_.contains(nut_id)) return false;
    auto loc_it = locations_.find(location_id);
    if (loc_it == locations_.end()) return false;

    Location& loc = loc_it->second;
    int target_level_idx = -1;

    // Fill from deepest (0) upwards
    for (size_t i = 0; i < loc.levels.size(); ++i) {
      if (!loc.levels[i].is_full()) {
        target_level_idx = static_cast<int>(i);
        break;
      }
    }

    if (target_level_idx == -1) return false;

    Nut new_nut;
    new_nut.id = nut_id;
    new_nut.weight = nut_weight;
    new_nut.expiry_timestamp = timestamp + time_to_expire;

    loc.levels[target_level_idx].nuts.insert(new_nut);
    active_nut_ids_.insert(nut_id);
    return true;
  }

  std::vector<std::string> retrieve_nut(double timestamp, const std::string& location_id, 
                                        int max_squirrel_capacity_in_nuts) {
    std::vector<std::string> retrieved_nuts;
    auto loc_it = locations_.find(location_id);
    if (loc_it == locations_.end()) return {};

    Location& loc = loc_it->second;

    for (int count = 0; count < max_squirrel_capacity_in_nuts; ++count) {
      int top_populated_idx = -1;
      for (int i = static_cast<int>(loc.levels.size()) - 1; i >= 0; --i) {
        if (!loc.levels[i].nuts.empty()) {
          top_populated_idx = i;
          break;
        }
      }

      if (top_populated_idx == -1) break; 

      // Determine Reachable Levels
      std::vector<int> reachable_levels;
      reachable_levels.push_back(top_populated_idx);
      if (loc.levels[top_populated_idx].occupancy_ratio() < 0.5 && top_populated_idx > 0) {
        reachable_levels.push_back(top_populated_idx - 1);
      }

      // Find Best Candidate
      int chosen_level_idx = -1;
      Nut best_candidate;
      bool candidate_found = false;

      for (int lvl_idx : reachable_levels) {
        const Level& lvl = loc.levels[lvl_idx];
        if (lvl.nuts.empty()) continue;
        const Nut& current = *lvl.nuts.rbegin(); // Best in this level

        if (!candidate_found || best_candidate < current) {
           chosen_level_idx = lvl_idx;
           best_candidate = current;
           candidate_found = true;
        }
      }

      if (!candidate_found) break;

      // Check Expiry
      if (timestamp <= best_candidate.expiry_timestamp) {
        retrieved_nuts.push_back(best_candidate.id);
      }

      // Remove
      active_nut_ids_.erase(best_candidate.id);
      auto& chosen_set = loc.levels[chosen_level_idx].nuts;
      chosen_set.erase(chosen_set.find(best_candidate));

      // Gravity Cascade
      int current_hole_idx = chosen_level_idx;
      while (current_hole_idx < top_populated_idx) {
        int above_idx = current_hole_idx + 1;
        Level& above_lvl = loc.levels[above_idx];
        if (above_lvl.nuts.empty()) break; 

        // Lightest falls (begin())
        Nut falling_nut = *above_lvl.nuts.begin();
        above_lvl.nuts.erase(above_lvl.nuts.begin());
        loc.levels[current_hole_idx].nuts.insert(falling_nut);

        current_hole_idx++;
      }
    }
    return retrieved_nuts;
  }
};

// =============================================================================
// SECTION 2: Simulation Wrapper for TestHarness
// =============================================================================

namespace {
  std::vector<std::string> Split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream token_stream(s);
    while (std::getline(token_stream, token, delimiter)) {
      if (!token.empty()) tokens.push_back(token);
    }
    return tokens;
  }
}

// This function acts as the interface between the raw strings and the engine.
std::vector<std::string> run_squirrel_simulation(const std::vector<std::string>& commands) {
  std::unique_ptr<SquirrelResearch> engine = nullptr;
  std::vector<std::string> results;

  for (const auto& line : commands) {
    if (line.empty()) continue;
    std::vector<std::string> tokens = Split(line, ' ');
    const std::string& cmd = tokens[0];

    if (cmd == "Init") {
      std::unordered_map<std::string, int> config;
      for (size_t i = 1; i < tokens.size(); ++i) {
        std::vector<std::string> parts = Split(tokens[i], ':');
        if (parts.size() == 2) config[parts[0]] = std::stoi(parts[1]);
      }
      engine = std::make_unique<SquirrelResearch>(config);
    }
    else if (cmd == "HideNut") {
      // HideNut <ts> <loc> <nut_id> <weight> <ttl>
      if (!engine) throw std::runtime_error("Command issued before Init");
      bool res = engine->hide_nut(std::stod(tokens[1]), tokens[2], tokens[3], 
                                  std::stod(tokens[4]), std::stod(tokens[5]));
      results.push_back("HideNut=" + std::string(res ? "True" : "False"));
    }
    else if (cmd == "RetrieveNut" || cmd == "RetrieveNuts") {
      // RetrieveNut <ts> <loc> <capacity>
      if (!engine) throw std::runtime_error("Command issued before Init");
      auto nuts = engine->retrieve_nut(std::stod(tokens[1]), tokens[2], std::stoi(tokens[3]));
      
      std::ostringstream oss;
      oss << "RetrieveNut=[";
      for (size_t i = 0; i < nuts.size(); ++i) {
        oss << "'" << nuts[i] << "'";
        if (i < nuts.size() - 1) oss << ", ";
      }
      oss << "]";
      results.push_back(oss.str());
    }
  }
  return results;
}

#ifndef USE_TEST_HARNESS
int main() {
    return 0;
}
#endif
// ==================== END LEETCODE SUBMISSION ====================

#ifdef USE_TEST_HARNESS
#include "TestHarness.h"

// Main Test Runner
int main(int argc, char* argv[]) {
  PARSE_TEST_ARGS(argc, argv);
  // 1. Prepare Input Data (Raw Commands)
  std::vector<std::string> input_commands = {
      "Init pineTree:3 oakTree:1",
      "HideNut 100 pineTree nut1 0.3 600",
      "HideNut 101 pineTree nut2 0.4 600",
      "HideNut 110 oakTree nut3 0.3 600",
      "HideNut 115 pineTree nut4 0.3 600",
      "HideNut 140 oakTree nut5 0.35 600",
      "RetrieveNut 141 oakTree 3",
      "RetrieveNut 142 pineTree 5"
  };

  // 2. Prepare Expected Output
  std::vector<std::string> expected_output = {
      "HideNut=True",
      "HideNut=True",
      "HideNut=True",
      "HideNut=True",
      "HideNut=False",
      "RetrieveNut=['nut3']",
      "RetrieveNut=['nut2', 'nut4', 'nut1']"
  };

  // 3. Run Test using your Harness
  // Note: TestHarness uses isEqual(vector, vector) which resolves to std::vector::operator==
  // and toString(vector) which resolves to the recursive helper.
  runTest("Sample Case", run_squirrel_simulation, expected_output, 500, input_commands);

  return 0;
}
#endif
