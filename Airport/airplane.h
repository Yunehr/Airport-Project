#pragma once

// Yuneh - Fall/Winter 2024/25 - Airport Project
// Airplane ADT

#include <stdio.h>
#include "passenger.h"

typedef struct airplane {
	//nameofplane
	//destination code
	//seat capacity
	SEATS seats;					//try to implement passenger into a linked list before continuing
} AIRPLANE;

typedef struct seats {
	int seatnum;
	STATUS status;
	PASSENGER passenger;
} SEATS;

typedef enum status { EMPTY, FILLED } STATUS;

//C - Create
SEATS CreateSeat(int seatnum, PASSENGER p);

//R - Read
bool WriteSeatToFile(FILE* fp, SEATS s);
SEATS ReadSeatFromFile(FILE* fp);

//U - Update

//D - Delete
void DestroySeat(SEATS Seat);

// Other
bool CompareSeats(SEATS lhs, SEATS rhs);
void PrintSeat(SEATS Seat);