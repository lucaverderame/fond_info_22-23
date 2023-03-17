## Decima esercitazione - Puntatori e Allocazione Dinamica della Memoria

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).

### [Esercizio 10_1] - Puntatori a strutture

Si scriva la funzione C++ prodotto_scalare che riceva come parametri il puntatore px al primo elemento di un array di numeri reali, il puntatore py al primo elemento di un array di numeri reali e la dimensione comune n dei due array (un numero intero). Utilizzando l'aritmetica dei puntatori, la funzione dovrà scandire i due array e calcolarne il prodotto scalare, restituito come valore di ritorno (un numero reale). Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione. Il programma chiederà all'utente di immettere da tastiera i valori per i due array, chiamerà la funzione prodotto_scalare e ne stamperà a video il valore di ritorno.

Esempio: se l'array puntato da px vale {1.0, 3.0, 2.5, 0.0, 1.2} e l'array puntato da py vale {2.0, 1.0, 2.0, 3.8, 10.0} (si ha quindi n = 5), la funzione restituisce il valore del prodotto scalare dei due array, ovvero: 1.0 × 2.0 + 3.0 × 1.0 + 2.5 × 2 + 0.0 × 3.8 + 1.2 × 10.0 = 22.0.

> :warning: Per fare di più: calcolare anche la distanza tra gli array puntati da px e da py e restituire, come parametro di uscita (anziché come valore di ritorno) una struttura che contenga due campi, il prodotto scalare e la distanza calcolati dalla funzione (due numeri reali). Modificare poi il programma di prova in modo che stampi entrambi i valori restituiti dalla funzione.

```cpp
#include <iostream>
#include <cmath>
using namespace std;

double prodotto_scalare(double* x, double* y, int n)
{
	double somma = 0;
	double* q = y;
	for (double* p = x; p < (x + n) && q < (y + n); p++) {
		somma += *p * *q;
		q++;
	}
	return somma;
}

// Implementazione alternativa, inserendo l'intera applicazione 
// dell'aritmetica dei puntatori nell'istruzine for
double prodotto_scalare_2(double* x, double* y, int n)
{
	double somma = 0;
	for (double* p = x, *q = y; p < (x + n) && q < (y + n); p++, q++)
		somma += *p * *q;
	return somma;
}

// Implementazione che calcola anche la distanza e restuisce
// l'output in una struttura passata come parametro di uscita
struct risultati {
	double prodotto;
	double distanza;
};

// Parte 2
void prodotto_scalare_e_distanza(double* x, double* y, int n, risultati* r)
{
	double somma = 0.0;
	double somma_quadrati = 0.0;
	double* q = y;
	for (double* p = x; p < (x + n) && q < (y + n); p++) {
		somma += *p * *q;
		somma_quadrati = (*p - *q) * (*p - *q);
		q++;
	}
	r->prodotto = somma;
	r->distanza = sqrt(somma_quadrati);
}

int main ()
{
	const int dim = 5;
	double a[dim], b[dim];

	cout << "Inserire due array, a e b, di " << dim << " numeri reali" << endl;
	for (int k = 0; k < dim; k++) {
		cout << "Inserire a[" << k << "]: ";
		cin >> a[k];
		cout << "Inserire b[" << k << "]: ";
		cin >> b[k];
	}
	cout << endl;

	cout << "Il prodotto scalare di: " << endl << "a = {" << a[0];
	for (int i = 1; i < dim; i++)
		cout << ", " << a[i];
	cout << "}" << " e" << endl << "b = {" << b[0];
	for (int j = 1; j < dim; j++)
		cout << ", " << b[j];
	cout << "}" << " e' " << prodotto_scalare(a, b, dim) << endl;
	cout << endl;
	
	// Parte 2
	risultati ris;
	prodotto_scalare_e_distanza(a, b, dim, &ris);
	cout << "Il prodotto scalare di: " << endl << "a = {" << a[0];
	for (int i = 1; i < dim; i++)
		cout << ", " << a[i];
	cout << "}" << " e" << endl << "b = {" << b[0];
	for (int j = 1; j < dim; j++)
		cout << ", " << b[j];
	cout << "}" << " e' " << ris.prodotto << endl;
	cout << "La distanza tra gli stessi due array vale " << ris.distanza << endl;
	cout << endl;
	
	return 0;
}

```
Un possibile risultato dell'esecuzione sarà:
```
Inserire due array, a e b, di 5 numeri reali
Inserire a[0]: 1.0
Inserire b[0]: 2.0
Inserire a[1]: 3
Inserire b[1]: 1
Inserire a[2]: 2.5
Inserire b[2]: 2
Inserire a[3]: 0
Inserire b[3]: 3.8
Inserire a[4]: 1.2
Inserire b[4]: 10

Il prodotto scalare di: 
a = {1, 3, 2.5, 0, 1.2} e
b = {2, 1, 2, 3.8, 10} e' 22

Il prodotto scalare di: 
a = {1, 3, 2.5, 0, 1.2} e
b = {2, 1, 2, 3.8, 10} e' 22
La distanza tra gli stessi due array vale 8.8
```

