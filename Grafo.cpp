#include "Grafo.h"

Grafo::Grafo()
{
}

Grafo::~Grafo()
{
}

map<string, List> Grafo::newGrafo(string vertice, string value) {
	this->G[vertice] = *new List(vertice, 1);

	return this->G;
}

map<string, List> Grafo::getGrafo() {
	return this->G;
}

void Grafo::insertGrafo(string vertice, string value) {
	Node aux;
	if (this->G.size() == 0) {
		this->G = newGrafo(vertice, value);
	}
	else {
		if (this->G.find(vertice) != this->G.end()) {
			if (this->G[vertice].find(value) && value != vertice) {
				this->G[vertice].findAndAttribute(value);
			}
			else if (value == vertice) {
				//Não faz nada
			}
			else {
				this->G[vertice].insertLast(value, 1);
			}
		}
		else {
			this->G[vertice] = *new List(vertice, 1);
		}
	}
	this->nVertices = this->getVertices();
	this->nArestas = this->getArestas();
}

void Grafo::printGrafo() {
	for (auto &x : this->G) {
		cout << x.first << " --- ";
		for (Node *p = x.second.getFirst(); p != NULL; p = p->getProx()) {
			cout << p->getValue() << " | ";
		}
		cout << endl;
	}
}

int Grafo::grafoSize() {
	return this->G.size();
}

int Grafo::getVertices() {
	return this->G.size();
}

void Grafo::insertGrafo_First(string vertice) {
	if (this->G.size() == 0) {
		this->G[vertice] = *new List(vertice, 1);
	}
	else if(this->G.find(vertice) == this->G.end()){
		this->G[vertice].insertFirst(vertice, 1);
	}
	this->nVertices = this->getVertices();
	this->nArestas = this->getArestas();
}

int Grafo::getArestas() {
	this->nArestas = 0;
	for (auto &x : this->G) {
		this->nArestas += x.second.listSize() - 1;
	}

	return this->nArestas;
}

void Grafo::setGrauSaida() {
	int aux = 0;
	pair<string, int> grau;
	for (auto &x : this->G) {
		for (Node *p = x.second.getFirst(); p != NULL; p = p->getProx()) {
			aux += p->getCost();
		}
		grau.first = x.first;
		grau.second = aux;

		this->grauSaida.push_back(grau);
		sort(this->grauSaida.begin(), this->grauSaida.end(), [](auto &left, auto &right) {
			return left.second > right.second;
		});
		aux = 0;
	}
}

void Grafo::get_BigE(int qtdeSaidas) {
	this->setGrauSaida();

	for (int i = 0; i < qtdeSaidas; i++) {
		if (i == 0) {
			cout << "Maiores "<< qtdeSaidas << " graus de envio: " << endl;
			cout << "...> " << this->grauSaida.at(i).first << ", " << this->grauSaida.at(i).second << endl;
		}
		else if (i == qtdeSaidas - 1) {
			cout << this->grauSaida.at(i).first << ", " << this->grauSaida.at(i).second << " <..." << endl;
		}
		else {
			cout << this->grauSaida.at(i).first << ", " << this->grauSaida.at(i).second << endl;
		}
	}
}

vector<pair<string, int>> Grafo::getGrauSaida() {
	return this->grauSaida;
}