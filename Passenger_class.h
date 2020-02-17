#ifndef PASSENGER_CLASS_H
#define PASSENGER_CLASS_H

class Passenger {

    int hasFullT;
    int hasReducedT;
    int deservesReducedT;

  public:

    Passenger(int f = 0, int r = 0, int d = 0);
    ~Passenger();

    void set(int f, int r, int d);
    int get_hft()const;
	int get_hrt()const;
	int get_drt()const;
};
#endif
