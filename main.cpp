#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Train_class.h"

using namespace std;

int main(int argc, char *argv[]) {
	
	int N,maxC,totalW,stations,totalPass,i,in,out;	
	const int fF = 100,rF = 50;	//Fines

	srand(time(NULL));	//Helps in the randomness of numbers

	if (argc > 3) {
		
		N=atoi(argv[1]);
		totalW=atoi(argv[2]);	//Arguments
		maxC=atoi(argv[3]);				
	}

	//Generate random numbers of passengers ,considering the capacity of the wagon
	out = rand() % maxC + 1;
	in = rand() % maxC + 1;				

	if(in < out) {
		
		in = out + 1;	//Passengers who enter are always more than the passengers who exit
	}

	if((in < 0) || (out < 0)) {

		in += 15;	//If rand() returns negative integers
		out += 15;
	}
		
	Train metro(totalW);	//Create the train
	int* arr = new int[totalW];								
			
	for(int j = 0; j < totalW; j++)	//Each wagon is empty at the beggining
		arr[j]=0;
		
	metro.set_activeStations(N);	//Get the number of stations that the train operates
	stations = metro.get_activeStations();	//Return the number of stations that the train operates

	cout << endl << "The train operates for " << stations << " stations" << endl;

	for(i=0; i < stations; i++) {	//Reapeat the proccess for each wagon

		cout << endl << "***Train is in station " << i+1 << " ***" << endl << endl;
		
			metro.operate(maxC,in,out,in,in*i,out*i,out*i,fF,rF,arr);			//The train operates		
	}

	delete[] arr;		
}
