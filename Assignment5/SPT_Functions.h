#ifndef SPT_Functions
#define SPT_Functions

#include <iostream>
#include <queue>

using namespace std;

// Due to the fact that passing a queue through
// a function does not change the queue, we need
// to declare a structure so that we can modify
// the queue and return the modified queue.
struct Return {
	queue <char> Queue;
	char character;
};

// We will use this so that we can kinda have a 
// "Global variable" but it be dependent on the
// Graph given.
int maxvalue(int A[10][10]) {
	int max = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (A[i][j] > max) {
				max = A[i][j];
			}
		}
	}
	return max;
}

// Will be used to get the index of a character.
int getIndex(char c, char * vertices) {
	for (int i = 0; i < 10; i++) {
		if (vertices[i] == c) {
			return i;
		}
	}
	return -1;
}

// This function will take a queue with some distances associated
// with it and return a smaller queue with the smallest element
// removed.
// I choose this over a priority queue do to the approach I took
// in implementing Dijkstra's Algorithm.
Return emptymin(queue <char> Q, int *distance, char *vertices) {

	// So we can dequeue but still hold values.
	queue <char> temp; 

	// Initialize the first element to be the smallest.
	int minindex = getIndex(Q.front(), vertices);
	int min = distance[minindex];
	char c;
	int i = 0;

	// Traverse the queue to find the smallest value.
	while (!Q.empty()) {
		c = Q.front();
		i = getIndex(c, vertices);
		Q.pop();
		temp.push(c);


		if (distance[i] < min) {
			min = distance[i];
			minindex = i;
		}
	}

	// vertex of the smallest value.
	char minchar = vertices[minindex];

	// Restore the queue without the smallest value.
	while (!temp.empty()) {
		c = temp.front();
		temp.pop();
		if (c == minchar) {
			continue;
		}
		Q.push(c);

	}

	// Return the vertex and the modified queue.
	Return R;
	R.Queue = Q;
	R.character = minchar;
	return R;
}

// This function will determine whether or not a vertex is
// incident to another using the Adjacency Matrix.
bool Incident(int A[10][10], int v, int n) {
	if (A[v][n] == 0) { return false; }
	else { return true; }
}

// Here is were we do the bulk of the work.
void DijkstraSPT(int A[10][10], int s, char* vertices) {

	// This queue will be used to travel through the graph.
	// We will update based on distance.
	queue <char> Q;

	// This array will contain the parent of a given vertex.
	int parent[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

	// This will be the distances. Here -1 represents infinity.
	int distance[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

	// Some local variables.
	int dist = 0;
	char u;
	int uindex;
	int max = maxvalue(A);
	int min;
	int minindex;
	Return R;

	// Start by adding the initial vertex.
	Q.push(vertices[s]);

	// Make the distance at the starting node to be 0.
	distance[s] = 0;

	// Go through the graph until everything has been checked.
	while (!Q.empty()) {
		// Take out the smallest element in the queue
		// and modify the queue.
		R = emptymin(Q, distance, vertices);
		u = R.character;
		Q = R.Queue;
		uindex = getIndex(u, vertices);

		// Some initialized values.
		min = max + 1;
		minindex = -1;

		// Here will will visit the neighbouring vertices of the
		// current node and update the distances accordingly.
		for (int n = 0; n < 10; n++) {
			if (Incident(A, uindex, n)) {
				dist = distance[uindex] + A[uindex][n];
				// If the new distance is smaller, update it.
				if (dist < distance[n] || distance[n] < 0) {
					distance[n] = dist;
					parent[n] = uindex; // Update parent.
					Q.push(vertices[n]);
				}
			}
		}
	}

	// Using the parent array, we modify the Adjacency Matrix
	// to now be the Adjacency Matrix of the SPT.
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (parent[j] == i || parent[i] == j) {
				continue;
			}
			else {
				A[i][j] = 0;
			}
		}
	}
}

// This function will print the Adjacency Matrix of a graph.
void print(int A[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << A[i][j] << "	";
		}
		cout << endl << endl;
	}
}
#endif SPT_Functions
