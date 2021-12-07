# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /snap/cmake/992/bin/cmake

# The command to remove a file.
RM = /snap/cmake/992/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kde/Practice-of-Projects/ui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kde/Practice-of-Projects/ui/build/linux

# Include any dependencies generated for this target.
include CMakeFiles/EnglishAssistant.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/EnglishAssistant.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/EnglishAssistant.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EnglishAssistant.dir/flags.make

zh_tw.qm: ../../assets/lang/zh_tw.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating zh_tw.qm"
	/usr/lib/qt5/bin/lrelease /home/kde/Practice-of-Projects/ui/assets/lang/zh_tw.ts -qm /home/kde/Practice-of-Projects/ui/build/linux/zh_tw.qm

zh_cn.qm: ../../assets/lang/zh_cn.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating zh_cn.qm"
	/usr/lib/qt5/bin/lrelease /home/kde/Practice-of-Projects/ui/assets/lang/zh_cn.ts -qm /home/kde/Practice-of-Projects/ui/build/linux/zh_cn.qm

en_us.qm: ../../assets/lang/en_us.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating en_us.qm"
	/usr/lib/qt5/bin/lrelease /home/kde/Practice-of-Projects/ui/assets/lang/en_us.ts -qm /home/kde/Practice-of-Projects/ui/build/linux/en_us.qm

../../assets/lang/zh_tw.ts: CMakeFiles/3.22.0/CompilerIdCXX/CMakeCXXCompilerId.cpp
../../assets/lang/zh_tw.ts: ../windows/CMakeFiles/3.22.0/CompilerIdCXX/CMakeCXXCompilerId.cpp
../../assets/lang/zh_tw.ts: ../../include/Crawler.h
../../assets/lang/zh_tw.ts: ../../include/MainWindow.h
../../assets/lang/zh_tw.ts: ../../include/OnlineTranslator.h
../../assets/lang/zh_tw.ts: ../../src/Crawler.cpp
../../assets/lang/zh_tw.ts: ../../src/MainWindow.cpp
../../assets/lang/zh_tw.ts: ../../src/OnlineTranslator.cpp
../../assets/lang/zh_tw.ts: ../../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating ../../assets/lang/zh_tw.ts"
	/usr/lib/qt5/bin/lupdate @/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles/zh_tw.ts_lst_file -ts /home/kde/Practice-of-Projects/ui/assets/lang/zh_tw.ts

../../assets/lang/zh_cn.ts: CMakeFiles/3.22.0/CompilerIdCXX/CMakeCXXCompilerId.cpp
../../assets/lang/zh_cn.ts: ../windows/CMakeFiles/3.22.0/CompilerIdCXX/CMakeCXXCompilerId.cpp
../../assets/lang/zh_cn.ts: ../../include/Crawler.h
../../assets/lang/zh_cn.ts: ../../include/MainWindow.h
../../assets/lang/zh_cn.ts: ../../include/OnlineTranslator.h
../../assets/lang/zh_cn.ts: ../../src/Crawler.cpp
../../assets/lang/zh_cn.ts: ../../src/MainWindow.cpp
../../assets/lang/zh_cn.ts: ../../src/OnlineTranslator.cpp
../../assets/lang/zh_cn.ts: ../../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Generating ../../assets/lang/zh_cn.ts"
	/usr/lib/qt5/bin/lupdate @/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles/zh_cn.ts_lst_file -ts /home/kde/Practice-of-Projects/ui/assets/lang/zh_cn.ts

../../assets/lang/en_us.ts: CMakeFiles/3.22.0/CompilerIdCXX/CMakeCXXCompilerId.cpp
../../assets/lang/en_us.ts: ../windows/CMakeFiles/3.22.0/CompilerIdCXX/CMakeCXXCompilerId.cpp
../../assets/lang/en_us.ts: ../../include/Crawler.h
../../assets/lang/en_us.ts: ../../include/MainWindow.h
../../assets/lang/en_us.ts: ../../include/OnlineTranslator.h
../../assets/lang/en_us.ts: ../../src/Crawler.cpp
../../assets/lang/en_us.ts: ../../src/MainWindow.cpp
../../assets/lang/en_us.ts: ../../src/OnlineTranslator.cpp
../../assets/lang/en_us.ts: ../../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Generating ../../assets/lang/en_us.ts"
	/usr/lib/qt5/bin/lupdate @/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles/en_us.ts_lst_file -ts /home/kde/Practice-of-Projects/ui/assets/lang/en_us.ts

