#include "flightSeating.h"
#include "seatingList.h"
#include <stdio.h>
#include <stdlib.h>

//prog71990-f24 - steveh - week10
// linkedlist impl

bool Add(PLISTNODE* list, SEATS s) {
	PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));
	if (!newNode) {
		fprintf(stderr, "error allocating memory\n");
		return false;
	}
	else {
		newNode->data = CopySeat(s);
		newNode->next = *list;
		*list = newNode;
		return true;
	}
}

bool Remove(PLISTNODE* list, SEATS s) {
	PLISTNODE current = *list;
	if (current != NULL && CompareSeats(current->data, s)) {
		*list = current->next;
		free(current);
		return true;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareSeats(current->data, s)) {
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return false;			// we hit end of list and did not match
	else {	// we found item in list
		prev->next = current->next;
		free(current);
		return true;
	}
}

void Display(PLISTNODE list) {
	PLISTNODE current = list;
	while (current != NULL) {
		PrintSeat(current->data);
		current = current->next;
	}
}
bool WriteListToStream(PLISTNODE list, FILE* fp) {
	PLISTNODE current = list;
	while (current != NULL) {
		if (!WriteSeatToFile(fp, current->data))
			return false;
		current = current->next;
	}
	return true;
}

int GetCountOfSeats(PLISTNODE list) {
	int count = 0;
	PLISTNODE current = list;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

bool Empty(PLISTNODE* list) {
	DestroyList(list);
	*list = NULL;
}

void DestroyList(PLISTNODE* list) {
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		DestroySeat(current->data);	//TODO: We did something in other versions that fixed this
		current = current->next;
		free(tmp);
	}
}