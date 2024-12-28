#define _CRT_SECURE_NO_WARNINGS
// Yuneh - Fall/Winter 2024/25 - Airport Project

// Implementation of Airplane Seating ADT

#include "flightSeating.h"
#include "passenger.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//C - Create
SEATS CreateSeat(int seatNum, PASSENGER p) {
	SEATS newSeat = { 0 };

	newSeat.seatnum = seatNum;
	newSeat.status = FILLED; 
	newSeat.passenger = p;

	return newSeat; 
}

//R - Read
bool WriteSeatToFile(FILE* fp, SEATS s) { //TODO:
	
	return false;
}
SEATS ReadSeatFromFile(FILE* fp) { //TODO:
	SEATS newSeat = { 0 };

	return newSeat;
}

//U - Update

//D - Delete
void DestroySeat(SEATS Seat) {
	// nothing
}

// Other
bool CompareSeats(SEATS lhs, SEATS rhs) {
	if (lhs.seatnum == rhs.seatnum) {
		if (lhs.status == rhs.status)
			return ComparePassenger(lhs.passenger, rhs.passenger);
		return true;
	}
	return false;
}

bool PrintSeat(SEATS Seat) { 
	// seat number				// can make it more fancy later
	printf("Seat Number:	%d\n", Seat.seatnum);

	if (Seat.status == FILLED) {
		PrintPassenger(Seat.passenger);
		return true;
	}
	printf("Seat EMPTY");
	return true;
}