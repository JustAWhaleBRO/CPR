#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include <cstring>

using namespace std;

// --- Candidate A: Backward Pass (Optimized Space) ---
class SolutionBackward {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> s; // Stores indices only

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            if (!s.empty()) {
                res[i] = s.top() - i;
            }
            s.push(i);
        }
        return res;
    }
};

// --- Candidate B: Forward Pass (Redundant Storage) ---
class SolutionForward {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> s; // Stores {temperature, index}

        for (int i = 0; i < n; ++i) {
            int current_temp = temperatures[i];
            while (!s.empty() && current_temp > s.top().first) {
                auto [prev_temp, prev_index] = s.top();
                s.pop();
                res[prev_index] = i - prev_index;
            }
            s.push({current_temp, i});
        }
        return res;
    }
};

// --- Helper: Generate Deterministic Large Dataset ---
vector<int> generateLargeDataset(int n) {
    // Fixed seed (42) ensures both runs process the exact same data
    mt19937 rng(42);
    uniform_int_distribution<int> dist(1, 100);

    vector<int> data(n);
    for (auto &x : data) x = dist(rng);
    return data;
}

int main(int argc, char* argv[]) {
    // Simple CLI parser
    if (argc < 2) {
        // Default behavior if no args provided (optional)
        std::cerr << "Usage: " << argv[0] << " [backward|forward]\n";
        return 1;
    }

    // 1. Generate Data (5 Million Elements)
    // The generation cost is excluded from the measurement if possible,
    // but since hyperfine measures the whole process, it adds a constant overhead to both.
    const int N = 100'000'000;
    vector<int> data = generateLargeDataset(N);

    // 2. Run Selected Algorithm
    if (std::strcmp(argv[1], "backward") == 0) {
        SolutionBackward sol;
        // volatile prevents dead-code elimination optimizations
        volatile auto res = sol.dailyTemperatures(data);
    }
    else if (std::strcmp(argv[1], "forward") == 0) {
        SolutionForward sol;
        volatile auto res = sol.dailyTemperatures(data);
    }
    else {
        std::cerr << "Error: Unknown mode '" << argv[1] << "'. Use 'backward' or 'forward'.\n";
        return 1;
    }

    return 0;
}