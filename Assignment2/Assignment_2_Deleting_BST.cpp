#include "Binary_Search_Tree_Functions.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

/**************************************************************************/
	// We initialize a new Binary tree.
	// This Binary tree we will use the predecessor to delete.
	Binary_Search_Tree B1P;

	// This vector holds the values that the binary tree will have.
	// The order is the order that they are to be added to the tree.
	vector<int> A = { 40, 60, 20, 80, 50, 10, 30, 15,
		5, 35, 25, 45, 55, 70, 90, 32, 33, 48, 46 };

	// We add this vector to this function that will add the individual
	// numbers in the order of the vector.
	B1P.addVector(A);

	// Traverse the tree in order.
	cout << "Here is the In-Order traversal of the binary tree: ";
	cout << endl;
	B1P.In_Order_Traversal();
	cout << endl << endl;
/**************************************************************************/

/**************************************************************************/
	// Now to delete using the predecessor.
	cout << "We will now delete two nodes, one after the other, ";
	cout << "using the predecessor." << endl;
	
	// Find the node that contains the value 40.
	Node *D1P = FindNode(40, B1P.root);

	// Delete this node and replace it with its predecessor.
	cout << "Deleting the Node with value 40 in the tree." << endl;;
	B1P.Delete_Predecessor(D1P);

	// Now traverse the tree.
	cout << "Here is the In-Order traversal of the new tree: " << endl;
	B1P.In_Order_Traversal();
	cout << endl << endl;

	// Find the node that contains the value 40.
	Node *D2P = FindNode(20, B1P.root);

	// Delete this node and replace it with its predecessor.
	cout << "Deleting the Node with value 20 in the tree." << endl;
	B1P.Delete_Predecessor(D2P);

	// Now traverse the tree.
	cout << "Here is the In-Order traversal of the new tree: " << endl;
	B1P.In_Order_Traversal();
	cout << endl << endl;
/**************************************************************************/

	cout << "------------------------------------------------------------";
	cout << endl;

/**************************************************************************/
	// We initialize a new Binary tree.
	// This Binary tree we will use the predecessor to delete.
	Binary_Search_Tree B1S;

	// We add the previous vector to this function that will add the
	// individual numbers in the order of the vector.
	B1S.addVector(A);

	// Traverse the tree in order.
	cout << "Let us reconstruct the tree." << endl;
	cout << "We will use this new tree to do deletion with succession.";
	cout << endl;
	cout << "Here is the In-Order traversal of the binary tree: " << endl;
	B1S.In_Order_Traversal();
	cout << endl << endl;
/**************************************************************************/

/**************************************************************************/
	// Now to delete using the successor.
	cout << "We will now delete two nodes, one after the other, ";
	cout << "using the successor." << endl;

	// Find the node that contains the value 40.
	Node *D1S = FindNode(40, B1S.root);

	// Delete this node and replace it with its predecessor.
	cout << "Deleting the Node with value 40 in the tree." << endl;;
	B1S.Delete_Successor(D1S);

	// Now traverse the tree.
	cout << "Here is the In-Order traversal of the new tree: " << endl;
	B1S.In_Order_Traversal();
	cout << endl << endl;

	// Find the node that contains the value 40.
	Node *D2S = FindNode(20, B1S.root);

	// Delete this node and replace it with its predecessor.
	cout << "Deleting the Node with value 20 in the tree." << endl;
	B1S.Delete_Successor(D2S);

	// Now traverse the tree.
	cout << "Here is the In-Order traversal of the new tree: " << endl;
	B1S.In_Order_Traversal();
	cout << endl << endl;
}