#include "Grafo.h"
#include <Windows.h>
#include "Search_Data.h"
#include "Largura.h"

void main() {
	Grafo *G = new Grafo();
	Search_Data sD;
	Largura *L = new Largura();

	sD.openDir_My("Enron", "Enron", G);

	cout << endl << "Numero de arestas do grafo: " << G->getVertices() << endl << endl;
	G->get_BigE(20);

	if (L->setQueue(G, "drew.fossum@enron.com")) {
		L = L->searchLargura(G, "drew.fossum@enron.com", "sandra.brawner@enron.com");
	}

	cout << endl;
	system("pause");
}
