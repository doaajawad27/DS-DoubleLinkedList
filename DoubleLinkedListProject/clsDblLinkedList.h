#pragma once

#include<iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{

protected:
	int _size = 0;

public:
	class Node {
	public:
		T value;
		Node* next;
		Node* prev;
	};

	Node* head = NULL;

	void insertAtBegining(T value) {

		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL)
		{
			head->prev = newNode;
		}

		head = newNode;

		_size++;
	}

	void printList() {
		Node* current = head;
		cout << "List: ";
		while (current != NULL) {
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}

	Node* findNode(T value) {
		Node* current = head;
		while (current != NULL) {
			if (current->value == value)
				return current;
			current = current->next;
		}
		return NULL;
	}

	void insertAfter(Node* current, T value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = current->next;
		newNode->prev = current;

		if (current->next != NULL)
			current->next->prev = newNode;

		current->next = newNode;

		_size++;
	}

	void insertAtEnd(T value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = NULL;

		if (head == NULL) {
			newNode->prev = NULL;
			head = newNode;
		}
		else {

			Node* lastNode = head;
			while (lastNode->next != NULL) {
				lastNode = lastNode->next;
			}
			newNode->prev = lastNode;
			lastNode->next = newNode;

			_size++;
		}
	}

	void deleteNode(Node*& nodeToDelete) {
		if (head == NULL || nodeToDelete == NULL) {
			return;
		}

		if (head == nodeToDelete) {
			head = nodeToDelete->next;
		}

		if (nodeToDelete->next != NULL) {
			nodeToDelete->next->prev = nodeToDelete->prev;
		}
		if (nodeToDelete->prev != NULL)
		{
			nodeToDelete->prev->next = nodeToDelete->next;
		}

		delete nodeToDelete;
		_size--;
	}

	void deleteFirstNode() {
		if (head == NULL)
			return;

		Node* tmp = head;
		head = head->next;

		if (head != NULL)
		{
			head->prev = NULL;
		}

		delete tmp;
		_size--;
	}

	void deleteLastNode() {
		if (head == NULL)
		{
			return;
		}

		if (head->next == NULL) {
			delete head;
			head = NULL;
			return;
		}

		Node* current = head;
		while (current->next->next != NULL) {
			current = current->next;
		}

		Node* tmp = current->next;
		current->next = NULL;
		delete tmp;
		_size--;
	}

	int size() {
		return _size;
	}

	void clear() {
		while (_size > 0) {
			deleteFirstNode();
		}
	}

	bool isEmpty() {
		return _size == 0 ? true : false;
	}

	void reverse() {
		
		Node* current = head;
		Node* tmp = nullptr;
		while (current != nullptr) {
			tmp = current->prev;
			current->prev = current->next;
			current->next = tmp;
			current = current->prev;
		}

		if (tmp != nullptr)
			head = tmp->prev;
			
	}

	Node* getNode(int n) {

		if (n < 0 || n >= _size) {
			return NULL;
		}

		Node* current = head;
		for (int i = 0; i < n; i++) {
			current = current->next;
		}
		return current;
	}

	T getItem(int index) {
		Node* N = getNode(index);
		if (N == NULL) {
			return NULL;
		}
		return N->value;
	}
	
	bool updateItem(int index, T newVaue) {

		Node * itemNode = getNode(index);
		if (itemNode == NULL) {
			return false;
		}
		else {
			itemNode->value = newVaue;
			return true;
		}
	}
};

