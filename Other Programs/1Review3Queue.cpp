#include <iostream>

using namespace std;

struct Node {
	int val;
	int index;
	Node *next;
};

class LLQueue {
public:
	Node *f = new Node();
	Node *r = f;

	int size();
	bool empty();
	int front();
	void enqueue(int);
	void dequeue();
	void traverse();
};

int LLQueue::size() {
	return (r->index - f->index);
}

bool LLQueue::empty() {
	if (f == r) {
		return 1;
	}
	else {
		return 0;
	}
}

int LLQueue::front() {
	return f->next->val;
}

void LLQueue::enqueue(int v) {
	Node *New = new Node();
	New->val = v;
	New->index = r->index;
	if (f == NULL) {
		f->next = New;
		r = New;
	}
	else {
		r->next = New;
		r = New;
		r->index++;
	}
}

void LLQueue::dequeue() {
	if (f == NULL) {
		cout << "Queue Empty!" << endl;
	}
	else {
		Node *temp = f->next;
		cout << temp->val << endl;
		f->next = temp->next;
		temp->next = NULL;
		delete(temp);
	}
}

void LLQueue::traverse() {
	if (f == NULL) {
		cout << "Queue Empty!" << endl;
	}
	else if (f->next == r) {
		cout << f->val << endl;
	}
	else {
		Node *temp = f->next;
		while (temp != r) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout <<temp->val << endl;
	}
}

class Queue {
public:
	int A[21];
	int f = 0;
	int r = 0;

	int size();
	bool empty();
	int front();
	void enqueue(int);
	void dequeue();
	void traverse();
};

int Queue::size() {
	if (r >= f) {
		return r - f;
	}
	else {
		return (r + 21) - f;
	}
}

bool Queue::empty() {
	if (f == r) {
		return 1;
	}
	else {
		return 0;
	}
}

int Queue::front() {
	if (f == r) {
		cout << "Queue Empty!" << endl;
		return -1;
	}
	else {
		return A[f];
	}
}

void Queue::enqueue(int v) {
	if ((r + 1) % 21 == f) {
		cout << "Queue Full!" << endl;
	}
	else {
		A[r] = v;
		r = (r + 1) % 21;
	}
}

void Queue::dequeue() {
	if (f == r) {
		cout << "Queue Empty!" << endl;
	}
	else {
		cout << A[f] << endl;
		f = (f + 1) % 21;
	}
}

void Queue::traverse() {
	if (f == r) {
		cout << "Queue Empty!" << endl;
	}
	int i = f;
	while ((i + 1) % 21 != r) {
		cout << A[i] << " ";
		i++;
	}
	cout << A[((r - 1) + 21) % 21] << endl;
}

int main() {
	/*
	Queue Q1;
	//cout << "1. " << endl;
	//cout << Q1.size() << endl;
	//cout << Q1.empty() << endl;

	//cout << "2. " << endl;

	for (int i = 0; i < 20; i++) {
		Q1.enqueue(i + 1);
		//cout << Q1.size() << " ";
	}
	//cout << endl;

	//cout << "3. " << endl;

	//cout << Q1.front() << endl;
	Q1.traverse();

	//cout << "4. " << endl;

	Q1.dequeue();

	//Q1.traverse();


	Q1.dequeue();
	Q1.dequeue();
	Q1.dequeue();

	//Q1.traverse();


	Q1.enqueue(27);
	Q1.traverse();
	*/

	LLQueue Q2;
	cout << "1. " << endl;
	cout << Q2.size() << endl;
	cout << Q2.empty() << endl;

	cout << "2. " << endl;

	for (int i = 0; i < 20; i++) {
		Q2.enqueue(i + 1);
		cout << Q2.size() << " ";
	}
	cout << endl;

	cout << "3. " << endl;

	cout << Q2.front() << endl;
	Q2.traverse();

	cout << "4. " << endl;

	Q2.dequeue();

	Q2.traverse();


	Q2.dequeue();
	Q2.dequeue();
	Q2.dequeue();

	Q2.traverse();


	Q2.enqueue(27);
	Q2.traverse();
}