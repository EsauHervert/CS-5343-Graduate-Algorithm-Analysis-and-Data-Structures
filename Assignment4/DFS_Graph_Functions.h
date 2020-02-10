#ifndef DFS_Graph_Functions
#define DFS_Graph_Functions

#include <iostream>

using namespace std;

// This will be used to make the linked lists.
struct Node {
	char vertex;
	Node* next;
};

class LinkedList {
public:
	Node *head = NULL;

	void add(char);
	void addarray(char *, int);
};

// Adding a vertex.
void LinkedList::add(char v) {
	Node *n = new Node();
	n->vertex = v;
	if (head == NULL) {
		head = n;
	}
	else
	{
		Node *temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
	}
}

// So that we can add all the vertices that are
// adjacent to L[i] efficiently.
void LinkedList::addarray(char *A,int n) {
	for (int i = 0; i < n; i++) {
		add(A[i]);
	}
}

// This will be used to traverse.
int index(char *A, int n, char c) {
	for (int i = 0; i < n; i++) {
		if (A[i] == c) {
			return i;
		}
	}
	return -1;
}

// Here we recursively traverse the graph using DFS
// with the Array representation of a graph.
void DFSGraphTraversalA(int A[10][10], int i, bool *transit,
	bool *visited, char *vertices) {

	transit[i] = true;
	for (int j = 0; j < 10; j++) {
		if (j == i) {
			continue;
		}
		else if (A[i][j] == 1) {
			if (transit[j] == false) {
				DFSGraphTraversalA(A, j, transit, visited,
					vertices);
			}
		}
	}
	visited[i] = true;
	cout << vertices[i] << " ";
}

// This will be used to tell us if our traversal was
// complete in the sense that we traversed all the
// vertices.
int Complete(bool *visited) {
	for (int i = 0; i < 10; i++) {
		if (visited[i] == false) {
			return i;
		}
	}
	return -1;
}

// Given that our original traversal algorithm does not take 
// into consideration the fact that the graph may be disconnected,
// We must have a second algorithm that will traverse all the 
// connected components of the graph.
void CDFSGraphTraversalA(int A[10][10], int i, bool *transit,
	bool *visited, char *vertices) {
	cout << "The First Connected Component is: ";
	DFSGraphTraversalA(A, i, transit, visited, vertices);

	// Here we check if we have traversed all the vertices.
	int j = Complete(visited);
	// If we have, then we are done.
	if (j == -1) {
		cout << endl;
		cout << "The Graph is Connected!" << endl;
	}
	// If we haven't, then we go to the first vertex that has not 
	// been visited and do our traversal there to find its connected
	// component. We do this until there are no more vertices unvisited.
	else
	{
		cout << "\nThe Graph is Disconnected!" << endl;;
		cout << "The Other Connected Components are: " << endl;
		while (j != -1) {
			cout << "Connected Component: ";
			DFSGraphTraversalA(A, j, transit, visited, vertices);
			j = Complete(visited);
			cout << endl;
		}
	}
}

// Here we recursively traverse the graph using DFS
// with the Linked List representation of a graph.
void DFSGraphTraversalL(LinkedList *L, int i, bool *transit,
	bool *visited, char *vertices) {

	transit[i] = true;
	int j = 0;
	Node *temp = L[i].head->next;
	while (temp != NULL) {
		j = index(vertices, 10, temp->vertex);
		if (transit[j] == false) {
			DFSGraphTraversalL(L, j, transit, visited, vertices);
		}
		temp = temp->next;
	}
	visited[i] = true;
	cout << vertices[i] << " ";
}

// Same arguments as for the Array representation.
void CDFSGraphTraversalL(LinkedList *L, int i, bool *transit,
	bool *visited, char *vertices) {
	cout << "The First Connected Component is: ";
	DFSGraphTraversalL(L, i, transit, visited, vertices);

	int j = Complete(visited);
	if (j == -1) {
		cout << endl;
		cout << "The Graph is Connected!" << endl;
	}
	else
	{
		cout << "\nThe Graph is Disconnected!" << endl;
		cout << "The Other Connected Components are: " << endl;
		while (j != -1) {
			cout << "Connected Component: ";
			DFSGraphTraversalL(L, j, transit, visited, vertices);
			j = Complete(visited);
			cout << endl;
		}
	}
}

#endif DFS_Graph_Functions