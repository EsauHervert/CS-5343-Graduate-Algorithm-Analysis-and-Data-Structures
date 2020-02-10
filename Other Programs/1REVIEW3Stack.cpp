#include <iostream>

using namespace std;

struct Node {
	int val;
	int index = 0;
	Node *next;
};

class LLStack {
public:
	Node *Top = new Node();

	int top();
	int size();
	bool empty();
	void push(int);
	void pop();
	void traverse();
};

int LLStack::size() {
	return Top->index;
}

int LLStack::top() {
	if (Top->index != 0) {
		return Top->val;
	}
	else {
		cout << "Stack Empty!";
		return -1;
	}
}

bool LLStack::empty() {
	if (Top->index == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void LLStack::push(int v) {
	Node *New = new Node();
	New->val = v;
	if (Top == NULL) {
		Top = New;
		Top->index++;
	}
	else {
		New->index = Top->index++;
		New->next = Top;
		Top = New;
		Top->index++;
	}
}

void LLStack::pop() {
	if (Top == NULL) {
		cout << "Stack Empty!";
	}
	else {
		cout << Top->val;
		Node *temp = Top;
		Top = Top->next;
		temp->next = NULL;
		delete (temp);
	}
}

void LLStack::traverse() {
	Node *temp = Top;

	while (temp->next != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

class Stack {
public:
	int A[20];
	int t = -1;

	int top() {
		if (t != -1) {
			return A[t];
		}
	}

	int size() {
		return (t + 1);
	}
	
	bool empty() {
		if (t == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	void push(int);
	void pop();

};

void Stack::push(int v) {
	if (t == 19) {
		cout << "Stack Full!";
	}
	else {
		A[t + 1] = v;
		t = t + 1;
	}
}

void Stack::pop() {
	if (t == -1) {
		cout << "Stack Empty!";
	}
	else {
		cout << A[t];
		t = t - 1;
	}
}

int main() {
	/*
	Stack S1;

	cout << S1.empty() << endl;

	for (int i = 0; i < 20; i++) {
		S1.push(i + 1);
		cout << S1.size() << " ";
	}
	cout << endl;
	cout << S1.empty() << endl;
	cout << S1.size() << endl;

	S1.push(7);
	cout << endl;
	S1.pop();
	cout << endl;
	cout << S1.top() << endl;
	*/

	LLStack S2;

	cout << S2.empty() << endl;
	cout << S2.size() << endl;

	for (int i = 0; i < 20; i++) {
		S2.push(i + 1);
		cout << S2.top() << " ";
	}

	cout << endl;
	cout << S2.empty() << endl;
	cout << S2.size() << endl;

	S2.push(7);
	cout << endl;

	S2.traverse();

	S2.pop();
	cout << endl;
	cout << S2.top() << endl;
}