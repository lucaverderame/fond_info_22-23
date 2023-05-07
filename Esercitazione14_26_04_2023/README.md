## Quattordicesima esercitazione - Sviluppo di classi con overloading degli operatori

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).

### [Esercizio 14_1] - Catena di Supermercati

Una catena di supermercati dispone di un certo numero di punti vendita in diverse città italiane e desidera elaborare informazioni relative agli incassi che i supermercati hanno ottenuto nel corso di un anno. A tale scopo si sviluppi in linguaggio C++ la classe Incassi_annuali avente i seguenti attributi: l’anno _a al quale gli incassi si riferiscono (un intero maggiore di 1990, anno di costituzione della catena di supermercati), 
il puntatore _pc al nome del luogo (cioè la città) in cui si trovano i supermercati (una stringa di caratteri), il puntatore _pi ad un array di numeri reali che rappresentano gli incassi in Euro ottenuti per quell’anno da ciascun supermercato presente nella città in questione e il numero _n di tali supermercati (un numero intero). Si implementino, inoltre, i seguenti metodi:
-	Il costruttore di default che inizializzi il numero intero _a con il valore 1990, il puntatore _pc a NULL, il puntatore _pi a NULL e il numero intero _n a zero.
-	Un costruttore con parametri che riceva in ingresso (ovvero come parametri), un numero intero a, una stringa di caratteri ct, un array ics di numeri reali e la sua dimensione dim (un numero intero). 
Il costruttore opererà come segue: effettuerà l’allocazione dinamica di un array di dim numeri reali e ne assegnerà il puntatore a _pi; assegnerà a ciascun elemento dell’array puntato da _pi il valore del corrispondente elemento dell’array ics, assegnerà il valore di dim a _n, il valore di a ad _a e inizializzerà la stringa puntata da _pc con il valore della stringa ct. Nel caso in cui il valore di uno dei parametri attuali non sia valido o l’allocazione dinamica della memoria non vada a buon fine, il costruttore inizializzerà _a con il valore 1990, i puntatori _pc e _pi a NULL e _n a zero.
-	Il costruttore di copia. Nel caso in cui l’allocazione dinamica della memoria non vada a buon fine, il costruttore inizializzerà _a con il valore 1990, i puntatori _pc e _pi a NULL e _n a zero.
-	Il distruttore.
-	I selettori (un metodo per ciascun attributo).
-	Il modificatore per l’anno al quale gli incassi si riferiscono che riceva in ingresso (ovvero come parametro) un numero intero e restituisca come valore di ritorno un numero intero. In caso di valore non valido (ovvero minore di 1990), il modificatore non opera alcuna modifica sui dati e restituisce 0. Altrimenti il modificatore restituisce 1.
-	Il modificatore per il luogo nel quale si trovano i supermercati ai quali gli incassi si riferiscono che riceva in ingresso (ovvero come parametro) una stringa di caratteri e restituisca come valore di ritorno un numero intero. In caso di fallimento dell’allocazione dinamica della memoria, il modificatore non opera alcuna modifica sui dati e restituisce 0. Altrimenti restituisce 1.
-	Il modificatore per l’array degli incassi che riceva in ingresso (ovvero come parametri) un array ics contenente i nuovi valori degli incassi e la sua dimensione dim e restituisca come valore di ritorno un numero intero. Il modificatore opera come segue: dichiara un puntatore p ad un array di numeri reali, alloca dinamicamente un array di dim numeri reali e ne assegna il puntatore a p, assegna a ciascun elemento dell’array puntato da p il valore del corrispondente elemento dell’array a, se l’allocazione dinamica avviene con successo e l’array ics non contiene dati non validi (cioè numeri negativi), il modificatore dealloca (se esiste) l’array puntato da _p, assegna il valore di p al puntatore _p, il valore di dim a _n e termina restituendo 1.  Altrimenti, il modificatore non opera alcuna modifica ai dati e restituisce 0.
-	L’operatore di assegnamento. Nel caso in cui l’allocazione dinamica della memoria non vada a buon fine, l’operatore assegnerà il valore 1990 ad _a, NULL i puntatori _pc e _pi e zero a _n. Eventuale memoria precedentemente allocata sarà deallocata.
-	L’operatore di estrazione. Nell’implementazione dell’operatore di estrazione, si supponga che il luogo in cui i supermercati si trovano sia rappresentato come una stringa composta da un massimo di 32 caratteri. Nel caso in cui l’operatore non termini con successo a causa di dati non validi o di errori nell’allocazione della memoria, l’operatore assegnerà il valore 1990 ad _a, NULL ai puntatori _pc e _pi e zero a _n. Eventuale memoria precedentemente allocata sarà deallocata.
-	L’operatore di inserimento che formatti l’uscita come segue: “Anno, Città, Incassi: x1 Euro, x2 Euro, x3 Euro, … , xn Euro”, dove ad Anno verrà sostituito il valore corrente di _a, a Città verrà sostituito il valore corrente della stringa puntata da _pc e a x1, x2, x3, … , xn i valori correnti degli _n incassi contenuti nell’array puntato da _pi. Nel caso in cui un oggetto abbia come valore degli attributi 0, NULL, NULL, 0, l’operatore inserisce la stringa “Dati non validi”.
-	Un metodo che calcoli e restituisca come valore di ritorno l’incasso totale ottenuto da tutti i supermercati presenti nella città in questione (un numero reale pari alla somma degli elementi dell’array puntato da _p). Nel caso in cui _p valga NULL il metodo restituisce zero.
-	Un metodo che calcoli e restituisca come valore di ritorno l’incasso medio ottenuto da tutti i supermercati presenti nella città in questione (un numero reale pari alla media degli elementi dell’array puntato da _p). Nel caso in cui _p valga NULL il metodo restituisce zero.
-	Un metodo che calcoli e restituisca come parametri di uscita l’incasso massimo e l’incasso minimo ottenuto dai supermercati presenti nella città in questione (due numeri reali pari al valore massimo e al valore minimo degli elementi dell’array puntato da _p). Nel caso in cui _p valga NULL il metodo assegna il valore zero ad entrambi i parametri di uscita.

