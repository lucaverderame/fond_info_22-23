#include <cmath>

/////////////////////////////////////////////////////////////////////
// Costruttori
/////////////////////////////////////////////////////////////////////

template <typename T>
punto2d<T>::punto2d()
	: _x(0), _y(0)
{
}

template <typename T>
punto2d<T>::punto2d(T x, T y)
	: _x(x), _y(y)
{
}

template <typename T>
punto2d<T>::punto2d(const punto2d<T>& p)
	: _x(p._x), _y(p._y)
{
}


/////////////////////////////////////////////////////////////////////
// Distruttore
/////////////////////////////////////////////////////////////////////

template <typename T>
punto2d<T>::~punto2d()
{
}


/////////////////////////////////////////////////////////////////////
// Selettori
/////////////////////////////////////////////////////////////////////

template <typename T>
T punto2d<T>::getX() const
{
	return _x;
}

template <typename T>
T punto2d<T>::getY() const
{
	return _y;
}


/////////////////////////////////////////////////////////////////////
// Modificatori
/////////////////////////////////////////////////////////////////////

template <typename T>
void punto2d<T>::setX(T x)
{
	_x = x;
}

template <typename T>
void punto2d<T>::setY(T y)
{
	_y = y;
}


/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati
/////////////////////////////////////////////////////////////////////

template <typename T>
punto2d<T> punto2d<T>::operator-() const
{
	return punto2d<T>(-getX(), -getY());
}

template <typename T>
punto2d<T>& punto2d<T>::operator++()
{
	setX(getX() + 1);
	setY(getY() + 1);
	return *this;
}

template <typename T>
punto2d<T> punto2d<T>::operator++(int)
{
	punto2d<T> temp(*this);
	setX(getX() + 1);
	setY(getY() + 1);
	return temp;
}

template <typename T>
punto2d<T>& punto2d<T>::operator--()
{
	setX(getX() - 1);
	setY(getY() - 1);
	return *this;
}

template <typename T>
punto2d<T> punto2d<T>::operator--(int)
{
	punto2d<T> temp(*this);
	setX(getX() - 1);
	setY(getY() - 1);
	return temp;
}

template <typename T>
punto2d<T> punto2d<T>::operator+(punto2d<T> p) const
{
	return punto2d<T>(getX() + p.getX(), getY() + p.getY());
}

template <typename T>
punto2d<T> punto2d<T>::operator-(punto2d<T> p) const
{
	return punto2d<T>(getX() - p.getX(), getY() - p.getY());
}

template <typename T>
punto2d<T> punto2d<T>::operator*(double s) const
{
	return punto2d<T>(s * getX(), s * getY());
}

template <typename T>
int punto2d<T>::operator==(punto2d<T> p) const
{
	return (getX() == p.getX() && getY() == p.getY());
}

template <typename T>
const punto2d<T>& punto2d<T>::operator=(const punto2d<T>& p)
{
	if (&p != this) {
		setX(p.getX());
		setY(p.getY());
	}
	return *this;
}

template <typename T>
ostream& operator<<(ostream& os, const punto2d<T>& p)
{
	os << "(" << p.getX() << "," << p.getY() << ")";
	return os;
}

template <typename T>
istream& operator>>(istream& is, punto2d<T>& p)
{
	double x = 0.0;
	double y = 0.0;
	is >> x >> y;
	p.setX(x);
	p.setY(y);
	return is;
}


/////////////////////////////////////////////////////////////////////
// Operazioni
/////////////////////////////////////////////////////////////////////

template <typename T>
double punto2d<T>::distanza(punto2d<T> p) const
{
	double deltaX = getX() - p.getX();
	double deltaY = getY() - p.getY();
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

