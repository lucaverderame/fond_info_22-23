## Sedicesima esercitazione - Esercizi Riepilogativi sulle Classi

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).

### [Esercizio 16_1] - Prova pratica del 24 luglio 2017, Testo 2, Esercizio 1

Completare il codice dell’interfaccia del seguente template di classe C++:

```cpp
1	// classe per rappresentare parabole secondo l’equazione y = ax2 + bx + c.
2	___________________ <typename T>
3	class Parabola {
4	___________________ :
5	    Parabola();
6	    Parabola(T a, T b, T c);
7	    ___________________ (const Parabola<T>& p);
8	    ~Parabola();
9	    T getA() const;
10	    T getB() const;
11	    T getC() const;
12	    void setData(T a, T b, T c);
13	    ___________________ operator=(const Parabola<T>& p);
14	private:
15	    T _a, _b, _c ; };
```
Soluzione:

```cpp
1	// classe per rappresentare parabole secondo l’equazione y = ax2 + bx + c.
2	template <typename T>
3	class Parabola {
4	public:
5	    Parabola();
6	    Parabola(T a, T b, T c);
7	    Parabola(const Parabola<T>& p);
8	    ~Parabola();
9	    T getA() const;
10	    T getB() const;
11	    T getC() const;
12	    void setData(T a, T b, T c);
13	    const Parabola<T>& operator=(const Parabola<T>& p);
14	private:
15	    T _a, _b, _c ; };

```

### [Esercizio 16_2] - Prova pratica del 23 luglio 2018, Testo 1, Esercizio 2

Identificare e correggere gli errori nella seguente dichiarazione di classe C++:

```cpp
1	class Prova {
2	public:
3		Prova();
4	   Prova(double val);
5	   Prova(const Prova& p);	
6	   double getVal();
7	   void setVal();
8	   Prova operator+(Prova p);
9	   operator=(const Prova& p);
10	   istream& operator>>(istream& is, Prova& p);
11	private:
12	   double _val;  };

```

Soluzione:
- Riga 06: il selettore è un metodo costante: double getVal() const;
- Riga 07: manca il parametro del modificatore: void setVal(double val);
- Riga 09: manca il tipo del valore di ritorno di operator=: 
         ```const Prova& operator=(const Prova& t);```
- Riga 10: l’operatore di estrazione è generalmente implementato come funzione amica:
         ``` friend istream& operator>>(istream& is, Prova& p);```


### [Esercizio 16_3] - Prova intermedia del 14 giugno 2018, Testo 1, Esercizio 1

Si dica se ciascuna delle seguenti affermazioni relative ai metodi di una classe C++ è corretta:

1. I selettori non possono essere implementati come metodi costanti.
2. I modificatori accedono agli attributi di un oggetto e ne modificano il valore.
3. I costruttori possono essere dotati di una lista di inizializzazione.
4. Il distruttore non ha valore di ritorno e non può avere parametri.
5. Tra gli operatori sovraccaricati deve sempre figurare l’operatore di assegnamento.
6. Il distruttore viene chiamato automaticamente quando si distrugge un oggetto della classe.
7. Le funzioni membro che sovraccaricano operatori unari hanno un parametro.
8. I costruttori non hanno valore di ritorno e non possono avere parametri.
9. Tra i metodi di una classe, hanno una particolare rilevanza le funzioni amiche.
10. Gli operatori sovraccaricati implementano per la classe gli operatori standard del C++.

Soluzione:

1. Falso
2. Vero
3. Vero
4. Vero
5. Falso
6. Vero
7. Falso
8. Falso
9. Falso
10. Vero

### [Esercizio 16_4] - Prova intermedia del 1 giugno 2016

