#pragma once

// Yuneh - Fall/Winter 2024/25 - Airport Project
// Airplane ADT


#include "passenger.h"

typedef struct airplane {
	//name
	//destination code
	//seat capacity
	//seats					//try to implement passenger into a linked list before continuing
} AIRPLANE;

typedef struct seats {
	int seatnum;
	STATUS status;
	// PASSENGER passenger;			//this feels wrong to have here
} SEATS;

typedef enum status { EMPTY, FILLED } STATUS;