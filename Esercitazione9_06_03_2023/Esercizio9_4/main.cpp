#include <iostream>
using namespace std;

const int dim = 3;

void righe_negative(int A[dim][dim], int* b[dim])
{
	for (int** parr = b; parr < (b + dim); parr++)
		*parr = NULL;

	int somma = 0; int** pb = b;
	for (int* p = &A[0][0]; p < &A[0][0] + (dim * dim); p += dim) {
		for (int* q = p; q < (p + dim); q++)
			somma += *q;
		if (somma < 0) {
			*pb = p;
			pb++;
		}
		somma = 0;
	}
}

// Parte 2
struct sottomatrice {
	int alto;
	int basso;
	int sinistra;
	int destra;
};

int righe_negative_2(int A[dim][dim], int* b[dim], sottomatrice s)
{
	for (int** parr = b; parr < (b + dim); parr++)
		*parr = NULL;
	
	if (s.alto < 0 || s.alto >= dim || s.basso < 0 || s.basso >= dim ||
		s.sinistra < 0 || s.sinistra >= dim || s.destra < 0 || s.destra >= dim ||
		s.alto >= s.basso || s.sinistra >= s.destra)
		return 0;
	
	int* pinizio = &A[s.alto][s.sinistra];
	int* pfine = &A[s.basso][s.destra];

	int somma = 0; int** pb = b;
	for (int* p = pinizio; p < pfine; p += dim) {
		for (int* q = p; q < (p + (s.destra - s.sinistra + 1)); q++)
			somma += *q;
		if (somma < 0) {
			*pb = p;
			pb++;
		}
		somma = 0;
	}
	return 1;
}

int main()
{
	int matrice[dim][dim];
	int* prighe[dim];

	cout << "Inserire gli elementi di una matrice A (" << dim << " x " << dim << ")" << endl;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++) {
			cout << "Elemento A[" << i << "][" << j << "]: ";
			cin >> matrice[i][j];
		}
	cout << endl;

	righe_negative(matrice, prighe);
	
	cout << "Righe con somma negativa:" << endl;
	int k = 0;
	while (prighe[k] != NULL && k < dim) {
		for (int h = 0; h < dim; h++)
			cout << *prighe[k]++ << " ";
		cout << endl;
		k++;
	}
	if (k == 0) cout << "Nessuna";
	cout << endl;
	
	// Parte 2
	sottomatrice sm = {0, 1, 1, 2};
	int numrighe = (sm.basso - sm.alto) + 1;
	int numcolonne = (sm.destra - sm.sinistra) + 1;
	if (righe_negative_2(matrice, prighe, sm) == 0)
		return -1;
	cout << "Righe con somma negativa:" << endl;
	k = 0;
	while (prighe[k] != NULL && k < numrighe) {
		for (int h = 0; h < numcolonne; h++)
			cout << *prighe[k]++ << " ";
		cout << endl;
		k++;
	}
	if (k == 0) cout << "Nessuna";
	cout << endl;

	return 0;
}
