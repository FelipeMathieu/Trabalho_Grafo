#include "Node.h"

Node::Node()
{
	this->prox = NULL;
}

Node::~Node()
{
}

Node::Node(string value, int cost) {
	this->value = value;
	this->cost = cost;
	this->prox = NULL;
}

int Node::getCost() {
	return this->cost;
}

Node *Node::getProx() {
	return this->prox;
}

string Node::getValue() {
	return this->value;
}

int Node::countAdj() {
	if (this->prox == NULL) {
		return 0;
	}
	else {
		int i = 0;
		Node *p = this;
		while (p->prox != NULL) {
			i += 1;
			p = p->prox;
		}
		return i;
	}
}

void Node::setProx(Node *p) {
	this->prox = p;
}

void Node::setCost(int newCost) {
	this->cost = newCost;
}