### [Esercizio 10_2] - Puntatori a funzione

Si desidera realizzare un programma C++ per eseguire semplici elaborazioni su array di numeri reali. A tale scopo si implementino le seguenti funzioni:
- La funzione minimum che riceva come parametri un array a di numeri reali e la sua dimensione n (un numero intero) e restituisca come valore di ritorno il valore del minimo elemento dell’array (un numero reale). 
- La funzione maximum che riceva come parametri un array a di numeri reali e la sua dimensione n (un numero intero) e restituisca come valore di ritorno il valore del massimo elemento dell’array (un numero reale).
- La funzione sum che riceva come parametri un array a di numeri reali e la sua dimensione n (un numero intero) e restituisca come valore di ritorno la somma degli elementi dell’array (un numero reale).
- La funzione sum_square che riceva come parametri un array a di numeri reali e la sua dimensione n (un numero intero) e restituisca come valore di ritorno la somma dei quadrati degli elementi dell’array (un numero reale).
- La funzione mean che riceva come parametri un array a di numeri reali e la sua dimensione n (un numero intero) e restituisca come valore di ritorno la media degli elementi dell’array (un numero reale). Per semplicità si supponga che la dimensione n dell’array sia valida (cioè sia un numero positivo).
Si scriva quindi un programma C++ che operi come segue:
- Dichiari un array v di 10 numeri reali.
- Dichiari un array pf di cinque puntatori a funzione che ricevano come parametri un array di numeri reali e un numero intero e restituiscano come valore di ritorno un numero reale e inizializzi gli elementi dell’array pf con gli indirizzi delle cinque funzioni precedentemente implementate (minimum, maximum, sum, sum_square, mean). 
- Chieda all’utente di inserire da tastiera i valori degli elementi dell’array v.
- Chieda all’utente di scegliere quale operazione desidera applicare agli elementi dell’array v, tra le cinque precedentemente implementate e i cui puntatori sono disponibili in pf.
- Utilizzando il puntatore contenuto nell’array pf, chiami la funzione corrispondente all’operazione desiderata e stampi a video il risultato.
> :warning: Per fare di più: vogliamo aggiungere un’ulteriore operazione, la somma degli inversi degli elementi dell’array che hanno valore diverso da 0. Aggiungere, quindi, la funzione corrispondente e modificare il programma per tenere conto di questa nuova operazione. 
> :warning: I puntatori a funzione ci permetteranno di ridurre notevolmente il numero di modifiche che occorre apportare al programma!

```cpp
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
```
Un possibile risultato dell'esecuzione sarà:
```
Inserire 10 numeri interi: 
Valore 1: 6
Valore 2: 23
Valore 3: 5
Valore 4: 2
Valore 5: 77
Valore 6: 9
Valore 7: 12
Valore 8: 3
Valore 9: 2
Valore 10: 54
Quale operazione si desidera applicare? 
1 - Minimo
2 - Massimo
3 - Somma
4 - Somma dei quadrati
5 - Media
3
Risultato: 193
```

### [Esercizio 10_3] - Array di Puntatori

