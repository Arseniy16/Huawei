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
CMAKE_SOURCE_DIR = /home/arseniy/Huawei/Projects/Stack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arseniy/Huawei/Projects/Stack/build

# Utility rule file for run_mybenchmark.

# Include the progress variables for this target.
include benchmark/CMakeFiles/run_mybenchmark.dir/progress.make

benchmark/CMakeFiles/run_mybenchmark:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/arseniy/Huawei/Projects/Stack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running mybenchmark"
	cd /home/arseniy/Huawei/Projects/Stack/build/benchmark && ./mybenchmark

run_mybenchmark: benchmark/CMakeFiles/run_mybenchmark
run_mybenchmark: benchmark/CMakeFiles/run_mybenchmark.dir/build.make

.PHONY : run_mybenchmark

# Rule to build all files generated by this target.
benchmark/CMakeFiles/run_mybenchmark.dir/build: run_mybenchmark

.PHONY : benchmark/CMakeFiles/run_mybenchmark.dir/build

benchmark/CMakeFiles/run_mybenchmark.dir/clean:
	cd /home/arseniy/Huawei/Projects/Stack/build/benchmark && $(CMAKE_COMMAND) -P CMakeFiles/run_mybenchmark.dir/cmake_clean.cmake
.PHONY : benchmark/CMakeFiles/run_mybenchmark.dir/clean

benchmark/CMakeFiles/run_mybenchmark.dir/depend:
	cd /home/arseniy/Huawei/Projects/Stack/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arseniy/Huawei/Projects/Stack /home/arseniy/Huawei/Projects/Stack/benchmark /home/arseniy/Huawei/Projects/Stack/build /home/arseniy/Huawei/Projects/Stack/build/benchmark /home/arseniy/Huawei/Projects/Stack/build/benchmark/CMakeFiles/run_mybenchmark.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmark/CMakeFiles/run_mybenchmark.dir/depend