CMakeFiles/EnglishAssistant.dir/src/main.cpp.o: CMakeFiles/EnglishAssistant.dir/flags.make
CMakeFiles/EnglishAssistant.dir/src/main.cpp.o: ../../src/main.cpp
CMakeFiles/EnglishAssistant.dir/src/main.cpp.o: CMakeFiles/EnglishAssistant.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/EnglishAssistant.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EnglishAssistant.dir/src/main.cpp.o -MF CMakeFiles/EnglishAssistant.dir/src/main.cpp.o.d -o CMakeFiles/EnglishAssistant.dir/src/main.cpp.o -c /home/kde/Practice-of-Projects/ui/src/main.cpp

CMakeFiles/EnglishAssistant.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EnglishAssistant.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kde/Practice-of-Projects/ui/src/main.cpp > CMakeFiles/EnglishAssistant.dir/src/main.cpp.i

CMakeFiles/EnglishAssistant.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EnglishAssistant.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kde/Practice-of-Projects/ui/src/main.cpp -o CMakeFiles/EnglishAssistant.dir/src/main.cpp.s

CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.o: CMakeFiles/EnglishAssistant.dir/flags.make
CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.o: ../../src/MainWindow.cpp
CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.o: CMakeFiles/EnglishAssistant.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.o -MF CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.o.d -o CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.o -c /home/kde/Practice-of-Projects/ui/src/MainWindow.cpp

CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kde/Practice-of-Projects/ui/src/MainWindow.cpp > CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.i

CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kde/Practice-of-Projects/ui/src/MainWindow.cpp -o CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.s

CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.o: CMakeFiles/EnglishAssistant.dir/flags.make
CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.o: ../../src/Crawler.cpp
CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.o: CMakeFiles/EnglishAssistant.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.o -MF CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.o.d -o CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.o -c /home/kde/Practice-of-Projects/ui/src/Crawler.cpp

CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kde/Practice-of-Projects/ui/src/Crawler.cpp > CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.i

CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kde/Practice-of-Projects/ui/src/Crawler.cpp -o CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.s

CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.o: CMakeFiles/EnglishAssistant.dir/flags.make
CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.o: ../../src/OnlineTranslator.cpp
CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.o: CMakeFiles/EnglishAssistant.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.o -MF CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.o.d -o CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.o -c /home/kde/Practice-of-Projects/ui/src/OnlineTranslator.cpp

CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kde/Practice-of-Projects/ui/src/OnlineTranslator.cpp > CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.i

CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kde/Practice-of-Projects/ui/src/OnlineTranslator.cpp -o CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.s

# Object files for target EnglishAssistant
EnglishAssistant_OBJECTS = \
"CMakeFiles/EnglishAssistant.dir/src/main.cpp.o" \
"CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.o" \
"CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.o" \
"CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.o"

# External object files for target EnglishAssistant
EnglishAssistant_EXTERNAL_OBJECTS =

EnglishAssistant: CMakeFiles/EnglishAssistant.dir/src/main.cpp.o
EnglishAssistant: CMakeFiles/EnglishAssistant.dir/src/MainWindow.cpp.o
EnglishAssistant: CMakeFiles/EnglishAssistant.dir/src/Crawler.cpp.o
EnglishAssistant: CMakeFiles/EnglishAssistant.dir/src/OnlineTranslator.cpp.o
EnglishAssistant: CMakeFiles/EnglishAssistant.dir/build.make
EnglishAssistant: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
EnglishAssistant: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.3
EnglishAssistant: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
EnglishAssistant: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
EnglishAssistant: CMakeFiles/EnglishAssistant.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable EnglishAssistant"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EnglishAssistant.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EnglishAssistant.dir/build: EnglishAssistant
.PHONY : CMakeFiles/EnglishAssistant.dir/build

CMakeFiles/EnglishAssistant.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EnglishAssistant.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EnglishAssistant.dir/clean

CMakeFiles/EnglishAssistant.dir/depend: ../../assets/lang/en_us.ts
CMakeFiles/EnglishAssistant.dir/depend: ../../assets/lang/zh_cn.ts
CMakeFiles/EnglishAssistant.dir/depend: ../../assets/lang/zh_tw.ts
CMakeFiles/EnglishAssistant.dir/depend: en_us.qm
CMakeFiles/EnglishAssistant.dir/depend: zh_cn.qm
CMakeFiles/EnglishAssistant.dir/depend: zh_tw.qm
	cd /home/kde/Practice-of-Projects/ui/build/linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kde/Practice-of-Projects/ui /home/kde/Practice-of-Projects/ui /home/kde/Practice-of-Projects/ui/build/linux /home/kde/Practice-of-Projects/ui/build/linux /home/kde/Practice-of-Projects/ui/build/linux/CMakeFiles/EnglishAssistant.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EnglishAssistant.dir/depend

