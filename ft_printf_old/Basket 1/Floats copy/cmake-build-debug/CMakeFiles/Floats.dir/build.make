# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Users/umoff/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/umoff/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/umoff/git_printf/Floats

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/umoff/git_printf/Floats/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Floats.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Floats.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Floats.dir/flags.make

CMakeFiles/Floats.dir/floats.c.o: CMakeFiles/Floats.dir/flags.make
CMakeFiles/Floats.dir/floats.c.o: ../floats.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/umoff/git_printf/Floats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Floats.dir/floats.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Floats.dir/floats.c.o   -c /Users/umoff/git_printf/Floats/floats.c

CMakeFiles/Floats.dir/floats.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Floats.dir/floats.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/umoff/git_printf/Floats/floats.c > CMakeFiles/Floats.dir/floats.c.i

CMakeFiles/Floats.dir/floats.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Floats.dir/floats.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/umoff/git_printf/Floats/floats.c -o CMakeFiles/Floats.dir/floats.c.s

# Object files for target Floats
Floats_OBJECTS = \
"CMakeFiles/Floats.dir/floats.c.o"

# External object files for target Floats
Floats_EXTERNAL_OBJECTS =

Floats: CMakeFiles/Floats.dir/floats.c.o
Floats: CMakeFiles/Floats.dir/build.make
Floats: CMakeFiles/Floats.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/umoff/git_printf/Floats/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Floats"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Floats.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Floats.dir/build: Floats

.PHONY : CMakeFiles/Floats.dir/build

CMakeFiles/Floats.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Floats.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Floats.dir/clean

CMakeFiles/Floats.dir/depend:
	cd /Users/umoff/git_printf/Floats/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/umoff/git_printf/Floats /Users/umoff/git_printf/Floats /Users/umoff/git_printf/Floats/cmake-build-debug /Users/umoff/git_printf/Floats/cmake-build-debug /Users/umoff/git_printf/Floats/cmake-build-debug/CMakeFiles/Floats.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Floats.dir/depend

