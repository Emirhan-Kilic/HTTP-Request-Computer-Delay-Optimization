/*
* Author : Emirhan Kılıç
* ID: 22203360
* Section : 3
* Homework : 2
* Description : HTTP Request Class with basic variables that define the request class in given pdf. Operator < is overloaded to simplfy the ordering process
* in other methods.
*/

#ifndef HW2_HTTPREQ_H
#define HW2_HTTPREQ_H
#include <iostream>

class httpReq {
private:
    int priority;
    int id;
    int requestTime;
    int processTime;

public:
    httpReq();
    httpReq(int priority, int id, int requestTime, int processTime);
    ~httpReq();

    int getPriority() const;

    void setPriority(int priority);

    int getId() const;

    void setId(int id);

    int getRTime() const;

    void setRTime(int rTime);

    int getPTime() const;

    void setPTime(int pTime);

    bool operator<(const httpReq &rhs) const;

    int getRequestTime() const;

    void setRequestTime(int requestTime);

    int getProcessTime() const;

    void setProcessTime(int processTime);
};


#endif //HW2_HTTPREQ_H
