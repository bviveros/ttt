# Makefile for tic-tac-toe game

# compiler
CXX= g++

# compiler flags for release
CXXFLAGS= -Wall -Wextra

# linker flags
LDFLAGS=

# object files
OBJ= ttt_main.o ttt.o

# name of executable
EXEC= ttt

# choose target: release or debug
all: release # release or debug

release: CXXFLAGS += -O2
release: $(EXEC)

debug: CXXFLAGS += -g
debug: $(EXEC)

# linking the object files into the final executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

# compiling ttt_main.cpp to ttt_main.o
ttt_main.o: ttt_main.cpp ttt.h
	$(CXX) $(CXXFLAGS) -c ttt_main.cpp

# compiling ttt.cpp to ttt.o
ttt.o: ttt.cpp ttt.h
	$(CXX) $(CXXFLAGS) -c ttt.cpp

# clean up objects and executable
clean:
	rm -f $(OBJ) $(EXEC)
	rm -rf $(EXEC).dSYM # cleaning up macOS debugging info

# prevent Make from mistaking a target for a filename
.PHONY: all clean