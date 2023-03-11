#include <iostream>
using namespace std;

int main()
{
    // Dichiarazioni
    int a = 0; int b = 0; 
    int c1 = 0; int c2 = 0; int c3 = 0; int c4 = 0;
	int& r = a;
    int* pa = &a; int* pb = &b;
    int** ppa = &pa;
    const int* pca = &a;
	
    // Lettura di a e b
    cout << "Inserire due numeri interi: ";
	cin >> a >> b;
    
    // Stampa di a e b
    cout << "Hai inserito i seguenti valori: ";
	cout << *pa << " e " << *pb << endl;
    
    // Stampa dei valori dei puntatori pa e pb
    cout << "I puntatori pa e pb valgono: " << pa << " e " << pb << endl;
    
    // Stampa del valore di ppa
    cout << "Il puntatore a puntatore ppa vale: " << *ppa << endl;
    
    // Stampa a video del valore puntato dal puntatore puntato da ppa
    cout << "Valore della variabile puntata dal puntatore al quale punta ppa: " << **ppa << endl;
    
    // Stampa del valore puntato dal puntatore a costante
    cout << "Il valore puntato dal puntatore a costante ppc vale: " << *pca << endl;
    
    // Assegnamenti
    c1 = *pa;
    c2 = **ppa;
    c3 = *pca;
    c4 = r;
    cout << "Le variabili c1, c2, c3 e c4 hanno i seguenti valori: " << endl;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c1 << endl;
    cout << "c3: " << c1 << endl;
    cout << "c4: " << c1 << endl;
    
    // Svolgimento di operazioni su a
    a += 3;
    cout << "a adesso vale " << a << endl;
    *pa += 3;
    cout << "a adesso vale " << a << endl;
    **ppa += 3;
    cout << "a adesso vale " << a << endl;
    r += 3;
    cout << "a adesso vale " << a << endl;
    
    // Assegnamento di pa e ripetizione delle operazioni precedenti
    a = c1;
    pa = pb;
    a += 3;
    cout << "a adesso vale " << a << endl;
    *pa += 3;
    cout << "a adesso vale " << a << endl;
    **ppa += 3;
    cout << "a adesso vale " << a << endl;
    r += 3;
    cout << "a adesso vale " << a << endl;
    cout << "b adesso vale " << b << endl;
    
    // *pca += 5;   
    // Non compila perché non posso modificare una variabile puntata da un puntatore a costante
    
	return 0;
}
