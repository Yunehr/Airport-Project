#pragma once
// Yuneh - Fall/Winter 2024/25 - Airport Project
// Passenger ADT

//	-Passengers
//		- Flight Class (Economy, Business, **First class (depending on flight)**) 
//		- Name First and Last Name
//		- Seat Number (Rows: A,B,C,etc...)(4 or 6 seats per row)

#include <stdbool.h>
#include <stdio.h>
#include "globals.h"

typedef struct passenger {
	// int seatNum;
	char name[MAX_NAME];
} PASSENGER;


//C - Create
PASSENGER CreatePassenger(char* Name);

//R - Read
bool WritePassengerToFile(FILE* fp, PASSENGER p);
PASSENGER ReadPassengerFromFile(FILE* fp);

//U - Update

//D - Delete
void DestroyPassenger(PASSENGER Passenger);

// Other
bool ComparePassenger(PASSENGER lhs, PASSENGER rhs);
void PrintPassenger(PASSENGER Passenger);