Il file Date.txt contiene per ciascuna riga una data espressa nel formato gg/mm/aaaa. Il numero di righe contenute nel file non è noto al programmatore. Si scriva un programma C++ che apra in lettura il file Date.txt, legga ciascuna riga in una stringa di 10 caratteri, scandisca la stringa e stampi a video la data corrispondente espressa nel formato giorno nome_del_mese anno, dove giorno e anno sono la rappresentazione numerica del giorno e dell’anno senza eventuali zeri iniziali. Per memorizzare i nomi dei mesi, si utilizzi un array di puntatori a costante di tipo carattere: ciò permette, infatti, di definire una sequenza di stringhe di lunghezza diversa. Per semplicità, si assuma che il file esista, non sia vuoto e che i dati contenuti nel file siano validi.
Esempio:
se il file contiene la data “19/03/2019”, il programma stampa a video “19 marzo 2019”;
se il file contiene la data “05/10/0546”, il programma stampa a video “5 ottobre 546”.

> :warning: Per fare di più: chiedere all’utente di inserire da tastiera un mese e un anno (due numeri interi) e scrivere nel file DateRecenti.txt le date contenute nel file Date.txt più recenti rispetto al mese e all’anno inseriti dall’utente.


```cpp
#include <iostream>
#include <fstream>
using namespace std;

const int num_mesi = 12;
const int dim_str = 11;
const int dim_data = 3;

int main() 
{
	const char* mesi[num_mesi] = { "gennaio", "febbraio", "marzo", "aprile",
		"maggio", "giugno", "luglio", "agosto", "settembre",
		"ottobre", "novembre", "dicembre" };
    
    int mese = 0; int anno = 0;
    cout << "Inserire mese e anno: " << endl;
    cout << "Mese: ";
    cin >> mese;
    cout << "Anno: ";
    cin >> anno;
	
	fstream fin, fout;
	fin.open("Date.txt", ios::in);
    fout.open("DateRecenti.txt", ios::out);
	
	char str[dim_str];
	while (!fin.eof()) {
		fin >> str;
		int k = 0; int n = 0;
		int data[dim_data] = {0, 0, 0}; int h = 0;
		while (str[k] != '\0') {
			if (str[k] == '/') {
				data[h] = n;
				h++;
				n = 0;
			}
			else
				n = n * 10 + (str[k] - '0');
			k++;
		}
		data[h] = n;
		cout << data[0] << " " << mesi[data[1] - 1] << " " << data[2] << endl;
        if (data[2] > anno || (data[2] == anno && data[1] > mese))
            fout << data[0] << " " << mesi[data[1] - 1] << " " << data[2] << endl;
	}

	fin.close();
    fout.close();
	return 0;
}
```

Un possibile risultato dell'esecuzione sarà:
```
Inserire mese e anno: 
Mese: 02
Anno: 1900
19 marzo 2019
5 ottobre 546

```

### [Esercizio 10_4] - Allocazione Dinamica della Memoria

La riallocazione è una tecnica che si può usare nel caso in cui i dati da elaborare siano ricevuti in tempi successivi e non si conosca la loro quantità esatta finché questi non siano tutti pervenuti. In sostanza, si prealloca una struttura dati (ad esempio un array) assegnandole una dimensione iniziale ragionevole per il problema che viene trattato. I dati in arrivo vengono memorizzati nella struttura dati finché questa non si riempie. Se la struttura dati è piena e arrivano ulteriori dati, la struttura dati viene riallocata. Viene creata, cioè, una nuova struttura dati più grande (ad esempio un array di dimensione multipla della dimensione precedente) e i dati vengono copiati nella nuova struttura dati. Questa procedura può essere eventualmente ripetuta, aumentando progressivamente le dimensioni della struttura dati, finché non siano pervenuti tutti i dati.
Per applicare la tecnica della riallocazione, si scriva un programma C++ che operi come segue:
-	Dichiari una costante intera d e la inizializzi a 10.
-	Dichiari un puntatore px a numero reale e lo inizializzi a NULL.
-	Allochi dinamicamente un array di d numeri reali, ne assegni il puntatore a px e inizializzi a zero tutti gli elementi dell’array. 
-	Chieda all’utente di inserire da tastiera una sequenza di numeri reali positivi o nulli. L’utente potrà inserire valori finché lo desidera – fino ad un massimo di 20 valori – e indicherà il termine della sequenza inserendo un numero negativo. La sequenza termina comunque, dopo che sono stati inseriti 20 valori.
-	Inserisca ciascun valore fornito dall’utente nell’array puntato da px. Nel caso in cui l’array sia pieno (ovvero siano stati inseriti d elementi), il programma riallocherà l’array aggiungendovi ulteriori d elementi. La riallocazione avviene in questo modo: il programma dichiara un puntatore pt a numero reale, alloca dinamicamente un array di (2 * d) elementi e ne assegna il puntatore a pt, copia nell’array puntato da pt tutti gli elementi dell’array puntato da px, aggiunge all’array puntato da pt l’ulteriore elemento inserito dall’utente, distrugge l’array puntato da px e assegna pt a px.
-	Completato l’inserimento dei valori della sequenza, il programma stampi a video il contenuto dell’array puntato da px, calcoli e stampi a video la somma dei valori inseriti, deallochi la memoria utilizzata e termini.

