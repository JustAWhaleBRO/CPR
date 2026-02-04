#!/bin/bash
# Extract AtCoder submission code from a dual-mode file
# Usage: extract <problem_name>
# Can be run from anywhere inside the CPR project
# Example: extract z-frog1

if [ -z "$1" ]; then
    echo "Usage: extract <problem_name>"
    echo "Example: extract z-frog1"
    echo ""
    echo "Can be run from anywhere inside the CPR project"
    exit 1
fi

PROBLEM_NAME="$1"

# Get the at_coder directory relative to this script's location
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
atcoder_dir="$SCRIPT_DIR"

if [ ! -d "$atcoder_dir" ]; then
    echo "Error: at_coder directory not found at $atcoder_dir"
    exit 1
fi

# Search for the problem folder in all subdirectories
found_dirs=()
while IFS= read -r dir; do
    found_dirs+=("$dir")
done < <(find "$atcoder_dir" -type d -name "$PROBLEM_NAME" 2>/dev/null)

if [ ${#found_dirs[@]} -eq 0 ]; then
    echo "Error: Problem folder '$PROBLEM_NAME' not found in at_coder directory"
    exit 1
fi

if [ ${#found_dirs[@]} -gt 1 ]; then
    echo "Error: Multiple folders found with name '$PROBLEM_NAME':"
    printf '%s\n' "${found_dirs[@]}"
    exit 1
fi

FILE="${found_dirs[0]}/$PROBLEM_NAME.cpp"

if [ ! -f "$FILE" ]; then
    echo "Error: File not found: $FILE"
    exit 1
fi

echo "Extracting AtCoder submission code from $FILE"
echo "=============================================="
echo ""

# Extract from ATCODER SUBMISSION marker to END ATCODER SUBMISSION marker
# Remove:
#   - ATCODER SUBMISSION markers
#   - #ifndef/#endif preprocessor directives
#   - #include "Debug.h"
#   - All dbg macro calls (dbg, dbg_*, cdbg)
sed -n '/ATCODER SUBMISSION (copy from here)/,/END ATCODER SUBMISSION/p' "$FILE" | \
    grep -v "ATCODER SUBMISSION" | \
    grep -v "END ATCODER SUBMISSION" | \
    grep -v "^#ifndef" | \
    grep -v "^#endif" | \
    grep -v 'Debug.h' | \
    grep -E -v '^[[:space:]]*dbg' | \
    grep -E -v '^[[:space:]]*cdbg'

echo ""
echo "=============================================="
echo "Copy the above code and paste it into AtCoder"