Si scriva quindi un programma C++ per verificare il corretto funzionamento della classe sviluppata. 
Il programma aprirà in lettura il file dati.txt, contenente nella sua prima riga il numero di successive righe di cui il file è composto e per ogni riga successiva un numero intero d che rappresenta l’anno al quale i dati nella riga si riferiscono, una stringa composta di un massimo di 32 caratteri che rappresenta la città alla quale i dati si riferiscono, un numero intero n che rappresenta il numero di supermercati presenti in tale città per quell’anno e una sequenza di n numeri reali che rappresentano gli incassi annuali di tali supermercati. Il programma legge la prima riga del file e alloca dinamicamente un array inc di d oggetti di tipo Incassi_annuali. Nel caso in cui l’allocazione si concluda con successo, il programma legge le righe successive del file e ne assegna i dati all’elemento corrispondente dell’array inc. Al termine della lettura, il programma chiuderà il file e, invocando sugli elementi dell’array inc gli opportuni metodi della classe Incassi_annuali, stamperà a video le informazioni relative a ciascun elemento contenuto nell’array inc ed inoltre calcolerà e stamperà a video l’incasso totale per tutti i supermercati i cui dati erano contenuti nel file. Infine, il programma deallocherà l’array inc e terminerà.

Esempio di file dati.txt:
```cpp
4
2019 Genova 4 935000 828500 542380 92800
2019 Torino 2 683800 259600
2019 Milano 3 996420 832430
2019 Bologna 1 745000	
```

