# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arseniy/Huawei/Projects/Queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arseniy/Huawei/Projects/Queue/build

# Utility rule file for run_queue_stack.

# Include the progress variables for this target.
include test/CMakeFiles/run_queue_stack.dir/progress.make

test/CMakeFiles/run_queue_stack:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/arseniy/Huawei/Projects/Queue/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running queue_stack"
	cd /home/arseniy/Huawei/Projects/Queue/build/test && ./queue_stack

run_queue_stack: test/CMakeFiles/run_queue_stack
run_queue_stack: test/CMakeFiles/run_queue_stack.dir/build.make

.PHONY : run_queue_stack

# Rule to build all files generated by this target.
test/CMakeFiles/run_queue_stack.dir/build: run_queue_stack

.PHONY : test/CMakeFiles/run_queue_stack.dir/build

test/CMakeFiles/run_queue_stack.dir/clean:
	cd /home/arseniy/Huawei/Projects/Queue/build/test && $(CMAKE_COMMAND) -P CMakeFiles/run_queue_stack.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/run_queue_stack.dir/clean

test/CMakeFiles/run_queue_stack.dir/depend:
	cd /home/arseniy/Huawei/Projects/Queue/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arseniy/Huawei/Projects/Queue /home/arseniy/Huawei/Projects/Queue/test /home/arseniy/Huawei/Projects/Queue/build /home/arseniy/Huawei/Projects/Queue/build/test /home/arseniy/Huawei/Projects/Queue/build/test/CMakeFiles/run_queue_stack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/run_queue_stack.dir/depend
