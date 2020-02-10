#include "DLLFunctions.h"
#include <iostream>

using namespace std;

int main(){
	// Create a double Linked List with values (1,2,3,4,5)
	DNode *N1 = NULL;
	N1 = new DNode();
	N1->val = 1;

	DNode *N2 = NULL;
	N2 = new DNode();
	N2->val = 2;

	DNode *N3 = NULL;
	N3 = new DNode();
	N3->val = 3;

	DNode *N4 = NULL;
	N4 = new DNode();
	N4->val = 4;

	DNode *N5 = NULL;
	N5 = new DNode();
	N5->val = 5;

	// Link the double Linked list.
	N1->prev = NULL;
	N1->next = N2;
	N2->prev = N1;
	N2->next = N3;
	N3->prev = N2;
	N3->next = N4;
	N4->prev = N3;
	N4->next = N5;
	N5->prev = N4;
	N5->next = NULL;

	// Print the double Linked List fowards and backwards.
	cout << "The linked list fowards is: ";
	Ftraversal(N1);
	cout << "The linked list backwards is: ";
	Btraversal(N5);
}