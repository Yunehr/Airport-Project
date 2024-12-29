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
bool AddSeatToAirplane(AIRPLANE* a, SEATS s);

bool RemoveSeatFromClassroom(AIRPLANE* plane, SEATS s);

//R - Read
bool WriteAirplaneToFile(AIRPLANE a, char* filename);
bool ReadAirplaneFromFile(AIRPLANE* a, char* filename);

//U - Update
bool UpgradeSeatInAirplane(AIRPLANE* a, SEATS s);

//D - Delete
bool EmptyAirplane(AIRPLANE* a);
void DestroyAirplane(AIRPLANE a);


// Other
bool PrintAirplane(AIRPLANE a);
bool CompareAirplane(AIRPLANE lhs, AIRPLANE rhs);
int GetCountOfSeatsInAirplane(AIRPLANE a);
bool IsAirplaneFull(AIRPLANE A);
bool IsAirplaneEmpty(AIRPLANE A);
bool IsSeatAvailable(AIRPLANE A, SEATS s);

//bool AddPassengerToSeat(AIRPLANE* a, PASSENGER p, SEATS s); //not sure if this is needed
