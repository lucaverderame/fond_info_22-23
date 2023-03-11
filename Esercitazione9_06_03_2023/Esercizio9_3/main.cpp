#include <iostream>
using namespace std;

void swap(int* a, int* b, int* c)
{
	int tmp = *b;
	*b = *a;
	*a = *c;
	*c = tmp;
}

void swap_2(int& a, int& b, int& c) 
{
	int tmp = b;
	b = a;
	a = c;
	c = tmp;	
}

int main ()
{
	int x, y, z;
	cout << "Inserire tre numeri interi" << endl;
	cout << "Primo numero: ";
	cin >> x;
	cout << "Secondo numero: ";
	cin >> y;
	cout << "Terzo numero: ";
	cin >> z;
	cout << endl;

	swap(&x, &y, &z);

	cout << "I valori ruotati sono" << endl;
	cout << "Primo numero: " << x << endl;
	cout << "Secondo numero: " << y << endl;
	cout << "Terzo numero: " << z << endl;
	cout << endl;
	
	// Parte 2
	swap_2(x, y, z);
	cout << "I valori ancora ruotati sono" << endl;
	cout << "Primo numero: " << x << endl;
	cout << "Secondo numero: " << y << endl;
	cout << "Terzo numero: " << z << endl;
	cout << endl;

	return 0;
}

// Se non si vogliono utilizzare i puntatori si può usare il passaggio per riferimento.
// In C++, in realtà, è consigliabile utilizzare il passaggio per riferimento
// anziché il passaggio per puntatore che deriva dal vecchio C.
