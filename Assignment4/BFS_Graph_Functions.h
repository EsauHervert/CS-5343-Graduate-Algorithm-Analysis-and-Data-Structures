#ifndef BFS_Graph_Functions
#define BFS_Graph_Functions

#include <iostream>
#include <queue>

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
void LinkedList::addarray(char *A, int n) {
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
void BFSGraphTraversalA(int A[10][10], int i, bool *visited,
	char *vertices) {

	// Start the queue with the starting node.
	queue<int> Traversal;
	visited[i] = true;
	Traversal.push(i);

	// We will add elements to the queue according to their
	// "level', i.e. going one traversal at a time.
	while (Traversal.empty() != true) {
		// We choose a vertex at level l and then add 
		// univisited connected vertices and denote them as
		// level l+1.
		int j = Traversal.front();
		Traversal.pop();
		cout << vertices[j] << " ";
		for (int k = 0; k < 10; k++) {
			if (k == j) {
				continue;
			}
			if (A[j][k] == 1) {
				if (visited[k] == false) {
					visited[k] = true;
					Traversal.push(k);
				}
			}
		}
	}
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
void CBFSGraphTraversalA(int A[10][10], int i, bool *visited,
	char *vertices) {

	cout << "The First Connected Component is: ";
	BFSGraphTraversalA(A, i, visited, vertices);

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
			BFSGraphTraversalA(A, j, visited, vertices);
			j = Complete(visited);
			cout << endl;
		}
	}
}

// Here we recursively traverse the graph using DFS
// with the Linked List representation of a graph.
void BFSGraphTraversalL(LinkedList *L, int i, bool *visited,
	char *vertices) {

	queue<int> Traversal;
	visited[i] = true;
	Traversal.push(i);

	while (Traversal.empty() != true) {
		int j = Traversal.front();
		Traversal.pop();
		cout << vertices[j] << " ";

		Node *temp = L[j].head->next;
		while (temp != NULL) {
			int k = index(vertices, 10, temp->vertex);
			if (visited[k] == false) {
				Traversal.push(k);
				visited[k] = true;
			}
			temp = temp->next;
		}

	}
}

// Same arguments as for the Array representation.
void CBFSGraphTraversalL(LinkedList *L, int i, bool *visited,
	char *vertices) {
	cout << "The First Connected Component is: ";
	BFSGraphTraversalL(L, i, visited, vertices);

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
			BFSGraphTraversalL(L, j, visited, vertices);
			j = Complete(visited);
			cout << endl;
		}
	}
}

#endif BFS_Graph_Functions