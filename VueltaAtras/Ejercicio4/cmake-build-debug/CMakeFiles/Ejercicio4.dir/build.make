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
CMAKE_COMMAND = C:\Users\cocol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8617.54\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\cocol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8617.54\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ejercicio4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Ejercicio4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Ejercicio4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ejercicio4.dir/flags.make

CMakeFiles/Ejercicio4.dir/main.c.obj: CMakeFiles/Ejercicio4.dir/flags.make
CMakeFiles/Ejercicio4.dir/main.c.obj: C:/Users/cocol/OneDrive/Escritorio/Universidad/Repos/AlgorithmDesign/VueltaAtras/Ejercicio4/main.c
CMakeFiles/Ejercicio4.dir/main.c.obj: CMakeFiles/Ejercicio4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Ejercicio4.dir/main.c.obj"
	C:\Users\cocol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8617.54\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Ejercicio4.dir/main.c.obj -MF CMakeFiles\Ejercicio4.dir\main.c.obj.d -o CMakeFiles\Ejercicio4.dir\main.c.obj -c C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4\main.c

CMakeFiles/Ejercicio4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ejercicio4.dir/main.c.i"
	C:\Users\cocol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8617.54\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4\main.c > CMakeFiles\Ejercicio4.dir\main.c.i

CMakeFiles/Ejercicio4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ejercicio4.dir/main.c.s"
	C:\Users\cocol\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.8617.54\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4\main.c -o CMakeFiles\Ejercicio4.dir\main.c.s

# Object files for target Ejercicio4
Ejercicio4_OBJECTS = \
"CMakeFiles/Ejercicio4.dir/main.c.obj"

# External object files for target Ejercicio4
Ejercicio4_EXTERNAL_OBJECTS =

Ejercicio4.exe: CMakeFiles/Ejercicio4.dir/main.c.obj
Ejercicio4.exe: CMakeFiles/Ejercicio4.dir/build.make
Ejercicio4.exe: CMakeFiles/Ejercicio4.dir/linklibs.rsp
Ejercicio4.exe: CMakeFiles/Ejercicio4.dir/objects1.rsp
Ejercicio4.exe: CMakeFiles/Ejercicio4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Ejercicio4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ejercicio4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ejercicio4.dir/build: Ejercicio4.exe
.PHONY : CMakeFiles/Ejercicio4.dir/build

CMakeFiles/Ejercicio4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ejercicio4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ejercicio4.dir/clean

CMakeFiles/Ejercicio4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4 C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4 C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4\cmake-build-debug C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4\cmake-build-debug C:\Users\cocol\OneDrive\Escritorio\Universidad\Repos\AlgorithmDesign\VueltaAtras\Ejercicio4\cmake-build-debug\CMakeFiles\Ejercicio4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ejercicio4.dir/depend

