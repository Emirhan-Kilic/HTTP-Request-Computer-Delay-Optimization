/*
* Author : Emirhan Kılıç
* ID: 22203360
* Section : 3
* Homework : 2
* Description : Computer Entity Class, has simple variable to keep its availability
*/
#ifndef HW2_CMPE_H
#define HW2_CMPE_H
#include "httpReq.h"

class cmpe {
private:
    int id;
    int timeAvailable;
public:
    cmpe();
    cmpe(int id);
    bool available(int time);
    ~cmpe();

    int getId() const;

    void setId(int id);

    int getTimeAvailable() const;

    void setTimeAvailable(int timeAvailable);

    void changeAvailableTime(httpReq req);

};


#endif //HW2_CMPE_H
