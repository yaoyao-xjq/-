# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/colin/0809colin/1-15restoration/4-7test/C_S/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/build

# Include any dependencies generated for this target.
include CMakeFiles/DisplayImage.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DisplayImage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DisplayImage.dir/flags.make

CMakeFiles/DisplayImage.dir/src/Client.cpp.o: CMakeFiles/DisplayImage.dir/flags.make
CMakeFiles/DisplayImage.dir/src/Client.cpp.o: ../src/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/0809colin/1-15restoration/4-7test/C_S/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DisplayImage.dir/src/Client.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisplayImage.dir/src/Client.cpp.o -c /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/Client.cpp

CMakeFiles/DisplayImage.dir/src/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisplayImage.dir/src/Client.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/Client.cpp > CMakeFiles/DisplayImage.dir/src/Client.cpp.i

CMakeFiles/DisplayImage.dir/src/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisplayImage.dir/src/Client.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/Client.cpp -o CMakeFiles/DisplayImage.dir/src/Client.cpp.s

CMakeFiles/DisplayImage.dir/src/Client.cpp.o.requires:

.PHONY : CMakeFiles/DisplayImage.dir/src/Client.cpp.o.requires

CMakeFiles/DisplayImage.dir/src/Client.cpp.o.provides: CMakeFiles/DisplayImage.dir/src/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/Client.cpp.o.provides.build
.PHONY : CMakeFiles/DisplayImage.dir/src/Client.cpp.o.provides

CMakeFiles/DisplayImage.dir/src/Client.cpp.o.provides.build: CMakeFiles/DisplayImage.dir/src/Client.cpp.o


CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o: CMakeFiles/DisplayImage.dir/flags.make
CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o: ../src/loadconf.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/0809colin/1-15restoration/4-7test/C_S/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o -c /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/loadconf.cpp

CMakeFiles/DisplayImage.dir/src/loadconf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisplayImage.dir/src/loadconf.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/loadconf.cpp > CMakeFiles/DisplayImage.dir/src/loadconf.cpp.i

CMakeFiles/DisplayImage.dir/src/loadconf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisplayImage.dir/src/loadconf.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/loadconf.cpp -o CMakeFiles/DisplayImage.dir/src/loadconf.cpp.s

CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o.requires:

.PHONY : CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o.requires

CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o.provides: CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o.requires
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o.provides.build
.PHONY : CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o.provides

CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o.provides.build: CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o


CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o: CMakeFiles/DisplayImage.dir/flags.make
CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o: ../src/mysocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/0809colin/1-15restoration/4-7test/C_S/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o -c /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/mysocket.cpp

CMakeFiles/DisplayImage.dir/src/mysocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisplayImage.dir/src/mysocket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/mysocket.cpp > CMakeFiles/DisplayImage.dir/src/mysocket.cpp.i

CMakeFiles/DisplayImage.dir/src/mysocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisplayImage.dir/src/mysocket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/mysocket.cpp -o CMakeFiles/DisplayImage.dir/src/mysocket.cpp.s

CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o.requires:

.PHONY : CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o.requires

CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o.provides: CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o.provides.build
.PHONY : CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o.provides

CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o.provides.build: CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o


CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o: CMakeFiles/DisplayImage.dir/flags.make
CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o: ../src/loadimg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/0809colin/1-15restoration/4-7test/C_S/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o -c /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/loadimg.cpp

CMakeFiles/DisplayImage.dir/src/loadimg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisplayImage.dir/src/loadimg.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/loadimg.cpp > CMakeFiles/DisplayImage.dir/src/loadimg.cpp.i

CMakeFiles/DisplayImage.dir/src/loadimg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisplayImage.dir/src/loadimg.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/loadimg.cpp -o CMakeFiles/DisplayImage.dir/src/loadimg.cpp.s

CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o.requires:

.PHONY : CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o.requires

CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o.provides: CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o.requires
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o.provides.build
.PHONY : CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o.provides

CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o.provides.build: CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o


CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o: CMakeFiles/DisplayImage.dir/flags.make
CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o: ../src/myPCA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/0809colin/1-15restoration/4-7test/C_S/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o -c /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/myPCA.cpp

CMakeFiles/DisplayImage.dir/src/myPCA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisplayImage.dir/src/myPCA.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/myPCA.cpp > CMakeFiles/DisplayImage.dir/src/myPCA.cpp.i

CMakeFiles/DisplayImage.dir/src/myPCA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisplayImage.dir/src/myPCA.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/src/myPCA.cpp -o CMakeFiles/DisplayImage.dir/src/myPCA.cpp.s

CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o.requires:

.PHONY : CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o.requires

CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o.provides: CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o.requires
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o.provides.build
.PHONY : CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o.provides

CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o.provides.build: CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o


# Object files for target DisplayImage
DisplayImage_OBJECTS = \
"CMakeFiles/DisplayImage.dir/src/Client.cpp.o" \
"CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o" \
"CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o" \
"CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o" \
"CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o"

# External object files for target DisplayImage
DisplayImage_EXTERNAL_OBJECTS =

DisplayImage: CMakeFiles/DisplayImage.dir/src/Client.cpp.o
DisplayImage: CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o
DisplayImage: CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o
DisplayImage: CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o
DisplayImage: CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o
DisplayImage: CMakeFiles/DisplayImage.dir/build.make
DisplayImage: /usr/local/lib/libopencv_videostab.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_ts.a
DisplayImage: /usr/local/lib/libopencv_superres.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_stitching.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_contrib.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_nonfree.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_ocl.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_gpu.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_photo.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_objdetect.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_legacy.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_video.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_ml.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_calib3d.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_features2d.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_highgui.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_imgproc.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_flann.so.2.4.9
DisplayImage: /usr/local/lib/libopencv_core.so.2.4.9
DisplayImage: CMakeFiles/DisplayImage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/colin/0809colin/1-15restoration/4-7test/C_S/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable DisplayImage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DisplayImage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DisplayImage.dir/build: DisplayImage

.PHONY : CMakeFiles/DisplayImage.dir/build

CMakeFiles/DisplayImage.dir/requires: CMakeFiles/DisplayImage.dir/src/Client.cpp.o.requires
CMakeFiles/DisplayImage.dir/requires: CMakeFiles/DisplayImage.dir/src/loadconf.cpp.o.requires
CMakeFiles/DisplayImage.dir/requires: CMakeFiles/DisplayImage.dir/src/mysocket.cpp.o.requires
CMakeFiles/DisplayImage.dir/requires: CMakeFiles/DisplayImage.dir/src/loadimg.cpp.o.requires
CMakeFiles/DisplayImage.dir/requires: CMakeFiles/DisplayImage.dir/src/myPCA.cpp.o.requires

.PHONY : CMakeFiles/DisplayImage.dir/requires

CMakeFiles/DisplayImage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DisplayImage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DisplayImage.dir/clean

CMakeFiles/DisplayImage.dir/depend:
	cd /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/colin/0809colin/1-15restoration/4-7test/C_S/Client /home/colin/0809colin/1-15restoration/4-7test/C_S/Client /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/build /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/build /home/colin/0809colin/1-15restoration/4-7test/C_S/Client/build/CMakeFiles/DisplayImage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DisplayImage.dir/depend
