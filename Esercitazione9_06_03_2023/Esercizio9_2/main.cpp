#include <iostream>
using namespace std;

int main()
{
	// Dichiarazioni
	const int dim = 20;
	int a[dim];
	int n = 0;

	// Inizializzazione
	for (int* p = a; p < (a + dim); p++)
		*p = 0;

	// Acquisizione e verifica dell'input
	do {
		cout << "Inserire un numero intero compreso tra 3 e 5: ";
		cin >> n;
		if (n < 3 || n > 5)
			cout << "Attenzione: il numero deve essere compreso tra 3 e 5" << endl;
	} while (n < 3 || n > 5);

	// Elaborazione dell'array
	for (int* q = a + n; q < (a + dim); q += n)
		*q = 1;

	// Stampa a video
	cout << "a = {";
	for (int i = 0; i < dim - 1; i++)
		cout << a[i] << ", ";
	cout << a[dim - 1] << "}" << endl;

	// Parte aggiuntiva 1
	char* pc;
	for (pc = (char*)a; pc < (char*)(a + dim); pc += 4)
		*pc = 10;
	cout << "a = {";
	for (int i = 0; i < dim - 1; i++)
		cout << a[i] << ", ";
	cout << a[dim - 1] << "}" << endl;
	// Utilizzando un puntatore a char ci si sposta nell'array byte per byte.
	// Si può quindi modificare separatamente ciascuno dei 4 byte che compongono un numero
	// intero di tipo int. Il valore 10 viene quindi assegnato al quarto byte di ciascun 
	// numero intero a[i] che pertanto diventa 0x0000000A (in rappresentazione esadecimale). 
	// Tutti gli elementi di a assumono quindi valore pari a 10.

	// Parte aggiuntiva 2
	for (pc = (char*)a; pc < (char*)(a + dim); pc += 2)
		*pc = 10;
	cout << "a = {";
	for (int i = 0; i < dim - 1; i++)
		cout << a[i] << ", ";
	cout << a[dim - 1] << "}" << endl;
	// In questo caso il valore 10 viene assegnato al secondo e al quarto byte di ciascun 
	// numero intero a[i] che pertanto diventa 0x000A000A (in rappresentazione esadecimale). 
	// Tutti gli elementi di a assumono quindi valore pari a 655370.

	return 0;
}
