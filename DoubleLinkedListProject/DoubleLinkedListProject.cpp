// DoubleLinkedListProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"clsDblLinkedList.h"
int main()
{
	clsDblLinkedList<int> myDblLinkedList;

	myDblLinkedList.insertAtBegining(10);
	myDblLinkedList.insertAtBegining(20);
	myDblLinkedList.insertAtBegining(30);
	myDblLinkedList.insertAtBegining(40);
	myDblLinkedList.insertAtBegining(50);
	myDblLinkedList.printList();
	
		myDblLinkedList.printList();
	cout << "\nsize:" << myDblLinkedList.size() ;


	if (myDblLinkedList.isEmpty()) {
		cout << " Your list is empty!! ";
	}
	else {
		cout << " Your list is not empty.";
	}

	cout << "\n\nclear list:";
	myDblLinkedList.clear();
	cout <<"\nsize=" << myDblLinkedList.size();

	if (myDblLinkedList.isEmpty()) {
		cout << " Your list is empty!! "<<endl;
	}
	else {
		cout << " Your list is not empty."<<endl;
	}
}

