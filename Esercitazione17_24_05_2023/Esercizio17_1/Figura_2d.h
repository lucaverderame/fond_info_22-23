#ifndef FIGURE_2D_H
#define FIGURE_2D_H

#include "List.h"
#include "Poligono_2d.h"
using namespace std;


class Figura2D {
public:
	// costruttori e distruttore
	Figura2D();
	Figura2D(int dim, Poligono2d p[]);
	Figura2D(const Figura2D& f);
	~Figura2D();

	// selettori per gli attributi
	int GetNumPoligoni() const;
	const Poligono2d* GetPoligono(int i) const;

	// modificatori
	void SetPoligono(int i, const Poligono2d& p);

	// operatori
	void InserisciPoligono(const Poligono2d& p);
	void EliminaPoligono(int i);
	const Figura2D& operator = (const Figura2D& f);
	Figura2D operator * (double s);
	friend ostream& operator << (ostream& os, const Figura2D& f);
	friend istream& operator >> (istream& is, Figura2D& f);


private:
	List<Poligono2d> _poligoni;
};

#include "Figura_2d.cpp"

#endif
