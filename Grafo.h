#pragma once

#include "List.h"
#include "Node.h"
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

class Grafo
{
private:
	map<string, List> G;
	int nVertices = 0;
	int nArestas = 0;
	vector<pair<string, int>> grauSaida;

public:
	Grafo();
	~Grafo();
	map<string, List> newGrafo(string vertice, string value);

	map<string, List> getGrafo();

	void insertGrafo(string vertice, string value);
	void insertGrafo_First(string vertice);
	void printGrafo();
	int grafoSize();
	int getVertices();
	int getArestas();
	vector<pair<string, int>> getGrauSaida();
	void setGrauSaida();
	void get_BigE(int qtdeSaidas);
};

