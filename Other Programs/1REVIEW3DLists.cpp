#include <iostream>

using namespace std;

struct DNode {
	int val;
	DNode *prev;
	DNode *next;
};

class DLinkedList {
public:
	DNode *head = NULL;
	DNode *tail = NULL;
	void addv(int);
	void traverse();
	void revTraverse();
	void insertBefore(DNode *, DNode *);
	void insertBeforevv(int, int);
	DNode *FindNode(int);
	void remove(DNode *);
	void removev(int);

};

void DLinkedList::addv(int v) {
	DNode *New = new DNode();
	New->val = v;
	if (head == NULL) {
		head = New;
		tail = New;
	}
	else {
		tail->next = New;
		New->prev = tail;
		tail = New;
	}
}

void DLinkedList::traverse(){
	DNode *temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

void DLinkedList::revTraverse() {
	DNode *temp = tail;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->prev;
	}
	cout << endl;
}

DNode *middle(DNode *head, DNode *tail) {
	if (head->next == tail->prev) {
		return head->next;
	}
	else if (head == tail->prev) {
		return NULL;
	}
	else {
		middle(head->next, tail->prev);
	}
}

void DLinkedList::insertBefore(DNode *New, DNode *Old) {
	DNode *Bb = Old->prev;
	Old->prev = New;
	New->next = Old;
	New->prev = Bb;
	Bb->next = New;
}

DNode *DLinkedList::FindNode(int v) {
	DNode *temp = head;
	while (temp->val != v && temp != tail) {
		temp = temp->next;
	}
	if (temp->val == v) {
		return temp;
	}
	else {
		return NULL;
	}

}

void DLinkedList::insertBeforevv(int N, int O) {
	DNode *Old = FindNode(O);
	DNode *New = new DNode();
	New->val = N;
	insertBefore(New, Old);
}

void DLinkedList::remove(DNode *N) {
	if (N == head) {
		head = head->next;
		head->prev = NULL;
		delete(N);
	}
	else if (N == tail) {
		tail = tail->prev;
		tail->next = NULL;
		delete(N);
	}
	else {
		N->prev->next = N->next;
		N->next->prev = N->prev;
		delete(N);
	}
}

void DLinkedList::removev(int v) {
	DNode *N = FindNode(v);
	remove(N);
}

int max(int v1, int v2) {
	if (v1 > v2) {
		return v1;
	}
	else {
		return v2;
	}
}
int Largest(DNode *temp) {
	if (temp == NULL) {
		return NULL;
	}
	else if (temp->next == NULL) {
		return temp->val;
	}
	else {
		return max(temp->val, Largest(temp->next));
	}
}
int main() {
	DLinkedList D;
	D.addv(1);
	D.addv(2);
	D.addv(3);
	D.addv(4);
	D.addv(5);
	
	D.traverse();
	D.revTraverse();
	DNode *M = middle(D.head, D.tail);
	cout << M->val << endl;

	cout << Largest(D.head) << endl;

	D.insertBeforevv(7, 4);

	D.traverse();

	cout << Largest(D.head) << endl;

	D.removev(3);

	D.traverse();

	D.remove(D.head);

	D.traverse();

	D.remove(D.tail);

	D.traverse();
}