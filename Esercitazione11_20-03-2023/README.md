## Undicesima esercitazione - Funzioni Ricorsive e Template

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).

### [Esercizio 11_2] - Funzioni Ricorsive

Si scriva in C++ una funzione ricorsiva che, dati due numeri interi M ed N ricevuti come parametri, verifichi che N sia positivo o nullo (altrimenti, se N è negativo, la funzione termina restituendo -1), calcoli e restituisca come valore di ritorno la potenza MN (un numero intero). 
Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione. 
Il programma chiederà all’utente di inserire una tastiera due numeri interi, chiamerà la funzione e stamperà a video il suo valore di ritorno. Le operazioni si ripeteranno finché l’utente lo desidera.
Per fare di più: estendere la funzione in modo che possa ricevere un esponente negativo. 
In tal caso, la funzione restituirà il valore M(-N) = 1 / MN.

```cpp
#include <iostream>
using namespace std;

int potenza(int base, int esponente) {
	if (esponente > 0)
		return base * potenza(base, esponente - 1);
	else
		return 1;
}

double potenza2(int base, int esponente) {
	if (esponente > 0)
		return base * potenza2(base, esponente - 1);
	else if (esponente < 0)
		return (1.0 / base) * potenza2(base, esponente + 1);
	else
		return 1;
}

int main()
{
	int n = 0;
	int m = 0;
	char c = 'n';

	do {
		cout << "Inserire il valore della base: ";
		cin >> m;
		cout << "Inserire il valore dell'esponente: ";
		cin >> n;
		if (n >= 0)
			cout << m << " elevato alla " << n << " vale " << potenza(m, n) << endl;
		else
			cout << m << " elevato alla " << n << " vale " << potenza2(m, n) << endl;
		cout << endl;
		do {
			cout << "Continuare (s/n)? ";
			cin >> c;
			if (c != 's' && c != 'n')
				cout << "Attenzione: inserire s oppure n";
		} while (c != 's' && c != 'n');
	} while (c == 's');

	return 0;
}

```
Un possibile risultato dell'esecuzione sarà:
```
Inserire il valore della base: 3
Inserire il valore dell'esponente: 4
3 elevato alla 4 vale 81

Continuare (s/n)? n

```

### [Esercizio 11_3] - Template di Funzioni

Si scriva il template di funzione C++ contaDistinti che riceva come parametri un array a di elementi di tipo T e la sua dimensione n (un numero intero), calcoli e restituisca come valore di ritorno il numero di elementi distinti contenuti nell’array a (un numero intero).
Si scriva quindi un programma per verificare il corretto funzionamento del template di funzione. 
Il programma chiederà all’utente di inserire da tastiera i valori per un array di 10 numeri interi, per un array di 10 numeri reali e per una stringa contenente al massimo 9 caratteri, chiamerà contaDistinti per ciascuno dei tre array e stamperà a video i tre valori di ritorno. Tali operazioni potranno essere ripetute finché l’utente lo desidera.
Nota: per conoscere la dimensione effettiva della stringa inserita dall’utente, si può usare la funzione strlen disponibile nella libreria cstring.
Esempio: dato l’array a = {1, 3, 5, 6, 5, 2, 1, 5, 3, 6} (n = 10), la funzione restituirà 5. L’array a contiene cioè 5 valori distinti (per la precisione si tratta dei valori: 1, 2, 3, 5, 6). 
Per fare di più: estendere il template di funzione contaDistinti in modo che riceva come parametro un ulteriore array f di numeri reali, della stessa dimensione dell’array a. La funzione assegnerà a ciascun elemento di f la frequenza del corrispondente elemento di a. La frequenza di un elemento di un array è definita come il numero di volte in cui l’elemento compare nell’array diviso per la dimensione dell’array. Nel caso dell’esempio sopra riportato, l’array f sarà dunque il seguente: 
f = {0.2, 0.2, 0.3, 0.2, 0.3, 0.1, 0.2, 0.3, 0.2, 0.2}. L’elemento 1 compare cioè 2 volte su 10, l’elemento 3 compare 2 volte su 10, l’elemento 5 compare 3 volte su 10 e così via.


