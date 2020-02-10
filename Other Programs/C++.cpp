#include <iostream>
#include <string>

using namespace std;


class StringNode // A node in a list of strings
{
private:
	string elem; // element value
	StringNode *next; // next item in the list

	friend class StringLinkedList; // provide StringLinkedList access
};

class StringLinkedList
{
public:
	StringLinkedList(); // empty list constructor
	~StringLinkedList(); // destructor

	bool empty() const; // is list empty?
	const string& front() const; // get front element
	void addFront(const string& e); // add to fron of list
	void removeFront(); // remove front item list
private:
	StringNode *head: //pointer to head of list.
};

StringLinkedList::StringLinkedList() // constructor
	:head(NULL) {}

StringLinkedList::~StringLinkedList() // destructor
{
	while (!empty()) removeFront();
}

bool StringLinkedList::empty() const // is list empty?
{
	return head == NULL;
}

const string& StringLinkedList::front() const // get front element
{
	return head->elem;
}

void StringLinkedList::addFront(const string& e) //add to front of list
{
	StringNode* v = new StringNode; // create new node
	v->elem = e; // store data
	v->next = head; // head now follows v
	head = v; // v is now the head
}

void StringLinkedList::removeFront()
{
	StringNode *old = head;
	head = old->next;
	delete old;
}

int main()
{
    cout << "Hello World!\n"; 
	return 0;

	StringLinkedList LL;
}

