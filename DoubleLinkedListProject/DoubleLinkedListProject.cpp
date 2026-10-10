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
	
	myDblLinkedList.insertAfter(myDblLinkedList.findNode(20), 25);
	myDblLinkedList.printList();

	myDblLinkedList.insertAtEnd(1);
	myDblLinkedList.printList();

	myDblLinkedList.deleteFirstNode();
	myDblLinkedList.printList();

	myDblLinkedList.deleteLastNode();
	myDblLinkedList.printList();

	clsDblLinkedList<int>::Node * N = myDblLinkedList.findNode(30);
	myDblLinkedList.deleteNode(N);
	myDblLinkedList.printList();
}

