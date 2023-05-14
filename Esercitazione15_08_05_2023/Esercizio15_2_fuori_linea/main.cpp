#include "punto2d.h"
#include "poligono2d.h"
#include <iostream>
using namespace std;

int arrotonda(double x)
{
	return (int(x) + (x - int(x) >= 0.5));
}

int main()
{
	int numVertici;
	do {
		cout << "Inserire il numero di vertici di un poligono: ";
		cin >> numVertici;
		if (numVertici <= 0)
			cout << "Attenzione! Il numero di vertici deve essere un numero positivo" << endl;
	} while (numVertici <= 0);

	poligono2d<double> pol_d(numVertici);
	cout << "Inserire le cordinate dei vertici del poligono:" << endl;
	cin >> pol_d;

	poligono2d<int> pol_i(numVertici);
	punto2d<int>* ppunti = new punto2d<int>[numVertici];
	if (ppunti == NULL) {
		cout << "Errore di allocazione" << endl;
		return -1;
	}
	const punto2d<double>* pvertici = pol_d.get_vertici();
	for (int i = 0; i < numVertici; i++) {
		ppunti[i].setX(arrotonda(pvertici[i].getX()));
		ppunti[i].setY(arrotonda(pvertici[i].getY()));
	}
	pol_i.set_poligono(ppunti, numVertici);

	double perimetro_d = pol_d.get_perimetro();
	cout << "Il perimetro del poligono costituito dai seguenti " << pol_d.get_num_vertici() << " vertici:" << endl;
	cout << pol_d << endl;
	cout << "e' lungo " << perimetro_d << endl;
	cout << endl;

	double perimetro_i = pol_i.get_perimetro();
	cout << "Il perimetro del poligono costituito dai seguenti " << pol_i.get_num_vertici() << " vertici:" << endl;
	cout << pol_i << endl;
	cout << "e' lungo " << perimetro_i << endl;
	cout << endl;

	double errore = (perimetro_d - perimetro_i) * (perimetro_d - perimetro_i);
	cout << "L'errore di arrotondamento vale: " << errore << endl;

	return 0;
}
