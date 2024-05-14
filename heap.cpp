/*
* Author : Emirhan Kılıç
* ID: 22203360
* Section : 3
* Homework : 2
* Description : Heap Implementation using arrays, using dynamic array to prevent stack overflow in case of large input number
*/

#include "heap.h"

heap::heap(int Size, bool sortOnlyRequestTime) {
    this->reqArray = new httpReq[Size];
    this->currentIndex = 0;
    this->sortOnlyRequestTime = sortOnlyRequestTime;
}
// Used heap implementation codes from slides provided in lectures.

bool heap::empty() const {
    return currentIndex == 0;
}

// Used heap implementation codes from slides provided in lectures, includes little edits to create min-heap.
void heap::insert(httpReq &inputIteam) {
    reqArray[currentIndex] = inputIteam;
    int itemIndex = currentIndex;
    int parentIndex = (itemIndex - 1) / 2;

    if (!sortOnlyRequestTime) {
        while ((itemIndex > 0) && (reqArray[itemIndex] < reqArray[parentIndex])) {
            httpReq temp = reqArray[parentIndex];
            reqArray[parentIndex] = reqArray[itemIndex];
            reqArray[itemIndex] = temp;
            itemIndex = parentIndex;
            parentIndex = (itemIndex - 1) / 2;
        }
    } else {
        while ((itemIndex > 0) && (reqArray[itemIndex].getId() < reqArray[parentIndex].getId())) {
            httpReq temp = reqArray[parentIndex];
            reqArray[parentIndex] = reqArray[itemIndex];
            reqArray[itemIndex] = temp;
            itemIndex = parentIndex;
            parentIndex = (itemIndex - 1) / 2;
        }
    }



    currentIndex++;
}

httpReq heap::removeRoot() {
    if (currentIndex == 0) {
        throw std::runtime_error("Empty Heap Error");
    }
    httpReq topIteam = reqArray[0];
    reqArray[0] = reqArray[--currentIndex];
    fixHeap(0);
    return topIteam;

}

void heap::fixHeap(int index) {
    int leftChlIndex = 2 * index + 1;

    if (!sortOnlyRequestTime) {

        if (leftChlIndex < currentIndex) {
            int rightChlIndex = leftChlIndex + 1;

            if ((rightChlIndex < currentIndex) && (reqArray[rightChlIndex] <  reqArray[leftChlIndex]) ) {
                leftChlIndex = rightChlIndex;
            }

            if (reqArray[leftChlIndex] < reqArray[index]) {
                httpReq temp = reqArray[index];
                reqArray[index] = reqArray[leftChlIndex];
                reqArray[leftChlIndex] = temp;
                fixHeap(leftChlIndex);
            }

        }
    } else {
        if (leftChlIndex < currentIndex) {
            int rightChlIndex = leftChlIndex + 1;

            if ((rightChlIndex < currentIndex) && (reqArray[rightChlIndex].getId() <  reqArray[leftChlIndex].getId()) ) {
                leftChlIndex = rightChlIndex;
            }

            if (reqArray[leftChlIndex].getId() < reqArray[index].getId()) {
                httpReq temp = reqArray[index];
                reqArray[index] = reqArray[leftChlIndex];
                reqArray[leftChlIndex] = temp;
                fixHeap(leftChlIndex);
            }

        }
    }



}

heap::~heap() {
    delete[] reqArray;
}

httpReq heap::peek() {
    if (currentIndex == 0) {
        throw std::runtime_error("Empty Heap Error");
    }
    return reqArray[0];
}


