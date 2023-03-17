#include <iostream>
#include <cmath>
using namespace std;

double prodotto_scalare(double* x, double* y, int n)
{
	double somma = 0;
	double* q = y;
	for (double* p = x; p < (x + n) && q < (y + n); p++) {
		somma += *p * *q;
		q++;
	}
	return somma;
}

// Implementazione alternativa, inserendo l'intera applicazione 
// dell'aritmetica dei puntatori nell'istruzine for
double prodotto_scalare_2(double* x, double* y, int n)
{
	double somma = 0;
	for (double* p = x, *q = y; p < (x + n) && q < (y + n); p++, q++)
		somma += *p * *q;
	return somma;
}

// Implementazione che calcola anche la distanza e restuisce
// l'output in una struttura passata come parametro di uscita
struct risultati {
	double prodotto;
	double distanza;
};

// Parte 2
void prodotto_scalare_e_distanza(double* x, double* y, int n, risultati* r)
{
	double somma = 0.0;
	double somma_quadrati = 0.0;
	double* q = y;
	for (double* p = x; p < (x + n) && q < (y + n); p++) {
		somma += *p * *q;
		somma_quadrati = (*p - *q) * (*p - *q);
		q++;
	}
	r->prodotto = somma;
	r->distanza = sqrt(somma_quadrati);
}

int main ()
{
	const int dim = 5;
	double a[dim], b[dim];

	cout << "Inserire due array, a e b, di " << dim << " numeri reali" << endl;
	for (int k = 0; k < dim; k++) {
		cout << "Inserire a[" << k << "]: ";
		cin >> a[k];
		cout << "Inserire b[" << k << "]: ";
		cin >> b[k];
	}
	cout << endl;

	cout << "Il prodotto scalare di: " << endl << "a = {" << a[0];
	for (int i = 1; i < dim; i++)
		cout << ", " << a[i];
	cout << "}" << " e" << endl << "b = {" << b[0];
	for (int j = 1; j < dim; j++)
		cout << ", " << b[j];
	cout << "}" << " e' " << prodotto_scalare(a, b, dim) << endl;
	cout << endl;
	
	// Parte 2
	risultati ris;
	prodotto_scalare_e_distanza(a, b, dim, &ris);
	cout << "Il prodotto scalare di: " << endl << "a = {" << a[0];
	for (int i = 1; i < dim; i++)
		cout << ", " << a[i];
	cout << "}" << " e" << endl << "b = {" << b[0];
	for (int j = 1; j < dim; j++)
		cout << ", " << b[j];
	cout << "}" << " e' " << ris.prodotto << endl;
	cout << "La distanza tra gli stessi due array vale " << ris.distanza << endl;
	cout << endl;
	
	return 0;
}
