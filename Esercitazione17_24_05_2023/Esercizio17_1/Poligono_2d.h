#ifndef __POL_H__
#define __POL_H__


#include <iostream>
#include <cmath>
#include "Punto_2d.h"
using namespace std;


/////////////////////////////////////////////////////////////////////
// Interfaccia della classe poligono2d
/////////////////////////////////////////////////////////////////////

class Poligono2d
{
public:

	// Costruttori
	Poligono2d();
	Poligono2d(int dim);
	Poligono2d(Punto2d pti[], int dim);
	Poligono2d(const Poligono2d& p);

	// Distruttore
	~Poligono2d();

	// Selettori
	int get_num_vertici() const;
	const Punto2d* get_vertici() const;

	// Modificatori
	void set_poligono(Punto2d pti[], int dim);

	// Operatori sovraccaricati
	Poligono2d operator*(double s) const;
	const Poligono2d& operator=(const Poligono2d& p);
	Punto2d& operator[](int indice);
	friend ostream& operator << (ostream& os, const Poligono2d& p);
	friend istream& operator >> (istream& is, Poligono2d& p);

	// Operazioni
	double get_perimetro() const;

private:
	Punto2d* _p;
	int _n;
};

#include "Poligono_2d.cpp"

#endif
