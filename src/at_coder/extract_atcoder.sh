#!/bin/bash
# Extract submission code from a dual-mode file
# Usage:
#   extract <problem_name>       - Print clean code to stdout (for copying)
#   extract -f <problem_name>    - Save clean code to a file in the problem directory
#
# Can be run from anywhere inside the CPR project
# Searches across all src subdirectories (at_coder, cses, leetcode, etc.)
# Example: extract z-frog1
#          extract -f two-sets

# Get the src directory (parent of this script's location)
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_DIR="$(dirname "$SCRIPT_DIR")"

# Function to find the problem directory
find_problem_dir() {
    local problem_name="$1"
    local found_dirs=()

    while IFS= read -r dir; do
        found_dirs+=("$dir")
    done < <(find "$SRC_DIR" -type d -name "$problem_name" 2>/dev/null)

    if [ ${#found_dirs[@]} -eq 0 ]; then
        echo "Error: Problem folder '$problem_name' not found in src directory" >&2
        return 1
    fi

    if [ ${#found_dirs[@]} -gt 1 ]; then
        echo "Error: Multiple folders found with name '$problem_name':" >&2
        printf '%s\n' "${found_dirs[@]}" >&2
        return 1
    fi

    echo "${found_dirs[0]}"
}

# Function to extract clean code from a file
extract_code() {
    local file="$1"

    # Try different submission markers (ATCODER, CSES, or generic SUBMISSION)
    # Remove:
    #   - SUBMISSION markers
    #   - #ifndef/#endif preprocessor directives
    #   - #include "Debug.h"
    #   - All dbg macro calls (dbg, dbg_*, cdbg)
    sed -n '/SUBMISSION (copy from here)/,/END.*SUBMISSION/p' "$file" | \
        grep -v "SUBMISSION" | \
        grep -v "^#ifndef" | \
        grep -v "^#endif" | \
        grep -v 'Debug.h' | \
        grep -E -v '^[[:space:]]*dbg' | \
        grep -E -v '^[[:space:]]*cdbg'
}

# Show usage
show_usage() {
    echo "Usage: extract [-f] <problem_name>"
    echo ""
    echo "Options:"
    echo "  -f    Save clean code to <problem>_clean.cpp file instead of stdout"
    echo ""
    echo "Examples:"
    echo "  extract z-frog1      # Print to stdout for copying"
    echo "  extract -f z-frog1   # Save to z-frog1_clean.cpp"
    echo ""
    echo "Can be run from anywhere inside the CPR project."
    echo "Searches across all src subdirectories (at_coder, cses, leetcode, etc.)"
}

# Command: extract to stdout
cmd_extract() {
    local problem_name="$1"

    local problem_dir
    problem_dir=$(find_problem_dir "$problem_name") || exit 1

    local file="${problem_dir}/${problem_name}.cpp"

    if [ ! -f "$file" ]; then
        echo "Error: File not found: $file"
        exit 1
    fi

    echo "Extracting submission code from $file"
    echo "=============================================="
    echo ""

    extract_code "$file"

    echo ""
    echo "=============================================="
    echo "Copy the above code and paste it into the judge"
}

# Command: extract to file
cmd_extract_file() {
    local problem_name="$1"

    local problem_dir
    problem_dir=$(find_problem_dir "$problem_name") || exit 1

    local source_file="${problem_dir}/${problem_name}.cpp"
    local output_file="${problem_dir}/${problem_name}_clean.cpp"

    if [ ! -f "$source_file" ]; then
        echo "Error: Source file not found: $source_file"
        exit 1
    fi

    # Extract and write to file
    extract_code "$source_file" > "$output_file"

    echo "Clean submission code extracted to: $output_file"
    echo ""
    echo "File contents:"
    echo "=============================================="
    cat "$output_file"
    echo ""
    echo "=============================================="
}

# Main entry point
FILE_MODE=false

# Parse options
while getopts "fh" opt; do
    case $opt in
        f)
            FILE_MODE=true
            ;;
        h)
            show_usage
            exit 0
            ;;
        \?)
            show_usage
            exit 1
            ;;
    esac
done

# Shift past options
shift $((OPTIND - 1))

# Get problem name
PROBLEM_NAME="$1"

if [ -z "$PROBLEM_NAME" ]; then
    show_usage
    exit 1
fi

# Run appropriate command
if [ "$FILE_MODE" = true ]; then
    cmd_extract_file "$PROBLEM_NAME"
else
    cmd_extract "$PROBLEM_NAME"
fi
