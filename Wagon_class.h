#ifndef WAGON_CLASS_H
#define WAGON_CLASS_H

#include "Passenger_class.h"

class Wagon {

    int maxCapacity;
    int numOfPassengers;
    int ticketCheck;
    int punished;
    int gotAwayWith;
    int fullFine;
    int reducedFine;
    Passenger** pasArr;
	int* penalty;

  public:

    Wagon(int maxCap = 0, int tC = 0, int nOP = 0, int pun = 0, int gAW = 0, int fF = 100, int rF = 50, Passenger** pasA = NULL, int* pen = 0);
    ~Wagon();

    void inStation(int, int, int, int, int, int);
	void betweenStations(int,int);
	int get_maxCap()const;
	int get_passengers()const;
	int get_money()const;
	void printStatistics();
};
#endif