```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

////////////////////////////////////////////////////////////////////
// Interfaccia
////////////////////////////////////////////////////////////////////

class Incassi_annuali {
public:

	// Costruttori
	Incassi_annuali();
	Incassi_annuali(int a, char ct[], double ics[], int dim);
	Incassi_annuali(const Incassi_annuali& inc);

	// Distruttore
	~Incassi_annuali();

	// Selettori
	int get_anno() const;
	const char* get_luogo() const;
	const double* get_incassi() const;
	int get_num_supermercati() const;

	// Modificatori
	int set_anno(int a);
	int set_luogo(char ct[]);
	int set_incassi(double ics[], int dim);

	// Overload di operatori
	const Incassi_annuali& operator=(const Incassi_annuali& inc);
	friend istream& operator>>(istream& is, Incassi_annuali& inc);
	friend ostream& operator<<(ostream& is, const Incassi_annuali& inc);

	// Altre operazioni
	double incasso_totale() const;
	double incasso_medio() const;
	void estremi_incasso(double& max_incasso, double& min_incasso) const;

private:
	int _a; 		// anno
	char* _pc;		// citt\ufffd
	double* _pi; 	// array di incassi
	int _n;			// elementi dell'array
};

////////////////////////////////////////////////////////////////////
// Costruttori
////////////////////////////////////////////////////////////////////

Incassi_annuali::Incassi_annuali()
	: _a(1990), _pc(NULL), _pi(NULL), _n(0)
{
}

Incassi_annuali::Incassi_annuali(int a, char ct[], double ics[], int dim)
	: _a(1990), _pc(NULL), _pi(NULL), _n(0)
{
	if (a < 1990)
		return;
	if (dim <= 0)
		return;

	double* pi = new double[dim];
	if (pi == NULL)
		return;
	for (int k = 0; k < dim; k++) {
		if (ics[k] < 0.0) {
			delete [] pi;
			return;
		}
		pi[k] = ics[k];
	}

	char* pc = strdup(ct);
	if (pc == NULL) {
		delete [] pi;
		return;
	}

	_a = a;
	_pc = pc;
	_pi = pi;
	_n = dim;
}

Incassi_annuali::Incassi_annuali(const Incassi_annuali& inc)
	: _a(1990), _pc(NULL), _pi(NULL), _n(0)
{
	if (inc._n <= 0)
		return;

	double* pi = new double[inc._n];
	if (pi == NULL)
		return;
	for (int k = 0; k < inc._n; k++)
		pi[k] = inc._pi[k];

	char* pc = strdup(inc._pc);
	if (pc == NULL) {
		delete[] pi;
		return;
	}

	_a = inc._a;
	_n = inc._n;
	_pc = pc;
	_pi = pi;
}

////////////////////////////////////////////////////////////////////
// Distruttore
////////////////////////////////////////////////////////////////////

Incassi_annuali::~Incassi_annuali()
{
	if (_pc != NULL)
		delete[] _pc;
	if (_pi != NULL)
		delete[] _pi;
}

////////////////////////////////////////////////////////////////////
// Selettori
////////////////////////////////////////////////////////////////////

int Incassi_annuali::get_anno() const
{
	return _a;
}

const char* Incassi_annuali::get_luogo() const
{
	return _pc;
}

const double* Incassi_annuali::get_incassi() const
{
	return _pi;
}

int Incassi_annuali::get_num_supermercati() const
{
	return _n;
}

////////////////////////////////////////////////////////////////////
// Modificatori
////////////////////////////////////////////////////////////////////

int Incassi_annuali::set_anno(int a)
{
	if (a < 1990)
		return 0;
	_a = a;
	return 1;
}

int Incassi_annuali::set_luogo(char ct[])
{
	char* pc = strdup(ct);
	if (pc == NULL)
		return 0;
	if (_pc != NULL)
		delete[] _pc;
	_pc = pc;
	return 1;
}

int Incassi_annuali::set_incassi(double ics[], int dim)
{
	if (dim < 0)
		return 0;

	double*	p = new double[dim];
	if (p == NULL)
		return 0;

	for (int k = 0; k < dim; k++) {
		if (ics[k] < 0.0) {
			delete[] p;
			return 0;
		}
		p[k] = ics[k];
	}

	if (_pi != NULL)
		delete[] _pi;
	_pi = p;
	_n = dim;
	return 1;
}

////////////////////////////////////////////////////////////////////
// Overload di operatori
////////////////////////////////////////////////////////////////////

const Incassi_annuali& Incassi_annuali::operator=(const Incassi_annuali& inc)
{
	if (this != &inc) {
		int check = set_luogo(inc._pc) && set_incassi(inc._pi, inc._n) && set_anno(inc._a);
		if (check == 0) {
			set_anno(1990);
			_n = 0;
			if (_pc != NULL) {
				delete [] _pc;
				_pc == NULL;
			}
			if (_pi != NULL) {
				delete [] _pi;
				_pi == NULL;
			}
		}
	}
	return *this;
}

////////////////////////////////////////////////////////////////////
// Altre operazioni
////////////////////////////////////////////////////////////////////

double Incassi_annuali::incasso_totale() const
{
	const double* p = get_incassi();
	int n = get_num_supermercati();
	double somma = 0.0;
	if (p != NULL) {
		for (int k = 0; k < n; k++)
			somma += p[k];
	}
	return somma;
}

double Incassi_annuali::incasso_medio() const
{
	int n = get_num_supermercati();
	if (n != 0)
		return incasso_totale() / n;
	return 0.0;
}

void Incassi_annuali::estremi_incasso(double& max_incasso, double& min_incasso) const
{
	const double* p = get_incassi();
	int n = get_num_supermercati();
	double m = 0.0; double M = 0.0;
	if (p != NULL) {
		m = p[0]; M = p[0];
		for (int k = 0; k < n; k++) {
			if (p[k] > M)
				M = p[k];
			if (p[k] < m)
				m = p[k];
		}
	}
	max_incasso = M;
	min_incasso = m;
}

////////////////////////////////////////////////////////////////////
// Funzioni amiche della classe incassi_annuali
////////////////////////////////////////////////////////////////////

istream& operator>> (istream& is, Incassi_annuali& inc)
{
	const int dim = 32;
	int anno = 1990; char luogo[dim] = ""; int n = 0;
	double* p = NULL;
	int flag = 1;
	is >> anno;
	if (anno < 1990)
		flag = 0;
	else {
		is >> luogo;
		is >> n;
		if (n < 0)
			flag = 0;
		else {
			p = new double[n];
			if (p == NULL)
				flag = 0;
			else {
				for (int i = 0; i < n; i++) {
					is >> p[i];
					if (p[i] < 0) {
						flag = 0;
						break;
					}
				}
			}
		}
	}
	if (flag == 1) {
		inc.set_anno(anno);
		inc.set_luogo(luogo);
		inc.set_incassi(p, n);
	}
	else {
		inc.set_anno(1990);
		if (inc._pc != NULL) {
			delete [] inc._pc;
			inc._pc = NULL;
		}
		if (inc._pi != NULL) {
			delete [] inc._pi;
			inc._pi = NULL;
		}
	}
	return is;
}

ostream& operator<< (ostream& os, const Incassi_annuali& inc)
{
	const double* p = inc.get_incassi();
	int n = inc.get_num_supermercati();
	if (p != NULL) {
		os << inc.get_anno() << ", " << inc.get_luogo() << ", Incassi: ";
		for (int i = 0; i < n - 1; i++)
			os << p[i] << ", ";
		os << p[n - 1];
	}
	else
		os << "Dati non validi";
	return os;
}

////////////////////////////////////////////////////////////////////
// Funzione main
////////////////////////////////////////////////////////////////////

int main()
{
	fstream fin;
	fin.open("dati.txt", ios::in);
	if (!fin)
		return -1;

	int d = 0;
	fin >> d;
	if (d <= 0)
	 return -2;

	Incassi_annuali* inc = new Incassi_annuali[d];
	if (inc == NULL)
		return -3;
	for (int i = 0; i < d; i++)
		fin >> inc[i];

	fin.close();

	cout << "Dati contenuti nel file: "<< endl;
	double somma = 0.0;
	for (int i = 0; i < d; i++) {
		somma += inc[i].incasso_totale();
		cout << inc[i] << endl;
	}
	cout << "Incasso totale: " << somma << endl;

	return 0;
}
```
Un possibile risultato dell'esecuzione sarà:
```
Dati contenuti nel file: 
2019, Genova, Incassi: 935000, 828500, 542380, 92800
2019, Torino, Incassi: 683800, 259600
2019, Milano, Incassi: 996420, 832430, 2019
Dati non validi
Incasso totale: 5.17295e+06
```

