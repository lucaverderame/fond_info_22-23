#ifndef __POLIGONO_2D_INCLUDED__
#define __POLIGONO_2D_INCLUDED__

#include <iostream>
using namespace std;

template <typename T>
class poligono2d
{
public:

	// Costruttori
	poligono2d();
	poligono2d(int dim);
	poligono2d(punto2d<T> pti[], int dim);
	poligono2d(const poligono2d<T>& p);

	// Distruttore
	~poligono2d();

	// Selettori
	int get_num_vertici() const;
	const punto2d<T>* get_vertici() const;

	// Modificatori
	void set_poligono(punto2d<T> pti[], int dim);

	// Operatori sovraccaricati
	poligono2d<T> operator*(double s) const;
	const poligono2d<T>& operator=(const poligono2d<T>& p);
	punto2d<T>& operator[](int indice);
	template <typename S>
	friend ostream& operator<<(ostream& os, const poligono2d<S>& p);
	template <typename S>
	friend istream& operator>>(istream& is, poligono2d<S>& p);

	// Operazioni
	double get_perimetro() const;

private:
	punto2d<T>* _p;
	int _n;
};

#include "poligono2d.cpp"

#endif
