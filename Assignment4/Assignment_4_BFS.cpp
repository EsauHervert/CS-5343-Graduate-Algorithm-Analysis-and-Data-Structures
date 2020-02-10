#include "BFS_Graph_Functions.h"

#include <iostream>

using namespace std;

int main() {

	// Adjacency Matrix representation of Graph 1.
	int AG1[10][10] = {
	{0,1,0,0,0,1,0,0,0,1},
	{1,0,1,0,0,0,0,1,0,0},
	{0,1,0,1,0,0,1,0,1,0},
	{0,0,1,0,1,0,0,1,0,0},
	{0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0},
	{0,0,1,0,0,1,0,1,0,0},
	{0,1,0,1,0,0,1,0,1,0},
	{0,0,1,0,0,0,0,1,0,1},
	{1,0,0,0,1,0,0,0,1,0} };

	//LinkedList Representation of Graph 1.
	LinkedList LG1[10];
	char A1[4] = { 'A','B','F','J' };
	char B1[4] = { 'B','A','C','H' };
	char C1[5] = { 'C','B','D','G','I' };
	char D1[4] = { 'D','C','E','H' };
	char E1[3] = { 'E','D','J' };
	char F1[3] = { 'F','A','G' };
	char G1[4] = { 'G','C','F','H' };
	char H1[5] = { 'H','B','D','G','I' };
	char I1[4] = { 'I','C','H','J' };
	char J1[4] = { 'J','A','E','I' };
	LG1[0].addarray(A1, 4);
	LG1[1].addarray(B1, 4);
	LG1[2].addarray(C1, 5);
	LG1[3].addarray(D1, 4);
	LG1[4].addarray(E1, 3);
	LG1[5].addarray(F1, 3);
	LG1[6].addarray(G1, 4);
	LG1[7].addarray(H1, 5);
	LG1[8].addarray(I1, 4);
	LG1[9].addarray(J1, 4);

	// Adjacency Matrix representation of Graph 2.
	int AG2[10][10] = {
	{0,1,0,0,0,1,0,0,0,1},
	{-1,0,1,0,0,0,0,1,0,0},
	{0,-1,0,1,0,0,1,0,1,0},
	{0,0,-1,0,1,0,0,-1,0,0},
	{0,0,0,-1,0,0,0,0,0,-1},
	{-1,0,0,0,0,0,-1,0,0,0},
	{0,0,-1,0,0,1,0,-1,0,0},
	{0,-1,0,1,0,0,1,0,-1,0},
	{0,0,-1,0,0,0,0,1,0,-1},
	{-1,0,0,0,1,0,0,0,1,0} };

	//LinkedList Representation of Graph 2.
	LinkedList LG2[10];
	char A2[4] = { 'A','B','F','J' };
	char B2[3] = { 'B','C','H' };
	char C2[4] = { 'C','D','G','I' };
	char D2[2] = { 'D','E' };
	char E2[1] = { 'E' };
	char F2[1] = { 'F' };
	char G2[2] = { 'G', 'F' };
	char H2[3] = { 'H','D','G' };
	char I2[2] = { 'I','H' };
	char J2[3] = { 'J','E','I' };
	LG2[0].addarray(A2, 4);
	LG2[1].addarray(B2, 3);
	LG2[2].addarray(C2, 4);
	LG2[3].addarray(D2, 2);
	LG2[4].addarray(E2, 1);
	LG2[5].addarray(F2, 1);
	LG2[6].addarray(G2, 2);
	LG2[7].addarray(H2, 3);
	LG2[8].addarray(I2, 2);
	LG2[9].addarray(J2, 3);

	// Adjacency Matrix representation of Graph 3.
	int AG3[10][10] = {
	{0,1,1,0,0,0,0,0,0,0},
	{1,0,1,0,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,1},
	{0,0,0,0,0,1,0,0,0,0},
	{0,0,0,1,1,0,1,0,1,0},
	{0,0,0,1,0,1,0,1,1,0},
	{0,0,0,1,0,0,1,0,1,1},
	{0,0,0,0,0,1,1,1,0,1},
	{0,0,0,1,0,0,0,1,1,0} };

	//LinkedList Representation of Graph 3.
	LinkedList LG3[10];
	char A3[3] = { 'A','B','C' };
	char B3[3] = { 'B','A','C' };
	char C3[3] = { 'C','A','B' };
	char D3[5] = { 'D','F','G','H','J' };
	char E3[2] = { 'E','F' };
	char F3[5] = { 'F','D','E','G','I' };
	char G3[5] = { 'G','D','F','H','I' };
	char H3[5] = { 'H','D','G','I','J' };
	char I3[5] = { 'I','F','G','H','J' };
	char J3[4] = { 'J','D','H','I' };
	LG3[0].addarray(A3, 3);
	LG3[1].addarray(B3, 3);
	LG3[2].addarray(C3, 3);
	LG3[3].addarray(D3, 5);
	LG3[4].addarray(E3, 2);
	LG3[5].addarray(F3, 5);
	LG3[6].addarray(G3, 5);
	LG3[7].addarray(H3, 5);
	LG3[8].addarray(I3, 5);
	LG3[9].addarray(J3, 4);

	// The vertices will be stored in this array.
	char Vertices[10] = { 'A','B','C','D','E','F',
	'G','H','I','J' };

	bool Avisited1[10] = { 0,0,0,0,0,0,0,0,0,0 };

	cout << "BFS traversal of Graph 1 using Adjancency Matrix." << endl;
	CBFSGraphTraversalA(AG1, 0, Avisited1, Vertices);

	cout << endl;

	bool Lvisited1[10] = { 0,0,0,0,0,0,0,0,0,0 };

	cout << "BFS traversal of Graph 1 using Linked List." << endl;
	CBFSGraphTraversalL(LG1, 0, Lvisited1, Vertices);

	cout << endl;

	bool Avisited2[10] = { 0,0,0,0,0,0,0,0,0,0 };

	cout << "DFS traversal of Graph 2 using Adjancency Matrix." << endl;
	CBFSGraphTraversalA(AG2, 0, Avisited2, Vertices);

	cout << endl;

	bool Lvisited2[10] = { 0,0,0,0,0,0,0,0,0,0 };

	cout << "DFS traversal of Graph 2 using Linked List." << endl;
	CBFSGraphTraversalL(LG2, 0, Lvisited2, Vertices);

	cout << endl;

	bool Avisited3[10] = { 0,0,0,0,0,0,0,0,0,0 };

	cout << "DFS traversal of Graph 3 using Adjancency Matrix." << endl;
	CBFSGraphTraversalA(AG3, 0, Avisited3, Vertices);

	cout << endl;

	bool Lvisited3[10] = { 0,0,0,0,0,0,0,0,0,0 };

	cout << "DFS traversal of Graph 3 using Linked List." << endl;
	CBFSGraphTraversalL(LG3, 0, Lvisited3, Vertices);
}