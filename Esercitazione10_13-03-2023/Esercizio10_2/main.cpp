#include <iostream>
using namespace std;

double minimum(double a[], int n)
{
    double min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

double maximum(double a[], int n)
{
    double max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

double sum(double a[], int n)
{
    double s = 0.0;
    for (int i = 0; i < n; i++)
            s += a[i];
    return s;
}

double sum_square(double a[], int n)
{
    double s = 0.0;
    for (int i = 0; i < n; i++)
        s += (a[i] * a[i]);
    return s;
}

double mean(double a[], int n)
{
    double s = 0.0;
    for (int i = 0; i < n; i++)
        s += a[i];
    return (s / n);
}

int main() 
{
	const int dim = 10;
    const int nf = 5;
    double v[dim];
    double (*pf[nf])(double[], int) = {minimum, maximum, sum, sum_square, mean};
    
	cout << "Inserire " << dim << " numeri interi: " << endl;
	for (int i = 0; i < dim; i++) {
		cout << "Valore " << i + 1 << ": ";
		cin >> v[i];
	}
	int scelta = 0;
	do {
		cout << "Quale operazione si desidera applicare? " << endl;
		cout << "1 - Minimo" << endl;
		cout << "2 - Massimo" << endl;
        cout << "3 - Somma" << endl;
        cout << "4 - Somma dei quadrati" << endl;
        cout << "5 - Media" << endl;
		cin >> scelta;
        if (scelta >= 1 && scelta <= 5) {
            double risultato = (*pf[scelta - 1])(v, dim);
            cout << "Risultato: " << risultato << endl;
        }
		else
			cout << "Errore: scegliere un valore tra 1 e 5" << endl;
	} while (scelta < 1 || scelta > 5);
	return 0;
}
