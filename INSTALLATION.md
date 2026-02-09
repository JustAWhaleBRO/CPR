# Installation Guide

## Requirements

- CMake 3.20+
- C++20 compiler (g++ 10+ or clang++ 10+)
- Make
- Git
- macOS, Linux, or WSL

---

## Choose Your Starting Point

**Option A: Empty skeleton (recommended for new users)**
```bash
git clone -b skeleton https://github.com/<your-username>/CPR.git <CPR_PATH>
```
→ The skeleton branch clones the project with no solutions, ready for your own problem solving

**Option B: With example solutions**
```bash
git clone https://github.com/<your-username>/CPR.git <CPR_PATH>
```
→ Includes *my* solutions from LeetCode, AtCoder, etc. which I have solved. Which you can also use as reference.

**Replace:**
- `<your-username>` with the GitHub username/org hosting the repo
- `<CPR_PATH>` with where you want to store the project (e.g., `~/CPR`, `~/projects/competitive-programming`)

---

## Quick Setup

```bash
cd <CPR_PATH>                   # Navigate to project
cmake -B cmake-build-debug -S . # Configure
make build                      # Build
make list                       # Verify
```

---

## New Computer Setup

### 1. Install Dependencies

**macOS:**
```bash
xcode-select --install
brew install cmake
```

**Ubuntu/Debian:**
```bash
sudo apt update && sudo apt install build-essential cmake g++
```

**Other Linux (Fedora, Arch, etc.):**
```bash
# Use your distribution's package manager to install: g++, cmake, make
```

### 2. Clone & Build

**Choose your branch (see "Choose Your Starting Point" above):**

```bash
# Option A: Empty skeleton (no solutions)
git clone -b skeleton https://github.com/<your-username>/CPR.git <CPR_PATH>

# Option B: With example solutions
git clone https://github.com/<your-username>/CPR.git <CPR_PATH>
```

**Then build:**
```bash
cd <CPR_PATH>
cmake -B cmake-build-debug -S .
make build
```

**Example paths:**
```bash
# Home directory
cd ~/CPR

# Projects folder
cd ~/projects/competitive-programming

# Absolute path
cd /home/user/dev/CPR
```

### 3. Setup Extract Command


One-time setup for the `extract` command:

**Replace `<CPR_PATH>` with your actual project path:**

```bash
# Make executable
chmod +x <CPR_PATH>/src/at_coder/extract_atcoder.sh

# Add alias (zsh)
echo 'alias extract="<CPR_PATH>/src/at_coder/extract_atcoder.sh"' >> ~/.zshrc
source ~/.zshrc

# For bash, use ~/.bashrc instead
# echo 'alias extract="<CPR_PATH>/src/at_coder/extract_atcoder.sh"' >> ~/.bashrc
# source ~/.bashrc
```

**Example for `/home/user/projects/CPR`:**
```bash
chmod +x /home/user/projects/CPR/src/at_coder/extract_atcoder.sh
echo 'alias extract="/home/user/projects/CPR/src/at_coder/extract_atcoder.sh"' >> ~/.zshrc
source ~/.zshrc
```

**Usage:** See [src/at_coder/README.md](src/at_coder/README.md)


### 4. Verify

```bash
# From any directory
make run l-deque       # Should show test results
```

---

## Troubleshooting

| Issue | Solution |
|-------|----------|
| CMake not found | `brew install cmake` (macOS) or `apt install cmake` (Linux) |
| Compiler not found | `xcode-select --install` (macOS) or `apt install build-essential` (Linux) |
| `extract` not found | Verify the alias in your shell config file and restart terminal |
| Build errors | `make clean && cmake -B cmake-build-debug -S . && make build` |
| Wrong path in alias | Verify `<CPR_PATH>` exists: `ls <CPR_PATH>/CMakeLists.txt` |

---

## IDE Setup (Optional)

**CLion:**
1. File → Open → Select `<CPR_PATH>` folder
2. CLion auto-detects CMakeLists.txt

**VS Code:**
1. Install C/C++ (Microsoft) and CMake Tools extensions
2. Open `<CPR_PATH>` folder
3. Configure CMake when prompted

---

→ **Next:** [README.md](README.md) for usage, [CMD_REFERENCE.md](CMD_REFERENCE.md) for commands





