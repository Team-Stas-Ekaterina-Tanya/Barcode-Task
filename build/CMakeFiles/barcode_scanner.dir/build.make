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
CMAKE_SOURCE_DIR = /home/komi/CodeCademy/Barcode-Task

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/komi/CodeCademy/Barcode-Task/build

# Include any dependencies generated for this target.
include CMakeFiles/barcode_scanner.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/barcode_scanner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/barcode_scanner.dir/flags.make

CMakeFiles/barcode_scanner.dir/src/main.c.o: CMakeFiles/barcode_scanner.dir/flags.make
CMakeFiles/barcode_scanner.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/komi/CodeCademy/Barcode-Task/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/barcode_scanner.dir/src/main.c.o"
	/mnt/c/mingw-w64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/barcode_scanner.dir/src/main.c.o   -c /home/komi/CodeCademy/Barcode-Task/src/main.c

CMakeFiles/barcode_scanner.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/barcode_scanner.dir/src/main.c.i"
	/mnt/c/mingw-w64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/komi/CodeCademy/Barcode-Task/src/main.c > CMakeFiles/barcode_scanner.dir/src/main.c.i

CMakeFiles/barcode_scanner.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/barcode_scanner.dir/src/main.c.s"
	/mnt/c/mingw-w64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/komi/CodeCademy/Barcode-Task/src/main.c -o CMakeFiles/barcode_scanner.dir/src/main.c.s

CMakeFiles/barcode_scanner.dir/src/Barcode.c.o: CMakeFiles/barcode_scanner.dir/flags.make
CMakeFiles/barcode_scanner.dir/src/Barcode.c.o: ../src/Barcode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/komi/CodeCademy/Barcode-Task/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/barcode_scanner.dir/src/Barcode.c.o"
	/mnt/c/mingw-w64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/barcode_scanner.dir/src/Barcode.c.o   -c /home/komi/CodeCademy/Barcode-Task/src/Barcode.c

CMakeFiles/barcode_scanner.dir/src/Barcode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/barcode_scanner.dir/src/Barcode.c.i"
	/mnt/c/mingw-w64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/komi/CodeCademy/Barcode-Task/src/Barcode.c > CMakeFiles/barcode_scanner.dir/src/Barcode.c.i

CMakeFiles/barcode_scanner.dir/src/Barcode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/barcode_scanner.dir/src/Barcode.c.s"
	/mnt/c/mingw-w64/mingw64/bin/x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/komi/CodeCademy/Barcode-Task/src/Barcode.c -o CMakeFiles/barcode_scanner.dir/src/Barcode.c.s

# Object files for target barcode_scanner
barcode_scanner_OBJECTS = \
"CMakeFiles/barcode_scanner.dir/src/main.c.o" \
"CMakeFiles/barcode_scanner.dir/src/Barcode.c.o"

# External object files for target barcode_scanner
barcode_scanner_EXTERNAL_OBJECTS =

barcode_scanner: CMakeFiles/barcode_scanner.dir/src/main.c.o
barcode_scanner: CMakeFiles/barcode_scanner.dir/src/Barcode.c.o
barcode_scanner: CMakeFiles/barcode_scanner.dir/build.make
barcode_scanner: CMakeFiles/barcode_scanner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/komi/CodeCademy/Barcode-Task/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable barcode_scanner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/barcode_scanner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/barcode_scanner.dir/build: barcode_scanner

.PHONY : CMakeFiles/barcode_scanner.dir/build

CMakeFiles/barcode_scanner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/barcode_scanner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/barcode_scanner.dir/clean

CMakeFiles/barcode_scanner.dir/depend:
	cd /home/komi/CodeCademy/Barcode-Task/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/komi/CodeCademy/Barcode-Task /home/komi/CodeCademy/Barcode-Task /home/komi/CodeCademy/Barcode-Task/build /home/komi/CodeCademy/Barcode-Task/build /home/komi/CodeCademy/Barcode-Task/build/CMakeFiles/barcode_scanner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/barcode_scanner.dir/depend

