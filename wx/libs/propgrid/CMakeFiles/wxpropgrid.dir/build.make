# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/theovasile/Desktop/wx 3d/wx"

# Include any dependencies generated for this target.
include libs/propgrid/CMakeFiles/wxpropgrid.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/propgrid/CMakeFiles/wxpropgrid.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/propgrid/CMakeFiles/wxpropgrid.dir/progress.make

# Include the compile flags for this target's objects.
include libs/propgrid/CMakeFiles/wxpropgrid.dir/flags.make

libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch: libs/propgrid/CMakeFiles/wxpropgrid.dir/flags.make
libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.cxx
libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx
libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch: libs/propgrid/CMakeFiles/wxpropgrid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/theovasile/Desktop/wx 3d/wx/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGSarm64) -Winvalid-pch -Xclang -emit-pch -Xclang -include -Xclang "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -x c++-header -MD -MT libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch -MF CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch.d -o CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch -c "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.cxx"

libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.i"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGSarm64) -Winvalid-pch -Xclang -emit-pch -Xclang -include -Xclang "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -x c++-header -E "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.cxx" > CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.i

libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.s"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGSarm64) -Winvalid-pch -Xclang -emit-pch -Xclang -include -Xclang "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -x c++-header -S "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.cxx" -o CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.s

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/flags.make
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.o: /Users/theovasile/Desktop/wx\ 3d/wxWidgets-3.2.2.1/src/propgrid/advprops.cpp
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/theovasile/Desktop/wx 3d/wx/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.o"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -MD -MT libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.o -MF CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.o.d -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.o -c "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/advprops.cpp"

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.i"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -E "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/advprops.cpp" > CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.i

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.s"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -S "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/advprops.cpp" -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.s

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/flags.make
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.o: /Users/theovasile/Desktop/wx\ 3d/wxWidgets-3.2.2.1/src/propgrid/editors.cpp
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/theovasile/Desktop/wx 3d/wx/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.o"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -MD -MT libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.o -MF CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.o.d -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.o -c "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/editors.cpp"

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.i"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -E "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/editors.cpp" > CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.i

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.s"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -S "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/editors.cpp" -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.s

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/flags.make
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.o: /Users/theovasile/Desktop/wx\ 3d/wxWidgets-3.2.2.1/src/propgrid/manager.cpp
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/theovasile/Desktop/wx 3d/wx/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.o"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -MD -MT libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.o -MF CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.o.d -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.o -c "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/manager.cpp"

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.i"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -E "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/manager.cpp" > CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.i

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.s"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -S "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/manager.cpp" -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.s

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/flags.make
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.o: /Users/theovasile/Desktop/wx\ 3d/wxWidgets-3.2.2.1/src/propgrid/property.cpp
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/theovasile/Desktop/wx 3d/wx/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.o"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -MD -MT libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.o -MF CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.o.d -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.o -c "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/property.cpp"

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.i"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -E "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/property.cpp" > CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.i

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.s"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -S "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/property.cpp" -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.s

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/flags.make
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.o: /Users/theovasile/Desktop/wx\ 3d/wxWidgets-3.2.2.1/src/propgrid/propgrid.cpp
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/theovasile/Desktop/wx 3d/wx/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.o"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -MD -MT libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.o -MF CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.o.d -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.o -c "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/propgrid.cpp"

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.i"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -E "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/propgrid.cpp" > CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.i

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.s"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -S "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/propgrid.cpp" -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.s

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/flags.make
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.o: /Users/theovasile/Desktop/wx\ 3d/wxWidgets-3.2.2.1/src/propgrid/propgridiface.cpp
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/theovasile/Desktop/wx 3d/wx/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.o"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -MD -MT libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.o -MF CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.o.d -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.o -c "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/propgridiface.cpp"

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.i"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -E "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/propgridiface.cpp" > CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.i

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.s"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -S "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/propgridiface.cpp" -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.s

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/flags.make
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.o: /Users/theovasile/Desktop/wx\ 3d/wxWidgets-3.2.2.1/src/propgrid/propgridpagestate.cpp
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/theovasile/Desktop/wx 3d/wx/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.o"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -MD -MT libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.o -MF CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.o.d -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.o -c "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/propgridpagestate.cpp"

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.i"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -E "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/propgridpagestate.cpp" > CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.i

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.s"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -S "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/propgridpagestate.cpp" -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.s

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/flags.make
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.o: /Users/theovasile/Desktop/wx\ 3d/wxWidgets-3.2.2.1/src/propgrid/props.cpp
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch
libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.o: libs/propgrid/CMakeFiles/wxpropgrid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/theovasile/Desktop/wx 3d/wx/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.o"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -MD -MT libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.o -MF CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.o.d -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.o -c "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/props.cpp"

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.i"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -E "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/props.cpp" > CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.i

libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.s"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xarch_arm64 "-include/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx" -S "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/src/propgrid/props.cpp" -o CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.s

# Object files for target wxpropgrid
wxpropgrid_OBJECTS = \
"CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.o" \
"CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.o" \
"CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.o" \
"CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.o" \
"CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.o" \
"CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.o" \
"CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.o" \
"CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.o"

# External object files for target wxpropgrid
wxpropgrid_EXTERNAL_OBJECTS =

lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: libs/propgrid/CMakeFiles/wxpropgrid.dir/cmake_pch_arm64.hxx.pch
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/advprops.cpp.o
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/editors.cpp.o
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/manager.cpp.o
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/property.cpp.o
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgrid.cpp.o
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridiface.cpp.o
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/propgridpagestate.cpp.o
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: libs/propgrid/CMakeFiles/wxpropgrid.dir/__/__/__/__/src/propgrid/props.cpp.o
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: libs/propgrid/CMakeFiles/wxpropgrid.dir/build.make
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: lib/libwx_osx_cocoau_core-3.2.0.2.1.dylib
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: lib/libwx_baseu-3.2.0.2.1.dylib
lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib: libs/propgrid/CMakeFiles/wxpropgrid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/theovasile/Desktop/wx 3d/wx/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library ../../lib/libwx_osx_cocoau_propgrid-3.2.dylib"
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wxpropgrid.dir/link.txt --verbose=$(VERBOSE)
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib ../../lib/libwx_osx_cocoau_propgrid-3.2.0.dylib ../../lib/libwx_osx_cocoau_propgrid-3.2.dylib

lib/libwx_osx_cocoau_propgrid-3.2.0.dylib: lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libwx_osx_cocoau_propgrid-3.2.0.dylib

lib/libwx_osx_cocoau_propgrid-3.2.dylib: lib/libwx_osx_cocoau_propgrid-3.2.0.2.1.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libwx_osx_cocoau_propgrid-3.2.dylib

# Rule to build all files generated by this target.
libs/propgrid/CMakeFiles/wxpropgrid.dir/build: lib/libwx_osx_cocoau_propgrid-3.2.dylib
.PHONY : libs/propgrid/CMakeFiles/wxpropgrid.dir/build

libs/propgrid/CMakeFiles/wxpropgrid.dir/clean:
	cd "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" && $(CMAKE_COMMAND) -P CMakeFiles/wxpropgrid.dir/cmake_clean.cmake
.PHONY : libs/propgrid/CMakeFiles/wxpropgrid.dir/clean

libs/propgrid/CMakeFiles/wxpropgrid.dir/depend:
	cd "/Users/theovasile/Desktop/wx 3d/wx" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1" "/Users/theovasile/Desktop/wx 3d/wxWidgets-3.2.2.1/build/cmake/lib/propgrid" "/Users/theovasile/Desktop/wx 3d/wx" "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid" "/Users/theovasile/Desktop/wx 3d/wx/libs/propgrid/CMakeFiles/wxpropgrid.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : libs/propgrid/CMakeFiles/wxpropgrid.dir/depend