### [Esercizio 14_2] - Punto2d

Progettare e sviluppare in linguaggio C++ la classe Punto2d per la gestione delle informazioni relative ai punti di coordinate (x, y) in uno spazio bidimensionale. La classe avrà come attributi le coordinate x e y di un punto (due numeri reali). Si implementino, inoltre, i seguenti metodi:
-	Il costruttore di default che inizializzi a zero entrambi gli attributi.
-	Un costruttore con parametri che riceva in ingresso (ovvero come parametri) due numeri reali che rappresentano le coordinate x e y di un punto bidimensionale e assegnino i valori dei parametri attuali ai corrispondenti attributi della classe.
-	Il costruttore di copia.
-	Il distruttore.
-	I selettori (un metodo per ciascun attributo).
-	I modificatori (un metodo per ciascun attributo).
-	L’operatore unario di cambio di segno, per calcolare l’opposto di un punto bidimensionale.
-	Gli operatori unari di incremento e decremento unitario prefisso e postfisso.
-	Gli operatori aritmetici di somma, sottrazione e moltiplicazione per scalare.
-	L’operatore di assegnamento.
-	L’operatore relazionale di uguaglianza ==, per il quale due punti bidimensionali sono uguali se hanno le stesse coordinate x e y.
-	Gli operatori di inserimento ed estrazione.
-	Un metodo per il calcolo della distanza tra due punti.
Si scriva quindi un programma C++ per verificare il corretto funzionamento della classe sviluppata. 
Il programma dichiarerà due oggetti di classe Punto2d, chiederà all’utente di immettere da tastiera i valori delle coordinate dei due punti utilizzando l’operatore di estrazione, stamperà a video le coordinate immesse utilizzando l’operatore di estrazione e calcolerà e stamperà a video la somma la differenza e la distanza tra i due punti.

