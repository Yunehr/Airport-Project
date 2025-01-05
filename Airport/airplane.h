#pragma once

// Yuneh - Fall/Winter 2024/25 - Airport Project
// Airplane ADT

#define _CRT_SECURE_NO_WARNINGS
#include "flightSeating.h"
#include "seatingList.h"
#include "globals.h"
#include <stdbool.h>

typedef struct airplane {
	char* nameofplane[MAX_NAME];		//name of the plane
	char* destination[DEST_CODE];	//destination code
	int seatcapacity;
	PLISTNODE seats;					//try to implement passenger into a linked list before continuing
} AIRPLANE;

//C - Create
AIRPLANE CreateAirplane(char* Name, char* Destination, int Capacity);
bool AddSeatToAirplane(AIRPLANE* air, SEATS s);
bool RemoveSeatFromAirplane(AIRPLANE* air, SEATS s);
bool UpdateSeatInAirplane(AIRPLANE* air, SEATS s);

//R - Read
bool WriteAirplaneToFile(AIRPLANE air, char* filename);
AIRPLANE ReadAirplaneFromFile(AIRPLANE* air, char* filename);

//U - Update
bool UpgradeSeatInAirplane(AIRPLANE* air, SEATS s);

//D - Delete
bool EmptyAirplane(AIRPLANE* air);
void DestroyAirplane(AIRPLANE air);


// Other
void PrintAirplane(AIRPLANE air);
bool CompareAirplane(AIRPLANE lhs, AIRPLANE rhs);
int GetCountOfSeatsInAirplane(AIRPLANE air);
bool IsAirplaneFull(AIRPLANE air);
bool IsAirplaneEmpty(AIRPLANE air);

//bool AddPassengerToSeat(AIRPLANE* a, PASSENGER p, SEATS s); //not sure if this is needed
