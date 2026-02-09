# AtCoder Problems

Solutions to AtCoder problems organized by contest.

---

## Extract Command Setup

One-time setup to enable the `extract` command:

```bash
# Make executable
chmod +x ~/<YOUR-CPR-PATH>/src/at_coder/extract_atcoder.sh

# Add alias (zsh)
echo 'alias extract="$HOME/<YOUR-CPR-PATH>/src/at_coder/extract_atcoder.sh"' >> ~/.zshrc
source ~/.zshrc
```

For bash, use `~/.bashrc` instead. For different paths, adjust accordingly.

---

## Usage

From **anywhere** inside the CPR project:

```bash
# Print to stdout (for copying)
extract i-coins

# Save to file (creates i-coins_clean.cpp in problem directory)
extract -f i-coins

# Works from any directory
cd src/leetcode
extract h-grid1

cd harness
extract -f l-deque
```

The script:
1. Finds the problem folder anywhere under `src/`
2. Extracts code between `SUBMISSION` markers
3. Removes debug code (`#include "Debug.h"`, `dbg()` calls, etc.)
4. Outputs clean submission-ready code

---

## Directory Structure

```
at_coder/
├── README.md              # This file
├── extract_atcoder.sh     # Extract script
├── template.cpp           # Template for new problems
└── educational_dp_contest/
    ├── i-coins/
    ├── l-deque/
    └── ...
```

---

## Adding New Contests

1. Create contest folder: `mkdir abc_350`
2. Add problem folders with `problem.cpp` files
3. Run `extract problem-name` from anywhere in CPR – works automatically!

---

## Troubleshooting

| Issue | Solution |
|-------|----------|
| `command not found: extract` | `source ~/.zshrc` or restart terminal |
| `Problem folder not found` | Check spelling or verify folder exists in `src/` |
| Not executable | `chmod +x src/at_coder/extract_atcoder.sh` |

---

→ **Commands & workflow:** [CMD_REFERENCE.md](../../CMD_REFERENCE.md)  
→ **Debug macros:** [harness/DEBUG_QUICK_REF.md](../../harness/DEBUG_QUICK_REF.md)
