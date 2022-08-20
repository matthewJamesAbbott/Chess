# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/squig/git/Chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/squig/git/Chess

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/squig/git/Chess/CMakeFiles /home/squig/git/Chess/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/squig/git/Chess/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Chess

# Build rule for target.
Chess: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Chess
.PHONY : Chess

# fast build rule for target.
Chess/fast:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/build
.PHONY : Chess/fast

Board.o: Board.cpp.o

.PHONY : Board.o

# target to build an object file
Board.cpp.o:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Board.cpp.o
.PHONY : Board.cpp.o

Board.i: Board.cpp.i

.PHONY : Board.i

# target to preprocess a source file
Board.cpp.i:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Board.cpp.i
.PHONY : Board.cpp.i

Board.s: Board.cpp.s

.PHONY : Board.s

# target to generate assembly for a file
Board.cpp.s:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Board.cpp.s
.PHONY : Board.cpp.s

Engine.o: Engine.cpp.o

.PHONY : Engine.o

# target to build an object file
Engine.cpp.o:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Engine.cpp.o
.PHONY : Engine.cpp.o

Engine.i: Engine.cpp.i

.PHONY : Engine.i

# target to preprocess a source file
Engine.cpp.i:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Engine.cpp.i
.PHONY : Engine.cpp.i

Engine.s: Engine.cpp.s

.PHONY : Engine.s

# target to generate assembly for a file
Engine.cpp.s:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Engine.cpp.s
.PHONY : Engine.cpp.s

Game.o: Game.cpp.o

.PHONY : Game.o

# target to build an object file
Game.cpp.o:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Game.cpp.o
.PHONY : Game.cpp.o

Game.i: Game.cpp.i

.PHONY : Game.i

# target to preprocess a source file
Game.cpp.i:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Game.cpp.i
.PHONY : Game.cpp.i

Game.s: Game.cpp.s

.PHONY : Game.s

# target to generate assembly for a file
Game.cpp.s:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Game.cpp.s
.PHONY : Game.cpp.s

MoveCalculator.o: MoveCalculator.cpp.o

.PHONY : MoveCalculator.o

# target to build an object file
MoveCalculator.cpp.o:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/MoveCalculator.cpp.o
.PHONY : MoveCalculator.cpp.o

MoveCalculator.i: MoveCalculator.cpp.i

.PHONY : MoveCalculator.i

# target to preprocess a source file
MoveCalculator.cpp.i:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/MoveCalculator.cpp.i
.PHONY : MoveCalculator.cpp.i

MoveCalculator.s: MoveCalculator.cpp.s

.PHONY : MoveCalculator.s

# target to generate assembly for a file
MoveCalculator.cpp.s:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/MoveCalculator.cpp.s
.PHONY : MoveCalculator.cpp.s

MoveRecorder.o: MoveRecorder.cpp.o

.PHONY : MoveRecorder.o

# target to build an object file
MoveRecorder.cpp.o:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/MoveRecorder.cpp.o
.PHONY : MoveRecorder.cpp.o

MoveRecorder.i: MoveRecorder.cpp.i

.PHONY : MoveRecorder.i

# target to preprocess a source file
MoveRecorder.cpp.i:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/MoveRecorder.cpp.i
.PHONY : MoveRecorder.cpp.i

MoveRecorder.s: MoveRecorder.cpp.s

.PHONY : MoveRecorder.s

# target to generate assembly for a file
MoveRecorder.cpp.s:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/MoveRecorder.cpp.s
.PHONY : MoveRecorder.cpp.s

Print.o: Print.cpp.o

.PHONY : Print.o

# target to build an object file
Print.cpp.o:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Print.cpp.o
.PHONY : Print.cpp.o

Print.i: Print.cpp.i

.PHONY : Print.i

# target to preprocess a source file
Print.cpp.i:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Print.cpp.i
.PHONY : Print.cpp.i

Print.s: Print.cpp.s

.PHONY : Print.s

# target to generate assembly for a file
Print.cpp.s:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/Print.cpp.s
.PHONY : Print.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/Chess.dir/build.make CMakeFiles/Chess.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... Chess"
	@echo "... Board.o"
	@echo "... Board.i"
	@echo "... Board.s"
	@echo "... Engine.o"
	@echo "... Engine.i"
	@echo "... Engine.s"
	@echo "... Game.o"
	@echo "... Game.i"
	@echo "... Game.s"
	@echo "... MoveCalculator.o"
	@echo "... MoveCalculator.i"
	@echo "... MoveCalculator.s"
	@echo "... MoveRecorder.o"
	@echo "... MoveRecorder.i"
	@echo "... MoveRecorder.s"
	@echo "... Print.o"
	@echo "... Print.i"
	@echo "... Print.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

