#include <iostream>
#include "Wagon_class.h"

using namespace std;
//Constructor of the class
Wagon::Wagon(int maxCap, int tC, int nOP, int pun, int gAW, int fF, int rF, Passenger** pasA, int* pen): 
	maxCapacity(maxCap), ticketCheck(tC), numOfPassengers(nOP), punished(pun), gotAwayWith(gAW), fullFine(fF), reducedFine(rF), pasArr(pasA), penalty(pen) {	
	
	pasArr = new Passenger*[maxCap]();	//Initialize an empty array
	penalty = new int[maxCap]();	//Initialize an empty array
	
   cout << "A wagon with capacity for " << maxCap <<" passengers, was created " << endl << endl;
}

int Wagon::get_maxCap()const {

	return maxCapacity;
}

void Wagon::inStation(int passEntered, int passExited, int hfT, int hrT, int drT, int tCheck) {	
																		
	numOfPassengers += passEntered;	//Calculate the number of passengers who enter and exit a wagon	
	numOfPassengers -= passExited;										
	
	ticketCheck = tCheck % 2;	//Define the status of the ticket check						
	
	int entCounter = 0, exCounter = 0;
	
	for(int i = 0; i < get_maxCap(); i++) {	//While there is available space in the wagon
	
		if(pasArr[i] == NULL && entCounter < passEntered) {
		
			int hft = hfT % 2 ,hrt = hrT % 2, drt = drT % 2; //Define the ticket status in a boolean way
					
					pasArr[i] = new Passenger(hft,hrt,drt);	//Add a new passenger in the wagon
					entCounter++;	
		}
					//Helps in the randomness of numbers
					hfT++;			
					hrT++;		
					drT++;
	}

	for(int k = 0; k < get_maxCap(); k++) {				
			
		if(penalty[k] == 1) {	//If a ticket check was applied and the passenger didn't have a ticket
						
			delete pasArr[k];	//Remove the passenger from the wagon		
			pasArr[k]=NULL;
		}
	}

	for(int j = 0; j < get_maxCap(); j++) {		

		if(pasArr[j] != NULL && exCounter < passExited) {	//If there are passengers in the wagon
			
			delete pasArr[j];	//Remove a random number of them
			pasArr[j] = NULL;
			exCounter++;
		}
	}
}
//Function that returns the number of passengers in a wagon
int Wagon::get_passengers()const {	
		
	return numOfPassengers;
}

void Wagon::betweenStations(int fF, int rF) {
	
	int tempP = this->get_passengers();	//Save the current number of passengers of the wagon into a temporary variable
	
	punished = 0;	//Initialize the number of the punished passengers
	gotAwayWith = 0;	//Initialize the number of the passengers who avoided the ticket check, without holding a ticket
	
	for(int j = 0; j < get_maxCap(); j++)	//Each time reinitialize the penalty status
		penalty[j] = 0;		
	
	for(int i = 0; i < get_maxCap(); i++)	{	//Repeat the proccess for each passenger
		
		if(pasArr[i] != NULL) {
		
			if(ticketCheck == 1) {	//If ticket check is applied,//the passengers with these ticket statuses should get punished
				
				if((pasArr[i]->get_hft() == 0 && pasArr[i]->get_hrt() == 0 && pasArr[i]->get_drt() == 0) || 
					(pasArr[i]->get_hft() == 0 && pasArr[i]->get_hrt() == 0 && pasArr[i]->get_drt() == 1) || 
					(pasArr[i]->get_hft() == 0 && pasArr[i]->get_hrt() == 1 && pasArr[i]->get_drt() == 0)) {	
															
					punished++;
					penalty[i] = 1;	//Current passenger will get punished
					
					numOfPassengers--;	//Kick passengers off train
					
					if(pasArr[i]->get_drt() == 0)	//If passenger doesn't deserve a reduced fine, he is fined with a full one
						fullFine += fF;
					
					else	//If passenger deserves a reduced fine, he is fined with one
						
						reducedFine += rF;				
					}
			}

			else		//If ticket check is applied,the passengers with these ticket statuses whould get punished, but they got away with it				
				
				if((pasArr[i]->get_hft() == 0 && pasArr[i]->get_hrt() == 0 && pasArr[i]->get_drt() == 0) || 
					(pasArr[i]->get_hft() == 0 && pasArr[i]->get_hrt() == 0 && pasArr[i]->get_drt() == 1) || 
					(pasArr[i]->get_hft() == 0 && pasArr[i]->get_hrt()==1 && pasArr[i]->get_drt() == 0)) {	
																													
					gotAwayWith++;
					penalty[i] = 0;
				}
		}
	}
}

//Function that returns the money of a wagon combining both fine types
int Wagon::get_money()const {			
			
	return fullFine+reducedFine;	
}
//Function that prints the number of passengers that did and din't got punished in each wagon	
void Wagon::printStatistics() {		 
	
	cout << "In the current wagon " << punished << " people got kicked." << endl;
	cout << "In the current wagon " << gotAwayWith << " people din't have a ticket but got away with it." << endl;
}	
//Destructor of the class
Wagon::~Wagon() {		
	
	for(int i = 0; i < maxCapacity; i++)
  		delete pasArr[i];

	delete[] pasArr;
	delete[] penalty;

	cout << "A waggon was destroyed" << endl << endl;
}
