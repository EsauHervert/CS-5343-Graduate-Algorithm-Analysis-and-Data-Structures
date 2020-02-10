#include <iostream>

using namespace std;

struct Node {
	int val;
	Node * next;
};

class LinkedList {
public:
	Node *head = NULL;
	Node *tail = NULL;
	void add(int);
	void traverse();
	void addN(Node *);
	void insertBeforevv(int, int);
	void insertBeforeNN(Node*, Node*);
	Node *FindNode(int);
	void deleteN(Node*);
	void deletev(int);
};

void LinkedList::addN(Node *N) {
	if (head == NULL) {
		head = N;
		tail = head;
	}
	else {
		tail->next = N;
		tail = N;
	}
}
void LinkedList::add(int v) {
	Node *New = new Node();
	New->val = v;
	New->next = NULL;

	addN(New);
}

void LinkedList::traverse() {
	Node *i = head;
	while (i != NULL) {
		cout << i->val << " ";
		i = i->next;
	}
	cout << endl;
}

void rtraverse(Node* tmp) {
	if (tmp == NULL) {
		cout << endl;
		return;
	}
	else {
		cout << tmp->val << " ";
		rtraverse(tmp->next);
	}
}

void LinkedList::insertBeforeNN(Node *B, Node *New) {
	if (B == head) {
		New->next = head;
		head = New;
		return;
	}
	
	Node *temp = head;
	while (temp->next != B) {
		temp = temp->next;
	}

	temp->next = New;
	New->next = B;
}

Node *LinkedList::FindNode(int v) {
	Node *temp = head;
	while (temp->val != v) {
		temp = temp->next;
	}
	return temp;
}
void LinkedList::insertBeforevv(int v1, int v2) {
	Node *New = new Node();
	New->val = v2;
	Node *B = FindNode(v1);
	insertBeforeNN(B, New);
}
void LinkedList::deleteN(Node *N) {
	if (N == head) {
		head = head->next;
		delete(N);
		return;
	}
	Node *temp = head;
	while (temp->next != N) {
		temp = temp->next;
	}
	temp->next = N->next;
	if (N == tail) {
		tail = temp;
	}
	delete(N);
	return;
}

void LinkedList::deletev(int v) {
	Node *N = FindNode(v);
	deleteN(N);
}

int main() {
	LinkedList L;
	L.add(1);
	L.add(2);
	L.add(3);
	L.add(4);
	L.add(5);

	L.traverse();
	rtraverse(L.head);
	cout << L.head->val << endl;
	cout << L.tail->val << endl;

	L.insertBeforevv(4, 7);

	L.traverse();
	cout << L.head->val << endl;
	cout << L.tail->val << endl;

	L.deletev(3);

	L.traverse();
	cout << L.head->val << endl;
	cout << L.tail->val << endl;

	L.deletev(1);

	L.traverse();
	cout << L.head->val << endl;
	cout << L.tail->val << endl;

	L.deletev(5);

	L.traverse();
	cout << L.head->val << endl;
	cout << L.tail->val << endl;
}