#include <iostream>
using namespace std;

template <typename T>
T somma(T** pM, int n) {
	T s = 0;
	for (T** p = pM; p < (pM + n); p++)
		for (T* q = *p; q < (*p + n); q++)
			s += *q;
	return s;
}

template <typename T>
T prodotto(T** pM, int n) {
	T pr = 1;
	for (T** p = pM; p < (pM + n); p++)
		for (T* q = *p; q < (*p + n); q++)
			pr *= *q;
	return pr;
}

template <typename T>
T traccia(T** pM, int n) {
	T tr = 0; int k = 0;
	for (T** p = pM; p < (pM + n); p++) {
		tr += *(*p + k);
		k++;
	}
	return tr;
}

int main() 
{
	int d;
	cout << "Inserire la dimensione della matrice quadrata: ";
	cin >> d;
	if (d > 0) {
		double** pData = new double*[d];
		if (pData == NULL) return -1;
		for (int i = 0; i < d; i++) {
			pData[i] = new double[d];
			if (pData == NULL) return -1;
		}
		for (int h = 0; h < d; h++)
			for (int k = 0; k < d; k++) {
				cout << "Inserire l'elemento in posizione (" << h + 1 << ", " << k + 1 << "): ";
				cin >> pData[h][k];
			}
		cout << "Somma degli elementi: " << somma(pData, d) << endl;
		cout << "Prodotto degli elementi: " << prodotto(pData, d) << endl;
		cout << "Traccia degli elementi: " << traccia(pData, d);
		for (int j = 0; j < d; j++)
			delete[] pData[j];
		delete[] pData;
	}
	return 0;
}
