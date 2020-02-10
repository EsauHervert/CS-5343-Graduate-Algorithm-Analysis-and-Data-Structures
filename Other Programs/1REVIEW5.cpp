#include <iostream>

using namespace std;

struct Node {
	int val;
	Node *left;
	Node *right;
};

class BinaryTree{
public:
	Node *root = NULL;

	void add(int);
};

void addN(Node *temp, Node *New) {
	if (temp->val > New->val) {
		if (temp->left == NULL) {
			temp->left = New;
			return;
		}
		addN(temp->left, New);
	}
	else {
		if (temp->right == NULL) {
			temp->right = New;
			return;
		}
		addN(temp->right, New);
	}
}

void BinaryTree::add(int v) {
	Node *New = new Node();
	New->val = v;
	if (root == NULL) {
		root = New;
		return;
	}
	addN(root, New);
}

void PreOrder(Node *temp) {
	if (temp == NULL) {
		return;
	}

	PreOrder(temp->left);
	PreOrder(temp->right);
	cout << temp->val << " ";
}

void InOrder(Node *temp) {
	if (temp == NULL) {
		return;
	}

	InOrder(temp->left);
	cout << temp->val << " ";
	InOrder(temp->right);
}

void PostOrder(Node *temp) {
	if (temp == NULL) {
		return;
	}
	cout << temp->val << " ";
	PostOrder(temp->left);
	PostOrder(temp->right);
}

int Nodes(Node *temp) {
	if (temp == NULL) {
		return 0;
	}
	return 1 + Nodes(temp->left) + Nodes(temp->right);
}

int Leaf(Node *temp) {
	if (temp == NULL) {
		return 0;
	}
	if (temp->left == NULL && temp->right == NULL) {
		return 1;
	}
	return Leaf(temp->left) + Leaf(temp->right);
}

Node *FindNode(Node *temp, int S) {
	if (temp->val == S) {
		return temp;
	 }
	else if (temp->val > S) {
		return FindNode(temp->left, S);
	}
	else {
		return FindNode(temp->right, S);
	}
}

Node *Sibling(Node *temp, Node *S) {
	if (temp->left == S) {
		if (temp->right != NULL) {
			return temp->right;
		}
		else {
			cout << "No Sibling!" << endl;
			return NULL;
		}
	}
	else if (temp->right == S) {
		if (temp->left != NULL) {
			return temp->left;
		}
		else {
			cout << "No Sibling!" << endl;
			return NULL;
		}
	}
	
	if (temp->val > S->val) {
		Sibling(temp->left, S);
	}
	else {
		Sibling(temp->right, S);
	}
}

int main() {
	BinaryTree B1;
	B1.add(1);
	B1.add(7);
	B1.add(4);
	B1.add(8);
	B1.add(3);
	B1.add(10);
	B1.add(9);
	B1.add(2);
	B1.add(5);
	B1.add(6);

	PreOrder(B1.root);
	cout << endl;
	InOrder(B1.root);
	cout << endl;
	PostOrder(B1.root);
	cout << endl;

	cout << Nodes(B1.root) << endl;

	cout << Leaf(B1.root) << endl;

	Node *N8 = FindNode(B1.root, 8);
	Node *S = Sibling(B1.root, N8);
	if (S != NULL) {
		cout << S->val << endl;
	}
}