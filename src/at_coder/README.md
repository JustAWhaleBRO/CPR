# AtCoder Problems

This directory contains solutions to AtCoder problems organized by contest.

## Installation

To set up the `extract` command on a new computer:

### Quick Setup

1. Make the script executable:
```bash
chmod +x ~/CLionProjects/leetcodes/src/at_coder/extract_atcoder.sh
```

2. Add this alias to your shell configuration file (`~/.zshrc` for zsh or `~/.bashrc` for bash):

```bash
# AtCoder extract command alias
alias extract="$HOME/CLionProjects/leetcodes/src/at_coder/extract_atcoder.sh"
```

3. Reload your shell configuration:

```bash
source ~/.zshrc  # or source ~/.bashrc
```

### Custom Location Setup

If your project is in a different location, adjust the path accordingly:

```bash
# 1. Make script executable
chmod +x /full/path/to/leetcodes/src/at_coder/extract_atcoder.sh

# 2. Add alias to your shell config (~/.zshrc or ~/.bashrc)
echo '' >> ~/.zshrc
echo '# AtCoder extract command alias' >> ~/.zshrc
echo 'alias extract="/full/path/to/leetcodes/src/at_coder/extract_atcoder.sh"' >> ~/.zshrc

# 3. Reload shell config
source ~/.zshrc
```

### Verification

Test that the installation worked:

```bash
cd /path/to/leetcodes/src/at_coder
extract i-coins
```

If you see C++ code output, the installation was successful!

## Usage

### Extract Submission Code

To extract clean submission code from any problem, use the `extract` command from **anywhere** inside the `at_coder/` directory:

```bash
# First time setup: restart your terminal or run:
source ~/.zshrc

# You can run extract from anywhere in at_coder directory tree:
cd src/at_coder
extract i-coins

# Or from within a contest directory:
cd src/at_coder/educational_dp_contest
extract h-grid1

# Or from any subdirectory:
cd src/at_coder/educational_dp_contest/i-coins
extract i-coins
```

The `extract` command will:
1. Automatically find the at_coder directory by searching upward
2. Search all subdirectories for the problem folder
3. Error if multiple folders with the same name exist
4. Extract only the submission code (between ATCODER SUBMISSION markers)
5. Print it to stdout ready to copy and paste into AtCoder

### Example

```bash
cd src/at_coder/educational_dp_contest
extract h-grid1
```

Output will be the clean C++ code ready for submission.

## Directory Structure

- `educational_dp_contest/` - All 26 problems from the Educational DP Contest
- `extract_atcoder.sh` - Script that extracts submission code (aliased as `extract`)
- `template.cpp` - Template for new AtCoder problems

## Debug Tools

Debug utilities are available in `harness/Debug.h`. See [DEBUG_QUICK_REF.md](../../harness/DEBUG_QUICK_REF.md) for full documentation.

### Quick Usage

```cpp
#include "Debug.h"

// Single variable
dbg(x);                    // [line] x = 42

// Vectors, maps, sets, etc.
dbg(vec);                  // [line] vec = [1, 2, 3]

// 1D DP table
dbg_dp(dp);                // Shows indices and values

// 2D DP table (great for knapsack, LCS, etc.)
dbg_dp2d(dp);              // Shows [i][j] grid with indices
dbg_dp2d_labeled(dp, "item", "weight");  // Custom labels

// Character grids (mazes, boards)
dbg_grid(grid);            // Color-coded # and . chars

// Graphs
dbg_graph(adj);            // Adjacency list visualization
```

To disable for submission, compile with `-DNO_DEBUG`.

## Adding New Contests

When you add a new contest directory:
1. Create a new folder under `at_coder/`
2. Add problem subdirectories with the dual-mode `.cpp` files
3. Use `extract <problem-name>` from within that contest directory

The extract command will work automatically with any new contest directory you create!

## Troubleshooting

### "command not found: extract"

1. Check if the alias is defined:
   ```bash
   alias | grep extract
   ```
   You should see: `extract='..../extract_atcoder.sh'`

2. If not, reload your shell config:
   ```bash
   source ~/.zshrc  # or source ~/.bashrc
   ```

3. If still not working, verify the script is executable:
   ```bash
   ls -la ~/CLionProjects/leetcodes/src/at_coder/extract_atcoder.sh
   ```
   It should show `-rwxr-xr-x` (with x for executable).

4. If not executable, run:
   ```bash
   chmod +x ~/CLionProjects/leetcodes/src/at_coder/extract_atcoder.sh
   ```

### "File not found" error when running extract

Make sure you're in the correct contest directory:
```bash
cd src/at_coder/educational_dp_contest  # or whichever contest
extract problem-name
```

The extract command looks for `problem-name/problem-name.cpp` in the current directory.

### Different project location

If your project is not at `~/CLionProjects/leetcodes`, update the PATH in your shell config file to point to the correct location.
