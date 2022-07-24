#include "singly-linked-list.h"
using namespace std;

SinglyLinkedList::SinglyLinkedList() {

	head = nullptr;
	tail = nullptr;
	size = 0;
}

Node* SinglyLinkedList::getNodeAt(int i) {			// GET NODE AT AN INDEX

	if (head == nullptr) {			// If the list is empty

		cout << endl << "The list is empty!" << endl;
		return nullptr;
	}
	if (invalidIndex(i)) {			// Checking validity of given index value

		cout << endl << "Invalid index! Do you want to try again with a valid index? Enter 'y' for yes or 'n' for no: ";
		if (confirmation()) {		// Allowing user to exit operation 

			cout << endl << "Enter index value: ";
			getNodeAt(integerInput());
		}
		else
			return nullptr;
	}
	if (i == 1)
		return head;
	if (size == i)
		return tail;

	Node* trav = head->getNext();
	for (int j = 2; j <= i; j++) {

		if (i == 2)
			break;
		trav = trav->getNext();
	}
	return trav;
}

void SinglyLinkedList::append(Node* n) {					// APPEND

	if (n == nullptr)
		return;
	if (head == nullptr) {		// If the list is empty

		head = n;
		size++;
		cout << endl << "List was empty. Node successfully added at the head!" << endl;
		return;
	}
	if (size == 1) {			// If the list contains only one node

		head->setNext(n);
		tail = n;
		size++;
		cout << endl << "The list contained only one node. Node successfully appended at the head!" << endl;
		return;
	}
	
	tail->setNext(n);
	tail = n;
	size++;
	cout << endl << "Node successfully appended!" << endl;
}

void SinglyLinkedList::prepend(Node* n) {					// PREPEND

	if (n == nullptr)
		return;
	if (head == nullptr) {

		head = n;
		size++;
		cout << endl << "List was empty. Node successfully added at the head!" << endl;
		return;
	}
	if (tail == nullptr) {

		tail = head;
		head = n;
		size++;
		cout << endl << "List contained only one Node. Node successfully prepended!" << endl;
		return;
	}

	n->setNext(head);
	head = n;
	cout << endl << "Node successfully prepended!" << endl;
	size++;
}

void SinglyLinkedList::insertAfter(int i, Node* n) {		// INSERT AFTER A NODE
	
	if (n == nullptr)
		return;
	if (head == nullptr) {				// If the list is empty

		prepend(n);
		return;
	}
	if (size == 1 || size == i) {					// If the list contains only 1 node or If the node has to be inserted at the end

		append(n);
		return;
	}

	
	Node* temp = getNodeAt(i);			// Obtaining and validating node at the given index
	if (temp == nullptr) {

		delete temp;
		return;
	}

	n->setNext(temp->getNext());
	temp->setNext(n);
	size++;
	cout << endl << "Node successfully inserted!" << endl;
	temp = nullptr;
	delete temp;	
}

void SinglyLinkedList::deleteAt(int i) {					// DELETE THE NODE AT A GIVEN INDEX

	if (head == nullptr) {

		cout << endl << "The list is already empty! Cannot delete anything from an empty list :'(" << endl;
		return;
	}
	if (invalidIndex(i)) {			// Checking validity of given index value

		cout << endl << "Invalid index! Do you want to try again with a valid index? Enter 'y' for yes or 'n' for no: ";
		if (confirmation()) {		// Allowing user to exit operation 

			cout << endl << "Enter index value: ";
			deleteAt(integerInput());
		}
		else
			return;
	}

	cout << endl << "Are you sure you want to delete node at index " << i << "? Enter 'y' for yes or 'n' for no: ";// Asking for confirmation
	if (!confirmation())
		return;

	if (size == 1) {				// If the list contains only 1 node

		Node* temp = head;
		head = tail = nullptr;
		delete temp;
		size--;
		cout << endl << "Node successfully deleted!" << endl;
		return;
	}
	if (i == 1) {					// If the node to be deleted is the head

		Node* temp = head;
		head = head->getNext();
		delete temp;
		size--;
		cout << endl << "Node successfully deleted!" << endl;
		return;
	}
	if (size == 2 && i == 2) {		// If the tail has to be deleted when the list has only 2 nodes

		Node* temp = tail;
		head->setNext(nullptr);
		tail = nullptr;
		delete temp;
		size--;
		cout << endl << "Node successfully deleted!" << endl;
		return;
	}
	
	Node *travPrev = head, *trav = head->getNext();// Using 2 traversal pointers to find and delete the Node
	for (int j = 2; j <= i; j++) {

		if (i == 2)
			break;
		if (trav->getNext() == nullptr)
			break;
		travPrev = trav;
		trav = trav->getNext();
	}

	if (trav == tail) {				// If the node to be deleted is the tail

		tail = travPrev;
		tail->setNext(nullptr);
		delete trav;
		size--;
		travPrev = nullptr;
		delete travPrev;
		cout << endl << "Node successfully deleted!" << endl;
		return;
	}
	travPrev->setNext(trav->getNext());
	delete trav;
	size--;
	cout << endl << "Node successfully deleted!" << endl;
	travPrev = nullptr;
	delete travPrev;
}

void SinglyLinkedList::updateAt(int i, int d) {				// UPDATE THE VALUE AT THE GIVEN INDEX

	Node* temp = getNodeAt(i);

	if (temp == nullptr) {

		delete temp;
		return;
	}

	cout << endl << "Are you sure you want to update the node at index " << i << "? Enter 'y' for yes or 'n' for no: ";// Asking for confirmation
	if (!confirmation())
		return;

	cout << endl << "Enter the updated integer data : ";
	temp->setData(integerInput());
	cout << endl << "Data successfully updated!" << endl;
	temp = nullptr;
	delete temp;
}

void SinglyLinkedList::display() {							// DISPLAY ALL THE NODES IN THE LIST

	switch (size) {

	case 0:
		cout << endl << "Empty list! No Nodes to display." << endl;
		return;
	case 1:
		cout << endl << head->getData() << endl;
		return;
	case 2:
		cout << endl << head->getData() << " -> " << tail->getData() << endl;
		return;
	default:
		break;
	}

	cout << endl;
	Node* trav = head;
	for (int i = 1; i <= size; i++) {

		cout << trav->getData() << " -> ";
		if (i % 24 == 0)
			cout << endl;
		trav = trav->getNext();
	}
	cout << endl;
	trav = nullptr;
	delete trav;
}