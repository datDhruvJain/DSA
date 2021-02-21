# Makefile automated build system for the DSA_Lab
# target: dependencies
# 	command

all: Week_02

# Week_02
Week_02: Week_02/Cpp-StackQa Week_02/C-StackQa
	
Week_02/Cpp-StackQa: Week_02/StackQa.cpp
	g++ Week_02/StackQa.cpp -std=c++11 -o Week_02/Cpp-StackQa

Week_02/C-StackQa: Week_02/StackQa.c 
	gcc Week_02/StackQa.c -std=c11 -o Week_02/C-StackQa
