#include <iostream>
using namespace std;

int main() 
{
	const int d = 10;
	double* px = NULL;
	px = new double[d];
	for (int i = 0; i < d; i++)
		px[i] = 0;

	int k = 0; double x = 0; int dim = d;
	while (k < 2 * d) {
		cout << "Inserire un valore: ";
		cin >> x;
		if (x < 0) break;
		if (k == d) {
			double* pt = new double[2 * d];
			for (int j = 0; j < k; j++)
				pt[j] = px[j];
			pt[k] = x;
			delete[] px;
			px = pt;
			dim = 2 * d;
		}
		else
			px[k] = x;
		k++;
	}

	double somma = 0.0;
	cout << "Valori inseriti: " << endl << "{ ";
	for (int i = 0; i < dim - 1; i++) {
		cout << px[i] << ", ";
		somma += px[i];
	}
	cout << px[dim - 1] << " } " << endl;
	somma += px[dim - 1];
	cout << "Somma: " << somma << endl;

	delete[] px;
	return 0;
}