Un’azienda di serramenti produce vari modelli di porte blindate. Allo scopo di gestire la produzione e la vendita di tali porte blindate, si sviluppi la classe C++ Porta avente i seguenti attributi: codice identificativo (un numero intero), larghezza in cm (un numero reale), altezza in cm (un numero reale), prezzo in Euro (un numero reale), numero di pezzi disponibili in magazzino (un numero intero). Si implementino, inoltre, i seguenti metodi:
-	Costruttori (di default, con parametri e di copia) e distruttore. Nel costruttore con parametri, per semplicità, si supponga che i valori impostati siano sempre validi.
-	Selettori (un metodo per ciascun attributo). 
-	Modificatori (un metodo per ciascun attributo). Per semplicità si supponga che i valori impostati siano sempre validi.
-	Il metodo Inserisci che chieda all’utente di inserire da tastiera il valore di ciascun attributo e assegni agli attributi i valori inseriti dall’utente. Nel caso in cui l’utente inserisca dei valori non validi, il metodo visualizzerà un messaggio di errore e continuerà a chiedere l’inserimento dei dati finché non vengano inseriti valori validi. Il metodo non restituisce alcun valore di ritorno.
-	Il metodo Stampa che stampi a video gli attributi di un oggetto Porta nel seguente formato:
<Codice>: <larghezza> x <altezza> cm, <prezzo> Euro, <numero pezzi> pezzi. Ad esempio: 12538: 220 x 110 cm, 1250 Euro, 35 pezzi. Il metodo non restituisce alcun valore di ritorno.
Si scriva, infine, la funzione main che operi come segue:
1.	Chieda all’utente di inserire il numero n di modelli di porte blindate che desidera gestire.
2.	Allochi un array p di oggetti di tipo Porta avente il numero di elementi n specificato dall’utente.
3.	Per ciascun elemento dell’array p chiami il metodo Inserisci.
4.	Per ciascun elemento dell’array p chiami il metodo Stampa.
5.	Calcoli e stampi a video il valore totale del magazzino (ovvero scandisca l’array p, calcoli per ciascun modello il prodotto del prezzo per il numero di pezzi disponibili in magazzino e sommi tali prodotti).
6.	Deallochi l’array p e termini.


```cpp
#include <iostream>
using namespace std;

class Porta {
public:
	Porta();
	Porta(int codice, double larghezza, double altezza, double prezzo, int n_pezzi);
	Porta(const Porta& p);
	~Porta();

	int getCodice() const;
	double getLarghezza() const;
	double getAltezza() const;
	double getPrezzo() const;
	int getNumPezzi() const;

	void setCodice(int codice);
	void setLarghezza(double larghezza);
	void setAltezza(double altezza);
	void setPrezzo(double prezzo);
	void setNumPezzi(double n_pezzi);

	void Inserisci();
	void Stampa() const;

private:
	int _codice;
	double _larghezza;
	double _altezza;
	double _prezzo;
	int _n_pezzi;
};

Porta::Porta() {
	_codice = 0;
	_larghezza = 0.0;
	_altezza = 0.0;
	_prezzo = 0.0;
	_n_pezzi = 0;
}

Porta::Porta(int codice, double larghezza, double altezza, double prezzo, int n_pezzi) {
	_codice = codice;
	_larghezza = larghezza;
	_altezza = altezza;
	_prezzo = prezzo;
	_n_pezzi = n_pezzi;
}

Porta::Porta(const Porta& p) {
	_codice = p._codice;
	_larghezza = p._larghezza;
	_altezza = p._altezza;
	_prezzo = p._prezzo;
	_n_pezzi = p._n_pezzi;
}

Porta::~Porta() {}

int Porta::getCodice() const {
	return _codice;
}

double Porta::getLarghezza() const {
	return _larghezza;
}

double Porta::getAltezza() const {
	return _altezza;
}

double Porta::getPrezzo() const {
	return _prezzo;
}

int Porta::getNumPezzi() const {
	return _n_pezzi;
}

void Porta::setCodice(int codice) {
	_codice = codice;
}

void Porta::setLarghezza(double larghezza) {
	_larghezza = larghezza;
}

void Porta::setAltezza(double altezza) {
	_altezza = altezza;
}

void Porta::setPrezzo(double prezzo) {
	_prezzo = prezzo;
}

void Porta::setNumPezzi(double n_pezzi) {
	_n_pezzi = n_pezzi;
}

void Porta::Inserisci() {
	do {
		cout << "Codice: ";
		cin >> _codice;
		cout << "Larghezza: ";
		cin >> _larghezza;
		cout << "Altezza: ";
		cin >> _altezza;
		cout << "Prezzo: ";
		cin >> _prezzo;
		cout << "Numero di pezzi: ";
		cin >> _n_pezzi;
		cout << endl;
	} while (_codice <= 0 || _larghezza <= 0 ||
		_altezza <= 0 || _prezzo <= 0 || _n_pezzi < 0);
}

void Porta::Stampa() const {
	cout << _codice << ": " << _larghezza << " x " << _altezza << " cm, "
		 << _prezzo << " Euro, " << _n_pezzi << " pezzi." << endl;
}

int main() {
	int n = 0;
	cout << "Inserire il numero di modelli desiderato: ";
	cin >> n;

	Porta* p = new Porta[n];
	for (int i = 0; i < n; i++)
		p[i].Inserisci();
	for (int j = 0; j < n; j++)
		p[j].Stampa();

	double valore = 0;
	for (int k = 0; k < n; k++)
		valore += p[k].getPrezzo() * p[k].getNumPezzi();
	cout << "Il valore totale del magazzino e' di " << valore << " Euro." << endl;

	delete[] p;

	return 0;
}
```

