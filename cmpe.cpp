/*
* Author : Emirhan Kılıç
* ID: 22203360
* Section : 3
* Homework : 2
* Description : Computer Entity Class, has simple variable to keep its availability
*/
#include "cmpe.h"

cmpe::cmpe() = default;

cmpe::cmpe(int id) {
    this->id = id;
    this->timeAvailable = 0;
}

bool cmpe::available(int time) {
    if (timeAvailable   < time) {
        return true;
    } else {
        return false;
    }
}

int cmpe::getId() const {
    return id;
}

void cmpe::setId(int id) {
    cmpe::id = id;
}

int cmpe::getTimeAvailable() const {
    return timeAvailable;
}

void cmpe::setTimeAvailable(int timeAvailable) {
    cmpe::timeAvailable = timeAvailable;
}


void cmpe::changeAvailableTime(httpReq req) {
    if (req.getRTime() > timeAvailable) {
        timeAvailable = req.getRTime() + req.getPTime();
    } else {
        timeAvailable = timeAvailable + 1 + req.getPTime();
    }
}


cmpe::~cmpe() = default;
