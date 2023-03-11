# Nona esercitazione - 06/03/23

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).

### [Esercizio 9_1] - Introduzione

Si scriva un programma C++ che operi come segue:

- Dichiari due variabili a e b di tipo intero e le inizializzi a zero.
- Dichiari quattro variabili c1, c2, c3 e c4 di tipo intero e le inizializzi a zero.
- Dichiari la variabile r di tipo riferimento ad intero e le assegni la variabile a.
- Dichiari le variabili puntatore pa e pb che puntino alle variabili a e b e la variabile puntatore ppa che punti al puntatore pa.
- Dichiari il puntatore a costante pca che punti alla variabile a.
- Legga da tastiera i valori di a e b e stampi a video i valori inseriti utilizzando i puntatori pa e pb.
- Stampi a video i valori di pa e pb. Che cosa viene stampato?
- Stampi a video il valore puntato da ppa. Che cosa viene stampato?
- Stampi a video il valore puntato dal puntatore al quale ppa punta. Che cosa viene stampato?
- Stampi a video il valore puntato da pca. Che cosa viene stampato?
- Assegni a c1 il valore puntato da pa, a c2 il valore puntato dal puntatore al quale punta ppa, a c3 il valore puntato da pca e a c4 il valore di r. Stampi quindi a video i valori di c1, c2, c3 e c4. Che cosa viene stampato? Perché?
- Sommi 3 ad a e stampi a video il valore di a; sommi 3 al valore puntato da pa e stampi a video il valore di a; sommi 3 al valore puntato dal puntatore al quale punta ppa e stampi a video il valore di a; sommi 3 a r e stampi a video il valore di a. Quale è l'effetto di queste operazioni sul valore della variabile a? Perché accade ciò che osserviamo nelle stampe dei valori di a dopo ciascuna operazione?
- Assegni ad a il valore di c1 e a pa il valore di pb e ripeta le operazioni le quattro operazioni svolte al punto precedente. Al termine stampi a video anche il valore di b. Che cosa è successo?  Perché accade ciò che osserviamo nelle stampe dei valori di a dopo ciascuna operazione e nella stampa finale del valore di b?
- Che cosa succederebbe se si provasse a sommare 5 al valore puntato dal puntatore pca?

> :warning: Un puntatore a costante si può anche assegnare l'indirizzo di una variabile. Ma non é vero il contrario: l'indirizzo di una costante può essere assegnato solo a un puntatore a costante. In altre parole il C++ accetta conversioni da puntatore a variabile a puntatore a costante, ma non viceversa.

```cpp
#include <iostream>
using namespace std;

int main()
{
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
    // Un puntatore a costante si può anche assegnare l'indirizzo di una variabile,
    // Ma non é vero il contrario: l'indirizzo di una costante può essere assegnato solo a un puntatore a costante.
    // In altre parole il C++ accetta conversioni da puntatore a variabile a puntatore a costante, ma non viceversa.
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
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;
    cout << "c4: " << c4 << endl;

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

```

> L'esecuzione del programma ha come risultato:

```cpp 
Inserire due numeri interi: 12
23
Hai inserito i seguenti valori: 12 e 23
I puntatori pa e pb valgono: 0xffffd20f0b98 e 0xffffd20f0b9c
Il puntatore a puntatore ppa vale: 0xffffd20f0b98
Valore della variabile puntata dal puntatore al quale punta ppa: 12
Il valore puntato dal puntatore a costante ppc vale: 12
Le variabili c1, c2, c3 e c4 hanno i seguenti valori: 
c1: 12
c2: 12
c3: 12
c4: 12
a adesso vale 15
a adesso vale 18
a adesso vale 21
a adesso vale 24
a adesso vale 15
a adesso vale 15
a adesso vale 15
a adesso vale 18
b adesso vale 29
```

### [Esercizio 9_2] Aritmetica dei puntatori

Si scriva un programma C++ che operi come segue:

- Dichiari un array a di 20 numeri interi.
- Utilizzando l'aritmetica dei puntatori, inizializzi a zero tutti gli elementi dell'array a. 
- Chieda all'utente di inserire da tastiera un numero intero n compreso tra 3 e 5. Nel caso in cui il numero inserito non sia compreso in tale intervallo, il programma continuerà a chiedere all'utente di operare l'inserimento finché non venga inserito un numero compreso nell'intervallo richiesto.
- Utilizzando l'aritmetica dei puntatori, assegni il valore 1 a tutti gli elementi dell'array a il cui indice è pari al numero n inserito dall'utente o è un suo multiplo intero. 
-Stampi a video l'array a così modificato e termini.

Per approfondire:

- Dichiarare un puntatore a carattere pc e scandire l'array a utilizzando l'aritmetica dei puntatori applicata al puntatore pc. L'incremento di pc ad ogni iterazione sarà pari a 4. Inoltre, ad ogni iterazione si assegnerà il valore 10 all'elemento puntato da pc. Al termine della scansione, stampare a video l'array a così modificato. Che cosa viene stampato? Perché? Ripetere ora le operazioni sopra descritte, applicando ad ogni iterazione un incremento di pc pari a 2. Al termine della scansione, stampare nuovamente a video l'array a. Che cosa viene stampato? Perché?


> Utilizzando un puntatore a char ci si sposta nell'array byte per byte. Si può quindi modificare separatamente ciascuno dei 4 byte che compongono un numero intero di tipo int. Il valore 10 viene quindi assegnato al quarto byte di ciascun numero intero a[i] che pertanto diventa 0x0000000A (in rappresentazione esadecimale).Tutti gli elementi di a assumono quindi valore pari a 10.

