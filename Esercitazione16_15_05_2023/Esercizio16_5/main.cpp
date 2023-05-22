#include <iostream>
#include <fstream>
using namespace std;

const int nr = 20;
const int nc = 13;

int somma(int M[nr][nc], int k) {
	int s = 0;
	for (int i = 0; i < nc; i++)
		s += M[k][i];
	return s;
}

int converti(int b[], int n) {
	int num = 0;
	for (int i = 0; i < n; i++)
		num = num * 2 + b[i];
	return num;
}

class SommeBinarie {
public:
	SommeBinarie();
	SommeBinarie(const SommeBinarie& sb);
	int getN() const;
	const SommeBinarie& operator=(const SommeBinarie& sb);
	void leggi(char nomeFile[]);
	int verifica(char nomeFile[]);
private:
	int _addendi[nr][nc];
	int _risultati[nr];
	int _n;
};

SommeBinarie::SommeBinarie() {
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_addendi[i][j] = 0;
	for (int k = 0; k < nr; k++)
		_risultati[k] = 0;
	_n = 0;
}

SommeBinarie::SommeBinarie(const SommeBinarie& sb) {
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_addendi[i][j] = sb._addendi[i][j];
	for (int k = 0; k < nr; k++)
		_risultati[k] = sb._risultati[k];
	_n = sb._n;
}

int SommeBinarie::getN() const {
	return _n;
}

const SommeBinarie& SommeBinarie::operator=(const SommeBinarie& sb) {
	if (this != &sb) {
		for (int i = 0; i < nr; i++)
			for (int j = 0; j < nc; j++)
				_addendi[i][j] = sb._addendi[i][j];
		for (int k = 0; k < nr; k++)
			_risultati[k] = sb._risultati[k];
		_n = sb._n;
	}
}

void SommeBinarie::leggi(char nomeFile[]) {
	const int nch = 128;
	const int nbits = 8;
	char linea[nch]; _n = 0;
	fstream fin;
	fin.open(nomeFile, ios::in);
	if (!fin) return;
	fin >> linea;
	while (!fin.eof()) {
		int k = 0; int c = 0;
		int b[nbits] = { 0 };
		while (linea[k] != '\0') {
			int h = 0;
			while (linea[k] != '+' && linea[k] != '=' && linea[k] != ';') {
				b[h] = linea[k] - '0';
				k++;
				h++;
			}
			if (linea[k] == '+' || linea[k] == '=') {
				_addendi[_n][c] = converti(b, h);
				c++;
			}
			else
				_risultati[_n] = converti(b, h);
			k++;
		}
		fin >> linea;
		_n++;
	}
	fin.close();
}

int SommeBinarie::verifica(char nomeFile[]) {
	int ncorretti = 0;
	fstream fout;
	fout.open(nomeFile, ios::out);
	for (int k = 0; k < _n; k++)
		if (somma(_addendi, k) == _risultati[k]) {
			fout << _risultati[k] << endl;
			ncorretti++;
		}
		else fout << "Errore" << endl;
	fout.close();
	return ncorretti;
}
	 
int main() {
	SommeBinarie sb;
	sb.leggi("Dati.txt");
	int n = sb.verifica("Somme.txt");
	cout << "Numero di somme corrette: " << n << endl;
	cout << "Numero di somme errate: " << sb.getN() - n << endl;
	return 0;
}

