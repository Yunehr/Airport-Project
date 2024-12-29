#define _CRT_SECURE_NO_WARNINGS
// Yuneh - Fall/Winter 2024/25 - Airport Project

// Implementation of Airplane Seating ADT

#include "flightSeating.h"
#include "passenger.h"
#include "utils.h"
#include "globals.h"
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

SEATS CopySeat(SEATS src) {
	SEATS newSeat = { 0 };
	newSeat.seatnum = src.seatnum;
	newSeat.status = src.status;
	newSeat.passenger = CopyPassenger(src.passenger);
	return newSeat;
}

//R - Read
bool WriteSeatStatusToFile(FILE* fp, int Status) {
	switch (Status) {
	case EMPTY:		fprintf(fp, "%s\n", "EMPTY");
		break;
	case FILLED:	fprintf(fp, "%s\n", "FILLED");
		break;
	default:	
		return false;	// if code gets to default, then seat status was not written to file
	}
	return true;
}

int GetSeatStatusFromFile(FILE* fp) {
	int S;

	char tempBuffer[MAX_STATUS] = { 0 };
	char* result = fgets(tempBuffer, MAX_STATUS, fp);
	if (result == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to read SeatStatus from file\n");
		exit(EXIT_FAILURE);
	}
	CleanNewLineFromString(tempBuffer);

	if (strncmp(tempBuffer, "FILLED", MAX_STATUS))
		return FILLED;
	if (strncmp(tempBuffer, "EMPTY", MAX_STATUS))
		return EMPTY;


	//if it gets to here there is an error
	fprintf(stderr, "error, SeatStatus Corrupted");
	exit(EXIT_FAILURE);
}



bool WriteSeatToFile(FILE* fp, SEATS s) { //TODO:
	WriteSeatStatusToFile(fp, s.status);

	switch (s.status) {
	case EMPTY:
		return true;
	case FILLED:	WritePassengerToFile(fp, s.passenger);
		return true;
	default:
		break;
	}

	return false;
}


SEATS ReadSeatFromFile(FILE* fp, int i) { 
	SEATS newSeat = { 0 };
	newSeat.seatnum = i;		// seat number
	
	newSeat.status = GetSeatStatusFromFile(fp);		// FILLED or EMPTY

	if (newSeat.status == FILLED) {
		newSeat.passenger = ReadPassengerFromFile(fp);	// if FILLED, who is sitting in that seat
	}

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