```cpp
#include <iostream>
#include <cmath>
using namespace std;

////////////////////////////////////////////////////////////////////
// Interfaccia
////////////////////////////////////////////////////////////////////

class Punto2d {

public:

	// Costruttori
	Punto2d();
	Punto2d(double x, double y);
	Punto2d(const Punto2d& p);
	
	// Distruttore
	~Punto2d();

	// Selettori
	double getX() const;
	double getY() const;

	// Modificatori
	void setX(double x);
	void setY(double x);

	// Operatori sovraccaricati
	Punto2d operator-() const;
	Punto2d& operator++();
	Punto2d operator++(int);
    Punto2d& operator--();
	Punto2d operator--(int);
	Punto2d operator+(Punto2d p) const;
	Punto2d operator-(Punto2d p) const;
	Punto2d operator*(double s) const;
	int operator==(Punto2d p) const;
	const Punto2d& operator=(const Punto2d& p);
	friend ostream& operator<<(ostream& os, const Punto2d& p);
	friend istream& operator>>(istream& is, Punto2d& p);
	
	// Operazioni
	double distanza(Punto2d p) const;

private:
	double _x;
	double _y;
};

/////////////////////////////////////////////////////////////////////
// Costruttori della classe punto2d
/////////////////////////////////////////////////////////////////////

Punto2d::Punto2d()
	: _x(0.0), _y(0.0)
{
}

Punto2d::Punto2d(double x, double y)
	: _x(x), _y(y)
{
}

Punto2d::Punto2d(const Punto2d& p)
	: _x(p._x), _y(p._y)
{
}

/////////////////////////////////////////////////////////////////////
// Distruttore della classe punto2d
/////////////////////////////////////////////////////////////////////

Punto2d::~Punto2d()
{
}
	
/////////////////////////////////////////////////////////////////////
// Selettori della classe punto2d
/////////////////////////////////////////////////////////////////////

double Punto2d::getX() const
{
	return _x;
}

double Punto2d::getY() const
{
	return _y;
}

/////////////////////////////////////////////////////////////////////
// Modificatori della classe punto2d
/////////////////////////////////////////////////////////////////////

void Punto2d::setX(double x)
{
	_x = x;
}

void Punto2d::setY(double y)
{
	_y = y;
}

/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati della classe punto2d
/////////////////////////////////////////////////////////////////////

Punto2d Punto2d::operator-() const
{
	return Punto2d(-getX(), -getY());
}

Punto2d& Punto2d::operator++()
{
	setX(getX() + 1.0);
	setY(getY() + 1.0);
	return *this;
}

Punto2d Punto2d::operator++(int)
{
	Punto2d temp(*this);
	setX(getX() + 1.0);
	setY(getY() + 1.0);
	return temp;
}

Punto2d& Punto2d::operator--()
{
	setX(getX() - 1.0);
	setY(getY() - 1.0);
	return *this;
}

Punto2d Punto2d::operator--(int)
{
	Punto2d temp(*this);
	setX(getX() - 1.0);
	setY(getY() - 1.0);
	return temp;
}

Punto2d Punto2d::operator+(Punto2d p) const
{
	return Punto2d(getX() + p.getX(), getY() + p.getY());
}

Punto2d Punto2d::operator-(Punto2d p) const
{
	return Punto2d(getX() - p.getX(), getY() - p.getY());
}

Punto2d Punto2d::operator*(double s) const
{
	return Punto2d(s * getX(), s * getY());
}

int Punto2d::operator==(Punto2d p) const
{
	return (getX() == p.getX() && getY() == p.getY());
}

const Punto2d& Punto2d::operator=(const Punto2d& p)
{	
	if (&p != this) {
		setX(p.getX());
		setY(p.getY());
	}
	return *this;
}

ostream& operator<<(ostream& os, const Punto2d& p)
{
	os << "(" << p.getX() << "," << p.getY() << ")";
	return os;
}

istream& operator >> (istream& is, Punto2d& p)
{
	double x = 0.0;
	double y = 0.0;
	is >> x >> y;
	p.setX(x);
	p.setY(y);
	return is;
}

/////////////////////////////////////////////////////////////////////
// Operazioni della classe punto2d
/////////////////////////////////////////////////////////////////////

double Punto2d::distanza(Punto2d p) const
{
	double deltaX = getX() - p.getX(); 
	double deltaY = getY() - p.getY();
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

/////////////////////////////////////////////////////////////////////
// Funzione main
/////////////////////////////////////////////////////////////////////

int main()
{
	Punto2d p, q;
	cout << "Immettere le coordinate (x1, y1) di un punto: " << endl;
	cin >> p;
	cout << endl;
	cout << "Immettere le coordinate (x2, y2) di un punto: " << endl;
	cin >> q;
	cout << endl;

	cout << "Dati i punti di coordinate " << p << " e " << q << ": " << endl;
	cout << "- la loro somma e': " << p + q << endl;
	cout << "- la loro differenza e': " << p - q << endl;
	cout << "- la loro distanza e': " << p.distanza(q) << endl;
	cout << endl;

	return 0;
}
```

Un possibile risultato dell'esecuzione sarà:
```
Immettere le coordinate (x1, y1) di un punto: 
3 5

Immettere le coordinate (x2, y2) di un punto: 
6 8

Dati i punti di coordinate (3,5) e (6,8): 
- la loro somma e': (9,13)
- la loro differenza e': (-3,-3)
- la loro distanza e': 4.24264
```

### [Esercizio 14_3] - Poligono2d

