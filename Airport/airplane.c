// Yuneh - Fall/Winter 2024/25 - Airport Project

// Implementation of the Airplane ADT

#include "airplane.h"
#include "seatingList.h"
#include "globals.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//C - Create
AIRPLANE CreateAirplane(char* Name, char* Destination, int Capacity) {
	AIRPLANE newAirplane;
	strncpy(newAirplane.nameofplane, Name, MAX_NAME);			//name of plane
	CleanNewLineFromString(newAirplane.nameofplane);

	strncpy(newAirplane.destination, Destination, DEST_CODE);	//destination code
	CleanNewLineFromString(newAirplane.destination);

	newAirplane.seatcapacity = Capacity;						//seating capacity
	newAirplane.seats = NULL;									//initialize linked list of seats
	for (int i = 0; i < Capacity; i++) {
		Add(&newAirplane.seats, CreateSeat(i));	//initialize seats
	}
	return newAirplane;
}

bool AddSeatToAirplane(AIRPLANE* air, SEATS s) {	// for now kep SEATS, but might need to be changed
	if (IsAirplaneFull(*air)) {
		fprintf(stderr, "Airplane is full\n");
		return false;
	}
	return Add(&(air->seats), s);
	//return Add(&(air->seats), CreateSeat(int seatnum, PASSENGER p));
}

bool RemoveSeatFromAirplane(AIRPLANE* air, SEATS s) {
	return Remove(&(air->seats), s);
}

bool UpdateSeatInAirplane(AIRPLANE* air, SEATS s) {
	return Update(&(air->seats), s);
}

//R - Read
bool WriteAirplaneToFile(AIRPLANE air, char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "error opening file %s for writing\n", filename);
		return false;
	}
	fprintf(fp, "%s\n", air.nameofplane);						//name
	fprintf(fp, "%s\n", air.destination);						//destination
	fprintf(fp, "%d\n", air.seatcapacity);						//capacity
	bool writeSuccess = WriteListToStream(air.seats, fp);		//seats

	fclose(fp);
	return writeSuccess;
}

AIRPLANE ReadAirplaneFromFile(AIRPLANE* air, char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "error opening file %s for reading\n", filename);
		fclose(fp);
		exit(EXIT_FAILURE); //exit if file not found
	}

	char tempBuffer[MAX_NAME] = { 0 };
	fgets(tempBuffer, MAX_NAME, fp);
	CleanNewLineFromString(tempBuffer);
	//strncpy(air->nameofplane, tempBuffer, MAX_NAME);

	char tempDest[DEST_CODE] = { 0 };
	fgets(tempDest, DEST_CODE, fp);
	CleanNewLineFromString(tempDest);
	//strncpy(air->destination, tempDest, DEST_CODE);

	int capacity = 0;
	fscanf(fp, "%d\n", &capacity);
	//air->seatcapacity = capacity;
	AIRPLANE tempAir = CreateAirplane(tempBuffer, tempDest, capacity); //create temp airplane to add seats to

	for (int i = 1; i <= capacity; i++) {
		if (feof(fp)) break;
		UpdateSeatInAirplane(&tempAir, ReadSeatFromFile(fp, capacity - i)); 
	}
	fclose(fp);
	return tempAir;
}

//U - Update
bool UpgradeSeatInAirplane(AIRPLANE* air, SEATS s) {	
	//TODO: implement	//might not be necessary, can do in user terminal
}


// Other
void PrintAirplane(AIRPLANE air) {
	printf("Airplane:	%s\n", air.nameofplane);
	printf("Destination:	%s\n", air.destination);
	Display(air.seats);
}

bool CompareAirplane(AIRPLANE lhs, AIRPLANE rhs) {	//check name of plane first, then check if destination is the same
	if (strncmp(lhs.nameofplane, rhs.nameofplane, MAX_NAME) == 0) {
		if (strncmp(lhs.destination, rhs.destination, DEST_CODE) == 0) {
			return true;
		}
	}
	return false;
}

int GetCountOfSeatsInAirplane(AIRPLANE air) {
	return air.seatcapacity;
}

bool IsAirplaneFull(AIRPLANE air) {
	return AreSeatsFull(air.seats);
}

bool IsAirplaneEmpty(AIRPLANE air) {
	//return (GetCountOfSeats(air.seats) == 0);	// not correct in current model
}

//D - Delete
bool EmptyAirplane(AIRPLANE* air) {
	//nothing
}

void DestroyAirplane(AIRPLANE air) {
	//nothing
}
