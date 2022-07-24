#include <iostream>
#include <string>
#include <new>
#include <limits>

class Node {
	
	int data;
	Node* next;
public:
	Node(int);

	void setData(int d) { data = d; }
	int getData() { return data; }
	void setNext(Node* n) { next = n; }
	Node* getNext() { return next; }
	~Node();
};

int integerInput();
Node* newNode();
bool confirmation();
void clearScreen();