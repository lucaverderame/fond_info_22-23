#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

////////////////////////////////////////////////////////////////////
// Interfaccia
////////////////////////////////////////////////////////////////////

class Incassi_annuali {
public:

	// Costruttori
	Incassi_annuali();
	Incassi_annuali(int a, char ct[], double ics[], int dim);
	Incassi_annuali(const Incassi_annuali& inc);

	// Distruttore
	~Incassi_annuali();

	// Selettori
	int get_anno() const;
	const char* get_luogo() const;
	const double* get_incassi() const;
	int get_num_supermercati() const;

	// Modificatori
	int set_anno(int a);
	int set_luogo(char ct[]);
	int set_incassi(double ics[], int dim);

	// Overload di operatori
	const Incassi_annuali& operator=(const Incassi_annuali& inc);
	friend istream& operator>>(istream& is, Incassi_annuali& inc);
	friend ostream& operator<<(ostream& is, const Incassi_annuali& inc);

	// Altre operazioni
	double incasso_totale() const;
	double incasso_medio() const;
	void estremi_incasso(double& max_incasso, double& min_incasso) const;

private:
	int _a; 		// anno
	char* _pc;		// citt\ufffd
	double* _pi; 	// array di incassi
	int _n;			// elementi dell'array
};

////////////////////////////////////////////////////////////////////
// Costruttori
////////////////////////////////////////////////////////////////////

Incassi_annuali::Incassi_annuali()
	: _a(1990), _pc(NULL), _pi(NULL), _n(0)
{
}

Incassi_annuali::Incassi_annuali(int a, char ct[], double ics[], int dim)
	: _a(1990), _pc(NULL), _pi(NULL), _n(0)
{
	if (a < 1990)
		return;
	if (dim <= 0)
		return;

	double* pi = new double[dim];
	if (pi == NULL)
		return;
	for (int k = 0; k < dim; k++) {
		if (ics[k] < 0.0) {
			delete [] pi;
			return;
		}
		pi[k] = ics[k];
	}

	char* pc = strdup(ct);
	if (pc == NULL) {
		delete [] pi;
		return;
	}

	_a = a;
	_pc = pc;
	_pi = pi;
	_n = dim;
}

Incassi_annuali::Incassi_annuali(const Incassi_annuali& inc)
	: _a(1990), _pc(NULL), _pi(NULL), _n(0)
{
	if (inc._n <= 0)
		return;

	double* pi = new double[inc._n];
	if (pi == NULL)
		return;
	for (int k = 0; k < inc._n; k++)
		pi[k] = inc._pi[k];

	char* pc = strdup(inc._pc);
	if (pc == NULL) {
		delete[] pi;
		return;
	}

	_a = inc._a;
	_n = inc._n;
	_pc = pc;
	_pi = pi;
}

////////////////////////////////////////////////////////////////////
// Distruttore
////////////////////////////////////////////////////////////////////

Incassi_annuali::~Incassi_annuali()
{
	if (_pc != NULL)
		delete[] _pc;
	if (_pi != NULL)
		delete[] _pi;
}

////////////////////////////////////////////////////////////////////
// Selettori
////////////////////////////////////////////////////////////////////

int Incassi_annuali::get_anno() const
{
	return _a;
}

const char* Incassi_annuali::get_luogo() const
{
	return _pc;
}

const double* Incassi_annuali::get_incassi() const
{
	return _pi;
}

int Incassi_annuali::get_num_supermercati() const
{
	return _n;
}

////////////////////////////////////////////////////////////////////
// Modificatori
////////////////////////////////////////////////////////////////////

int Incassi_annuali::set_anno(int a)
{
	if (a < 1990)
		return 0;
	_a = a;
	return 1;
}

int Incassi_annuali::set_luogo(char ct[])
{
	char* pc = strdup(ct);
	if (pc == NULL)
		return 0;
	if (_pc != NULL)
		delete[] _pc;
	_pc = pc;
	return 1;
}

int Incassi_annuali::set_incassi(double ics[], int dim)
{
	if (dim < 0)
		return 0;

	double*	p = new double[dim];
	if (p == NULL)
		return 0;

	for (int k = 0; k < dim; k++) {
		if (ics[k] < 0.0) {
			delete[] p;
			return 0;
		}
		p[k] = ics[k];
	}

	if (_pi != NULL)
		delete[] _pi;
	_pi = p;
	_n = dim;
	return 1;
}

