#include <iostream>
#include "Train_class.h"
#include "Wagon_class.h"

using namespace std;
//Constructor of the class
Train::Train(int totalWag, int tM, int monC, Wagon** w): totalWagons(totalWag), tempM(tM), moneyCollected(monC), wag(w) {		
	
	wag = new Wagon*[totalWag]();	//Initialize empty array
	
   cout << "A metro train with " << totalWag << " wagons, was created" << endl;
}
//Function that defines the number of stations that the train operates
void Train::set_activeStations(int nStations) {	
	
	numOfStations = nStations;	
}
//Function that returns the number of stations that the train operates
int Train::get_activeStations()const {	
	
	return numOfStations;
}
//Function that saves a temporary amount of money
void Train::set_tempMoney(int m) {	
	
	tempM = m;
}
//Function that returns a sum of money 
int Train::printStatistics(int& m) {	 
	
	 m = tempM;
	 moneyCollected = m + moneyCollected;
		
	return moneyCollected;
}
//Function that defines a train's operation
void Train::operate(int maxCap, int passEntered, int passExited, int tCheck, int hfT, int hrT, int drT, int fF, int rF, int *temp) {	
		
	for(int i=0; i < totalWagons; i++) {	//Reapeat the proccess for each wagon
			
		wag[i] = new Wagon(maxCap);	//Create a wagon
		
		cout << "  ~Wagon No " << i+1 << "~" << endl << endl;
		
		passEntered--;	//Helps in the randomness of numbers	
		passExited++;
		
		if(passEntered <= passExited) {	//Helps in the randomness of numbers
			
			passEntered += 5;
			passExited += 2;
		}
															//Make ticket Check even more random
		wag[i]->inStation(passEntered + temp[i],passExited,hfT,hrT,drT,tCheck*i);	//Add the passengers who were in the wagon to the passengers who just entered
		wag[i]->betweenStations(fF,rF);
		
		temp[i] = wag[i]->get_passengers();	//Keep the number of passengers that are currently in the wagon
		
		wag[i]->printStatistics();	//Each wagon's statistics at each station	
		
		int wagonM = wag[i]->get_money();	//Money collected from each wagon, at each station
		set_tempMoney(wagonM);
		
		int totalM = printStatistics(wagonM);	//Keep adding till you reach the total amount money collected
		cout << totalM << "$ collected from fines " << endl << endl;
		
		wag[i]->inStation(-temp[i],0,hfT,hrT,drT,0);	//Reinitialize , to avoid messing the passengers among the wagons						
	}
}
//Destructor of the class
Train::~Train() {	

	for(int i = 0; i < totalWagons; i++)
  		delete wag[i];
		
   		delete[] wag;
   		
		cout << "A metro train was destroyed" << endl;
}