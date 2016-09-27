#pragma once
#include<iostream>

using namespace std;

class Node
{
private:
	string value;
	int cost = 0;
	Node *prox;

public:
	Node();
	~Node();
	Node(string value, int cost);

	string getValue();
	int getCost();
	Node *getProx();
	int countAdj();
	void setProx(Node *p);
	void setCost(int newCost);
};

