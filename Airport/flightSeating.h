#pragma once
// Yuneh - Fall/Winter 2024/25 - Airport Project
// Airplane Seating ADT

#include "globals.h"
#include "passenger.h"
#include <stdbool.h>
#include <stdio.h>

typedef enum status {
	EMPTY = 0,
	FILLED
} STATUS;

typedef struct seats {
	int seatnum;
	STATUS status;
	PASSENGER passenger;
} SEATS;

//C - Create
SEATS CreateSeat(int seatNum, PASSENGER p);

//R - Read
bool WriteSeatStatusToFile(FILE* fp, int Status);
int GetSeatStatusFromFile(FILE* fp);

bool WriteSeatToFile(FILE* fp, SEATS s);
SEATS ReadSeatFromFile(FILE* fp, int i);


//U - Update

//D - Delete
void DestroySeat(SEATS Seat);

// Other
bool CompareSeats(SEATS lhs, SEATS rhs);
bool PrintSeat(SEATS Seat);