Progettare e sviluppare in linguaggio C++ la classe Poligono2d per rappresentare poligoni i cui vertici sono punti bidimensionali. Il poligono è rappresentato come un array di punti bidimensionali, ovvero un array di oggetti della classe Punto2d sviluppata nell’Esercizio 3. La classe avrà pertanto i seguenti attributi: 
il puntatore _p ad un array di oggetti di classe Punto2d e il numero _n di punti contenuti nell’array (un numero intero). Si implementino, inoltre, i seguenti metodi:
-	Il costruttore di default che inizializzi _p a NULL e _n a zero.
-	Un costruttore con parametri che riceva in ingresso (ovvero come parametri) un numero intero dim. Il costruttore effettuerà l’allocazione dinamica di un array di dim oggetti di classe Punto2d, ne assegnerà il puntatore a _p e assegnerà dim a _n. Nel caso in cui l’allocazione dinamica della memoria non vada a buon fine o il valore di dim non sia valido, il costruttore inizializzerà _p a NULL e _n a zero.
-	Un costruttore con parametri che riceva in ingresso (ovvero come parametri) un array pti di oggetti di classe Punto2d e la sua dimensione dim (un numero intero). Il costruttore opererà come segue: nel caso in cui dim assuma un valore valido, effettuerà l’allocazione dinamica di un array di dim oggetti di classe Punto2d e ne assegnerà il puntatore a _p; nel caso in cui l’allocazione dinamica della memoria vada a buon fine, assegnerà a ciascun elemento dell’array puntato da _p, il valore del corrispondente elemento dell’array pti e assegnerà dim a _n; nel caso in cui l’allocazione dinamica della memoria non vada a buon fine o il valore di dim non sia valido, il costruttore inizializzerà _p a NULL e _n a zero.
-	Il costruttore di copia. Nel caso in cui l’allocazione dinamica della memoria non vada a buon fine, il costruttore inizializzerà _p a NULL e _n a zero.
-	Il distruttore.
-	I selettori (un metodo per ciascun attributo).
-	Il modificatore per l’array puntato da _p che riceva in ingresso (ovvero come parametri) un array pti contenente i nuovi valori e la sua dimensione dim e operi come segue: nel caso in cui il valore di dim sia valido, dichiari un puntatore p a un array di oggetti di classe Punto2d, effettui l’allocazione dinamica di un array di dim oggetti di classe Punto2d e ne assegni il puntatore a p, nel caso in cui l’allocazione dinamica della memoria vada a buon fine, assegni a ciascun elemento dell’array puntato da p, il valore del corrispondente elemento dell’array a, deallochi (se esiste) l’array puntato da _p, assegni il valore di p al puntatore _p e assegni dim a _n; nel caso in cui l’allocazione dinamica della memoria non vada a buon fine o il valore di dim non sia valido, il modificatore non opera alcuna modifica ai dati.
-	L’operatore di moltiplicazione per scalare.
-	L’operatore di assegnamento. Nel caso in cui l’allocazione dinamica della memoria non vada a buon fine, l’operatore assegnerà NULL a _p e zero a _n.
-	L’operatore di selezione con indice.
-	L’operatore relazionale di uguaglianza, per il quale due poligoni sono uguali se sono uguali le coordinate di tutti i punti che ne costituiscono i vertici.
-	Gli operatori di inserimento ed estrazione.
-	Un metodo per calcolare il perimetro del poligono come somma delle distanze tra coppie di vertici consecutivi.
Si scriva infine un programma C++ per verificare il corretto funzionamento della classe sviluppata. 
Il programma chiederà all’utente di inserire da tastiera il numero di vertici desiderato per il poligono, dichiarerà un oggetto di classe Poligono2d passando al costruttore il numero di vertici desiderato, chiederà quindi all’utente di inserire da tastiera le coordinate dei vertici del poligono utilizzando l’operatore di estrazione, calcolerà infine il perimetro del poligono e ne stamperà a video il valore.

