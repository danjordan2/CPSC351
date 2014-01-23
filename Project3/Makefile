# Daniel Jordan 
# CPSC351 Project 3
# Makefile for memory map program

all:	memorymap

memorymap:	memorymap.o
	g++ memorymap.o -o memorymap

memorymap.o:	memorymap.cpp
	g++ -c memorymap.cpp

clean:
	rm -rf memorymap memorymap.o
