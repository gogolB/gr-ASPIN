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

# Utility rule file for ASPIN_swig_swig_doc.

# Include the progress variables for this target.
include swig/CMakeFiles/ASPIN_swig_swig_doc.dir/progress.make

swig/CMakeFiles/ASPIN_swig_swig_doc: swig/ASPIN_swig_doc.i

ASPIN_swig_swig_doc: swig/CMakeFiles/ASPIN_swig_swig_doc
ASPIN_swig_swig_doc: swig/CMakeFiles/ASPIN_swig_swig_doc.dir/build.make
.PHONY : ASPIN_swig_swig_doc

# Rule to build all files generated by this target.
swig/CMakeFiles/ASPIN_swig_swig_doc.dir/build: ASPIN_swig_swig_doc
.PHONY : swig/CMakeFiles/ASPIN_swig_swig_doc.dir/build

swig/CMakeFiles/ASPIN_swig_swig_doc.dir/clean:
	cd /home/root/gr-ASPIN/ebuild/swig && $(CMAKE_COMMAND) -P CMakeFiles/ASPIN_swig_swig_doc.dir/cmake_clean.cmake
.PHONY : swig/CMakeFiles/ASPIN_swig_swig_doc.dir/clean

swig/CMakeFiles/ASPIN_swig_swig_doc.dir/depend:
	cd /home/root/gr-ASPIN/ebuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/root/gr-ASPIN /home/root/gr-ASPIN/swig /home/root/gr-ASPIN/ebuild /home/root/gr-ASPIN/ebuild/swig /home/root/gr-ASPIN/ebuild/swig/CMakeFiles/ASPIN_swig_swig_doc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : swig/CMakeFiles/ASPIN_swig_swig_doc.dir/depend

