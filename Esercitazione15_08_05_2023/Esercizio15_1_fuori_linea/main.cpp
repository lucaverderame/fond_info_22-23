#include "array.h"

int main() {

	const int dim = 10;
	array<int> a(dim);

	cout << "Inserire " << dim << " numeri interi:" << endl;
	a.read();
	cout << "Hai inserito i seguenti numeri: ";
	a.print();

	int somma = 0;
	for (int k = 0; k < dim; k++)
		somma += a[k];
	cout << "Somma degli elementi inseriti: " << somma << endl;

	return 0;
}