////////////////////////////////////////////////////////////////////
// Overload di operatori
////////////////////////////////////////////////////////////////////

const Incassi_annuali& Incassi_annuali::operator=(const Incassi_annuali& inc)
{
	if (this != &inc) {
		int check = set_luogo(inc._pc) && set_incassi(inc._pi, inc._n) && set_anno(inc._a);
		if (check == 0) {
			set_anno(1990);
			_n = 0;
			if (_pc != NULL) {
				delete [] _pc;
				_pc == NULL;
			}
			if (_pi != NULL) {
				delete [] _pi;
				_pi == NULL;
			}
		}
	}
	return *this;
}

////////////////////////////////////////////////////////////////////
// Altre operazioni
////////////////////////////////////////////////////////////////////

double Incassi_annuali::incasso_totale() const
{
	const double* p = get_incassi();
	int n = get_num_supermercati();
	double somma = 0.0;
	if (p != NULL) {
		for (int k = 0; k < n; k++)
			somma += p[k];
	}
	return somma;
}

double Incassi_annuali::incasso_medio() const
{
	int n = get_num_supermercati();
	if (n != 0)
		return incasso_totale() / n;
	return 0.0;
}

void Incassi_annuali::estremi_incasso(double& max_incasso, double& min_incasso) const
{
	const double* p = get_incassi();
	int n = get_num_supermercati();
	double m = 0.0; double M = 0.0;
	if (p != NULL) {
		m = p[0]; M = p[0];
		for (int k = 0; k < n; k++) {
			if (p[k] > M)
				M = p[k];
			if (p[k] < m)
				m = p[k];
		}
	}
	max_incasso = M;
	min_incasso = m;
}

////////////////////////////////////////////////////////////////////
// Funzioni amiche della classe incassi_annuali
////////////////////////////////////////////////////////////////////

istream& operator>> (istream& is, Incassi_annuali& inc)
{
	const int dim = 32;
	int anno = 1990; char luogo[dim] = ""; int n = 0;
	double* p = NULL;
	int flag = 1;
	is >> anno;
	if (anno < 1990)
		flag = 0;
	else {
		is >> luogo;
		is >> n;
		if (n < 0)
			flag = 0;
		else {
			p = new double[n];
			if (p == NULL)
				flag = 0;
			else {
				for (int i = 0; i < n; i++) {
					is >> p[i];
					if (p[i] < 0) {
						flag = 0;
						break;
					}
				}
			}
		}
	}
	if (flag == 1) {
		inc.set_anno(anno);
		inc.set_luogo(luogo);
		inc.set_incassi(p, n);
	}
	else {
		inc.set_anno(1990);
		if (inc._pc != NULL) {
			delete [] inc._pc;
			inc._pc = NULL;
		}
		if (inc._pi != NULL) {
			delete [] inc._pi;
			inc._pi = NULL;
		}
	}
	return is;
}

ostream& operator<< (ostream& os, const Incassi_annuali& inc)
{
	const double* p = inc.get_incassi();
	int n = inc.get_num_supermercati();
	if (p != NULL) {
		os << inc.get_anno() << ", " << inc.get_luogo() << ", Incassi: ";
		for (int i = 0; i < n - 1; i++)
			os << p[i] << ", ";
		os << p[n - 1];
	}
	else
		os << "Dati non validi";
	return os;
}

////////////////////////////////////////////////////////////////////
// Funzione main
////////////////////////////////////////////////////////////////////

int main()
{
	fstream fin;
	fin.open("dati.txt", ios::in);
	if (!fin)
		return -1;

	int d = 0;
	fin >> d;
	if (d <= 0)
	 return -2;

	Incassi_annuali* inc = new Incassi_annuali[d];
	if (inc == NULL)
		return -3;
	for (int i = 0; i < d; i++)
		fin >> inc[i];

	fin.close();

	cout << "Dati contenuti nel file: "<< endl;
	double somma = 0.0;
	for (int i = 0; i < d; i++) {
		somma += inc[i].incasso_totale();
		cout << inc[i] << endl;
	}
	cout << "Incasso totale: " << somma << endl;

	return 0;
}