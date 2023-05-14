#include <cmath>
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


/////////////////////////////////////////////////////////////////////
// Costruttori
/////////////////////////////////////////////////////////////////////

template <typename T>
poligono2d<T>::poligono2d()
	: _p(NULL), _n(0)
{
}

template <typename T>
poligono2d<T>::poligono2d(int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		punto2d<T>* p = new punto2d<T>[dim];
		if (p != NULL) {
			_p = p;
			_n = dim;
		}
	}
}

template <typename T>
poligono2d<T>::poligono2d(punto2d<T> pti[], int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		punto2d<T>* p = new punto2d<T>[dim];
		if (p != NULL) {
			for (int k = 0; k < dim; k++)
				p[k] = pti[k];
			_p = p;
			_n = dim;
		}
	}
}

template <typename T>
poligono2d<T>::poligono2d(const poligono2d<T>& p)
	: _p(NULL), _n(0)
{
	if (p._n > 0) {
		punto2d<T>* pol = new punto2d<T>[p._n];
		if (pol != NULL) {
			for (int k = 0; k < p._n; k++)
				pol[k] = p._p[k];
			_p = pol;
			_n = p._n;
		}
	}
}


/////////////////////////////////////////////////////////////////////
// Distruttore
/////////////////////////////////////////////////////////////////////

template <typename T>
poligono2d<T>::~poligono2d()
{
	if (_p != NULL) {
		delete [] _p;
	}
}


/////////////////////////////////////////////////////////////////////
// Selettori
/////////////////////////////////////////////////////////////////////

template <typename T>
int poligono2d<T>::get_num_vertici() const
{
	return _n;
}

template <typename T>
const punto2d<T>* poligono2d<T>::get_vertici() const
{
	return _p;
}


/////////////////////////////////////////////////////////////////////
// Modificatori
/////////////////////////////////////////////////////////////////////
	
template <typename T>
void poligono2d<T>::set_poligono(punto2d<T> pti[], int dim)
{
	if (dim > 0) {
		punto2d<T>* p = new punto2d<T>[dim];
		if (p != NULL) {
			for (int k = 0; k < dim; k++)
				p[k] = pti[k];
			if (_p != NULL)
				delete [] _p;
			_p = p;
			_n = dim;
		}
	}
}


/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati
/////////////////////////////////////////////////////////////////////

template <typename T>
poligono2d<T> poligono2d<T>::operator*(double s) const
{
	poligono2d<T> p(*this);
	if (get_vertici() != NULL) {
		for (int k = 0; k < get_num_vertici(); k++)
			p[k]= get_vertici()[k] * s;
	}
	return p;
}

template <typename T>
const poligono2d<T>& poligono2d<T>::operator=(const poligono2d<T>& p)
{
	if (&p != this) {
		if (_p != NULL) {
			delete [] _p;
			_p = NULL;
		}
		_n = 0;
		int n = p.get_num_vertici();
		if (n > 0) {
			punto2d<T>* pnewpol = new punto2d<T>[n];
			if (pnewpol != NULL) {
				for (int k = 0; k < n; k++)
					pnewpol[k] = (p._p)[k];
				_p = pnewpol;
				_n = n;
			}
		}
	}
	return *this;
}

template <typename T>
punto2d<T>& poligono2d<T>::operator[](int indice)
{
	return _p[indice];
}


/////////////////////////////////////////////////////////////////////
// Operazioni
/////////////////////////////////////////////////////////////////////

template <typename T>
double poligono2d<T>::get_perimetro() const
{
	double perimetro = 0.0;
	if (get_vertici() != NULL) {
		for (int k = 0; k < (get_num_vertici() - 1); k++)
			perimetro += (get_vertici()[k]).distanza(get_vertici()[k + 1]);
		perimetro += (get_vertici()[0]).distanza(get_vertici()[get_num_vertici() - 1]);
	}
	return perimetro;
}


////////////////////////////////////////////////////////////////////
// Funzioni amiche
////////////////////////////////////////////////////////////////////

template <typename T>
ostream& operator<<(ostream& os, const poligono2d<T>& p)
{
	const punto2d<T>* pt = p.get_vertici();
	if (pt != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			os << pt[k] << ' ';
	return os;
}

template <typename T>
istream& operator>>(istream& is, poligono2d<T>& p)
{
	if (p.get_vertici() != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			is >> p[k];
	return is;
}

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
