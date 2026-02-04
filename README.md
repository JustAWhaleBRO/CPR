# Competitive Programming Resuscitation (CPR)

**For:** Competitive programmers, DSA practitioners, and interview prep learners
**Problem:** You write code locally with debug output, but submissions to LeetCode/AtCoder require clean code without debug statements. You spend time manually cleaning code, risk introducing bugs, and manage test cases separately.
**Solution:** CPR is an integrated C++ environment where you write once with debugging, test locally with visual debug output, and extract clean submission code automatically—no manual cleanup, no errors.

**In one sentence:** Write messy debug code locally → test with rich, intuitive visualizations → one command extracts judge-ready code → copy-paste to LeetCode/AtCoder/Codeforces for submission.

---

## Getting Started

**Choose your starting point:**

| Branch | Command | What You Get                                            |
|--------|---------|---------------------------------------------------------|
| `skeleton` | `git clone -b skeleton https://github.com/<user>/CPR.git` | Empty project, no solutions—start fresh                 |
| `main` | `git clone https://github.com/<user>/CPR.git` | Includes *my* solutions for *my* problems I have solved |

**Then build:**
```bash
cd CPR
cmake -B cmake-build-debug -S .
make build
```

→ See [INSTALLATION.md](INSTALLATION.md) for detailed setup instructions

---

## What CPR Does For You

### For Debugging & Problem-Solving

- **Visual Debug Framework** – See visuals of DP tables, graphs, and arrays formatted beautifully so that you can visualize how your algorithm works step by step.
- **30+ Debug Macros** – Pre-built commands for every data structure: `dbg_dp2d()`, `dbg_graph()`, `dbg_btree()`, etc.
- **No Recompile for Debug Toggle** – Set `DEBUG_ENABLED=1` to see debug output; remove it to see clean results—no code changes
- **Organize Tests** – Run all test cases or debug a single failing test
- **Color-Coded Results** – ✓ PASS (green), ✗ FAIL (red)—immediate visual feedback

### For Submission Management

- **Write Debug Code Freely** – Include debug statements, test prints, and visualization code without fear
- **Automatic Code Extraction** – `extract problem-name` removes all debug code and outputs judge-ready submission
- **One-Judge-Per-File** – Test your solution locally with test cases, submit to any judge (LeetCode, AtCoder, Codeforces, etc.)—same code
- **Multi-Platform Organization** – Manage all problems from all judges in one environment
- **Zero Manual Cleanup** – Extract automatically handles all separation—no copy-paste errors or needing to adjust code before submission.

---

## Quick Start

Suppose you want to practice Leetcode problems.

**Step 1: Create a problem**
```bash
mkdir -p src/leetcode/my_problem/my_problem
touch src/leetcode/my_problem/my_problem/my_problem.cpp
```

**Step 2: Write your solution** (no need to hide debug code!)
```cpp
#include "Debug.h" // enables debugging macros

int main() {
    vector<int> arr = {1, 2, 3};
    dbg(arr);  // ← This will show in debug mode, hidden in submission
    return 0;
}
```

**Step 3: Test locally**
```bash
make run my_problem              # Run with tests (clean output)
make run-debug my_problem        # Run with debug output (see dbg() statements)
make run-debug my_problem Test1  # Run one of your test cases with visualizations
```

**Step 4: Extract for submission**
```bash
extract my_problem
# → Outputs clean code ready to copy-paste to LeetCode
```

---

## Project Structure

**Everything in one place—organized by judge:**

```
CPR/
├── README.md                 # This file
├── CMD_REFERENCE.md          # Commands, workflow, debug macros
├── INSTALLATION.md           # Setup instructions
├── Makefile / CMakeLists.txt # Automated build system
├── harness/
│   ├── Debug.h               # 30+ debug macros
│   ├── TestHarness.h         # Test runner framework
│   └── DEBUG_QUICK_REF.md    # Debug macro syntax reference
└── src/                       # All your problems from all judges
    ├── at_coder/             # AtCoder problems
    ├── leetcode/             # LeetCode problems
    ├── codeforces/           # Codeforces problems
    ├── interview/            # Interview prep problems
    └── misc/                 # Personal practice
```

**CPR automatically discovers problems at any nesting depth:**
- Each problem gets its own folder: `problem_name/problem_name.cpp`
- CMake finds them all, builds them all, runs them all
- No configuration needed—add a problem, run it immediately

### Expanding to Multiple Problem Sources

Start with any judge, add more anytime:

```
src/
├── leetcode/
│   ├── 1_two_sum/1_two_sum.cpp
│   ├── 2_add_two_numbers/2_add_two_numbers.cpp
│   └── ...
├── atcoder/
│   ├── educational_dp/
│   │   ├── i_coins/i_coins.cpp
│   │   └── ...
├── codeforces/            // add new directories
│   ├── div2_round_900/
│   │   ├── problem_a/problem_a.cpp
│   │   └── problem_b/problem_b.cpp
├── interview/             // practice your interviews
│   ├── arrays/
│   │   ├── two_sum/two_sum.cpp
│   │   └── median_sorted_arrays/median_sorted_arrays.cpp
│   └── trees/
│       └── invert_tree/invert_tree.cpp
└── misc/
    └── random_practice/random_practice.cpp
```

---

## How to Add New Problems

**Creating a new problem takes 30 seconds:**

```bash
# 1. Create the folder (name must match .cpp filename)
mkdir -p src/leetcode/my_problem/my_problem
# or
mkdir -p src/interview/arrays/two_sum/two_sum

# 2. Create the file
touch src/leetcode/my_problem/my_problem/my_problem.cpp

# 3. Start coding (include Debug.h to be able do debug)
#include "Debug.h"
// ... your solution ...

# 4. Run immediately (auto-builds)
make run my_problem
```

**That's it.** No Makefile edits, no configuration files. CMake auto-discovers everything.

---

## Real-World Example

Here's what solving a problem looks like:

```
1. You see a LeetCode problem (Two Sum)
   → mkdir -p src/leetcode/1_two_sum/1_two_sum

2. Write solution with debug statements:
   vector<int> nums = {2, 7, 11, 15};
   dbg("Input:", nums);           // Shows values
   dbg_section("Processing");
   map<int, int> seen;
   dbg(seen);                      // Shows map

3. Test locally:
   make run 1_two_sum              # Output: ✓ PASS / ✗ FAIL
   make run-debug 1_two_sum        # Output: Shows all debug output

4. Failing test? Debug it:
   make run-debug 1_two_sum Test2  # Shows debug output only for Test2

5. Fixed? Extract for submission (from anywhere in CPR):
   extract 1_two_sum
   # Outputs clean code without any debug statements

6. Paste into LeetCode:
   → All dbg() calls removed
   → Debug macros gone
   → Submission-ready code
   → No compilation errors
```

---

## Related documentation

| Document | Description |
|----------|-------------|
| [CMD_REFERENCE.md](CMD_REFERENCE.md) | Commands, workflow, debug macros |
| [INSTALLATION.md](INSTALLATION.md) | Setup and troubleshooting |
| [harness/DEBUG_QUICK_REF.md](harness/DEBUG_QUICK_REF.md) | Debug macro syntax |
| [src/at_coder/README.md](src/at_coder/README.md) | AtCoder extract setup |

---

## Requirements

CMake 3.20+, C++20 compiler, Make

→ See [INSTALLATION.md](INSTALLATION.md) for setup details.
