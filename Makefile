

all: simulator

simulator: cmpe.cpp cmpe.h heap.cpp heap.h httpReq.cpp httpReq.h main.cpp pQueue.cpp pQueue.h simMethods.cpp simMethods.h
	g++ cmpe.cpp heap.cpp httpReq.cpp main.cpp pQueue.cpp simMethods.cpp -o simulator

delete:
	rm -f simulator output*.txt
