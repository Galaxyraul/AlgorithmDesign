# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\cocol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\cocol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/EjercicioCentroUnion.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/EjercicioCentroUnion.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/EjercicioCentroUnion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EjercicioCentroUnion.dir/flags.make

CMakeFiles/EjercicioCentroUnion.dir/main.c.obj: CMakeFiles/EjercicioCentroUnion.dir/flags.make
CMakeFiles/EjercicioCentroUnion.dir/main.c.obj: D:/AlgorithmDesign/DivideYVenceras/EjercicioCentroUnion/main.c
CMakeFiles/EjercicioCentroUnion.dir/main.c.obj: CMakeFiles/EjercicioCentroUnion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/EjercicioCentroUnion.dir/main.c.obj"
	C:\Users\cocol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/EjercicioCentroUnion.dir/main.c.obj -MF CMakeFiles\EjercicioCentroUnion.dir\main.c.obj.d -o CMakeFiles\EjercicioCentroUnion.dir\main.c.obj -c D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion\main.c

CMakeFiles/EjercicioCentroUnion.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EjercicioCentroUnion.dir/main.c.i"
	C:\Users\cocol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion\main.c > CMakeFiles\EjercicioCentroUnion.dir\main.c.i

CMakeFiles/EjercicioCentroUnion.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EjercicioCentroUnion.dir/main.c.s"
	C:\Users\cocol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion\main.c -o CMakeFiles\EjercicioCentroUnion.dir\main.c.s

# Object files for target EjercicioCentroUnion
EjercicioCentroUnion_OBJECTS = \
"CMakeFiles/EjercicioCentroUnion.dir/main.c.obj"

# External object files for target EjercicioCentroUnion
EjercicioCentroUnion_EXTERNAL_OBJECTS =

EjercicioCentroUnion.exe: CMakeFiles/EjercicioCentroUnion.dir/main.c.obj
EjercicioCentroUnion.exe: CMakeFiles/EjercicioCentroUnion.dir/build.make
EjercicioCentroUnion.exe: CMakeFiles/EjercicioCentroUnion.dir/linklibs.rsp
EjercicioCentroUnion.exe: CMakeFiles/EjercicioCentroUnion.dir/objects1.rsp
EjercicioCentroUnion.exe: CMakeFiles/EjercicioCentroUnion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable EjercicioCentroUnion.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\EjercicioCentroUnion.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EjercicioCentroUnion.dir/build: EjercicioCentroUnion.exe
.PHONY : CMakeFiles/EjercicioCentroUnion.dir/build

CMakeFiles/EjercicioCentroUnion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\EjercicioCentroUnion.dir\cmake_clean.cmake
.PHONY : CMakeFiles/EjercicioCentroUnion.dir/clean

CMakeFiles/EjercicioCentroUnion.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion\cmake-build-debug D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion\cmake-build-debug D:\AlgorithmDesign\DivideYVenceras\EjercicioCentroUnion\cmake-build-debug\CMakeFiles\EjercicioCentroUnion.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EjercicioCentroUnion.dir/depend
