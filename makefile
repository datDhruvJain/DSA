# Makefile automated build system for the DSA_Lab
# target: dependencies
# 	command
# target expects *exact target*
# eg linkedlist/linkedlist does not work for linkedlist/linkedlist.out

cc=gcc

all: Week_02 linkedlist/linkedlist.out

# Week_02
Week_02: Week_02/Cpp-StackQa.out Week_02/C-StackQa.out
	
Week_02/Cpp-StackQa.out: Week_02/StackQa.cpp
	g++ Week_02/StackQa.cpp -std=c++11 -o Week_02/Cpp-StackQa.out

Week_02/C-StackQa.out: Week_02/StackQa.c 
	cc Week_02/StackQa.c -std=c11 -o Week_02/C-StackQa.out

linkedlist/linkedlist.out: linkedlist/linkedlist.c
	cc linkedlist/linkedlist.c -o linkedlist/linkedlist.out
