#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
int contaDistinti(T a[], int n) {
	int c = 1; int i, j;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++)
			if (a[j] == a[i])
				break;
		if (i == j)
			c++;
	}
	return c;
}

template <typename T>
int contaDistinti2(T a[], int n, double f[]) {
	int c = 1;
	f[0] = 1.0 / n;
	for (int i = 1; i < n; i++) {
		f[i] = 1.0 / n;
		int t = 0;
		for (int j = 0; j < i; j++)
			if (a[j] == a[i]) {
				f[j] += 1.0 / n;
				f[i] += 1.0 / n;
				t = 1;
			}
		if (t == 0) 
			c++;
	}
	return c;
}

int main()
{
	const int dim = 10;
	int v[dim] = { 0 };
	double w[dim] = { 0.0 };
	char s[dim] = "";
	double fr1[dim] = { 0 };
	double fr2[dim] = { 0 };
	double fr3[dim] = { 0 };

	char c = 'n';
	do {
		cout << "Inserire i valori per un array di " << dim << " numeri interi" << endl;
		for (int i = 0; i < dim; i++) {
			cout << "Inserire il valore in posizione " << i + 1 << ": ";
			cin >> v[i];
		}
		cout << "Inserire i valori per un array di " << dim << " numeri reali" << endl;
		for (int i = 0; i < dim; i++) {
			cout << "Inserire il valore in posizione " << i + 1 << ": ";
			cin >> w[i];
		}
		cout << "Inserire una stringa di " << dim -1 << " caratteri" << endl;
		cin >> s;
		int l = strlen(s);
		cout << "Numero di elementi distinti: " << endl;
		cout << "Per l'array di numeri interi: " << contaDistinti2(v, dim, fr1) << endl;
		cout << "Frequenze degli elementi: {";
		for (int i = 0; i < dim - 1; i++)
			cout << fr1[i] << ", ";
		cout << fr1[dim - 1] << "}" << endl;
		cout << "Per l'array di numeri reali: " << contaDistinti2(w, dim, fr2) << endl;
		cout << "Frequenze degli elementi: {";
		for (int i = 0; i < dim - 1; i++)
			cout << fr2[i] << ", ";
		cout << fr2[dim - 1] << "}" << endl;
		cout << "Per la stringa di caratteri: " << contaDistinti2(s, l, fr3) << endl;
		cout << "Frequenze degli elementi: {";
		for (int i = 0; i < dim - 1; i++)
			cout << fr3[i] << ", ";
		cout << fr3[dim - 1] << "}" << endl;
		do {
			cout << "Desideri continuare (s/n)? ";
			cin >> c;
			if (c != 's' && c != 'n')
				cout << "Inserire s oppure n" << endl;
		} while (c != 's' && c != 'n');
	} while (c == 's');
	
	return 0;
}
