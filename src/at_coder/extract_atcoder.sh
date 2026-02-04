#!/bin/bash
# Extract AtCoder submission code from a dual-mode file
# Usage: extract <problem_name>
# Can be run from anywhere inside the at_coder directory
# Example: extract z-frog1

if [ -z "$1" ]; then
    echo "Usage: extract <problem_name>"
    echo "Example: extract z-frog1"
    echo ""
    echo "Can be run from anywhere inside the at_coder directory"
    exit 1
fi

PROBLEM_NAME="$1"

# Find the at_coder directory by searching upwards
current_dir="$PWD"
atcoder_dir=""

while [ "$current_dir" != "/" ]; do
    if [ "$(basename "$current_dir")" = "at_coder" ]; then
        atcoder_dir="$current_dir"
        break
    fi
    current_dir="$(dirname "$current_dir")"
done

if [ -z "$atcoder_dir" ]; then
    echo "Error: Not in at_coder directory or any of its subdirectories"
    exit 1
fi

# Search for the problem folder in all subdirectories
found_dirs=()
while IFS= read -r line; do
    found_dirs+=("$line")
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
# Remove comment lines and preprocessor directives
sed -n '/ATCODER SUBMISSION (copy from here)/,/END ATCODER SUBMISSION/p' "$FILE" | \
    grep -v "ATCODER SUBMISSION" | \
    grep -v "END ATCODER SUBMISSION" | \
    grep -v "^#ifndef" | \
    grep -v "^#endif"

echo ""
echo "=============================================="
echo "Copy the above code and paste it into AtCoder"

