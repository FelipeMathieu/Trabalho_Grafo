#pragma once

#include "Node.h"
#include <conio.h>

class List
{
private:
	Node *first;
	Node *last;
	int size = 0;

public:
	List();
	~List();
	List(string value, int cost);

	Node *getFirst();
	Node *getLast();
	bool isVoid();
	void insertFirst(string value, int cost);
	void insertLast(string value, int cost);
	void printList();
	void insertInOrder(string value, int cost);
	Node *insertAfter(Node *thisNode, Node *aux);
	void removeFirst();
	void removeLast();
	void removeAdj(string value, int cost);
	int listSize();
	List *getList() {
		return this;
	};
	bool find(string value);
	void findAndAttribute(string value);
};

