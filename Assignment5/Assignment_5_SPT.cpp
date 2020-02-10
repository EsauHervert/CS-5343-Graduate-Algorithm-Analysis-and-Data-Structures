#include "SPT_Functions.h"

#include <iostream>
#include <queue>

using namespace std;

int main() {

	// Here is the Adjacency Matrix of the graph.
	int Graph[10][10] = {
	{0,7,11,0,0,0,0,5,0,0},
	{7,0,0,0,9,0,0,0,0,0},
	{11,0,0,0,0,0,0,15,0,0},
	{0,0,0,0,0,15,5,11,0,0},
	{0,9,0,0,0,12,10,0,11,0},
	{0,0,0,15,12,0,11,0,0,0},
	{0,0,0,5,10,11,0,6,10,0},
	{5,0,15,11,0,0,6,0,8,6},
	{0,0,0,0,11,0,10,8,0,10},
	{0,0,0,0,0,0,0,6,10,0} };

	cout << "The Adjacency Matrix of the Graph is: " << endl;

	print(Graph); // Print the Adjacency Matrix.

	char Vertices[10] = { 'A','B','C','D','E','F','G','H','I','J' };

	cout << endl;

	DijkstraSPT(Graph, 0, Vertices);

	cout << "The Adjacency Matrix of the SPT is: " << endl;

	print(Graph);

	
}