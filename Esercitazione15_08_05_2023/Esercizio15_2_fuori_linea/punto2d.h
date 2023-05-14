#ifndef __PUNTO_2D_INCLUDED__
#define __PUNTO_2D_INCLUDED__

#include <iostream>
using namespace std;

template <typename T>
class punto2d {

public:

	// Costruttori
	punto2d();
	punto2d(T x, T y);
	punto2d(const punto2d<T>& p);

	// Distruttore
	~punto2d();

	// Selettori
	T getX() const;
	T getY() const;

	// Modificatori
	void setX(T x);
	void setY(T x);

	// Operatori sovraccaricati
	punto2d<T> operator-() const;
	punto2d<T>& operator++();
	punto2d<T> operator++(int);
    punto2d<T>& operator--();
	punto2d<T> operator--(int);
	punto2d<T> operator+(punto2d<T> p) const;
	punto2d<T> operator-(punto2d<T> p) const;
	punto2d<T> operator*(double s) const;
	int operator==(punto2d<T> p) const;
	const punto2d<T>& operator=(const punto2d<T>& p);
	template <typename S>
	friend ostream& operator<<(ostream& os, const punto2d<S>& p);
	template <typename S>
	friend istream& operator>>(istream& is, punto2d<S>& p);

	// Operazioni
	double distanza(punto2d<T> p) const;

private:
	T _x;
	T _y;
};

#include "punto2d.cpp"

#endif
