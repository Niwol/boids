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
CMAKE_SOURCE_DIR = /home/lowin/Documents/projects/BE/boids

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lowin/Documents/projects/BE/boids/build

# Include any dependencies generated for this target.
include src/CMakeFiles/boids.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/boids.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/boids.dir/flags.make

src/CMakeFiles/boids.dir/boidSystem.cpp.o: src/CMakeFiles/boids.dir/flags.make
src/CMakeFiles/boids.dir/boidSystem.cpp.o: ../src/boidSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lowin/Documents/projects/BE/boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/boids.dir/boidSystem.cpp.o"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/boidSystem.cpp.o -c /home/lowin/Documents/projects/BE/boids/src/boidSystem.cpp

src/CMakeFiles/boids.dir/boidSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/boidSystem.cpp.i"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lowin/Documents/projects/BE/boids/src/boidSystem.cpp > CMakeFiles/boids.dir/boidSystem.cpp.i

src/CMakeFiles/boids.dir/boidSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/boidSystem.cpp.s"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lowin/Documents/projects/BE/boids/src/boidSystem.cpp -o CMakeFiles/boids.dir/boidSystem.cpp.s

src/CMakeFiles/boids.dir/keyFrameComponent.cpp.o: src/CMakeFiles/boids.dir/flags.make
src/CMakeFiles/boids.dir/keyFrameComponent.cpp.o: ../src/keyFrameComponent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lowin/Documents/projects/BE/boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/boids.dir/keyFrameComponent.cpp.o"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/keyFrameComponent.cpp.o -c /home/lowin/Documents/projects/BE/boids/src/keyFrameComponent.cpp

src/CMakeFiles/boids.dir/keyFrameComponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/keyFrameComponent.cpp.i"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lowin/Documents/projects/BE/boids/src/keyFrameComponent.cpp > CMakeFiles/boids.dir/keyFrameComponent.cpp.i

src/CMakeFiles/boids.dir/keyFrameComponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/keyFrameComponent.cpp.s"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lowin/Documents/projects/BE/boids/src/keyFrameComponent.cpp -o CMakeFiles/boids.dir/keyFrameComponent.cpp.s

src/CMakeFiles/boids.dir/main.cpp.o: src/CMakeFiles/boids.dir/flags.make
src/CMakeFiles/boids.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lowin/Documents/projects/BE/boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/boids.dir/main.cpp.o"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/main.cpp.o -c /home/lowin/Documents/projects/BE/boids/src/main.cpp

src/CMakeFiles/boids.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/main.cpp.i"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lowin/Documents/projects/BE/boids/src/main.cpp > CMakeFiles/boids.dir/main.cpp.i

src/CMakeFiles/boids.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/main.cpp.s"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lowin/Documents/projects/BE/boids/src/main.cpp -o CMakeFiles/boids.dir/main.cpp.s

src/CMakeFiles/boids.dir/mainApplication.cpp.o: src/CMakeFiles/boids.dir/flags.make
src/CMakeFiles/boids.dir/mainApplication.cpp.o: ../src/mainApplication.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lowin/Documents/projects/BE/boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/boids.dir/mainApplication.cpp.o"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/mainApplication.cpp.o -c /home/lowin/Documents/projects/BE/boids/src/mainApplication.cpp

src/CMakeFiles/boids.dir/mainApplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/mainApplication.cpp.i"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lowin/Documents/projects/BE/boids/src/mainApplication.cpp > CMakeFiles/boids.dir/mainApplication.cpp.i

src/CMakeFiles/boids.dir/mainApplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/mainApplication.cpp.s"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lowin/Documents/projects/BE/boids/src/mainApplication.cpp -o CMakeFiles/boids.dir/mainApplication.cpp.s

src/CMakeFiles/boids.dir/mainWindow.cpp.o: src/CMakeFiles/boids.dir/flags.make
src/CMakeFiles/boids.dir/mainWindow.cpp.o: ../src/mainWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lowin/Documents/projects/BE/boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/boids.dir/mainWindow.cpp.o"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/mainWindow.cpp.o -c /home/lowin/Documents/projects/BE/boids/src/mainWindow.cpp

src/CMakeFiles/boids.dir/mainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/mainWindow.cpp.i"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lowin/Documents/projects/BE/boids/src/mainWindow.cpp > CMakeFiles/boids.dir/mainWindow.cpp.i

src/CMakeFiles/boids.dir/mainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/mainWindow.cpp.s"
	cd /home/lowin/Documents/projects/BE/boids/build/src && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lowin/Documents/projects/BE/boids/src/mainWindow.cpp -o CMakeFiles/boids.dir/mainWindow.cpp.s

# Object files for target boids
boids_OBJECTS = \
"CMakeFiles/boids.dir/boidSystem.cpp.o" \
"CMakeFiles/boids.dir/keyFrameComponent.cpp.o" \
"CMakeFiles/boids.dir/main.cpp.o" \
"CMakeFiles/boids.dir/mainApplication.cpp.o" \
"CMakeFiles/boids.dir/mainWindow.cpp.o"

# External object files for target boids
boids_EXTERNAL_OBJECTS =

boids: src/CMakeFiles/boids.dir/boidSystem.cpp.o
boids: src/CMakeFiles/boids.dir/keyFrameComponent.cpp.o
boids: src/CMakeFiles/boids.dir/main.cpp.o
boids: src/CMakeFiles/boids.dir/mainApplication.cpp.o
boids: src/CMakeFiles/boids.dir/mainWindow.cpp.o
boids: src/CMakeFiles/boids.dir/build.make
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libGui.so.1.0.0
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libIO.so.1.0.0
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libassimp.so.5
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libtinyply.so
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libPluginBase.so.1.0.0
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libEngine.so.1.0.0
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libCore.so.1.0.0
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libOpenMeshTools.so.8.1
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libOpenMeshCore.so.8.1
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libcpplocate.so.2.2.1
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libglobjects.so.2.0.0
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libglbinding-aux.so.3.1.0
boids: /home/lowin/Documents/projects/BE/Radium-Engine/Bundle-GNU/lib/libglbinding.so.3.1.0
boids: /usr/lib/llvm-11/lib/libomp.so
boids: /lib/x86_64-linux-gnu/libpthread.so
boids: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.14.2
boids: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.14.2
boids: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.14.2
boids: src/CMakeFiles/boids.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lowin/Documents/projects/BE/boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../boids"
	cd /home/lowin/Documents/projects/BE/boids/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boids.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/boids.dir/build: boids

.PHONY : src/CMakeFiles/boids.dir/build

src/CMakeFiles/boids.dir/clean:
	cd /home/lowin/Documents/projects/BE/boids/build/src && $(CMAKE_COMMAND) -P CMakeFiles/boids.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/boids.dir/clean

src/CMakeFiles/boids.dir/depend:
	cd /home/lowin/Documents/projects/BE/boids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lowin/Documents/projects/BE/boids /home/lowin/Documents/projects/BE/boids/src /home/lowin/Documents/projects/BE/boids/build /home/lowin/Documents/projects/BE/boids/build/src /home/lowin/Documents/projects/BE/boids/build/src/CMakeFiles/boids.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/boids.dir/depend
