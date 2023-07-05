#include <fstream>
#include <iostream>
#include "List.h"

// Tipi di elementi
const int operando = 0;
const int operatore = 1;
const int errore = 2;

// Operatori
const int somma = 1;
const int differenza = 2;
const int prodotto = 3;
const int rapporto = 4;

// Lunghezza stringhe
const int dim = 128;

// Legge una porzione di stringa ed estrae un elemento (operando o operatore)
int leggi(char espressione[], int n, int& tipo, int& valore)
{
	int k = n;
	while(espressione[k] == ' ')
		k++;
	if (espressione[k] >= '0' && espressione[k] <= '9') {
		valore = 0;
		tipo = operando;
		while (espressione[k] >= '0' && espressione[k] <= '9') {
			valore = valore * 10 + (espressione[k] - '0');
			k++;
		}
		return k;
	}
	else {
		tipo = operatore;
		switch(espressione[k]) {
			case '+':
				valore = somma;
				break;
			case '-':
				valore = differenza;
				break;
			case '*':
				valore = prodotto;
				break;
			case '/':
				valore = rapporto;
				break;
			default:
				tipo = errore;
				valore = -1;
				break;
		}
		k++;
		return k;
	}
}

// Esegue un'operazione
double calcola(double operando1, double operando2, int operatore)
{
	double risultato = 0;
	switch(operatore) {
		case somma:
			risultato = operando1 + operando2;
			break;
		case differenza:
			risultato = operando1 - operando2;
			break;
		case prodotto:
			risultato = operando1 * operando2;
			break;
		case rapporto:
			if (operando2 != 0.0)
				risultato = operando1 / operando2;
			break;
	}
	return risultato;
}

int main()
{
	List<double> stack;

	fstream fin;
	fstream fout;
	char linea[dim];

	fin.open("operazioni.txt", ios::in);
	fout.open("risultati.txt", ios::out);
	if (!fin)
		return -1;

	int n = 0;
	fin.getline(linea, dim, '\n');
	while (!fin.eof()) {
		int k = 0;
		cout << "Operazione: " << linea << endl;
		while (linea[k] != '\0') {
			int valore = 0; int tipo = 0;
			k = leggi(linea, k, tipo, valore);
			if (tipo != errore) {
				if (tipo == operando)
					stack.insertFront(double(valore));
				else if (tipo == operatore) {
					if (stack.numItems() >= 2) {
						double op2 = stack.getHead()->getData();
						stack.removeFront();
						double op1 = stack.getHead()->getData();
						stack.removeFront();
						int op = valore;
						double res = calcola(op1, op2, op);
						stack.insertFront(res);
					}
				}
			}
			else {
				cout << "Errore di sintassi" << endl;
				fin.close();
				fout.close();
				return -1;
			}
		}
		double risultato = stack.getHead()->getData();
		stack.clear();
		fout << risultato << endl;
		cout << "Risultato: " << risultato << endl;
		fin.getline(linea, dim, '\n');
		n++;
	}

	fin.close();
	fout.close();
	cout << "Eseguite " << n << " operazioni" << endl;

	return 0;
}