```cpp
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

```

Un possibile risultato dell'esecuzione sarà:
```
Inserire i valori per un array di 10 numeri interi
Inserire il valore in posizione 1: 4
Inserire il valore in posizione 2: 3
Inserire il valore in posizione 3: 6
Inserire il valore in posizione 4: 76
Inserire il valore in posizione 5: 4
Inserire il valore in posizione 6: 35
Inserire il valore in posizione 7: 3
Inserire il valore in posizione 8: 1
Inserire il valore in posizione 9: 3
Inserire il valore in posizione 10: 4
Inserire i valori per un array di 10 numeri reali
Inserire il valore in posizione 1: 1.3
Inserire il valore in posizione 2: 4.2
Inserire il valore in posizione 3: 4.
Inserire il valore in posizione 4: 3.2
Inserire il valore in posizione 5: 3.2
Inserire il valore in posizione 6: 7.9
Inserire il valore in posizione 7: 6.9
Inserire il valore in posizione 8: 6.
Inserire il valore in posizione 9: 44.5
Inserire il valore in posizione 10: 2.3
Inserire una stringa di 10 caratteri
daisdadasd
Numero di elementi distinti: 
Per l'array di numeri interi: 6
Frequenze degli elementi: {0.3, 0.3, 0.1, 0.1, 0.3, 0.1, 0.3, 0.1, 0.3, 0.3}
Per l'array di numeri reali: 9
Frequenze degli elementi: {0.1, 0.1, 0.1, 0.2, 0.2, 0.1, 0.1, 0.1, 0.1, 0.1}
Per la stringa di caratteri: 4
Frequenze degli elementi: {0.4, 0.3, 0.1, 0.2, 0.4, 0.3, 0.4, 0.3, 0.2, 0.4}
Desideri continuare (s/n)? n

```

### [Esercizio 11_4] - Template a Funzioni 2

Si desidera realizzare un programma C++ per eseguire semplici elaborazioni su matrici quadrate di elementi di tipo generico. A tale scopo si implementino i seguenti template di funzione:
˗	Il template di funzione somma che riceva come parametri un puntatore pM a un puntatore a un oggetto di tipo T e un numero intero n e restituisca come valore di ritorno un oggetto di tipo T. Il puntatore pM punta a una matrice quadrata di n righe e n colonne di oggetti di tipo T. La funzione calcola e restituisce come valore di ritorno la somma degli elementi della matrice puntata da pM.
˗	Il template di funzione prodotto che riceva come parametri un puntatore pM a un puntatore a un oggetto di tipo T e un numero intero n e restituisca come valore di ritorno un oggetto di tipo T. Il puntatore pM punta a una matrice quadrata di n righe e n colonne di oggetti di tipo T. La funzione calcola e restituisce come valore di ritorno il prodotto degli elementi della matrice puntata da pM.
˗	Il template di funzione traccia che riceva come parametri un puntatore pM a un puntatore a un oggetto di tipo T e un numero intero n e restituisca come valore di ritorno un oggetto di tipo T. Il puntatore pM punta a una matrice quadrata di n righe e n colonne di oggetti di tipo T. La funzione calcola e restituisce come valore di ritorno la traccia degli elementi della matrice puntata da pM. Si ricorda che la traccia di una matrice quadrata è data dalla somma degli elementi sulla diagonale principale.
Si scriva quindi un programma C++ che operi come segue:
-	Chieda all’utente di inserire da tastiera la dimensione d (un numero intero) delle matrici quadrate che si vogliono elaborare.
-	Allochi dinamicamente una matrice di d x d numeri reali. A tale scopo, dichiari un puntatore a un puntatore a un numero reale pData, allochi dinamicamente un array di d puntatori a numeri reali e ne assegni il puntatore a pData, allochi dinamicamente d array di numeri reali e ne assegni i puntatori agli elementi dell’array puntato da pData.
-	Chieda all’utente di inserire da tastiera il valore di ciascun elemento della matrice così allocata.
-	Chiami somma, prodotto e traccia e stampi a video i loro valori di ritorno.
-	Deallochi la memoria precedentemente allocata e termini.
Per fare di più: utilizzare i puntatori a funzione per permettere all’utente di scegliere quale funzione chiamare. A tale scopo, il programma implementerà i seguenti ulteriori passi:
-	Dichiari un array pf di tre puntatori a funzioni che ricevano come parametri un puntatore a puntatore a numero reale e un numero intero e restituiscano come valore di ritorno un numero reale.
-	Inizializzi gli elementi dell’array pf con gli indirizzi dei tre template di funzione precedentemente implementati (somma, prodotto, traccia).
-	Chieda quindi all’utente di scegliere quale operazione desidera applicare alla matrice puntata da pData, tra le tre precedentemente implementate e i cui puntatori sono disponibili nell’array pf. 
-	Infine, utilizzando il puntatore contenuto nell’array pf, chiami la funzione corrispondente all’operazione desiderata e stampi a video il risultato.


