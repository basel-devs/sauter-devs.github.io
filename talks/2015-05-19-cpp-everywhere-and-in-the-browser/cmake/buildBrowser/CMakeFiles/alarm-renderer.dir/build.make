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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake/buildBrowser

# Include any dependencies generated for this target.
include CMakeFiles/alarm-renderer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/alarm-renderer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alarm-renderer.dir/flags.make

CMakeFiles/alarm-renderer.dir/src/main.cpp.o: CMakeFiles/alarm-renderer.dir/flags.make
CMakeFiles/alarm-renderer.dir/src/main.cpp.o: CMakeFiles/alarm-renderer.dir/includes_CXX.rsp
CMakeFiles/alarm-renderer.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake/buildBrowser/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/alarm-renderer.dir/src/main.cpp.o"
	/opt/softwares/emsdk_portable/emscripten/master/em++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/alarm-renderer.dir/src/main.cpp.o -c /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake/src/main.cpp

CMakeFiles/alarm-renderer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alarm-renderer.dir/src/main.cpp.i"
	/opt/softwares/emsdk_portable/emscripten/master/em++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake/src/main.cpp > CMakeFiles/alarm-renderer.dir/src/main.cpp.i

CMakeFiles/alarm-renderer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alarm-renderer.dir/src/main.cpp.s"
	/opt/softwares/emsdk_portable/emscripten/master/em++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake/src/main.cpp -o CMakeFiles/alarm-renderer.dir/src/main.cpp.s

CMakeFiles/alarm-renderer.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/alarm-renderer.dir/src/main.cpp.o.requires

CMakeFiles/alarm-renderer.dir/src/main.cpp.o.provides: CMakeFiles/alarm-renderer.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/alarm-renderer.dir/build.make CMakeFiles/alarm-renderer.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/alarm-renderer.dir/src/main.cpp.o.provides

CMakeFiles/alarm-renderer.dir/src/main.cpp.o.provides.build: CMakeFiles/alarm-renderer.dir/src/main.cpp.o

# Object files for target alarm-renderer
alarm__renderer_OBJECTS = \
"CMakeFiles/alarm-renderer.dir/src/main.cpp.o"

# External object files for target alarm-renderer
alarm__renderer_EXTERNAL_OBJECTS =

libalarm-renderer.js: CMakeFiles/alarm-renderer.dir/src/main.cpp.o
libalarm-renderer.js: CMakeFiles/alarm-renderer.dir/build.make
libalarm-renderer.js: CMakeFiles/alarm-renderer.dir/objects1.rsp
libalarm-renderer.js: CMakeFiles/alarm-renderer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libalarm-renderer.js"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alarm-renderer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alarm-renderer.dir/build: libalarm-renderer.js
.PHONY : CMakeFiles/alarm-renderer.dir/build

CMakeFiles/alarm-renderer.dir/requires: CMakeFiles/alarm-renderer.dir/src/main.cpp.o.requires
.PHONY : CMakeFiles/alarm-renderer.dir/requires

CMakeFiles/alarm-renderer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/alarm-renderer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/alarm-renderer.dir/clean

CMakeFiles/alarm-renderer.dir/depend:
	cd /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake/buildBrowser && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake/buildBrowser /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake/buildBrowser /home/daminetreg/workspace/experiments/emscripten/presentation_may2015/cmake/buildBrowser/CMakeFiles/alarm-renderer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/alarm-renderer.dir/depend

