Personal Creation of a Project we did in class

- Dev 1.0 and 2.0 will be written in C, using what I have currently learned
- Dev 3.0 or higher will be written using an Object-Oriented language in April 2025

Overview of Project:
- Airport (multiple planes in dev 2.0)
  - Airport Code (used to determine destination code) (AITA/ICAO or Made up)		//If I have time, multiple airports
     - https://en.wikipedia.org/wiki/IATA_airport_code
  - Airplane / Flight (one Flight/plane only in dev 1.0)
    - Plane Name (what company made/owns the plane, EX. Air Canada, Dubai Air)
    - Flight Number (Destination code)
    - Seat availability (O for available, X for Not Available)
    - Passengers
      - Flight Class (Economy, Business, **First class (depending on flight)**)
      - Name First and Last Name
      - Seat Number (Rows: A,B,C,etc...)(4 or 6 seats per row)

  - Passengers must be able to:
    - upgrade/downgrade seats from flight class
    - change seating arrangement (when displaying seats have X for in use and O for available)
    - Book multiple seats, and select which seats to book (set a max of 5 seats per reservation)

Dev Update 1.0.0: Dec 21, 2024
- Created Repository

Dev Update 1.1.0: Dec 22, 2024
- Basic Tombstone signature
- Commented requirements into main.c and top of README
- Created: (Empty Files)
  - displayUI.c, displayUI.h
  - airplane.c, airplane.h
  - passenger.c, passenger.h
- Included:
  - globals.h
  - utils.h, utils.c (utils library used in previous projects)
- Completed:
  - Passenger ADT
   

  
