# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dgerard/projects/yuni/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dgerard/projects/yuni/src

# Include any dependencies generated for this target.
include yuni/CMakeFiles/yuni-static-parser.dir/depend.make

# Include the progress variables for this target.
include yuni/CMakeFiles/yuni-static-parser.dir/progress.make

# Include the compile flags for this target's objects.
include yuni/CMakeFiles/yuni-static-parser.dir/flags.make

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o: yuni/CMakeFiles/yuni-static-parser.dir/flags.make
yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o: yuni/parser/peg/grammar.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dgerard/projects/yuni/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o -c /home/dgerard/projects/yuni/src/yuni/parser/peg/grammar.cpp

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.i"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dgerard/projects/yuni/src/yuni/parser/peg/grammar.cpp > CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.i

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.s"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dgerard/projects/yuni/src/yuni/parser/peg/grammar.cpp -o CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.s

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o.requires:
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o.requires

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o.provides: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o.requires
	$(MAKE) -f yuni/CMakeFiles/yuni-static-parser.dir/build.make yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o.provides.build
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o.provides

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o.provides.build: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o: yuni/CMakeFiles/yuni-static-parser.dir/flags.make
yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o: yuni/parser/peg/node.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dgerard/projects/yuni/src/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o -c /home/dgerard/projects/yuni/src/yuni/parser/peg/node.cpp

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.i"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dgerard/projects/yuni/src/yuni/parser/peg/node.cpp > CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.i

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.s"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dgerard/projects/yuni/src/yuni/parser/peg/node.cpp -o CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.s

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o.requires:
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o.requires

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o.provides: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o.requires
	$(MAKE) -f yuni/CMakeFiles/yuni-static-parser.dir/build.make yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o.provides.build
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o.provides

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o.provides.build: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o: yuni/CMakeFiles/yuni-static-parser.dir/flags.make
yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o: yuni/parser/peg/export-cpp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dgerard/projects/yuni/src/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o -c /home/dgerard/projects/yuni/src/yuni/parser/peg/export-cpp.cpp

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.i"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dgerard/projects/yuni/src/yuni/parser/peg/export-cpp.cpp > CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.i

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.s"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dgerard/projects/yuni/src/yuni/parser/peg/export-cpp.cpp -o CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.s

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o.requires:
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o.requires

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o.provides: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o.requires
	$(MAKE) -f yuni/CMakeFiles/yuni-static-parser.dir/build.make yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o.provides.build
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o.provides

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o.provides.build: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o: yuni/CMakeFiles/yuni-static-parser.dir/flags.make
yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o: yuni/parser/peg/export-dot.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dgerard/projects/yuni/src/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o -c /home/dgerard/projects/yuni/src/yuni/parser/peg/export-dot.cpp

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.i"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dgerard/projects/yuni/src/yuni/parser/peg/export-dot.cpp > CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.i

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.s"
	cd /home/dgerard/projects/yuni/src/yuni && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dgerard/projects/yuni/src/yuni/parser/peg/export-dot.cpp -o CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.s

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o.requires:
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o.requires

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o.provides: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o.requires
	$(MAKE) -f yuni/CMakeFiles/yuni-static-parser.dir/build.make yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o.provides.build
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o.provides

yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o.provides.build: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o

# Object files for target yuni-static-parser
yuni__static__parser_OBJECTS = \
"CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o" \
"CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o" \
"CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o" \
"CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o"

# External object files for target yuni-static-parser
yuni__static__parser_EXTERNAL_OBJECTS =

build/debug/lib/libyuni-static-parser.a: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o
build/debug/lib/libyuni-static-parser.a: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o
build/debug/lib/libyuni-static-parser.a: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o
build/debug/lib/libyuni-static-parser.a: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o
build/debug/lib/libyuni-static-parser.a: yuni/CMakeFiles/yuni-static-parser.dir/build.make
build/debug/lib/libyuni-static-parser.a: yuni/CMakeFiles/yuni-static-parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../build/debug/lib/libyuni-static-parser.a"
	cd /home/dgerard/projects/yuni/src/yuni && $(CMAKE_COMMAND) -P CMakeFiles/yuni-static-parser.dir/cmake_clean_target.cmake
	cd /home/dgerard/projects/yuni/src/yuni && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yuni-static-parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
yuni/CMakeFiles/yuni-static-parser.dir/build: build/debug/lib/libyuni-static-parser.a
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/build

yuni/CMakeFiles/yuni-static-parser.dir/requires: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/grammar.cpp.o.requires
yuni/CMakeFiles/yuni-static-parser.dir/requires: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/node.cpp.o.requires
yuni/CMakeFiles/yuni-static-parser.dir/requires: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-cpp.cpp.o.requires
yuni/CMakeFiles/yuni-static-parser.dir/requires: yuni/CMakeFiles/yuni-static-parser.dir/parser/peg/export-dot.cpp.o.requires
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/requires

yuni/CMakeFiles/yuni-static-parser.dir/clean:
	cd /home/dgerard/projects/yuni/src/yuni && $(CMAKE_COMMAND) -P CMakeFiles/yuni-static-parser.dir/cmake_clean.cmake
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/clean

yuni/CMakeFiles/yuni-static-parser.dir/depend:
	cd /home/dgerard/projects/yuni/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dgerard/projects/yuni/src /home/dgerard/projects/yuni/src/yuni /home/dgerard/projects/yuni/src /home/dgerard/projects/yuni/src/yuni /home/dgerard/projects/yuni/src/yuni/CMakeFiles/yuni-static-parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : yuni/CMakeFiles/yuni-static-parser.dir/depend

