#
# Author : Emirhan Kılıç
# ID: 22203360
# Section : 3
# Homework : 2
# Description : Very simple makefile to create simulator output.
# Use "make" to create ./simulator, "make run" to run tests for log 1-3 and "make delete" to remove the outputs includes simulator
#


all: simulator

simulator: cmpe.cpp cmpe.h heap.cpp heap.h httpReq.cpp httpReq.h main.cpp pQueue.cpp pQueue.h simMethods.cpp simMethods.h
	g++ cmpe.cpp heap.cpp httpReq.cpp main.cpp pQueue.cpp simMethods.cpp -o simulator

run: simulator
	./simulator log1.txt 5 > output1.txt
	./simulator log2.txt 15 > output2.txt
	./simulator log3.txt 46 > output3.txt
	./simulator log3.txt 17 > output4.txt

delete:
	rm -f simulator output*.txt