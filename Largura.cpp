#include "Largura.h"

Largura::Largura()
{
}

Largura::~Largura()
{
}

Largura *Largura::searchLargura(Grafo *G, string origem, string destino) {
	string x = "";

	auto &g = G->getGrafo();

	if (g.find(destino) != g.end()) {

		if (this->q.empty()) {
			cout << endl << "Nao e possivel acessar o destino" << endl << endl;
			return this;
		}
		else {
			x = this->q.front();
			this->visit(g[x].getFirst());

			if (x == destino) {
				this->v.push_back(x);
				this->getVisits();
				return this;
			}
			else {
				if (!this->nV.empty()) {
					this->v.push_back(this->nV.at(0));
					this->nV.erase(remove(this->nV.begin(), this->nV.end(), this->v.back()), this->nV.end());
				}

				for (int i = 0; i < this->nV.size(); i++) {

					if (find(this->q.begin(), this->q.end(), this->nV.at(i)) == this->q.end()) {
						if (find(this->v.begin(), this->v.end(), this->nV.at(i)) == this->v.end()) {
							this->q.push_back(this->nV.at(i));
						}
					}
				}

				if (!this->q.empty()) {
					return this->searchLargura(G, this->q.front(), destino);
				}
				else {
					cout << endl << "Nao e possivel acessar o destino" << endl << endl;
					return this;
				}
			}
		}
	}
	else {
		cout << endl << "Destino nao existe" << endl << endl;
	}
}

void Largura::visit(Node *node) {
	this->nV.push_back(this->q.front());
	this->q.pop_front();

	while (node != NULL) {
		if (find(this->nV.begin(), this->nV.end(), node->getValue()) == this->nV.end()) {
			if (find(this->v.begin(), this->v.end(), node->getValue()) == this->v.end()) {
				this->nV.push_back(node->getValue());
			}
		}
		node = node->getProx();
	}
}

void Largura::getVisits() {
	cout << "Nos visitados" << endl;
	for (int i = 0; i < this->v.size(); i++) {
		if (i == 0) {
			cout << "...> " << this->v.at(i) << endl;
		}
		else if (i == this->v.size() - 1) {
			cout << this->v.at(i) << " <..." << endl;
		}
		else {
			cout << this->v.at(i) << endl;
		}
	}
}

void Largura::getNotVisits() {
	cout << "Nos nao visitados" << endl;
	for (int i = 0; i < this->nV.size(); i++) {
		if (i == 0) {
			cout << "...> " << this->nV.at(i) << endl;
		}
		else if (i == this->nV.size() - 1) {
			cout << this->nV.at(i) << " <..." << endl;
		}
		else {
			cout << this->nV.at(i) << endl;
		}
	}
}

bool Largura::setQueue(Grafo *G, string value) {
	auto &x = G->getGrafo();

	if (x.find(value) != x.end()) {
		this->q.push_back(value);
		return true;
	}
	else
	{
		cout << endl << "Origem nao existe" << endl << endl;
		return false;
	}
}