> :warning: Per fare di più: modificare il programma in modo che possa elaborare sequenze di lunghezza qualunque (cioè non limitate a 20 valori). Ogni volta che l’array puntato da px risulterà essere pieno, esso verrà riallocato, aggiungendo ulteriori d elementi.

```cpp
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

/// versione 2

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
	cout << "Inserire un valore: ";
	cin >> x;
	while (x >= 0) {
		if (k == dim) {
			double* pt = new double[dim + d];
			for (int j = 0; j < k; j++)
				pt[j] = px[j];
			pt[k] = x;
			delete[] px;
			px = pt;
			dim += d;
		}
		else
			px[k] = x;
		k++;
		cout << "Inserire un valore: ";
		cin >> x;
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

```

Un possibile risultato dell'esecuzione sarà:
```
Inserire un valore: 4
Inserire un valore: 3
Inserire un valore: 45
Inserire un valore: 23
Inserire un valore: 7
Inserire un valore: 8
Inserire un valore: 9
Inserire un valore: 12
Inserire un valore: 35
Inserire un valore: 4
Inserire un valore: 23
Inserire un valore: 5
Inserire un valore: 43
Inserire un valore: 4
Inserire un valore: 34
Inserire un valore: 4
Inserire un valore: 56
Inserire un valore: -1
Valori inseriti: 
{ 4, 3, 45, 23, 7, 8, 9, 12, 35, 4, 23, 5, 43, 4, 34, 4, 56, 0, 0, 0 } 
Somma: 319

```

### [Esercizio 10_5] - Allocazione Dinamica di Array di Strutture

Allo scopo di gestire gli studenti che frequentano un corso di studi universitario, si sviluppi quanto segue in linguaggio C++:
-	La struttura studente avente i seguenti campi: il puntatore ad una stringa che contiene il nome dello studente, il puntatore ad una stringa che contiene il cognome dello studente, il numero di matricola dello studente (un numero intero).
-	La funzione leggi che riceva come parametro il puntatore ad una stringa che contiene il nome di un file e come parametro di uscita (ovvero per riferimento) un numero intero n e restituisca come valore di ritorno un puntatore a un array di strutture di tipo studente. I file che la funzione legge sono organizzati come segue: la prima riga contiene un numero intero che rappresenta il numero di studenti i cui dati sono memorizzati nel file, le righe successive contengono i dati relativi a ciascuno studente (nome, cognome e numero di matricola). La funzione apre in lettura il file il cui nome è passato come parametro, legge la prima riga del file, alloca dinamicamente un array di strutture di tipo studente della dimensione letta, legge le righe successive del file e ne copia il contenuto nei campi delle strutture contenute nell’array (ogni riga del file corrisponde ad una struttura nell’array). Al termine, la funzione chiude il file, copia nel parametro di uscita n la dimensione dell’array allocato e restituisce il puntatore all’array stesso. Nel caso in cui l’operazione di lettura non vada a buon fine la funzione restituisce NULL.
-	La funzione stampa che riceva come parametri un array di strutture di tipo studente e la sua dimensione (un numero intero) e, utilizzando l’aritmetica dei puntatori, scandisca l’array passato come parametro e stampi a video il valore dei campi delle strutture contenute nell’array.
-	La funzione dealloca che riceva come parametri un array di strutture di tipo studente e la sua dimensione (un numero intero) e operi come segue: scandisca l’array e deallochi le stringhe puntate dai puntatori che costituiscono i campi delle strutture contenute nell’array e, al termine della scansione, deallochi l’intero array.
-	La funzione main che operi come segue: chieda all’utente di inserire da tastiera il nome di un file; chiami la funzione leggi passandole il nome del file inserito dall’utente; se la lettura è andata a buon fine, chiami la funzione stampa passandole l’array puntato dal puntatore restituito da leggi e, successivamente, la funzione dealloca, passando anche ad essa l’array puntato dal puntatore restituito da leggi.
Esempio: la funzione leggi elabora file organizzati nel modo seguente:
4 
Mario Rossi 123456
Giovanna Neri 123457
Paolo Verdi 123458
Michela Bianchi 123459
Per fare di più: aggiungere la funzione cerca per cercare uno studente all’interno di un array di strutture di tipo studente. La funzione riceve come parametro l’array di strutture, la sua dimensione e un numero di matricola (un numero intero) e restituisce come valore di ritorno un puntatore a una struttura di tipo studente. Nel caso in cui la ricerca abbia successo, la funzione restituisce il puntatore all’elemento dell’array la cui matricola corrisponde a quella passata come parametro, altrimenti, se la ricerca fallisce, la funzione restituisce NULL. Modificare, quindi, la funzione main allo scopo di verificare il corretto funzionamento della funzione cerca.

