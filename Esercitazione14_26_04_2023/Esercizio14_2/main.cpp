#include <iostream>
#include <cmath>
using namespace std;

////////////////////////////////////////////////////////////////////
// Interfaccia
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

/////////////////////////////////////////////////////////////////////
// Costruttori della classe punto2d
/////////////////////////////////////////////////////////////////////

Punto2d::Punto2d()
	: _x(0.0), _y(0.0)
{
}

Punto2d::Punto2d(double x, double y)
	: _x(x), _y(y)
{
}

Punto2d::Punto2d(const Punto2d& p)
	: _x(p._x), _y(p._y)
{
}

/////////////////////////////////////////////////////////////////////
// Distruttore della classe punto2d
/////////////////////////////////////////////////////////////////////

Punto2d::~Punto2d()
{
}
	
/////////////////////////////////////////////////////////////////////
// Selettori della classe punto2d
/////////////////////////////////////////////////////////////////////

double Punto2d::getX() const
{
	return _x;
}

double Punto2d::getY() const
{
	return _y;
}

/////////////////////////////////////////////////////////////////////
// Modificatori della classe punto2d
/////////////////////////////////////////////////////////////////////

void Punto2d::setX(double x)
{
	_x = x;
}

void Punto2d::setY(double y)
{
	_y = y;
}

/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati della classe punto2d
/////////////////////////////////////////////////////////////////////

Punto2d Punto2d::operator-() const
{
	return Punto2d(-getX(), -getY());
}

Punto2d& Punto2d::operator++()
{
	setX(getX() + 1.0);
	setY(getY() + 1.0);
	return *this;
}

Punto2d Punto2d::operator++(int)
{
	Punto2d temp(*this);
	setX(getX() + 1.0);
	setY(getY() + 1.0);
	return temp;
}

Punto2d& Punto2d::operator--()
{
	setX(getX() - 1.0);
	setY(getY() - 1.0);
	return *this;
}

Punto2d Punto2d::operator--(int)
{
	Punto2d temp(*this);
	setX(getX() - 1.0);
	setY(getY() - 1.0);
	return temp;
}

Punto2d Punto2d::operator+(Punto2d p) const
{
	return Punto2d(getX() + p.getX(), getY() + p.getY());
}

Punto2d Punto2d::operator-(Punto2d p) const
{
	return Punto2d(getX() - p.getX(), getY() - p.getY());
}

Punto2d Punto2d::operator*(double s) const
{
	return Punto2d(s * getX(), s * getY());
}

int Punto2d::operator==(Punto2d p) const
{
	return (getX() == p.getX() && getY() == p.getY());
}

const Punto2d& Punto2d::operator=(const Punto2d& p)
{	
	if (&p != this) {
		setX(p.getX());
		setY(p.getY());
	}
	return *this;
}

ostream& operator<<(ostream& os, const Punto2d& p)
{
	os << "(" << p.getX() << "," << p.getY() << ")";
	return os;
}

istream& operator >> (istream& is, Punto2d& p)
{
	double x = 0.0;
	double y = 0.0;
	is >> x >> y;
	p.setX(x);
	p.setY(y);
	return is;
}

/////////////////////////////////////////////////////////////////////
// Operazioni della classe punto2d
/////////////////////////////////////////////////////////////////////

double Punto2d::distanza(Punto2d p) const
{
	double deltaX = getX() - p.getX(); 
	double deltaY = getY() - p.getY();
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

/////////////////////////////////////////////////////////////////////
// Funzione main
/////////////////////////////////////////////////////////////////////

int main()
{
	Punto2d p, q;
	cout << "Immettere le coordinate (x1, y1) di un punto: " << endl;
	cin >> p;
	cout << endl;
	cout << "Immettere le coordinate (x2, y2) di un punto: " << endl;
	cin >> q;
	cout << endl;

	cout << "Dati i punti di coordinate " << p << " e " << q << ": " << endl;
	cout << "- la loro somma e': " << p + q << endl;
	cout << "- la loro differenza e': " << p - q << endl;
	cout << "- la loro distanza e': " << p.distanza(q) << endl;
	cout << endl;

	return 0;
}
