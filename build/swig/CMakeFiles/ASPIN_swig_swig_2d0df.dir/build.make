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
CMAKE_SOURCE_DIR = /home/joe/gr-ASPIN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joe/gr-ASPIN/build

# Include any dependencies generated for this target.
include swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/depend.make

# Include the progress variables for this target.
include swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/progress.make

# Include the compile flags for this target's objects.
include swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/flags.make

swig/ASPIN_swig_swig_2d0df.cpp: ../swig/ASPIN_swig.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/tagged_stream_block.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/gnuradio.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/realtime.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/block.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/block_detail.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/constants.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/sync_block.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/gr_shared_ptr.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/block_gateway.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/sync_interpolator.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/gr_types.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/basic_block.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/gr_ctrlport.i
swig/ASPIN_swig_swig_2d0df.cpp: swig/ASPIN_swig_doc.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/io_signature.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/top_block.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/gr_extras.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/message.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/tags.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/msg_handler.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/runtime_swig.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/msg_queue.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/buffer.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/gr_swig_block_magic.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/hier_block2.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/runtime_swig_doc.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/feval.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/sync_decimator.i
swig/ASPIN_swig_swig_2d0df.cpp: ../swig/ASPIN_swig.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/gr_logger.i
swig/ASPIN_swig_swig_2d0df.cpp: /usr/local/include/gnuradio/swig/prefs.i
swig/ASPIN_swig_swig_2d0df.cpp: swig/ASPIN_swig.tag
	cd /home/joe/gr-ASPIN/build/swig && /usr/bin/cmake -E copy /home/joe/gr-ASPIN/build/swig/ASPIN_swig_swig_2d0df.cpp.in /home/joe/gr-ASPIN/build/swig/ASPIN_swig_swig_2d0df.cpp

swig/ASPIN_swig_doc.i: swig/ASPIN_swig_doc_swig_docs/xml/index.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /home/joe/gr-ASPIN/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating python docstrings for ASPIN_swig_doc"
	cd /home/joe/gr-ASPIN/docs/doxygen && /usr/bin/python2 -B /home/joe/gr-ASPIN/docs/doxygen/swig_doc.py /home/joe/gr-ASPIN/build/swig/ASPIN_swig_doc_swig_docs/xml /home/joe/gr-ASPIN/build/swig/ASPIN_swig_doc.i

swig/ASPIN_swig.tag: swig/_ASPIN_swig_swig_tag
	$(CMAKE_COMMAND) -E cmake_progress_report /home/joe/gr-ASPIN/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ASPIN_swig.tag"
	cd /home/joe/gr-ASPIN/build/swig && ./_ASPIN_swig_swig_tag
	cd /home/joe/gr-ASPIN/build/swig && /usr/bin/cmake -E touch /home/joe/gr-ASPIN/build/swig/ASPIN_swig.tag

swig/ASPIN_swig_doc_swig_docs/xml/index.xml: swig/_ASPIN_swig_doc_tag
	$(CMAKE_COMMAND) -E cmake_progress_report /home/joe/gr-ASPIN/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating doxygen xml for ASPIN_swig_doc docs"
	cd /home/joe/gr-ASPIN/build/swig && ./_ASPIN_swig_doc_tag
	cd /home/joe/gr-ASPIN/build/swig && /usr/bin/doxygen /home/joe/gr-ASPIN/build/swig/ASPIN_swig_doc_swig_docs/Doxyfile

swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o: swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/flags.make
swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o: swig/ASPIN_swig_swig_2d0df.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/joe/gr-ASPIN/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o"
	cd /home/joe/gr-ASPIN/build/swig && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o -c /home/joe/gr-ASPIN/build/swig/ASPIN_swig_swig_2d0df.cpp

swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.i"
	cd /home/joe/gr-ASPIN/build/swig && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/joe/gr-ASPIN/build/swig/ASPIN_swig_swig_2d0df.cpp > CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.i

swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.s"
	cd /home/joe/gr-ASPIN/build/swig && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/joe/gr-ASPIN/build/swig/ASPIN_swig_swig_2d0df.cpp -o CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.s

swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o.requires:
.PHONY : swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o.requires

swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o.provides: swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o.requires
	$(MAKE) -f swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/build.make swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o.provides.build
.PHONY : swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o.provides

swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o.provides.build: swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o

# Object files for target ASPIN_swig_swig_2d0df
ASPIN_swig_swig_2d0df_OBJECTS = \
"CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o"

# External object files for target ASPIN_swig_swig_2d0df
ASPIN_swig_swig_2d0df_EXTERNAL_OBJECTS =

swig/ASPIN_swig_swig_2d0df: swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o
swig/ASPIN_swig_swig_2d0df: swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/build.make
swig/ASPIN_swig_swig_2d0df: swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ASPIN_swig_swig_2d0df"
	cd /home/joe/gr-ASPIN/build/swig && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ASPIN_swig_swig_2d0df.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Swig source"
	cd /home/joe/gr-ASPIN/build/swig && /usr/bin/cmake -E make_directory /home/joe/gr-ASPIN/build/swig
	cd /home/joe/gr-ASPIN/build/swig && /usr/bin/swig2.0 -python -fvirtual -modern -keyword -w511 -module ASPIN_swig -I/home/joe/gr-ASPIN/build/swig -I/home/joe/gr-ASPIN/swig -I/usr/local/include/gnuradio/swig -I/usr/include/python2.7 -I/usr/include/python2.7 -I/usr/include/x86_64-linux-gnu/python2.7 -outdir /home/joe/gr-ASPIN/build/swig -c++ -I/home/joe/gr-ASPIN/lib -I/home/joe/gr-ASPIN/include -I/home/joe/gr-ASPIN/build/lib -I/home/joe/gr-ASPIN/build/include -I/usr/include -I/usr/include -I/usr/local/include -I/home/joe/gr-ASPIN/build/swig -I/home/joe/gr-ASPIN/swig -I/usr/local/include/gnuradio/swig -I/usr/include/python2.7 -I/usr/include/python2.7 -I/usr/include/x86_64-linux-gnu/python2.7 -o /home/joe/gr-ASPIN/build/swig/ASPIN_swigPYTHON_wrap.cxx /home/joe/gr-ASPIN/swig/ASPIN_swig.i

# Rule to build all files generated by this target.
swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/build: swig/ASPIN_swig_swig_2d0df
.PHONY : swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/build

swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/requires: swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/ASPIN_swig_swig_2d0df.cpp.o.requires
.PHONY : swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/requires

swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/clean:
	cd /home/joe/gr-ASPIN/build/swig && $(CMAKE_COMMAND) -P CMakeFiles/ASPIN_swig_swig_2d0df.dir/cmake_clean.cmake
.PHONY : swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/clean

swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/depend: swig/ASPIN_swig_swig_2d0df.cpp
swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/depend: swig/ASPIN_swig_doc.i
swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/depend: swig/ASPIN_swig.tag
swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/depend: swig/ASPIN_swig_doc_swig_docs/xml/index.xml
	cd /home/joe/gr-ASPIN/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joe/gr-ASPIN /home/joe/gr-ASPIN/swig /home/joe/gr-ASPIN/build /home/joe/gr-ASPIN/build/swig /home/joe/gr-ASPIN/build/swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : swig/CMakeFiles/ASPIN_swig_swig_2d0df.dir/depend

