# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/xaliq/CS/L2/S2/DT/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xaliq/CS/L2/S2/DT/cmake/build

# Include any dependencies generated for this target.
include src/CMakeFiles/CMake-test.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/CMake-test.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/CMake-test.dir/flags.make

src/CMakeFiles/CMake-test.dir/main.c.o: src/CMakeFiles/CMake-test.dir/flags.make
src/CMakeFiles/CMake-test.dir/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xaliq/CS/L2/S2/DT/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/CMake-test.dir/main.c.o"
	cd /home/xaliq/CS/L2/S2/DT/cmake/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CMake-test.dir/main.c.o   -c /home/xaliq/CS/L2/S2/DT/cmake/src/main.c

src/CMakeFiles/CMake-test.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CMake-test.dir/main.c.i"
	cd /home/xaliq/CS/L2/S2/DT/cmake/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xaliq/CS/L2/S2/DT/cmake/src/main.c > CMakeFiles/CMake-test.dir/main.c.i

src/CMakeFiles/CMake-test.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CMake-test.dir/main.c.s"
	cd /home/xaliq/CS/L2/S2/DT/cmake/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xaliq/CS/L2/S2/DT/cmake/src/main.c -o CMakeFiles/CMake-test.dir/main.c.s

src/CMakeFiles/CMake-test.dir/main.c.o.requires:

.PHONY : src/CMakeFiles/CMake-test.dir/main.c.o.requires

src/CMakeFiles/CMake-test.dir/main.c.o.provides: src/CMakeFiles/CMake-test.dir/main.c.o.requires
	$(MAKE) -f src/CMakeFiles/CMake-test.dir/build.make src/CMakeFiles/CMake-test.dir/main.c.o.provides.build
.PHONY : src/CMakeFiles/CMake-test.dir/main.c.o.provides

src/CMakeFiles/CMake-test.dir/main.c.o.provides.build: src/CMakeFiles/CMake-test.dir/main.c.o


# Object files for target CMake-test
CMake__test_OBJECTS = \
"CMakeFiles/CMake-test.dir/main.c.o"

# External object files for target CMake-test
CMake__test_EXTERNAL_OBJECTS =

bin/CMake-test: src/CMakeFiles/CMake-test.dir/main.c.o
bin/CMake-test: src/CMakeFiles/CMake-test.dir/build.make
bin/CMake-test: include/libf.so
bin/CMake-test: src/CMakeFiles/CMake-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xaliq/CS/L2/S2/DT/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/CMake-test"
	cd /home/xaliq/CS/L2/S2/DT/cmake/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CMake-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/CMake-test.dir/build: bin/CMake-test

.PHONY : src/CMakeFiles/CMake-test.dir/build

src/CMakeFiles/CMake-test.dir/requires: src/CMakeFiles/CMake-test.dir/main.c.o.requires

.PHONY : src/CMakeFiles/CMake-test.dir/requires

src/CMakeFiles/CMake-test.dir/clean:
	cd /home/xaliq/CS/L2/S2/DT/cmake/build/src && $(CMAKE_COMMAND) -P CMakeFiles/CMake-test.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/CMake-test.dir/clean

src/CMakeFiles/CMake-test.dir/depend:
	cd /home/xaliq/CS/L2/S2/DT/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xaliq/CS/L2/S2/DT/cmake /home/xaliq/CS/L2/S2/DT/cmake/src /home/xaliq/CS/L2/S2/DT/cmake/build /home/xaliq/CS/L2/S2/DT/cmake/build/src /home/xaliq/CS/L2/S2/DT/cmake/build/src/CMakeFiles/CMake-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/CMake-test.dir/depend
