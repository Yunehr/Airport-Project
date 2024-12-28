// Yuneh - Fall/Winter 2024/25 - Airport Project

// Implementation of the Airplane ADT

#include <stdio.h>
#include "airplane.h"
#include "utils.h"


//C - Create
SEATS CreateSeat(int SeatNum, PASSENGER p) {
	SEATS newSeat = { 0 };

	newSeat.seatnum = SeatNum;
	newSeat.status = FILLED;
	newSeat.passenger = p;
}

//R - Read
bool WriteSeatToFile(FILE* fp, SEATS s) {
	switch (s.status) {
	case EMPTY:		fprintf(fp, "EMPTY\n");
					break;	//lets try not giving anything else when empty is flagged
	case FILLED:	fprintf(fp, "FILLED\n");
					WritePassengerToFile(fp, s.passenger);
					break;
	default:		fprintf(stderr, "unknown attendee type\n");
					return false;	// nothing that is intended was written thus false return
	}
	return true;
}
SEATS ReadSeatFromFile(FILE* fp) {
	//TODO: do this, I am too lazy to write it right now
}

//U - Update


//D - Delete
void DestroySeat(SEATS Seat) {
	//nothing to do
}

// Other
bool CompareSeats(SEATS lhs, SEATS rhs) {
	if (lhs.seatnum == rhs.seatnum) {
		return ComparePassenger(lhs.passenger, rhs.passenger);
	}
	return false;
}
void PrintSeat(SEATS Seat) {

}