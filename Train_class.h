#ifndef TRAIN_CLASS_H
#define TRAIN_CLASS_H

#include "Wagon_class.h"

class Train {
    
	int tempM;
    int totalWagons;
    int moneyCollected;
    int numOfStations;
	Wagon** wag;
	
  public:

    Train(int totalWag = 0, int tM = 0, int monC = 0, Wagon** w = NULL);
	~Train();
	
	void set_activeStations(int);
	void operate(int, int, int, int, int ,int, int, int, int, int*);
	void set_tempMoney(int);
	int get_activeStations()const;
	int printStatistics(int&);
};
#endif