```cpp
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
```

Un possibile risultato dell'esecuzione sarà:
```
Inserire la dimensione della matrice quadrata: 2
Inserire l'elemento in posizione (1, 1): 3
Inserire l'elemento in posizione (1, 2): 4
Inserire l'elemento in posizione (2, 1): 5
Inserire l'elemento in posizione (2, 2): 6
Somma degli elementi: 18
Prodotto degli elementi: 360
Traccia degli elementi: 9

```

### [Esercizio 11_5] - Sottocampiona

Si scriva il template di funzione Sottocampiona che riceva come parametri un array a di elementi di tipo generico T, la sua dimensione n (un numero intero positivo) e un secondo numero intero m tale che 0 < m ≤ n / 2. Il template di funzione restituisce come valore di ritorno un puntatore a un array di elementi di tipo generico T e opera in questo modo: calcola k=⌈n/m⌉ (cioè il quoziente della divisione di n per m, approssimato al numero intero immediatamente superiore), alloca dinamicamente un array s di m elementi di tipo generico T, copia in s un elemento ogni k dell’array a, partendo dal primo elemento di a. Ad esempio, assumendo che T venga istanziato con il tipo concreto int e che siano dati a = {3, 2, 8, 5, 4, 9, 6, 1, 2, 1} (n = 10) e m = 3, il template di funzione allocherà un array s di 3 elementi e lo riempirà copiandovi un elemento ogni k=⌈10/3⌉=4 elementi di a (copierà quindi il primo, il quinto e il nono elemento di a), cioè si avrà s = {3, 4, 2}. Se il valore di n o m non è valido, il template di funzione restituisce NULL. Si supponga che il template di funzione venga istanziato con un tipo concreto dotato di operatore di assegnamento.
Si scriva quindi un programma C++ che operi come segue: dichiari un array v di 10 numeri interi e chieda all’utente di inserirne i valori da tastiera, chieda all’utente di inserire un numero intero t compreso tra 1 e 5 (in caso di inserimento di un valore non valido, il programma chiederà di ripetere l’inserimento finché non pervenga un valore valido), chiami il template di funzione Sottocampiona passando l’array v, la sua dimensione e la dimensione del nuovo array t come parametri, stampi a video i valori contenuti nell’array puntato dal puntatore che il template di funzione restituisce come valore di ritorno (tale array avrà dimensione t), deallochi tale array e termini.


```cpp
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
```

Un possibile risultato dell'esecuzione sarà:
```
Inserire 10 numeri interi: 
3
4
66
4
12
23
5
6
8
76
Inserire un numero compreso tra 1 e 5
3
3 12 8 
```
