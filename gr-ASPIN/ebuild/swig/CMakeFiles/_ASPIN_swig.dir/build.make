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
CMAKE_SOURCE_DIR = /home/root/gr-ASPIN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/root/gr-ASPIN/ebuild

# Include any dependencies generated for this target.
include swig/CMakeFiles/_ASPIN_swig.dir/depend.make

# Include the progress variables for this target.
include swig/CMakeFiles/_ASPIN_swig.dir/progress.make

# Include the compile flags for this target's objects.
include swig/CMakeFiles/_ASPIN_swig.dir/flags.make

swig/ASPIN_swigPYTHON_wrap.cxx: swig/ASPIN_swig_swig_2d0df

swig/ASPIN_swig.py: swig/ASPIN_swig_swig_2d0df

swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o: swig/CMakeFiles/_ASPIN_swig.dir/flags.make
swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o: swig/ASPIN_swigPYTHON_wrap.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/root/gr-ASPIN/ebuild/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o"
	cd /home/root/gr-ASPIN/ebuild/swig && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -Wno-unused-but-set-variable -o CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o -c /home/root/gr-ASPIN/ebuild/swig/ASPIN_swigPYTHON_wrap.cxx

swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.i"
	cd /home/root/gr-ASPIN/ebuild/swig && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -Wno-unused-but-set-variable -E /home/root/gr-ASPIN/ebuild/swig/ASPIN_swigPYTHON_wrap.cxx > CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.i

swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.s"
	cd /home/root/gr-ASPIN/ebuild/swig && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -Wno-unused-but-set-variable -S /home/root/gr-ASPIN/ebuild/swig/ASPIN_swigPYTHON_wrap.cxx -o CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.s

swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o.requires:
.PHONY : swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o.requires

swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o.provides: swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o.requires
	$(MAKE) -f swig/CMakeFiles/_ASPIN_swig.dir/build.make swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o.provides.build
.PHONY : swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o.provides

swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o.provides.build: swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o

# Object files for target _ASPIN_swig
_ASPIN_swig_OBJECTS = \
"CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o"

# External object files for target _ASPIN_swig
_ASPIN_swig_EXTERNAL_OBJECTS =

swig/_ASPIN_swig.so: swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o
swig/_ASPIN_swig.so: swig/CMakeFiles/_ASPIN_swig.dir/build.make
swig/_ASPIN_swig.so: /usr/lib/libpython2.7.so
swig/_ASPIN_swig.so: lib/libgnuradio-ASPIN-1.0.0git.so.0.0.0
swig/_ASPIN_swig.so: /usr/lib/libboost_filesystem-mt.so
swig/_ASPIN_swig.so: /usr/lib/libboost_system-mt.so
swig/_ASPIN_swig.so: /usr/lib/libgnuradio-runtime.so
swig/_ASPIN_swig.so: /usr/lib/libgnuradio-pmt.so
swig/_ASPIN_swig.so: swig/CMakeFiles/_ASPIN_swig.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module _ASPIN_swig.so"
	cd /home/root/gr-ASPIN/ebuild/swig && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_ASPIN_swig.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
swig/CMakeFiles/_ASPIN_swig.dir/build: swig/_ASPIN_swig.so
.PHONY : swig/CMakeFiles/_ASPIN_swig.dir/build

swig/CMakeFiles/_ASPIN_swig.dir/requires: swig/CMakeFiles/_ASPIN_swig.dir/ASPIN_swigPYTHON_wrap.cxx.o.requires
.PHONY : swig/CMakeFiles/_ASPIN_swig.dir/requires

swig/CMakeFiles/_ASPIN_swig.dir/clean:
	cd /home/root/gr-ASPIN/ebuild/swig && $(CMAKE_COMMAND) -P CMakeFiles/_ASPIN_swig.dir/cmake_clean.cmake
.PHONY : swig/CMakeFiles/_ASPIN_swig.dir/clean

swig/CMakeFiles/_ASPIN_swig.dir/depend: swig/ASPIN_swigPYTHON_wrap.cxx
swig/CMakeFiles/_ASPIN_swig.dir/depend: swig/ASPIN_swig.py
	cd /home/root/gr-ASPIN/ebuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/root/gr-ASPIN /home/root/gr-ASPIN/swig /home/root/gr-ASPIN/ebuild /home/root/gr-ASPIN/ebuild/swig /home/root/gr-ASPIN/ebuild/swig/CMakeFiles/_ASPIN_swig.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : swig/CMakeFiles/_ASPIN_swig.dir/depend
