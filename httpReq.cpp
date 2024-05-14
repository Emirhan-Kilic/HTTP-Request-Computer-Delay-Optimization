/*
* Author : Emirhan Kılıç
* ID: 22203360
* Section : 3
* Homework : 2
* Description : HTTP Request Class with basic variables that define the request class in given pdf. Operator < is overloaded to simplfy the ordering process
* in other methods.
*/

#include "httpReq.h"

httpReq::httpReq(int priority, int id, int requestTime, int processTime) {
    this->priority = priority;
    this->id = id;
    this->requestTime = requestTime;
    this->processTime = processTime;
}

int httpReq::getPriority() const {
    return priority;
}

void httpReq::setPriority(int priority) {
    this->priority = priority;
}

int httpReq::getId() const {
    return id;
}

void httpReq::setId(int id) {
    this->id = id;
}

int httpReq::getRTime() const {
    return requestTime;
}

void httpReq::setRTime(int requestTime) {
    this->requestTime = requestTime;
}

int httpReq::getPTime() const {
    return processTime;
}

void httpReq::setPTime(int processTime) {
    this->processTime = processTime;
}

// looking at first priority then request time and then lastly id and taking the smallest one for each of them
bool httpReq::operator<(const httpReq &rhs) const {
    if (priority > rhs.priority)
        return true;
    else if (rhs.priority > priority)
        return false;
    else {
        if (requestTime == rhs.requestTime){
            return id < rhs.id;
        } else {
            return requestTime < rhs.requestTime;
        }

    }
}

int httpReq::getRequestTime() const {
    return requestTime;
}

void httpReq::setRequestTime(int requestTime) {
    httpReq::requestTime = requestTime;
}

int httpReq::getProcessTime() const {
    return processTime;
}

void httpReq::setProcessTime(int processTime) {
    httpReq::processTime = processTime;
}

httpReq::~httpReq() = default;

httpReq::httpReq() = default;
