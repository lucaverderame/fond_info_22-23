#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Retta {
public:
	Retta();
	Retta(T m, T q);
	Retta(const Retta& r);
	~Retta();

	T getM() const;
	T getQ() const;
	
	void setM(T m);
	void setQ(T q);

	void inserisciDati();
	void stampaDati() const;
	double calcolaDistanza(T xp, T yp) const;
		
private:
	T _m;
	T _q;
};

template <typename T>
Retta<T>::Retta() : _m(0), _q(0)
{
}

template <typename T>
Retta<T>::Retta(T m, T q) : _m(m), _q(q)
{
}

template <typename T>
Retta<T>::Retta(const Retta& r) : _m(r._m), _q(r._q)
{
}

template <typename T>
Retta<T>::~Retta() {
}

template <typename T>
T Retta<T>::getM() const {
	return _m;
}

template <typename T>
T Retta<T>::getQ() const {
	return _q;
}


template <typename T>
void Retta<T>::setM(T m) {
	_m = m;
}

template <typename T>
void Retta<T>::setQ(T q) {
	_q = q;
}

template <typename T>
double Retta<T>::calcolaDistanza(T xp, T yp) const {
	return abs(yp - (_m * xp + _q)) / sqrt(1 + _m * _m);
}

template <typename T>
void Retta<T>::inserisciDati() {
	cout << "Inserire il coefficente angolare: ";
	cin >> _m;
	cout << "Inserire l'intercetta: ";
	cin >> _q;
}

template <typename T>
void Retta<T>::stampaDati() const {
	cout << "r: y = " << _m << "x + " << _q << ";" << endl;
}
	 
int main() {
	int n = 0;
	cout << "Inserire dimensione: ";
	cin >> n;
	if (n <= 0) {
		cout << "Errore" << endl;
		return -1;
	}

	Retta<double>* p = new Retta<double>[n];
	for (int i = 0; i < n; i++) {
		p[i].inserisciDati();
	}

	double xq = 0.0, yq = 0.0;
	cout << "Inserire coordinate: ";
	cin >> xq >> yq;
	for (int k = 0; k < n; k++)
		cout << p[k].calcolaDistanza(xq, yq) << endl;

	delete[] p;

	return 0;
}

