#include <iostream>
#include "Passenger_class.h"

using namespace std;
//Constructor of the class
Passenger::Passenger(int f, int r , int d): hasFullT(f), hasReducedT(r), deservesReducedT(d) {	//Passenger has a full ticket//has a reduced ticket//Passenger deserves a reduced ticket						
		
	//cout << "A passenger was created" << endl;   
}
//Function to set the ticket status of a passenger
void Passenger::set(int f, int r, int d) {		
	
	hasFullT = f;
	hasReducedT = r;
	deservesReducedT = d;
}
//Function that returns full ticket status	
int Passenger::get_hft()const {	
	
	return hasFullT;
}
//Function tthat returns reduced ticket status
int Passenger::get_hrt()const {	
	
	return hasReducedT;
}
//Function that returns 1 if a passenger deserves a reduced ticket,else it returns 0
int Passenger::get_drt()const {	
	
	return deservesReducedT;
}
//Destructor of the class
Passenger::~Passenger() {	
	
	//cout << "A passenger was destroyed" << endl;
}

