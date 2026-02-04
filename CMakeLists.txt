cmake_minimum_required(VERSION 3.29)
project(CPR)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(harness)

# Find all .cpp files in src/ directory (recursive)
# Works with any directory structure: src/leetcode/, src/at_coder/, src/codeforces/, etc.
file(GLOB_RECURSE PROBLEM_SOURCES "src/*.cpp")

# Loop through each found .cpp file
foreach(SOURCE_FILE ${PROBLEM_SOURCES})
    # Get the filename without extension
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)

    # Create executable
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})

    # Add USE_TEST_HARNESS for ALL problem directories
    # This works for: at_coder, leetcode, codeforces, interview, misc, and ANY future directories
    # All problems now use the dual-mode pattern with #ifdef USE_TEST_HARNESS
    target_compile_definitions(${EXECUTABLE_NAME} PRIVATE USE_TEST_HARNESS)
endforeach()
