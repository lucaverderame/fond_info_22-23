#ifndef __PUNTO_H__
#define __PUNTO_H__

#include <iostream>
#include <cmath>
using namespace std;

////////////////////////////////////////////////////////////////////
// Interfaccia della classe punto2d
////////////////////////////////////////////////////////////////////

class Punto2d {

public:

	// Costruttori
	Punto2d();
	Punto2d(double x, double y);
	Punto2d(const Punto2d& p);

	// Distruttore
	~Punto2d();

	// Selettori
	double getX() const;
	double getY() const;

	// Modificatori
	void setX(double x);
	void setY(double x);

	// Operatori sovraccaricati
	Punto2d operator-() const;
	Punto2d& operator++();
	Punto2d operator++(int);
    Punto2d& operator--();
	Punto2d operator--(int);
	Punto2d operator+(Punto2d p) const;
	Punto2d operator-(Punto2d p) const;
	Punto2d operator*(double s) const;
	int operator==(Punto2d p) const;
	const Punto2d& operator=(const Punto2d& p);
	friend ostream& operator<<(ostream& os, const Punto2d& p);
	friend istream& operator>>(istream& is, Punto2d& p);

	// Operazioni
	double distanza(Punto2d p) const;

private:
	double _x;
	double _y;
};

#include "Punto_2d.cpp"

#endif