```cpp
#include <iostream>
#include <cmath>
using namespace std;

////////////////////////////////////////////////////////////////////
// Interfaccia della classe punto2d
////////////////////////////////////////////////////////////////////

class Punto2d {

public:

	// Costruttori
	Punto2d();
	Punto2d(double x, double y);
	Punto2d(const Punto2d& p);

	// Distruttore
	~Punto2d();

	// Selettori
	double getX() const;
	double getY() const;

	// Modificatori
	void setX(double x);
	void setY(double x);

	// Operatori sovraccaricati
	Punto2d operator-() const;
	Punto2d& operator++();
	Punto2d operator++(int);
    Punto2d& operator--();
	Punto2d operator--(int);
	Punto2d operator+(Punto2d p) const;
	Punto2d operator-(Punto2d p) const;
	Punto2d operator*(double s) const;
	int operator==(Punto2d p) const;
	const Punto2d& operator=(const Punto2d& p);
	friend ostream& operator<<(ostream& os, const Punto2d& p);
	friend istream& operator>>(istream& is, Punto2d& p);

	// Operazioni
	double distanza(Punto2d p) const;

private:
	double _x;
	double _y;
};

/////////////////////////////////////////////////////////////////////
// Costruttori della classe punto2d
/////////////////////////////////////////////////////////////////////

Punto2d::Punto2d()
	: _x(0.0), _y(0.0)
{
}

Punto2d::Punto2d(double x, double y)
	: _x(x), _y(y)
{
}

Punto2d::Punto2d(const Punto2d& p)
	: _x(p._x), _y(p._y)
{
}

/////////////////////////////////////////////////////////////////////
// Distruttore della classe punto2d
/////////////////////////////////////////////////////////////////////

Punto2d::~Punto2d()
{
}

/////////////////////////////////////////////////////////////////////
// Selettori della classe punto2d
/////////////////////////////////////////////////////////////////////

double Punto2d::getX() const
{
	return _x;
}

double Punto2d::getY() const
{
	return _y;
}

/////////////////////////////////////////////////////////////////////
// Modificatori della classe punto2d
/////////////////////////////////////////////////////////////////////

void Punto2d::setX(double x)
{
	_x = x;
}

void Punto2d::setY(double y)
{
	_y = y;
}

/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati della classe punto2d
/////////////////////////////////////////////////////////////////////

Punto2d Punto2d::operator-() const
{
	return Punto2d(-getX(), -getY());
}

Punto2d& Punto2d::operator++()
{
	setX(getX() + 1.0);
	setY(getY() + 1.0);
	return *this;
}

Punto2d Punto2d::operator++(int)
{
	Punto2d temp(*this);
	setX(getX() + 1.0);
	setY(getY() + 1.0);
	return temp;
}

Punto2d& Punto2d::operator--()
{
	setX(getX() - 1.0);
	setY(getY() - 1.0);
	return *this;
}

Punto2d Punto2d::operator--(int)
{
	Punto2d temp(*this);
	setX(getX() - 1.0);
	setY(getY() - 1.0);
	return temp;
}

Punto2d Punto2d::operator+(Punto2d p) const
{
	return Punto2d(getX() + p.getX(), getY() + p.getY());
}

Punto2d Punto2d::operator-(Punto2d p) const
{
	return Punto2d(getX() - p.getX(), getY() - p.getY());
}

Punto2d Punto2d::operator*(double s) const
{
	return Punto2d(s * getX(), s * getY());
}

int Punto2d::operator==(Punto2d p) const
{
	return (getX() == p.getX() && getY() == p.getY());
}

const Punto2d& Punto2d::operator=(const Punto2d& p)
{
	if (&p != this) {
		setX(p.getX());
		setY(p.getY());
	}
	return *this;
}

ostream& operator<<(ostream& os, const Punto2d& p)
{
	os << "(" << p.getX() << "," << p.getY() << ")";
	return os;
}

istream& operator >> (istream& is, Punto2d& p)
{
	double x = 0.0;
	double y = 0.0;
	is >> x >> y;
	p.setX(x);
	p.setY(y);
	return is;
}

/////////////////////////////////////////////////////////////////////
// Operazioni della classe punto2d
/////////////////////////////////////////////////////////////////////

double Punto2d::distanza(Punto2d p) const
{
	double deltaX = getX() - p.getX();
	double deltaY = getY() - p.getY();
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

/////////////////////////////////////////////////////////////////////
// Interfaccia della classe poligono2d
/////////////////////////////////////////////////////////////////////

class Poligono2d
{
public:

	// Costruttori
	Poligono2d();
	Poligono2d(int dim);
	Poligono2d(Punto2d pti[], int dim);
	Poligono2d(const Poligono2d& p);

	// Distruttore
	~Poligono2d();

	// Selettori
	int get_num_vertici() const;
	const Punto2d* get_vertici() const;

	// Modificatori
	void set_poligono(Punto2d pti[], int dim);

	// Operatori sovraccaricati
	Poligono2d operator*(double s) const;
	const Poligono2d& operator=(const Poligono2d& p);
	Punto2d& operator[](int indice);
	friend ostream& operator << (ostream& os, const Poligono2d& p);
	friend istream& operator >> (istream& is, Poligono2d& p);

	// Operazioni
	double get_perimetro() const;

private:
	Punto2d* _p;
	int _n;
};

/////////////////////////////////////////////////////////////////////
// Costruttori della classe poligono2d
/////////////////////////////////////////////////////////////////////

Poligono2d::Poligono2d()
	: _p(NULL), _n(0)
{
}

Poligono2d::Poligono2d(int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		Punto2d* p = new Punto2d[dim];
		if (p != NULL) {
			_p = p;
			_n = dim;
		}
	}
}

Poligono2d::Poligono2d(Punto2d pti[], int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		Punto2d* p = new Punto2d[dim];
		if (p != NULL) {
			for (int k = 0; k < dim; k++)
				p[k] = pti[k];
			_p = p;
			_n = dim;
		}
	}
}

Poligono2d::Poligono2d(const Poligono2d& p)
	: _p(NULL), _n(0)
{
	if (p._n > 0) {
		Punto2d* pol = new Punto2d[p._n];
		if (pol != NULL) {
			for (int k = 0; k < p._n; k++)
				pol[k] = p._p[k];
			_p = pol;
			_n = p._n;
		}
	}
}

/////////////////////////////////////////////////////////////////////
// Distruttore della classe poligono2d
/////////////////////////////////////////////////////////////////////

Poligono2d::~Poligono2d()
{
	if (_p != NULL) {
		delete [] _p;
	}
}

/////////////////////////////////////////////////////////////////////
// Selettori della classe poligono2d
/////////////////////////////////////////////////////////////////////

int Poligono2d::get_num_vertici() const
{
	return _n;
}

const Punto2d* Poligono2d::get_vertici() const
{
	return _p;
}

/////////////////////////////////////////////////////////////////////
// Modificatori della classe poligono2d
/////////////////////////////////////////////////////////////////////

void Poligono2d::set_poligono(Punto2d pti[], int dim)
{
	if (dim > 0) {
		Punto2d* p = new Punto2d[dim];
		if (p != NULL) {
			for (int k = 0; k < dim; k++)
				p[k] = pti[k];
			if (_p != NULL)
				delete [] _p;
			_p = p;
			_n = dim;
		}
	}
}

/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati della classe poligono2d
/////////////////////////////////////////////////////////////////////

Poligono2d Poligono2d::operator*(double s) const
{
	Poligono2d p(*this);
	if (get_vertici() != NULL) {
		for (int k = 0; k < get_num_vertici(); k++)
			p[k]= get_vertici()[k] * s;
	}
	return p;
}

const Poligono2d& Poligono2d::operator=(const Poligono2d& p)
{
	if (&p != this) {
		if (_p != NULL) {
			delete [] _p;
			_p = NULL;
		}
		_n = 0;
		int n = p.get_num_vertici();
		if (n > 0) {
			Punto2d* pnewpol = new Punto2d[n];
			if (pnewpol != NULL) {
				for (int k = 0; k < n; k++)
					pnewpol[k] = (p._p)[k];
				_p = pnewpol;
				_n = n;
			}
		}
	}
	return *this;
}

Punto2d& Poligono2d::operator[](int indice)
{
	return _p[indice];
}

/////////////////////////////////////////////////////////////////////
// Operazioni della classe poligono2d
/////////////////////////////////////////////////////////////////////

double Poligono2d::get_perimetro() const
{
	double perimetro = 0.0;
	if (get_vertici() != NULL) {
		for (int k = 0; k < (get_num_vertici() - 1); k++)
			perimetro += (get_vertici()[k]).distanza(get_vertici()[k + 1]);
		perimetro += (get_vertici()[0]).distanza(get_vertici()[get_num_vertici() - 1]);
	}
	return perimetro;
}

////////////////////////////////////////////////////////////////////
// Funzioni amiche della classe poligono2d
////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& os, const Poligono2d& p)
{
	const Punto2d* pt = p.get_vertici();
	if (pt != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			os << pt[k] << ' ';
	return os;
}

istream& operator>>(istream& is, Poligono2d& p)
{
	if (p.get_vertici() != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			is >> p[k];
	return is;
}

/////////////////////////////////////////////////////////////////////
// Funzione main
/////////////////////////////////////////////////////////////////////

int main ()
{
	int numVertici;
	do {
		cout << "Inserire il numero di vertici di un poligono: ";
		cin >> numVertici;
		if (numVertici <= 0)
			cout << "Attenzione! Il numero di vertici deve essere un numero positivo" << endl;
	} while (numVertici <= 0);

	Poligono2d p(numVertici);

	cout << "Inserire le cordinate dei vertici del poligono:" << endl;
	cin >> p;

	cout << "Il perimetro del poligono costituito dai seguenti " << p.get_num_vertici() << " vertici:" << endl;
	cout << p << endl;
	cout << "e' lungo " << p.get_perimetro() << endl;
	cout << endl;

	return 0;
}
```

Un possibile risultato dell'esecuzione sarà:
```
Inserire il numero di vertici di un poligono: 5
Inserire le cordinate dei vertici del poligono:
3 4
6 16
1 1
12 18
23 36
Il perimetro del poligono costituito dai seguenti 5 vertici:
(3,4) (6,16) (1,1) (12,18) (23,36) 
e' lungo 107.26
```