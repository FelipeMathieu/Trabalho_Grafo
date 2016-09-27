#pragma once

#include "Grafo.h"
#include "List.h"
#include "Node.h"
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

class Largura
{
private:
	deque<string> q;
	vector<string> nV;
	vector<string> v;

public:
	Largura();
	~Largura();

	Largura *searchLargura(Grafo *G, string origem, string destino);
	void visit(Node *node);

	deque<string> getQueue() {
		return this->q;
	}

	void getVisits();

	void getNotVisits();

	int getVisits_Size() {
		return this->v.size();
	}

	int getNotVisits_Size() {
		return this->nV. size();
	}

	bool setQueue(Grafo *G, string value);
};

