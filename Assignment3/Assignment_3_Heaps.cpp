#include "Heap_Functions.h"

#include <iostream>

using namespace std;

int main() {
	// Here is the heap.
	HeapTwenty H;

	// We add numbers 1-15 in random order.
	H.add(1);
	H.add(13);
	H.add(10);
	H.add(3);
	H.add(6);
	H.add(14);
	H.add(7);
	H.add(15);
	H.add(12);
	H.add(4);
	H.add(9);
	H.add(5);
	H.add(2);
	H.add(11);
	H.add(8);

	H.printNH(); // Print the unheaped array.
	H.printT();
	cout << endl;

	// Make the heap and print it.
	H.Heapify();
	H.print();
	H.printT();
	cout << endl;

	// Now, sort the heap and print.
	H.sort();
	H.printsort();

	// Print the resulting array.
	cout << endl;
	H.printNH();
	H.printT();
}