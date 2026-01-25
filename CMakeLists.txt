cmake_minimum_required(VERSION 3.29)
project(leetcodes)

set(CMAKE_CXX_STANDARD 23)

include_directories(harness)


# 1. Find all files in the 'src' directory that end in .cpp
file(GLOB_RECURSE PROBLEM_SOURCES "src/*.cpp")

# 2. Loop over every file that was found
foreach(SOURCE_FILE ${PROBLEM_SOURCES})

	# 3. Get the filename without the path or .cpp extension
	#    e.g., "src/1_two_sum.cpp" -> "1_two_sum"
	get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)

	# 4. Create a new executable for this file
	#    e.g., add_executable(1_two_sum src/1_two_sum.cpp)
	add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})

endforeach()
