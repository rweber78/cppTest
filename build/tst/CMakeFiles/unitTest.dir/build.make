# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rweber/source/cppTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rweber/source/cppTest/build

# Include any dependencies generated for this target.
include tst/CMakeFiles/unitTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tst/CMakeFiles/unitTest.dir/compiler_depend.make

# Include the progress variables for this target.
include tst/CMakeFiles/unitTest.dir/progress.make

# Include the compile flags for this target's objects.
include tst/CMakeFiles/unitTest.dir/flags.make

tst/CMakeFiles/unitTest.dir/__/src/Chrono.cpp.o: tst/CMakeFiles/unitTest.dir/flags.make
tst/CMakeFiles/unitTest.dir/__/src/Chrono.cpp.o: /Users/rweber/source/cppTest/src/Chrono.cpp
tst/CMakeFiles/unitTest.dir/__/src/Chrono.cpp.o: tst/CMakeFiles/unitTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rweber/source/cppTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tst/CMakeFiles/unitTest.dir/__/src/Chrono.cpp.o"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/unitTest.dir/__/src/Chrono.cpp.o -MF CMakeFiles/unitTest.dir/__/src/Chrono.cpp.o.d -o CMakeFiles/unitTest.dir/__/src/Chrono.cpp.o -c /Users/rweber/source/cppTest/src/Chrono.cpp

tst/CMakeFiles/unitTest.dir/__/src/Chrono.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unitTest.dir/__/src/Chrono.cpp.i"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rweber/source/cppTest/src/Chrono.cpp > CMakeFiles/unitTest.dir/__/src/Chrono.cpp.i

tst/CMakeFiles/unitTest.dir/__/src/Chrono.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unitTest.dir/__/src/Chrono.cpp.s"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rweber/source/cppTest/src/Chrono.cpp -o CMakeFiles/unitTest.dir/__/src/Chrono.cpp.s

tst/CMakeFiles/unitTest.dir/__/src/Logger.cpp.o: tst/CMakeFiles/unitTest.dir/flags.make
tst/CMakeFiles/unitTest.dir/__/src/Logger.cpp.o: /Users/rweber/source/cppTest/src/Logger.cpp
tst/CMakeFiles/unitTest.dir/__/src/Logger.cpp.o: tst/CMakeFiles/unitTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rweber/source/cppTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tst/CMakeFiles/unitTest.dir/__/src/Logger.cpp.o"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/unitTest.dir/__/src/Logger.cpp.o -MF CMakeFiles/unitTest.dir/__/src/Logger.cpp.o.d -o CMakeFiles/unitTest.dir/__/src/Logger.cpp.o -c /Users/rweber/source/cppTest/src/Logger.cpp

tst/CMakeFiles/unitTest.dir/__/src/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unitTest.dir/__/src/Logger.cpp.i"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rweber/source/cppTest/src/Logger.cpp > CMakeFiles/unitTest.dir/__/src/Logger.cpp.i

tst/CMakeFiles/unitTest.dir/__/src/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unitTest.dir/__/src/Logger.cpp.s"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rweber/source/cppTest/src/Logger.cpp -o CMakeFiles/unitTest.dir/__/src/Logger.cpp.s

tst/CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.o: tst/CMakeFiles/unitTest.dir/flags.make
tst/CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.o: /Users/rweber/source/cppTest/src/StringUtil.cpp
tst/CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.o: tst/CMakeFiles/unitTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rweber/source/cppTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tst/CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.o"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.o -MF CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.o.d -o CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.o -c /Users/rweber/source/cppTest/src/StringUtil.cpp

tst/CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.i"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rweber/source/cppTest/src/StringUtil.cpp > CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.i

tst/CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.s"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rweber/source/cppTest/src/StringUtil.cpp -o CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.s

tst/CMakeFiles/unitTest.dir/TestTrite.cpp.o: tst/CMakeFiles/unitTest.dir/flags.make
tst/CMakeFiles/unitTest.dir/TestTrite.cpp.o: /Users/rweber/source/cppTest/tst/TestTrite.cpp
tst/CMakeFiles/unitTest.dir/TestTrite.cpp.o: tst/CMakeFiles/unitTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rweber/source/cppTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tst/CMakeFiles/unitTest.dir/TestTrite.cpp.o"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/unitTest.dir/TestTrite.cpp.o -MF CMakeFiles/unitTest.dir/TestTrite.cpp.o.d -o CMakeFiles/unitTest.dir/TestTrite.cpp.o -c /Users/rweber/source/cppTest/tst/TestTrite.cpp

