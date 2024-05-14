/*
* Author : Emirhan Kılıç
* ID: 22203360
* Section : 3
* Homework : 2
* Description : Priority Queue Implementation using heap class, similar to provided course slides with addition to peek to simplfy things
*/

#ifndef HW2_PQUEUE_H
#define HW2_PQUEUE_H
#include "heap.h"


class pQueue {
private:
    heap *minHeap;
    int maxSize;
    int currentSize;
public:
    explicit pQueue(int maxSize, bool sortOnlyRequestTime);
    ~pQueue();
    bool isEmpty();

    void insert(httpReq request);

    httpReq remove();

    httpReq peek();

    int getCurrentSize() const;


};


#endif //HW2_PQUEUE_H
