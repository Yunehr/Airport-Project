#pragma once
// Yuneh - Fall/Winter 2024/25 - Airport Project
// Passenger ADT

//	-Passengers
//		- Flight Class (Economy, Business, **First class (depending on flight)**) 
//		- Name First and Last Name
//		- Seat Number (Rows: A,B,C,etc...)(4 or 6 seats per row)

#include "globals.h"

typedef struct passenger {
	int seatNum;
	TYPE type;
	char name[MAX_NAME];
} PASSENGER;

typedef enum type { ECON, BUS } TYPE;