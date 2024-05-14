/*
* Author : Emirhan Kılıç
* ID: 22203360
* Section : 3
* Homework : 2
* Description : Priority Queue Implementation using heap class, similar to provided course slides with addition to peek to simplfy things
*/

#include "pQueue.h"

pQueue::pQueue(int maxSize, bool sortOnlyRequestTime) {
    this->maxSize = maxSize;
    minHeap = new heap(maxSize, sortOnlyRequestTime);
    this->currentSize = 0;
}

pQueue::~pQueue() {
    delete minHeap;
}

bool pQueue::isEmpty() {
    return minHeap->empty();
}

void pQueue::insert(httpReq request) {
    minHeap->insert(request);
    currentSize++;
}

httpReq pQueue::remove() {
    currentSize--;
    return minHeap->removeRoot();
}

int pQueue::getCurrentSize() const {
    return currentSize;
}

httpReq pQueue::peek() {
    return minHeap->peek();
}
