# Debug & Command Reference

## Command Cheat Sheet

```bash
make run <target>                    # Run tests (no debug)
make run <target> <test>             # Run specific test
make run-debug <target>              # Run with debug output
make run-debug <target> <test>       # Debug specific test
make build                           # Build all
make list                            # List targets
make clean                           # Clean build
make help                            # Show help
extract <problem>                    # Extract submission code to stdout
extract-file <problem>               # Extract submission code to file
```

---

## Debug Macros

For full syntax reference → [harness/DEBUG_QUICK_REF.md](harness/DEBUG_QUICK_REF.md)

### Most Used

```cpp
dbg(var1, var2, ...);                        // Print variables
dbg_section("title");                        // Section separator
dbg_iter(i, vars...);                        // In loops
dbg_dp2d_labeled(dp, "row", "col");          // DP tables
```

### By Category

| Category | Macros |
|----------|--------|
| Basic | `dbg()`, `dbg_section()`, `dbg_iter()`, `dbg_if()` |
| Arrays | `dbg_arr()`, `dbg_mat()`, `dbg_grid()` |
| DP | `dbg_dp()`, `dbg_dp2d()`, `dbg_dp2d_labeled()` |
| Graphs | `dbg_graph()`, `dbg_ugraph()`, `dbg_tree()` |
| Data Structures | `dbg_list()`, `dbg_btree()` |
| Binary | `dbg_bin()`, `dbg_bits()`, `dbg_range()` |

---

## Typical Workflow

```bash
# 1. See which tests fail
make run l-deque

# 2. Debug failing test
make run-debug l-deque Sample4

# 3. Fix, verify all pass
make run l-deque

# 4. Extract for submission (from anywhere in CPR)
extract l-deque              # Print to stdout for copying
# OR
extract-file l-deque         # Save to <problem>_clean.cpp file
```

---

## Example Output

**Without debug (`make run`):**
```
══════════ Test: Sample1 ══════════
✓ PASS (0 ms)
```

**With debug (`make run-debug`):**
```
[10] N, a = 4, [10, 80, 90, 30]

══════════ After base case ══════════
[20] dp (4×4) [L][R]:
R\L   0  1  2  3
    +------------
  0  10 70 20 10
  ...
══════════ Test: Sample1 ══════════
✓ PASS (0 ms)
```

---

## Code Template

```cpp
#include "Debug.h"

ll solve(int N, const vector<int>& a) {
    dbg(N, a);                              // Print inputs
    
    vector<vector<ll>> dp(N, vector<ll>(N));
    dbg_section("Initialized");
    dbg_dp2d_labeled(dp, "L", "R");
    
    for (int i = 0; i < N; i++) {
        dbg_iter(i, dp[i]);
    }
    
    return dp[0][N-1];
}
```

---

## Submission

Code between these markers is extracted:

```cpp
// ==================== ATCODER SUBMISSION (copy from here) ====================
// solution code
// ==================== END ATCODER SUBMISSION ====================
```

Debug macros are **inactive** on online judges (no `DEBUG_ENABLED=1`).

---

→ **Macro syntax:** [harness/DEBUG_QUICK_REF.md](harness/DEBUG_QUICK_REF.md)  
→ **Setup:** [INSTALLATION.md](INSTALLATION.md)
