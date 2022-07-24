#include "node.h"

class SinglyLinkedList{

	Node *head, *tail;
	int size;
public:
	SinglyLinkedList();
	
	bool invalidIndex(int i) { return (i > size) || (i <= 0); }
	int getSize() { return size; }
	Node* getNodeAt(int);
	void append(Node*);
	void prepend(Node*);
	void insertAfter(int, Node*);
	void deleteAt(int);
	void updateAt(int, int d = 0);
	void display();
};