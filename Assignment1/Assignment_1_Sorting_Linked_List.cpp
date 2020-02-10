#include "Sorting_Functions_Linked_List.h"
#include <iostream>

using namespace std;

int main() {

	// Linked List 1:
	LinkedList LL1;
	LL1.Add(15);
	LL1.Add(14);
	LL1.Add(13);
	LL1.Add(12);
	LL1.Add(11);
	LL1.Add(10);
	LL1.Add(9);
	LL1.Add(8);
	LL1.Add(7);
	LL1.Add(6);
	LL1.Add(5);
	LL1.Add(4);
	LL1.Add(3);
	LL1.Add(2);
	LL1.Add(1);

	cout << "Linked List 1 is: ";
	traversal(LL1.head);

	cout << "The Select Sorted Linked List 1 is: ";
	LL1.head = SelectSortLL(LL1.head);
	traversal(LL1.head);
	cout << endl << endl;

	// Linked List 2:
	LinkedList LL2;
	LL2.Add(14);
	LL2.Add(4);
	LL2.Add(12);
	LL2.Add(5);
	LL2.Add(7);
	LL2.Add(6);
	LL2.Add(9);
	LL2.Add(11);
	LL2.Add(1);
	LL2.Add(2);
	LL2.Add(8);
	LL2.Add(3);
	LL2.Add(13);
	LL2.Add(10);
	LL2.Add(15);

	cout << "Linked List 2 is: ";
	traversal(LL2.head);

	// Define a structure that will hold the head of the
	// Bubble Sorted List and the number of passes.
	BubbleValues *result = NULL;
	result = BubbleSort(LL2.head);

	cout << "The Bubble Sorted Linked List 2 with " << result->Passes;
	cout << " Passes is: ";
	traversal(result->head);
}