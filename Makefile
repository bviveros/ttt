# Makefile for tic-tac-toe game

CPP = g++

CPPFLAGS = -g -Wall

all: ttt

clean: 
	-rm -f *.o *.d
	-rm -f ttt

ttt: ttt_main.cpp ttt.o
		$(CPP) $(CPPFLAGS) -o $@ ttt_main.cpp
