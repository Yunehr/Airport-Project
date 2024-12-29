#pragma once
#include "flightSeating.h"
#include <stdbool.h>


// prog71990-f24 - steveh - week10
// linked list interface
typedef struct listnode {
	SEATS data;
	struct listnode* next;
} LISTNODE, * PLISTNODE;


bool Add(PLISTNODE* list, SEATS s);


bool Remove(PLISTNODE* list, SEATS s);


void Display(PLISTNODE list);
bool WriteListToStream(PLISTNODE list, FILE* fp);

int GetCountOfSeats(PLISTNODE list);
bool Empty(PLISTNODE* list);

/// <summary>/// /// </summary>/// <param name="list"></param>
void DestroyList(PLISTNODE* list);