# AtCoder Problems

Solutions to AtCoder problems organized by contest.

---

## Extract Command Setup

One-time setup to enable the `extract` command:

```bash
# Make executable
chmod +x ~/CLionProjects/CPR/src/at_coder/extract_atcoder.sh

# Add alias (zsh)
echo 'alias extract="$HOME/CLionProjects/CPR/src/at_coder/extract_atcoder.sh"' >> ~/.zshrc
source ~/.zshrc
```

For bash, use `~/.bashrc` instead. For different paths, adjust accordingly.

---

## Usage

From **anywhere** inside `at_coder/`:

```bash
cd src/at_coder
extract i-coins

cd src/at_coder/educational_dp_contest
extract h-grid1

cd src/at_coder/educational_dp_contest/i-coins
extract i-coins
```

The script:
1. Finds the problem folder anywhere under `at_coder/`
2. Extracts code between `ATCODER SUBMISSION` markers
3. Outputs clean submission-ready code

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
3. Run `extract problem-name` – works automatically!

---

## Troubleshooting

| Issue | Solution |
|-------|----------|
| `command not found: extract` | `source ~/.zshrc` or restart terminal |
| `File not found` | Make sure you're inside `at_coder/` directory |
| Not executable | `chmod +x src/at_coder/extract_atcoder.sh` |

---

→ **Commands & workflow:** [CMD_REFERENCE.md](../../CMD_REFERENCE.md)  
→ **Debug macros:** [harness/DEBUG_QUICK_REF.md](../../harness/DEBUG_QUICK_REF.md)
