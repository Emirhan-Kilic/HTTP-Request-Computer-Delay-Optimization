/*
* Author : Emirhan Kılıç
* ID: 22203360
* Section : 3
* Homework : 2
* Description : Main implementation of finding min computer number and time calculations
*/

#include "simMethods.h"
#include <fstream>
#include <iomanip>

using namespace std;

simMethods::simMethods(const std::string &fileNameString, int inputAverageWaitingTime) : fileNameString(fileNameString),
                                                                                         inputAverageWaitingTime(inputAverageWaitingTime) {}

int simMethods::calcuateMinNumber() {

    double numberOfRequests;
    string fileNameString = this->fileNameString;
    int inputAverageWaitingTime = this->inputAverageWaitingTime;
    int currentComputerSize = 0;
    double currentAVGWaitingTime = 0;

    while (true) {
        currentComputerSize++;
        currentAVGWaitingTime = 0;
        int currentTime = 0;
        double totalDelayTime = 0;
        int doneNumber = 0;


        ifstream inputTxt(fileNameString);

        if (!inputTxt.is_open()) {
            cout << " Error: Input File" << endl;
            return -1;
        }

        inputTxt >> numberOfRequests;

        pQueue priorityQueue(numberOfRequests,false);
        pQueue allRequestQueue(numberOfRequests,true);

        for (int i = 0; i < numberOfRequests; ++i) {
            httpReq tempReq;
            int tempId, tempPriority, tempRequestTime, tempProcessTime;
            inputTxt >> tempId >> tempPriority >> tempRequestTime >> tempProcessTime;
            tempReq.setId(tempId);
            tempReq.setPriority(tempPriority);
            tempReq.setRequestTime(tempRequestTime);
            tempReq.setProcessTime(tempProcessTime);
            allRequestQueue.insert(tempReq);
        }


        inputTxt.close();


        cmpe computerArray[currentComputerSize];

        for (int i = 0; i < currentComputerSize; ++i) {
            computerArray[i] = cmpe(i);
        }

        // continue until all nodes are processed
        while ( doneNumber < numberOfRequests ){


            while (true) {
                if (!allRequestQueue.isEmpty()) {
                    if (allRequestQueue.peek().getRTime() <= currentTime) {
                        priorityQueue.insert(allRequestQueue.remove());
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }

            if (!priorityQueue.isEmpty()) {
                for (int i = 0; i < currentComputerSize; ++i) {
                    if (currentTime == 96 && currentComputerSize == 3) {
                    }
                    if (computerArray[i].available(currentTime)) {

                        if (!priorityQueue.isEmpty()) {
                            httpReq req = priorityQueue.remove();
                            totalDelayTime += currentTime - req.getRequestTime();
                            computerArray[i].changeAvailableTime(req);
                            doneNumber++;
                        }
                    }
                }
            }
            currentTime++;
        }


        currentAVGWaitingTime = totalDelayTime / numberOfRequests;

        if (currentAVGWaitingTime <= inputAverageWaitingTime) {
            break;
        }

    }
    return currentComputerSize;
}

void simMethods::printProcess(int min) {


    cout << "Minimum number of computers required: " << min << endl;
    cout << endl;
    cout << "Simulation with " << min << " computers:" << endl;
    cout << endl;

    double numberOfRequests;
    string fileNameString = this->fileNameString;
    int inputAverageWaitingTime = this->inputAverageWaitingTime;
    int currentComputerSize = 0;
    double currentAVGWaitingTime = 0;

    while (true) {
        currentComputerSize++;
        currentAVGWaitingTime = 0;
        int currentTime = 0;
        double totalDelayTime = 0;
        int doneNumber = 0;


        ifstream inputTxt(fileNameString);

        if (!inputTxt.is_open()) {
            cout << " Error: Input File" << endl;
            return;
        }

        inputTxt >> numberOfRequests;

        pQueue priorityQueue(numberOfRequests,false);
        pQueue allRequestQueue(numberOfRequests,true);

        for (int i = 0; i < numberOfRequests; ++i) {
            httpReq tempReq;
            int tempId, tempPriority, tempRequestTime, tempProcessTime;
            inputTxt >> tempId >> tempPriority >> tempRequestTime >> tempProcessTime;
            tempReq.setId(tempId);
            tempReq.setPriority(tempPriority);
            tempReq.setRequestTime(tempRequestTime);
            tempReq.setProcessTime(tempProcessTime);
            allRequestQueue.insert(tempReq);
        }


        inputTxt.close();


        cmpe computerArray[currentComputerSize];

        for (int i = 0; i < currentComputerSize; ++i) {
            computerArray[i] = cmpe(i);
        }


        while ( doneNumber < numberOfRequests ){


            while (true) {
                if (!allRequestQueue.isEmpty()) {
                    if (allRequestQueue.peek().getRTime() <= currentTime) {
                        priorityQueue.insert(allRequestQueue.remove());
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }

            if (!priorityQueue.isEmpty()) {
                for (int i = 0; i < currentComputerSize; ++i) {
                    if (currentTime == 96 && currentComputerSize == 3) {
                    }
                    if (computerArray[i].available(currentTime)) {

                        if (!priorityQueue.isEmpty()) {
                            httpReq req = priorityQueue.remove();
                            if (currentComputerSize == min) {
                                cout << "Computer " << i << " takes request " << req.getId() << " at ms " <<  currentTime << " (wait: " <<  currentTime - req.getRequestTime() << " ms)"<< endl;
                            }
                            totalDelayTime += currentTime - req.getRequestTime();
                            computerArray[i].changeAvailableTime(req);
                            doneNumber++;
                        }
                    }
                }
            }
            currentTime++;
        }


        currentAVGWaitingTime = totalDelayTime / numberOfRequests;

        if (currentAVGWaitingTime <= inputAverageWaitingTime) {
            break;
        }

    }

    cout << endl;
    cout << "Average waiting time: " << std::fixed << std::setprecision(2) << currentAVGWaitingTime << " ms" << endl;


}

simMethods::~simMethods() = default;