Un possibile risultato dell'esecuzione sarà:
```
Inserire il numero di modelli desiderato: 2
Codice: 12343
Larghezza: 45
Altezza: 23
Prezzo: 12000
Numero di pezzi: 6

Codice: 45543
Larghezza: 22
Altezza: 10
Prezzo: 1000
Numero di pezzi: 12

12343: 45 x 23 cm, 12000 Euro, 6 pezzi.
45543: 22 x 10 cm, 1000 Euro, 12 pezzi.
Il valore totale del magazzino e' di 84000 Euro.
```

### [Esercizio 16_5] - Prova intermedia del 1 giugno 2016

Un file contiene, per ciascuna riga, una somma di numeri interi positivi in rappresentazione binaria e il risultato della somma stessa secondo il seguente formato:
001100+01101+0101=011110;
0011+0101=1000;
00011+000111+000111+01010=0110011;
…
Il file contiene al più 20 righe, ma il numero effettivo di righe di cui il file si compone non è noto al programmatore. Ciascuna riga contiene al più 127 caratteri. I numeri binari sono composti al più da 8 bit. Ogni riga contiene almeno 2 e non più di 13 addendi. Si supponga, inoltre, che i dati siano validi (è cioè garantito che tutte le righe del file seguono il formato specificato). Non è però garantito che i risultati delle somme siano corretti: alcuni risultati potrebbero quindi essere errati. Per elaborare i dati e individuare eventuali errori, si sviluppi quanto segue in linguaggio C++:
1.	La funzione somma che riceva come parametri una matrice M di numeri interi di 20 righe e 13 colonne e l’indice k di una sua riga (un numero intero) e restituisca come valore di ritorno la somma degli elementi contenuti nella k-esima riga di M (un numero intero). Nel caso in cui il valore dell’indice non sia valido la funzione restituisce 0.
2.	La funzione converti che riceva come parametri un array di numeri interi b e la sua dimensione n e restituisca come valore di ritorno un numero intero. Gli elementi dell’array b possono valere soltanto 0 oppure 1 e sono i bit della rappresentazione binaria di un numero intero positivo. La funzione calcolerà e restituirà come valore di ritorno la rappresentazione decimale dello stesso numero.
3.	La classe SommeBinarie avente i seguenti attributi: la matrice di numeri interi _addendi di 20 righe e 13 colonne in cui copiare, in ciascuna riga, gli addendi delle somme presenti nella corrispondente riga del file; il numero _n di righe della matrice _addendi che contengono valori validi (pari al numero di righe di cui è composto il file); l’array di 20 numeri interi _risultati in cui copiare, in ciascun elemento, il risultato della somma presente nella corrispondente riga del file. Si implementino, inoltre, i seguenti metodi:
-	Il costruttore di default che inizializzi a 0 la variabile membro _n, tutti gli elementi della matrice _addendi e tutti gli elementi dell’array _risultati. 
-	Il costruttore di copia.
-	Il selettore per la variabile membro _n.
-	L’operatore di assegnamento.
-	Il metodo leggi che riceve come parametro una stringa nomeFile e non restituisce valori di ritorno. Il metodo opera come segue: inizializza a 0 la variabile membro _n e tutti gli elementi della matrice _addendi e dell’array _risultati; apre in lettura il file il cui nome è passato come parametro; per ciascuna riga del file, formattata come descritto, legge la riga del file in una stringa, scandisce la stringa e assegna agli elementi della riga corrispondente della matrice _addendi la rappresentazione decimale dei numeri binari contenuti nella stringa prima del carattere ‘=’, assegna quindi all’elemento corrispondente dell’array _risultati la rappresentazione decimale del numero binario che si trova dopo il carattere ‘=’; dopo aver letto tutte le righe del file, lo chiude e assegna a _n il numero di righe lette. Nota: si può usare la funzione converti per ottenere la rappresentazione decimale dei numeri binari.
-	Il metodo verifica che riceve come parametro una stringa nomeFile e restituisce come valore di ritorno un numero intero. Il metodo opera come segue: apre in scrittura il file il cui nome è passato come parametro; per ciascuna riga della matrice _addendi, chiama la funzione somma per calcolare il risultato corretto della somma degli addendi; verifica quindi che la somma calcolata corrisponda al risultato contenuto nell’elemento corrispondente dell’array _risultati. Se la somma è corretta, la scrive (in rappresentazione decimale) nella corrispondente riga del file il cui nome è passato come parametro, altrimenti scrive “Errore”. La funzione restituisce il numero di somme corrette.
4.	Si scriva, infine, un programma C++ che operi come segue: dichiari un oggetto sb di tipo SommeBinarie; chiami il metodo leggi dell’oggetto sb, passando il nome del file “Dati.txt” come parametro; chiami il metodo verifica dell’oggetto sb, passando il nome del file “Somme.txt” come parametro; stampi a video il numero di somme corrette e il numero di somme errate contenute nel file Dati.txt.


