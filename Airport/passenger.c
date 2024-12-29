#define _CRT_SECURE_NO_WARNINGS
// Yuneh - Fall/Winter 2024/25 - Airport Project

// Implementation of passenger ADT

#include "passenger.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//C - Create
PASSENGER CreatePassenger(char* Name) {
	PASSENGER newPassenger;

	strncpy(newPassenger.name, Name, MAX_NAME); 
	CleanNewLineFromString(newPassenger.name);		// validation to keep name proper

	return newPassenger;
}
PASSENGER CopyPassenger(PASSENGER src) {
	return CreatePassenger(src.name);
}

//R - Read
bool WritePassengerToFile(FILE* fp, PASSENGER p) {
	fprintf(fp, "%s\n", p.name);
	return true;
}

PASSENGER ReadPassengerFromFile(FILE* fp) {
	char tempBuffer[MAX_NAME] = { 0 };
	char* result = fgets(tempBuffer, MAX_NAME, fp);
	if (result == NULL) {  // bad things happened
		fprintf(stderr, "error, not able to read name from file\n");
		exit(EXIT_FAILURE);
	}
	return CreatePassenger(tempBuffer);
}

//U - Update


//D - Delete
void DestroyPassenger(PASSENGER Passenger) {	// not really needed in higher up versions but still here just in case
	// nothing to do
}

// Other
bool ComparePassenger(PASSENGER lhs, PASSENGER rhs) {
	return strncmp(lhs.name, rhs.name, MAX_NAME);
}

void PrintPassenger(PASSENGER Passenger) {
	printf("Passenger Name: %s\n", Passenger.name);
}