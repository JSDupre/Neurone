# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/INTRANET/dupre/myfiles/infoBA3/S2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/INTRANET/dupre/myfiles/infoBA3/S2

# Include any dependencies generated for this target.
include CMakeFiles/Neurone.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Neurone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Neurone.dir/flags.make

CMakeFiles/Neurone.dir/Neurone.cpp.o: CMakeFiles/Neurone.dir/flags.make
CMakeFiles/Neurone.dir/Neurone.cpp.o: Neurone.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/dupre/myfiles/infoBA3/S2/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Neurone.dir/Neurone.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Neurone.dir/Neurone.cpp.o -c /home/INTRANET/dupre/myfiles/infoBA3/S2/Neurone.cpp

CMakeFiles/Neurone.dir/Neurone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neurone.dir/Neurone.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/dupre/myfiles/infoBA3/S2/Neurone.cpp > CMakeFiles/Neurone.dir/Neurone.cpp.i

CMakeFiles/Neurone.dir/Neurone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neurone.dir/Neurone.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/dupre/myfiles/infoBA3/S2/Neurone.cpp -o CMakeFiles/Neurone.dir/Neurone.cpp.s

CMakeFiles/Neurone.dir/Neurone.cpp.o.requires:
.PHONY : CMakeFiles/Neurone.dir/Neurone.cpp.o.requires

CMakeFiles/Neurone.dir/Neurone.cpp.o.provides: CMakeFiles/Neurone.dir/Neurone.cpp.o.requires
	$(MAKE) -f CMakeFiles/Neurone.dir/build.make CMakeFiles/Neurone.dir/Neurone.cpp.o.provides.build
.PHONY : CMakeFiles/Neurone.dir/Neurone.cpp.o.provides

CMakeFiles/Neurone.dir/Neurone.cpp.o.provides.build: CMakeFiles/Neurone.dir/Neurone.cpp.o

CMakeFiles/Neurone.dir/main.cpp.o: CMakeFiles/Neurone.dir/flags.make
CMakeFiles/Neurone.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/dupre/myfiles/infoBA3/S2/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Neurone.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Neurone.dir/main.cpp.o -c /home/INTRANET/dupre/myfiles/infoBA3/S2/main.cpp

CMakeFiles/Neurone.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neurone.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/dupre/myfiles/infoBA3/S2/main.cpp > CMakeFiles/Neurone.dir/main.cpp.i

CMakeFiles/Neurone.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neurone.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/dupre/myfiles/infoBA3/S2/main.cpp -o CMakeFiles/Neurone.dir/main.cpp.s

CMakeFiles/Neurone.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/Neurone.dir/main.cpp.o.requires

CMakeFiles/Neurone.dir/main.cpp.o.provides: CMakeFiles/Neurone.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Neurone.dir/build.make CMakeFiles/Neurone.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Neurone.dir/main.cpp.o.provides

CMakeFiles/Neurone.dir/main.cpp.o.provides.build: CMakeFiles/Neurone.dir/main.cpp.o

# Object files for target Neurone
Neurone_OBJECTS = \
"CMakeFiles/Neurone.dir/Neurone.cpp.o" \
"CMakeFiles/Neurone.dir/main.cpp.o"

# External object files for target Neurone
Neurone_EXTERNAL_OBJECTS =

Neurone: CMakeFiles/Neurone.dir/Neurone.cpp.o
Neurone: CMakeFiles/Neurone.dir/main.cpp.o
Neurone: CMakeFiles/Neurone.dir/build.make
Neurone: CMakeFiles/Neurone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Neurone"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Neurone.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Neurone.dir/build: Neurone
.PHONY : CMakeFiles/Neurone.dir/build

CMakeFiles/Neurone.dir/requires: CMakeFiles/Neurone.dir/Neurone.cpp.o.requires
CMakeFiles/Neurone.dir/requires: CMakeFiles/Neurone.dir/main.cpp.o.requires
.PHONY : CMakeFiles/Neurone.dir/requires

CMakeFiles/Neurone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Neurone.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Neurone.dir/clean

CMakeFiles/Neurone.dir/depend:
	cd /home/INTRANET/dupre/myfiles/infoBA3/S2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/INTRANET/dupre/myfiles/infoBA3/S2 /home/INTRANET/dupre/myfiles/infoBA3/S2 /home/INTRANET/dupre/myfiles/infoBA3/S2 /home/INTRANET/dupre/myfiles/infoBA3/S2 /home/INTRANET/dupre/myfiles/infoBA3/S2/CMakeFiles/Neurone.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Neurone.dir/depend

