CC=g++
CFLAGS=-g
OBJECTS=main.o Passenger_constr.o Wagon_constr.o Train_constr.o

train_sim: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o train_sim

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

Passenger_constr.o: Passenger_constr.cpp
	$(CC) $(CFLAGS) -c Passenger_constr.cpp -o Passenger_constr.o

Wagon_constr.o: Wagon_constr.cpp
	$(CC) $(CFLAGS) -c Wagon_constr.cpp -o Wagon_constr.o


Train_constr.o: Train_constr.cpp
	$(CC) $(CFLAGS) -c Train_constr.cpp -o Train_constr.o


.PHONY: clean
clean:
	rm train_sim $(OBJECTS) 

