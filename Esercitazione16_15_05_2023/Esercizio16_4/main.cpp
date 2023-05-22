#include <iostream>
using namespace std;

class Porta {
public:
	Porta();
	Porta(int codice, double larghezza, double altezza, double prezzo, int n_pezzi);
	Porta(const Porta& p);
	~Porta();

	int getCodice() const;
	double getLarghezza() const;
	double getAltezza() const;
	double getPrezzo() const;
	int getNumPezzi() const;

	void setCodice(int codice);
	void setLarghezza(double larghezza);
	void setAltezza(double altezza);
	void setPrezzo(double prezzo);
	void setNumPezzi(double n_pezzi);

	void Inserisci();
	void Stampa() const;

private:
	int _codice;
	double _larghezza;
	double _altezza;
	double _prezzo;
	int _n_pezzi;
};

Porta::Porta() {
	_codice = 0;
	_larghezza = 0.0;
	_altezza = 0.0;
	_prezzo = 0.0;
	_n_pezzi = 0;
}

Porta::Porta(int codice, double larghezza, double altezza, double prezzo, int n_pezzi) {
	_codice = codice;
	_larghezza = larghezza;
	_altezza = altezza;
	_prezzo = prezzo;
	_n_pezzi = n_pezzi;
}

Porta::Porta(const Porta& p) {
	_codice = p._codice;
	_larghezza = p._larghezza;
	_altezza = p._altezza;
	_prezzo = p._prezzo;
	_n_pezzi = p._n_pezzi;
}

Porta::~Porta() {}

int Porta::getCodice() const {
	return _codice;
}

double Porta::getLarghezza() const {
	return _larghezza;
}

double Porta::getAltezza() const {
	return _altezza;
}

double Porta::getPrezzo() const {
	return _prezzo;
}

int Porta::getNumPezzi() const {
	return _n_pezzi;
}

void Porta::setCodice(int codice) {
	_codice = codice;
}

void Porta::setLarghezza(double larghezza) {
	_larghezza = larghezza;
}

void Porta::setAltezza(double altezza) {
	_altezza = altezza;
}

void Porta::setPrezzo(double prezzo) {
	_prezzo = prezzo;
}

void Porta::setNumPezzi(double n_pezzi) {
	_n_pezzi = n_pezzi;
}

void Porta::Inserisci() {
	do {
		cout << "Codice: ";
		cin >> _codice;
		cout << "Larghezza: ";
		cin >> _larghezza;
		cout << "Altezza: ";
		cin >> _altezza;
		cout << "Prezzo: ";
		cin >> _prezzo;
		cout << "Numero di pezzi: ";
		cin >> _n_pezzi;
		cout << endl;
	} while (_codice <= 0 || _larghezza <= 0 ||
		_altezza <= 0 || _prezzo <= 0 || _n_pezzi < 0);
}

void Porta::Stampa() const {
	cout << _codice << ": " << _larghezza << " x " << _altezza << " cm, "
		 << _prezzo << " Euro, " << _n_pezzi << " pezzi." << endl;
}

int main() {
	int n = 0;
	cout << "Inserire il numero di modelli desiderato: ";
	cin >> n;

	Porta* p = new Porta[n];
	for (int i = 0; i < n; i++)
		p[i].Inserisci();
	for (int j = 0; j < n; j++)
		p[j].Stampa();

	double valore = 0;
	for (int k = 0; k < n; k++)
		valore += p[k].getPrezzo() * p[k].getNumPezzi();
	cout << "Il valore totale del magazzino e' di " << valore << " Euro." << endl;

	delete[] p;

	return 0;
}