tst/CMakeFiles/unitTest.dir/TestTrite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unitTest.dir/TestTrite.cpp.i"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rweber/source/cppTest/tst/TestTrite.cpp > CMakeFiles/unitTest.dir/TestTrite.cpp.i

tst/CMakeFiles/unitTest.dir/TestTrite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unitTest.dir/TestTrite.cpp.s"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rweber/source/cppTest/tst/TestTrite.cpp -o CMakeFiles/unitTest.dir/TestTrite.cpp.s

tst/CMakeFiles/unitTest.dir/TestTypeErasure.cpp.o: tst/CMakeFiles/unitTest.dir/flags.make
tst/CMakeFiles/unitTest.dir/TestTypeErasure.cpp.o: /Users/rweber/source/cppTest/tst/TestTypeErasure.cpp
tst/CMakeFiles/unitTest.dir/TestTypeErasure.cpp.o: tst/CMakeFiles/unitTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rweber/source/cppTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object tst/CMakeFiles/unitTest.dir/TestTypeErasure.cpp.o"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/unitTest.dir/TestTypeErasure.cpp.o -MF CMakeFiles/unitTest.dir/TestTypeErasure.cpp.o.d -o CMakeFiles/unitTest.dir/TestTypeErasure.cpp.o -c /Users/rweber/source/cppTest/tst/TestTypeErasure.cpp

tst/CMakeFiles/unitTest.dir/TestTypeErasure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unitTest.dir/TestTypeErasure.cpp.i"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rweber/source/cppTest/tst/TestTypeErasure.cpp > CMakeFiles/unitTest.dir/TestTypeErasure.cpp.i

tst/CMakeFiles/unitTest.dir/TestTypeErasure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unitTest.dir/TestTypeErasure.cpp.s"
	cd /Users/rweber/source/cppTest/build/tst && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rweber/source/cppTest/tst/TestTypeErasure.cpp -o CMakeFiles/unitTest.dir/TestTypeErasure.cpp.s

# Object files for target unitTest
unitTest_OBJECTS = \
"CMakeFiles/unitTest.dir/__/src/Chrono.cpp.o" \
"CMakeFiles/unitTest.dir/__/src/Logger.cpp.o" \
"CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.o" \
"CMakeFiles/unitTest.dir/TestTrite.cpp.o" \
"CMakeFiles/unitTest.dir/TestTypeErasure.cpp.o"

# External object files for target unitTest
unitTest_EXTERNAL_OBJECTS =

tst/unitTest: tst/CMakeFiles/unitTest.dir/__/src/Chrono.cpp.o
tst/unitTest: tst/CMakeFiles/unitTest.dir/__/src/Logger.cpp.o
tst/unitTest: tst/CMakeFiles/unitTest.dir/__/src/StringUtil.cpp.o
tst/unitTest: tst/CMakeFiles/unitTest.dir/TestTrite.cpp.o
tst/unitTest: tst/CMakeFiles/unitTest.dir/TestTypeErasure.cpp.o
tst/unitTest: tst/CMakeFiles/unitTest.dir/build.make
tst/unitTest: lib/libgtest_main.a
tst/unitTest: lib/libgtest.a
tst/unitTest: tst/CMakeFiles/unitTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rweber/source/cppTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable unitTest"
	cd /Users/rweber/source/cppTest/build/tst && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unitTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tst/CMakeFiles/unitTest.dir/build: tst/unitTest
.PHONY : tst/CMakeFiles/unitTest.dir/build

tst/CMakeFiles/unitTest.dir/clean:
	cd /Users/rweber/source/cppTest/build/tst && $(CMAKE_COMMAND) -P CMakeFiles/unitTest.dir/cmake_clean.cmake
.PHONY : tst/CMakeFiles/unitTest.dir/clean

tst/CMakeFiles/unitTest.dir/depend:
	cd /Users/rweber/source/cppTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rweber/source/cppTest /Users/rweber/source/cppTest/tst /Users/rweber/source/cppTest/build /Users/rweber/source/cppTest/build/tst /Users/rweber/source/cppTest/build/tst/CMakeFiles/unitTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tst/CMakeFiles/unitTest.dir/depend

