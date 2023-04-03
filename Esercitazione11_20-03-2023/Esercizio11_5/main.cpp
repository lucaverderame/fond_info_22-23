#include <iostream>
using namespace std;

template <typename T>
T* Sottocampiona(T a[], int n, int m) {
	if (n < 0 || m <= 0 || m > n / 2)
		return NULL;
	int k = n / m;
	if (n % m != 0)
		k += 1;
	T* s = new T[m];
	if (s == NULL) 
		return NULL;
	for (int i = 0; i < n; i += k)
		s[i / k] = a[i];
	return s;
}

int main() {
	const int dim = 10;
	int v[dim] = {0};
	cout << "Inserire " << dim << " numeri interi: " << endl;
	for (int i = 0; i < dim; i++)
		cin >> v[i];
	int t = 0;
	cout << "Inserire un numero compreso tra 1 e " << dim / 2 << endl;
	do {
		cin >> t;
		if (t <= 0 || t > dim / 2)
			cout << "Attenzione: inserire un numero compreso tra 1 e " << dim / 2 << endl;
	} while (t <= 0 || t > dim / 2);
	int* p = Sottocampiona(v, dim, t);
	if (p != NULL) {
		for (int i = 0; i < t; i++)
			cout << p[i] << " ";
		cout << endl;
		delete[] p;
	}
	return 0;
}