```cpp
#include <iostream>
#include <fstream>
using namespace std;

const int nr = 20;
const int nc = 13;

int somma(int M[nr][nc], int k) {
	int s = 0;
	for (int i = 0; i < nc; i++)
		s += M[k][i];
	return s;
}

int converti(int b[], int n) {
	int num = 0;
	for (int i = 0; i < n; i++)
		num = num * 2 + b[i];
	return num;
}

class SommeBinarie {
public:
	SommeBinarie();
	SommeBinarie(const SommeBinarie& sb);
	int getN() const;
	const SommeBinarie& operator=(const SommeBinarie& sb);
	void leggi(char nomeFile[]);
	int verifica(char nomeFile[]);
private:
	int _addendi[nr][nc];
	int _risultati[nr];
	int _n;
};

SommeBinarie::SommeBinarie() {
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_addendi[i][j] = 0;
	for (int k = 0; k < nr; k++)
		_risultati[k] = 0;
	_n = 0;
}

SommeBinarie::SommeBinarie(const SommeBinarie& sb) {
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_addendi[i][j] = sb._addendi[i][j];
	for (int k = 0; k < nr; k++)
		_risultati[k] = sb._risultati[k];
	_n = sb._n;
}

int SommeBinarie::getN() const {
	return _n;
}

const SommeBinarie& SommeBinarie::operator=(const SommeBinarie& sb) {
	if (this != &sb) {
		for (int i = 0; i < nr; i++)
			for (int j = 0; j < nc; j++)
				_addendi[i][j] = sb._addendi[i][j];
		for (int k = 0; k < nr; k++)
			_risultati[k] = sb._risultati[k];
		_n = sb._n;
	}
}

void SommeBinarie::leggi(char nomeFile[]) {
	const int nch = 128;
	const int nbits = 8;
	char linea[nch]; _n = 0;
	fstream fin;
	fin.open(nomeFile, ios::in);
	if (!fin) return;
	fin >> linea;
	while (!fin.eof()) {
		int k = 0; int c = 0;
		int b[nbits] = { 0 };
		while (linea[k] != '\0') {
			int h = 0;
			while (linea[k] != '+' && linea[k] != '=' && linea[k] != ';') {
				b[h] = linea[k] - '0';
				k++;
				h++;
			}
			if (linea[k] == '+' || linea[k] == '=') {
				_addendi[_n][c] = converti(b, h);
				c++;
			}
			else
				_risultati[_n] = converti(b, h);
			k++;
		}
		fin >> linea;
		_n++;
	}
	fin.close();
}

int SommeBinarie::verifica(char nomeFile[]) {
	int ncorretti = 0;
	fstream fout;
	fout.open(nomeFile, ios::out);
	for (int k = 0; k < _n; k++)
		if (somma(_addendi, k) == _risultati[k]) {
			fout << _risultati[k] << endl;
			ncorretti++;
		}
		else fout << "Errore" << endl;
	fout.close();
	return ncorretti;
}
	 
int main() {
	SommeBinarie sb;
	sb.leggi("Dati.txt");
	int n = sb.verifica("Somme.txt");
	cout << "Numero di somme corrette: " << n << endl;
	cout << "Numero di somme errate: " << sb.getN() - n << endl;
	return 0;
}
```

Un possibile risultato dell'esecuzione sarà:
```
Numero di somme corrette: 2
Numero di somme errate: 1

```