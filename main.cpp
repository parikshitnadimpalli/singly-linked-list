/*
Author			:	Parikshit Nadimpalli
Program name	:	Singly Linked List
Program version	:	v1.0
*/

#include "singly-linked-list.h"
using namespace std;

int main() {

	int option, i;
	string msg;
	SinglyLinkedList sll;

	do {

		cout << "\t\t\t|  Enter any one of the options below:      |" << endl;
		cout << "\t\t\t|                                           |" << endl;
		cout << "\t\t\t| NOTE: The list can only store integer     |" << endl;
		cout << "\t\t\t|       values. Index values start from 1   |" << endl;
		cout << "\t\t\t|                                           |" << endl;
		cout << "\t\t\t|             Press 0 to exit               |" << endl;
		cout << "\t\t\t|    1. Append a value to the list          |" << endl;
		cout << "\t\t\t|    2. Prepend a value to the list         |" << endl;
		cout << "\t\t\t|    3. Check if the list is empty          |" << endl;
		cout << "\t\t\t|    4. Get the value at an index           |" << endl;
		cout << "\t\t\t|    5. Insert a Node after an index        |" << endl;
		cout << "\t\t\t|    6. Count the total number of values    |" << endl;
		cout << "\t\t\t|    7. Delete the value at a position      |" << endl;
		cout << "\t\t\t|    8. Change the value at a position      |" << endl;
		cout << "\t\t\t|    9. Display the entire list             |" << endl;
		cout << "\t\t\t|   10. Clear screen                        |" << endl;
		cout << "\t\tEnter option: ";
		option = integerInput();

		switch (option) {

		case 0:
			break;
		case 1:
			sll.append(newNode());
			break;
		case 2:
			sll.prepend(newNode());
			break;
		case 3:
			msg = sll.getSize() == 0 ? "The list is empty." : "The list is not empty.";
			cout << endl << msg << endl;
			break;
		case 4:
			cout << endl << "Enter the index of the Node: ";
			sll.getNodeAt(integerInput());
			break;
		case 5:
			cout << endl << "Enter the index to insert after: ";
			i = integerInput();
			sll.insertAfter(i, newNode());
			break;
		case 6:
			cout << endl << "The total number of nodes in the list are: " << sll.getSize() << endl;
			break;
		case 7:
			cout << endl << "Enter the index of the Node that you want to delete: ";
			sll.deleteAt(integerInput());
			break;
		case 8:
			cout << endl << "Enter the index where you want to change the value: ";
			sll.updateAt(integerInput());
			break;
		case 9:
			sll.display();
			break;
		case 10:
			clearScreen();
			break;
		default:
			cout << endl << "Invalid option!";
			break;
		}
	} while (option != 0);

	return 0;
}