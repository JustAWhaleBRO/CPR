#!/bin/bash
# Extract AtCoder submission code from a dual-mode file
# Usage: ./extract_atcoder.sh z-frog1

if [ -z "$1" ]; then
    echo "Usage: $0 <problem_name>"
    echo "Example: $0 z-frog1"
    exit 1
fi

FILE="src/at_coder/$1/$1.cpp"

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