> Nel secondo caso, il valore 10 viene assegnato al secondo e al quarto byte di ciascun numero intero a[i] che pertanto diventa 0x000A000A (in rappresentazione esadecimale). Tutti gli elementi di a assumono quindi valore pari a 655370.

> Attenzione: per poter compilare il programma così modificato occorre convertire esplicitamente i puntatori ad int in puntatori a char.

```cpp
#include <iostream>
using namespace std;

int main(){

	const int dim = 20;
	int a[dim];
	int n = 0;

	for (int* p = a; p < (a + dim); p++)
		*p = 0;

    	// Acquisizione e verifica dell'input
	do {
		cout << "Inserire un numero intero compreso tra 3 e 5: ";
		cin >> n;
		if (n < 3 || n > 5)
			cout << "Attenzione: il numero deve essere compreso tra 3 e 5" << endl;
	} while (n < 3 || n > 5);

	for (int* p = a + n; p < (a + dim); p += n)
		*p = 1;

		// Stampa a video
	cout << "a = {";
	for (int* p = a; p < (a+dim); p++)
		cout << *p << ", ";
    cout << "\b\b}" << endl;

    char* pc;
	for (pc = (char*)a; pc < (char*)(a + dim); pc += 4)
		*pc = 10;
	cout << "a = {";
	for (int* p = a; p < (a+dim); p++)
		cout << *p << ", ";
    cout << "\b\b}" << endl;
    // Utilizzando un puntatore a char ci si sposta nell'array byte per byte.
	// Si può quindi modificare separatamente ciascuno dei 4 byte che compongono un numero
	// intero di tipo int. Il valore 10 viene quindi assegnato al quarto byte di ciascun
	// numero intero a[i] che pertanto diventa 0x0000000A (in rappresentazione esadecimale).
	// Tutti gli elementi di a assumono quindi valore pari a 10.

    for (pc = (char*)a; pc < (char*)(a + dim); pc += 2)
		*pc = 10;
	cout << "a = {";
	for (int* p = a; p < (a+dim); p++)
		cout << *p << ", ";
    cout << "\b\b}" << endl;
    // In questo caso il valore 10 viene assegnato al secondo e al quarto byte di ciascun
	// numero intero a[i] che pertanto diventa 0x000A000A (in rappresentazione esadecimale).
	// Tutti gli elementi di a assumono quindi valore pari a 655370.
}

```
> L'esecuzione del programma ha come risultato:

```cpp 
Inserire un numero intero compreso tra 3 e 5: 4
a = {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0}
a = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}
a = {655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370, 655370}

```

### [Esercizio 9_3] Passaggio di puntatori a funzione

Si scriva la funzione C++ swap che riceva come parametri i puntatori a tre numeri interi a, b e c e ne ruoti i valori, ovvero: a b viene assegnato il valore di a, a c viene assegnato il valore di b e ad a viene assegnato il valore di c. Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione. Il programma chiederà all'utente di immettere da tastiera tre numeri interi, chiamerà la funzione swap per ruotarne i valori e stamperà a video il risultato.

Esempio: se a vale 3, b vale 5 e c vale 10, dopo la chiamata alla funzione si avrà che a varrà 10, b varrà 3 e c varrà 5. 

Se non si volessero utilizzare i puntatori come si potrebbe re-implementare la funzione? Per verificarlo, scrivete una funzione swap_2 che scambi i valori senza usare i puntatori e utilizzatela nel programma sviluppato. Confrontate il codice dell'implementazione con i puntatori e di quella senza i puntatori. In che cosa si differenziano?


```cpp
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

```

> L'esecuzione del programma ha come risultato:

```cpp 
Inserire tre numeri interi
Primo numero: 12
Secondo numero: 4
Terzo numero: 5

I valori ruotati sono
Primo numero: 5
Secondo numero: 12
Terzo numero: 4

I valori ancora ruotati sono
Primo numero: 4
Secondo numero: 5
Terzo numero: 12
```

### [Esercizio 9_4] Puntatori e Matrici

Si scriva la funzione C++ righenegative che riceva come parametri una matrice A di n righe e n colonne (n è dichiarato come una costante intera all'inizio del programma) e un array di puntatori a numeri interi b. L'array b è costituito anche esso dallo stesso numero costante n di elementi e la funzione lo inizializza in modo tale che tutti gli elementi siano NULL. La funzione scandirà la matrice A riga per riga ed inserirà nell'array b i puntatori alle righe per le quali la somma degli elementi risulta essere un numero negativo. Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione: il programma chiederà all'utente di immettere da tastiera gli elementi della matrice A, chiamerà la funzione righe_negative e stamperà a video le righe la cui somma degli elementi è un numero negativo.

```cpp
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



	return 0;
}

```

> L'esecuzione del programma ha come risultato:

```cpp 
Inserire gli elementi di una matrice A (3 x 3)
Elemento A[0][0]: 2
Elemento A[0][1]: -4
Elemento A[0][2]: 1
Elemento A[1][0]: 3
Elemento A[1][1]: 2
Elemento A[1][2]: 3
Elemento A[2][0]: -12
Elemento A[2][1]: 3
Elemento A[2][2]: 4

Righe con somma negativa:
2 -4 1 
-12 3 4 
```