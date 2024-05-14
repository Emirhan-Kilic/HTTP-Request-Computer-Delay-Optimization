/*
* Author : Emirhan Kılıç
* ID: 22203360
* Section : 3
* Homework : 2
* Description : main file that initializes simMethods with given paramteres.
*/
#include <fstream>
#include "simMethods.h"
using namespace std;

int main(int argc, char* argv[]) {

    string fileNameString = argv[1];
    int inputAverageWaitingTime = stoi(argv[2]);
    simMethods simulate(fileNameString,inputAverageWaitingTime );
    int minNumber = simulate.calcuateMinNumber();
    simulate.printProcess(minNumber);

}
