#ifndef DLinked_List_H
#define DLinked_List_H

#include <iostream>

using namespace std;

struct DNode {
	int val;
	DNode* prev;
	DNode* next;
};

void Ftraversal(DNode *h) {
	if (h == NULL) { 
		cout << endl;
		return;
	}
	cout << h->val << " ";
	Ftraversal(h->next);
}

void Btraversal(DNode *t) {
	if (t == NULL) { 
		cout << endl;
		return;
	}
	cout << t->val << " ";
	Btraversal(t->prev);
}
#endif DLinked_List_H