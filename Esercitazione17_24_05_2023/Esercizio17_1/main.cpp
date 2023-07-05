#include "Figura_2d.h"

int main() {

	Figura2D f;

	const int numOp = 5;
	while (1) {
		cout << endl << "Operazioni disponibile: " << endl;
		cout << "1. Aggiungere un poligono alla figura" << endl;
		cout << "2. Rimuovere un poligono dalla figura" << endl;
		cout << "3. Ottenere il numero di poligoni di cui la figura si compone" << endl;
		cout << "4. Stampare i dati relativi alla figura" << endl;
		cout << "5. Uscire dal programma" << endl;
		cout << "Scegliere l'operazione: ";

		int op = 0;
		cin >> op;

		switch (op) {
		case 1: {
			cout << "Inserire il numero di vertici del nuovo poligono: ";
			int numVertici = 0;
			cin >> numVertici;
			Poligono2d p(numVertici);
			cout << "Inserire i vertici del poligono: " << endl;
			cin >> p;
			f.InserisciPoligono(p);
			break;
		}
		case 2: {
			cout << "Inserire l'indice del poligono da rimuovere: " << endl;
			int indice = 0;
			do {
				cin >> indice;
				if (indice < 0 || indice >= f.GetNumPoligoni())
					cout << "Attenzione: inserire un numero tra 0 e " << f.GetNumPoligoni() - 1 << endl;
			} while (indice < 0 || indice >= f.GetNumPoligoni());
			f.EliminaPoligono(indice);
			break;
		}
		case 3:
			cout << "Figura composta da " << f.GetNumPoligoni() << " poligoni" << endl;
			break;
		case 4:
			cout << "Figura composta da " << f.GetNumPoligoni() << " poligoni" << endl;
			cout << "Poligoni che compongono la figura:" << endl;
			cout << f;
			break;
		case 5:
			return 0;
		default:
			cout << "Attenzione: inserire un numero tra 1 e " << numOp << endl;
		}

	}
}
