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
CMAKE_SOURCE_DIR = C:\Users\migue\CLionProjects\Lixo\Lixo\Depression

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\migue\CLionProjects\Lixo\Lixo\Depression\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Depression.c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Depression.c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Depression.c.dir/flags.make

CMakeFiles/Depression.c.dir/Depression.c.obj: CMakeFiles/Depression.c.dir/flags.make
CMakeFiles/Depression.c.dir/Depression.c.obj: ../Depression.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\migue\CLionProjects\Lixo\Lixo\Depression\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Depression.c.dir/Depression.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Depression.c.dir\Depression.c.obj   -c C:\Users\migue\CLionProjects\Lixo\Lixo\Depression\Depression.c

CMakeFiles/Depression.c.dir/Depression.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Depression.c.dir/Depression.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\migue\CLionProjects\Lixo\Lixo\Depression\Depression.c > CMakeFiles\Depression.c.dir\Depression.c.i

CMakeFiles/Depression.c.dir/Depression.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Depression.c.dir/Depression.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\migue\CLionProjects\Lixo\Lixo\Depression\Depression.c -o CMakeFiles\Depression.c.dir\Depression.c.s

# Object files for target Depression.c
Depression_c_OBJECTS = \
"CMakeFiles/Depression.c.dir/Depression.c.obj"

# External object files for target Depression.c
Depression_c_EXTERNAL_OBJECTS =

Depression.c.exe: CMakeFiles/Depression.c.dir/Depression.c.obj
Depression.c.exe: CMakeFiles/Depression.c.dir/build.make
Depression.c.exe: CMakeFiles/Depression.c.dir/linklibs.rsp
Depression.c.exe: CMakeFiles/Depression.c.dir/objects1.rsp
Depression.c.exe: CMakeFiles/Depression.c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\migue\CLionProjects\Lixo\Lixo\Depression\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Depression.c.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Depression.c.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Depression.c.dir/build: Depression.c.exe

.PHONY : CMakeFiles/Depression.c.dir/build

CMakeFiles/Depression.c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Depression.c.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Depression.c.dir/clean

CMakeFiles/Depression.c.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\migue\CLionProjects\Lixo\Lixo\Depression C:\Users\migue\CLionProjects\Lixo\Lixo\Depression C:\Users\migue\CLionProjects\Lixo\Lixo\Depression\cmake-build-debug C:\Users\migue\CLionProjects\Lixo\Lixo\Depression\cmake-build-debug C:\Users\migue\CLionProjects\Lixo\Lixo\Depression\cmake-build-debug\CMakeFiles\Depression.c.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Depression.c.dir/depend

