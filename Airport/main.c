// Yuneh - Fall/Winter 2024/25 - Airport Project

//	Airport (multiple planes in dev 2.0)
//		- Airport Code (used to determine destination code) (AITA/ICAO or Made up ones)		// Ff I have time, multiple airports in dev 3.0 
//				- https://en.wikipedia.org/wiki/IATA_airport_code
//		- Airplane / Flight (one Flight/plane only in dev 1.0)
//				- Plane Name (what company made/owns the plane, EX. Air Canada, Dubai Air)
//				- Flight Number (Destination code)
//				- Capacity
//				- Seat availability
//					- Passengers
//						- Flight Class (Economy, Business, **First class (depending on flight)**) 
//						- Name First and Last Name
//						- Seat Number (Rows: A,B,C,etc...)(4 or 6 seats per row)

//	Passengers must be able to:
//		- upgrade/downgrade seats from flight class
//		- change seating arrangement (when displaying seats have X for in use and O for available)
//		- Book multiple seats, and select which seats to book (set a max of 5 seats per reservation)

#include "passenger.h"
#include "flightSeating.h"
#include "seatingList.h"
#include "airplane.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	AIRPLANE* air = (AIRPLANE*)malloc(sizeof(AIRPLANE));
	if (air == NULL) {
		fprintf(stderr, "error allocating memory\n");
		return EXIT_FAILURE;
	}
	
	AIRPLANE newAirplane = ReadAirplaneFromFile(air, "airplane.txt");


	PrintAirplane(newAirplane); // print airplane 

	UpdateSeatInAirplane(&newAirplane, AddPassengerToSeat(10, CreatePassenger("testPassenger2\n")));

	PrintAirplane(newAirplane);

	WriteAirplaneToFile(newAirplane, "airplane.txt"); // write to file
	
	free(air); // free memory
	return 0;
}