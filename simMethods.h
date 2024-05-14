/*
* Author : Emirhan Kılıç
* ID: 22203360
* Section : 3
* Homework : 2
* Description : Main implementation of finding min computer number and time calculations
*/

#ifndef HW2_SIMMETHODS_H
#define HW2_SIMMETHODS_H
#include "pQueue.h"


class simMethods {
private:
    std::string fileNameString;
    int inputAverageWaitingTime;
public:
    simMethods(const std::string &fileNameString, int inputAverageWaitingTime);

    virtual ~simMethods();

    int calcuateMinNumber();

    void printProcess(int min);

};


#endif //HW2_SIMMETHODS_H
