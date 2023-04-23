#include <iostream>
#include <fstream>

using namespace std;

const int nr = 8;
const int nc = 5;

class Dipendenti {
public:
	Dipendenti();
	Dipendenti(double s[nc], int D[nr][nc]);
	Dipendenti(const Dipendenti& d);
	~Dipendenti();
	const double* getStipendi() const;
	int getDipendenti(int h, int k) const;
	void setStipendi(double s[nc]);
	void setDipendenti(int D[nr][nc]);
	int totaleDipendenti() const;
	void estremiStipendio(int& dipMax, int& dipMin) const;

private:
	double _s[nc];
	int _D[nr][nc];
};

Dipendenti::Dipendenti() {
	for (int k = 0; k < nc; k++)
		_s[k] = 0.0;
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_D[i][j] = 0;
}

Dipendenti::Dipendenti(double s[nc], int D[nr][nc]) {
	for (int k = 0; k < nc; k++)
		_s[k] = s[k];
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_D[i][j] = D[i][j];
}

Dipendenti::Dipendenti(const Dipendenti& d) {
	for (int k = 0; k < nc; k++)
		_s[k] = d._s[k];
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_D[i][j] = d._D[i][j];
}

Dipendenti::~Dipendenti() {
}

const double* Dipendenti::getStipendi() const {
	return _s;
}

int Dipendenti::getDipendenti(int h, int k) const {
	if ((h >= 0 && h < nr) && (k >= 0 && k < nc))
		return _D[h][k];
	return -1;
}

void Dipendenti::setStipendi(double s[nc]) {
	for (int k = 0; k < nc; k++)
		_s[k] = s[k];
}

void Dipendenti::setDipendenti(int D[nr][nc]) {
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_D[i][j] = _D[i][j];
}

int Dipendenti::totaleDipendenti() const {
	int somma = 0;
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			somma += _D[i][j];
	return somma;
}

void Dipendenti::estremiStipendio(int& dipMax, int& dipMin) const {
	double stip[nr];
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			stip[i] += _s[j] * _D[i][j];

	double Min = stip[0]; double Max = stip[0];
	int iMin = 0; int iMax = 0;
	for (int k = 0; k < nr; k++) {
		if (stip[k] > Max) {
				iMax = k;
				Max = stip[k];
		}
		if (stip[k] < Min) {
			iMin = k;
			Min = stip[k];
		}
	}
	dipMax = iMax;
	dipMin = iMin;
}


int main() {
	double stp[nc] = { 0.0 };
	int Dip[nr][nc] = { 0 };
	fstream fin;
	fin.open("Dati.txt", ios::in);
	if (!fin) return -1;
	for (int k = 0; k < nc; k++)
		fin >> stp[k];
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			fin >> Dip[i][j];
	fin.close();
	Dipendenti* pdip = new Dipendenti(stp, Dip);
	int DMin = 0; int DMax = 0;
	cout << "Numero dipendenti: " << pdip->totaleDipendenti() << endl;
	pdip->estremiStipendio(DMax, DMin);
	cout << "Dipartimento piu' costoso: " << DMax + 1 << endl;
	cout << "Dipartimento meno costoso: " << DMin + 1 << endl;
	delete pdip;
	return 0;
}



