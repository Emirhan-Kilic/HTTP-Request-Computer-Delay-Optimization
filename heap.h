/*
* Author : Emirhan Kılıç
* ID: 22203360
* Section : 3
* Homework : 2
* Description : Heap Implementation using arrays, using dynamic array to prevent stack overflow in case of large input number
*/
#ifndef HW2_HEAP_H
#define HW2_HEAP_H
#include "cmpe.h"

// Used heap implementation codes from slides provided in lectures, includes little edits to create min-heap.

class heap {
private:
    httpReq *reqArray;
    int currentIndex;
    bool sortOnlyRequestTime;
public:
    heap(int size, bool sortOnlyRequestTime);

    ~heap();

    bool empty() const;
    void insert(httpReq &inputIteam);
    httpReq removeRoot();
    void fixHeap(int index);

    httpReq peek();
};


#endif //HW2_HEAP_H