```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int str_max_dim = 32;

struct studente {
	char* nome;
	char* cognome;
	int matricola;
};

studente* leggi (char* nome_file, int& n) {
	if (nome_file == NULL)
		return NULL;
		
	fstream fin;
	fin.open(nome_file, ios::in);
	if (!fin) 
		return NULL;
	
	fin >> n;
	if (fin.eof() || n <= 0)
		return NULL;
		
	studente* pdati = new studente[n];
	if (pdati == NULL)
		return NULL;
		
	char s[str_max_dim];
	for (studente* p = pdati; p < (pdati + n); p++) {
		fin >> s;
		p->nome = strdup(s);
		fin >> s;
		p->cognome = strdup(s);
		fin >> p->matricola;
	}
		
	fin.close();
	return pdati;
}

void stampa (studente* pdati, int n) {
	if (pdati != NULL)
		for (studente* p = pdati; p < (pdati + n); p++)
			cout << p->nome << " " << p->cognome << "\t" << p->matricola << endl;
}

studente* cerca(studente* pdati, int n, int matricola) {
    if (pdati != NULL) {
        for (studente* p = pdati; p < (pdati + n); p++)
            if (p->matricola == matricola) 
                return p;
    }
    return NULL;
}

void dealloca (studente* pdati, int n) {
	if (pdati != NULL) {
		for (studente* p = pdati; p < (pdati + n); p++) {
			delete[] p->nome;
			delete[] p->cognome;
		}
		delete[] pdati;	
	}
}

int main() { 
	char file[32];
	cout << "Inserire il nome di un file contente i dati richiesti: ";
	cin >> file;
	int d = 0;
	studente* pstudenti = leggi(file, d);
	if (pstudenti != NULL) {
		cout << "Dati relativi a " << d << " studenti: " << endl;
		stampa(pstudenti, d);
		//da commentare in caso di parte aggiuntiva
		//dealloca(pstudenti, d);
        
        // Parte aggiuntiva
        int m = 0;
        cout << "Inserire un numero di matricola: ";
        cin >> m;
        studente* p = cerca(pstudenti, d, m);
        if (p != NULL)
            cout << "Si tratta dello studente " << p->nome << " " << p->cognome << endl;
        else
            cout << "Non ci sono studenti con questo numero di matricola" << endl;        
	}
	return 0;  
}
```

Un possibile risultato dell'esecuzione sarà:
```
Inserire il nome di un file contente i dati richiesti: studenti.txt
Dati relativi a 4 studenti: 
Mario Rossi	123456
Giovanna Neri	123457
Paolo Verdi	123458
Michela Bianchi	123459
Inserire un numero di matricola: 123456
Si tratta dello studente Mario Rossi

```