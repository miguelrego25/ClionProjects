# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\migue\CLionProjects\Lab1\Ficha3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\migue\CLionProjects\Lab1\Ficha3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ficha3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ficha3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ficha3.dir/flags.make

CMakeFiles/Ficha3.dir/ficha3.1.3.c.obj: CMakeFiles/Ficha3.dir/flags.make
CMakeFiles/Ficha3.dir/ficha3.1.3.c.obj: ../ficha3.1.3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\migue\CLionProjects\Lab1\Ficha3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Ficha3.dir/ficha3.1.3.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Ficha3.dir\ficha3.1.3.c.obj   -c C:\Users\migue\CLionProjects\Lab1\Ficha3\ficha3.1.3.c

CMakeFiles/Ficha3.dir/ficha3.1.3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ficha3.dir/ficha3.1.3.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\migue\CLionProjects\Lab1\Ficha3\ficha3.1.3.c > CMakeFiles\Ficha3.dir\ficha3.1.3.c.i

CMakeFiles/Ficha3.dir/ficha3.1.3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ficha3.dir/ficha3.1.3.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\migue\CLionProjects\Lab1\Ficha3\ficha3.1.3.c -o CMakeFiles\Ficha3.dir\ficha3.1.3.c.s

# Object files for target Ficha3
Ficha3_OBJECTS = \
"CMakeFiles/Ficha3.dir/ficha3.1.3.c.obj"

# External object files for target Ficha3
Ficha3_EXTERNAL_OBJECTS =

Ficha3.exe: CMakeFiles/Ficha3.dir/ficha3.1.3.c.obj
Ficha3.exe: CMakeFiles/Ficha3.dir/build.make
Ficha3.exe: CMakeFiles/Ficha3.dir/linklibs.rsp
Ficha3.exe: CMakeFiles/Ficha3.dir/objects1.rsp
Ficha3.exe: CMakeFiles/Ficha3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\migue\CLionProjects\Lab1\Ficha3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Ficha3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ficha3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ficha3.dir/build: Ficha3.exe

.PHONY : CMakeFiles/Ficha3.dir/build

CMakeFiles/Ficha3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ficha3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ficha3.dir/clean

CMakeFiles/Ficha3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\migue\CLionProjects\Lab1\Ficha3 C:\Users\migue\CLionProjects\Lab1\Ficha3 C:\Users\migue\CLionProjects\Lab1\Ficha3\cmake-build-debug C:\Users\migue\CLionProjects\Lab1\Ficha3\cmake-build-debug C:\Users\migue\CLionProjects\Lab1\Ficha3\cmake-build-debug\CMakeFiles\Ficha3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ficha3.dir/depend

