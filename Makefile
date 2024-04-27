CPP = g++

CPPFLAGS = -Wall

PRODUCT = 

tic_tac_toe: tttMain.cpp
		# g++ -std=c++11 tttMain.cpp ttt.cpp ttt.h
		g++ -Wall -o $@ $@.cpp ttt.cpp ttt.h
