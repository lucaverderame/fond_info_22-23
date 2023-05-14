## Quindicesima esercitazione - Template di Classi

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).

### [Esercizio 15_1] - Reimplementare gli Array

Si progetti e si implementi in linguaggio C++ il template di classe MyArray per realizzare un array contenente n oggetti generici di tipo T. Si supponga che il tipo T sia dotato degli operatori di assegnamento, di inserimento e di estrazione. Il template di classe avrà i seguenti attributi: un puntatore _pdata a un array di oggetti di tipo T e la dimensione _dim dell’array, cioè il numero di oggetti di cui l’array si compone (un numero intero). Il template di classe dovrà inoltre fornire i seguenti metodi:
-	Il costruttore di default che inizializzi _pdata a NULL e _dim a zero.
-	Un costruttore con parametri che riceva in ingresso (ovvero come parametro) un numero intero n e operi come segue: verifichi che n sia un numero positivo e, in tal caso, allochi dinamicamente un array di n oggetti di tipo T, ne assegni il puntatore a _pdata e assegni a _dim il valore n. Nel caso in cui n sia negativo o nullo, il costruttore inizializzerà _pdata a NULL e _dim a zero.
-	Un costruttore con parametri che riceva in ingresso (ovvero come parametri) un numero intero n e un array data di n oggetti di tipo T. Il costruttore opera come segue: verifica che n sia un numero positivo e, in tal caso, alloca dinamicamente un array di n oggetti di tipo T, ne assegna il puntatore a _pdata, assegna a _dim il valore n, scandisce l’array data e ne copia gli elementi nell’array puntato da _pdata. Nel caso in cui n sia negativo o nullo, il costruttore inizializzerà _pdata a NULL e _dim a zero.
-	Il costruttore di copia.
-	Il distruttore.
-	Il selettore get_size che restituisca la dimensione _dim dell’array (un numero intero).
-	Il selettore get_value che riceva come parametro un numero intero index e, dopo aver verificato che index sia compreso tra 0 e _dim – 1, restituisca come valore di ritorno il puntatore all’elemento dell’array di indice index (un puntatore a costante di tipo T). Nel caso in cui il valore di index non sia valido o il puntatore _pdata sia nullo, il selettore restituisce NULL.
-	Il selettore get_array che restituisca come valore di ritorno il puntatore al primo elemento dell’array (un puntatore a costante di tipo T).
-	Il modificatore set_size che riceva come parametro un numero intero n, restituisca come valore di ritorno un numero intero e modifichi l’array in modo tale che esso contenga n elementi. Il modificatore potrà utilizzare la tecnica di riallocazione già incontrata nelle precedenti esercitazioni. In particolare, il metodo allocherà un nuovo array di dimensione n, vi copierà gli elementi contenuti nell’array puntato da _pdata (nel caso in cui la nuova dimensione n sia più piccola della precedente, gli elementi eccedenti andranno perduti), deallocherà l’array puntato da _pdata e assegnerà a _pdata il puntatore al nuovo array. Al termine della riallocazione, il modificatore assegnerà a _dim la nuova dimensione n. Nel caso in cui il valore di n non sia valido o la riallocazione non vada a buon fine, il metodo non modifica l’array e restituisce 0, altrimenti restituisce 1.
-	Il modificatore set_value che riceva come parametro un numero intero index e un oggetto data di tipo T e restituisca come valore di ritorno un numero intero. Dopo aver verificato che index sia compreso tra 0 e _dim – 1, il modificatore assegna l’oggetto T all’elemento dell’array di indice index. Nel caso in cui il valore di index non sia valido o il puntatore _pdata sia nullo, il modificatore restituisce 0, altrimenti restituisce 1.
-	Il modificatore set_array che riceva come parametro un array data di oggetti tipo T e la sua dimensione n e restituisca come valore di ritorno un numero intero. Dopo aver verificato che n sia pari alla dimensione _dim dell’array puntato da _pdata, il modificatore copia gli elementi dell’array data negli elementi dell’array puntato da _pdata. Nel caso in cui il valore di n non sia valido o il puntatore _pdata sia nullo, il modificatore restituisce 0, altrimenti restituisce 1.
-	L’operatore di assegnamento.
-	Il metodo print che scandisca l’array puntato da _pdata e ne stampi a video gli elementi.
-	Il metodo read che acquisisca da tastiera i valori degli elementi contenuti nell’array puntato da _pdata. 
Si scriva quindi un programma C++ per verificare il corretto funzionamento del template di classe. 
Il programma dichiarerà un oggetto a di tipo MyArray, istanziandone il tipo generico con il tipo int e utilizzando il primo costruttore con parametri passando la dimensione n = 10, chiederà all’utente di inserire da tastiera gli elementi dell’array a utilizzando il metodo read, stamperà quindi l’intero array utilizzando il metodo print, infine scandirà l’array calcolando e stampando a video la somma dei valori in esso contenuti.

>Per fare di più: aggiungere al template di classe MyArray l’operatore di selezione con indice []. Il template di classe MyArray così realizzato permette di svolgere le stesse operazioni normalmente supportate dagli array predefiniti? Permette anche di svolgere ulteriori operazioni che gli array predefiniti non supportano?


```cpp
#include <iostream>
using namespace std;

template<typename T>
class MyArray {

public:

	// Costruttori
	MyArray();
	MyArray(int n);
	MyArray(int n, T data[]);
	MyArray(const MyArray& a);

	// Distruttore
	~MyArray();

	// Selettori
	int get_size() const;
	const T* get_value(int index) const;
	const T* get_array() const;

	// Modificatori
	int set_size(int n);
	int set_value(int index, const T& data);
	int set_array(T data[], int n);

	// Operazioni
	void print() const;
	void read();

	// Operatori sovraccaricati
	const MyArray& operator = (const MyArray& a);
	T& operator [] (int index);

private:
	T* _pdata;
	int _dim;
};
/////////////////////////////////////////////////////////////////////
// Costruttori
/////////////////////////////////////////////////////////////////////

template<typename T>
MyArray<T>::MyArray() {
	_pdata = NULL;
	_dim = 0;
}

template<typename T>
MyArray<T>::MyArray(int n)
	: _pdata(NULL), _dim(0)
{
	if (n > 0) {
		T* p = new T[n];
		if (p != NULL) {
			_pdata = p;
			_dim = n;
		}
	}
}

template<typename T>
MyArray<T>::MyArray(int n, T data[])
	: _pdata(NULL), _dim(0)
{
	if (n > 0) {
		T* p = new T[n];
		if (p != NULL) {
			_pdata = p;
			_dim = n;
			for (int i = 0; i < n; i++)
				_pdata[i] = data[i];
		}
	}
}

template<typename T>
MyArray<T>::MyArray(const MyArray& a)
	: _pdata(NULL), _dim(0)
{
	int n = a._dim;
	if (n > 0) {
		T* p = new T[n];
		if (p != NULL) {
			_pdata = p;
			_dim = n;
			for (int i = 0; i < n; i++)
				_pdata[i] = a._pdata[i];
		}
	}
}


/////////////////////////////////////////////////////////////////////
// Distruttore
/////////////////////////////////////////////////////////////////////

template<typename T>
MyArray<T>::~MyArray() {
	if (_pdata != NULL)
		delete[] _pdata;
}


/////////////////////////////////////////////////////////////////////
// Selettori
/////////////////////////////////////////////////////////////////////

template<typename T>
int MyArray<T>::get_size() const {
	return _dim;
}

template<typename T>
const T* MyArray<T>::get_value(int index) const {
	if (index >= 0 && index < _dim - 1 && _pdata != NULL) {
		return _pdata[index];
	}
	return NULL;
}

template<typename T>
const T* MyArray<T>::get_array() const
{
	return _pdata;
}


/////////////////////////////////////////////////////////////////////
// Modificatori
/////////////////////////////////////////////////////////////////////

template<typename T>
int MyArray<T>::set_size(int n) {
	if (n <= 0)
		return 0;

	T* p = new T[n];
	if (p == NULL)
		return 0;

	if (_pdata != NULL) {
		for (int i = 0; i < min(_dim, n); i++)
			p[i] = _pdata[i];
		delete[] _pdata;
	}
	_pdata = p;
	_dim = n;
	return 1;
}

template<typename T>
int MyArray<T>::set_value(int index, const T& data) {
	if (index >= 0 && index < _dim - 1 && _pdata != NULL) {
		_pdata[index] = data;
		return 1;
	}
	return 0;
}

template<typename T>
int MyArray<T>::set_array(T data[], int n) {
	if (n == _dim && _pdata != NULL) {
		for(int i = 0; i < n; i++)
			_pdata[i] = data[i];
		return 0;
	}
	return 1;
}


/////////////////////////////////////////////////////////////////////
// Operazioni
/////////////////////////////////////////////////////////////////////

template<typename T>
void MyArray<T>::print() const {
	if (_pdata != NULL) {
		cout << "{";
		for (int i = 0; i < _dim - 1; i++)
			cout << _pdata[i] << ", ";
		cout << _pdata[_dim - 1] << "}" << endl;
	}
}

template<typename T>
void MyArray<T>::read() {
	if (_pdata != NULL) {
		for (int i = 0; i < _dim; i++) {
			cout << "Inserire elemento " << i + 1 << endl;
			cin >> _pdata[i];
		}
	}
}


/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati
/////////////////////////////////////////////////////////////////////

template<typename T>
const MyArray<T>& MyArray<T>::operator = (const MyArray<T>& a) {
	if (this != &a) {
		if (_pdata != NULL) {
			delete[] _pdata;
		}
		int n = a._dim;
		if (n > 0) {
			T* p = new T[n];
			if (p != NULL) {
				_pdata = p;
				_dim = n;
				for (int i = 0; i < n; i++)
					_pdata[i] = a._pdata[i];
			}
			else {
				_pdata = NULL;
				_dim = 0;
			}
		}
		else {
			_pdata = NULL;
			_dim = 0;
		}
	}
	return *this;
}

template<typename T>
T& MyArray<T>::operator [] (int index) {
	return _pdata[index];
}


int main() {

	const int dim = 10;
	MyArray<int> a(dim);

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
```
Un possibile risultato dell'esecuzione sarà:
```
Inserire 10 numeri interi:
Inserire elemento 1
4
Inserire elemento 2
3
Inserire elemento 3
4
Inserire elemento 4
67
Inserire elemento 5
4
Inserire elemento 6
23
Inserire elemento 7
23
Inserire elemento 8
4
Inserire elemento 9
5
Inserire elemento 10
6
Hai inserito i seguenti numeri: {4, 3, 4, 67, 4, 23, 23, 4, 5, 6}
Somma degli elementi inseriti: 143

```

### [Esercizio 15_2] - Estendere le classi per elaborare dati geometrici

Si riprendano le classi punto2d e poligono2d, sviluppate nelle precedenti esercitazioni, e si estendano trasformandole in due template di classe.
Suggerimento: per implementare gli operatori di inserimento e di estrazione, ricordiamo che essi sono di norma funzioni amiche, esterne alla classe e, in questo caso particolare, saranno dei template di funzione. Ad esempio, nel caso del template di classe punto2d, gli operatori di inserimento e di estrazione potranno essere inseriti nell’interfaccia della classe in questo modo:
template <typename S> 
friend ostream& operator<<(ostream& os, const punto2d<S>& p);
template <typename S> 
friend istream& operator>>(istream& is, punto2d<S>& p);
Allo scopo di verificare il corretto funzionamento dei due template di classe, si scriva, infine, un programma C++ che operi come segue:
-	Chieda all’utente di inserire da tastiera il numero di vertici n desiderato per la costruzione di un poligono.
-	Dichiari un oggetto pol_d di tipo poligono2d, istanziandone il tipo generico con il tipo double e passando al costruttore il numero di vertici desiderato n.
-	Chieda all’utente di inserire da tastiera le coordinate dei vertici del poligono utilizzando l’operatore di estrazione.
-	Dichiari un oggetto pol_i di tipo poligono2d, istanziandone il tipo generico con il tipo int e passando al costruttore il numero di vertici desiderato n.
-	Assegni i vertici del poligono pol_i, in modo che questo sia una approssimazione del poligono pol_d, costruita su di una griglia contenente soltanto coordinate intere. A tale scopo, utilizzando l’opportuno modificatore, il programma assegnerà alle coordinate x e y di ciascun vertice di pol_i, il valore intero più vicino al valore delle coordinate x e y del corrispondente vertice di pol_d.
-	Calcoli la lunghezza del perimetro di pol_i e del perimetro di pol_d, ne stampi a video i valori e calcoli e stampi a video l’errore di approssimazione calcolato come la differenza dei due valori elevata al quadrato, ovvero Errore = (Perimetro(pol_d) – Perimetro(pol_i))2.

```cpp
#include <cmath>
#include <iostream>

using namespace std;

template <typename T>
class punto2d {

public:

	// Costruttori
	punto2d();
	punto2d(T x, T y);
	punto2d(const punto2d<T>& p);

	// Distruttore
	~punto2d();

	// Selettori
	T getX() const;
	T getY() const;

	// Modificatori
	void setX(T x);
	void setY(T x);

	// Operatori sovraccaricati
	punto2d<T> operator-() const;
	punto2d<T>& operator++();
	punto2d<T> operator++(int);
    punto2d<T>& operator--();
	punto2d<T> operator--(int);
	punto2d<T> operator+(punto2d<T> p) const;
	punto2d<T> operator-(punto2d<T> p) const;
	punto2d<T> operator*(double s) const;
	int operator==(punto2d<T> p) const;
	const punto2d<T>& operator=(const punto2d<T>& p);
	template <typename S>
	friend ostream& operator<<(ostream& os, const punto2d<S>& p);
	template <typename S>
	friend istream& operator>>(istream& is, punto2d<S>& p);

	// Operazioni
	double distanza(punto2d<T> p) const;

private:
	T _x;
	T _y;
};


/////////////////////////////////////////////////////////////////////
// Costruttori
/////////////////////////////////////////////////////////////////////

template <typename T>
punto2d<T>::punto2d()
	: _x(0), _y(0)
{
}

template <typename T>
punto2d<T>::punto2d(T x, T y)
	: _x(x), _y(y)
{
}

template <typename T>
punto2d<T>::punto2d(const punto2d<T>& p)
	: _x(p._x), _y(p._y)
{
}


/////////////////////////////////////////////////////////////////////
// Distruttore
/////////////////////////////////////////////////////////////////////

template <typename T>
punto2d<T>::~punto2d()
{
}


/////////////////////////////////////////////////////////////////////
// Selettori
/////////////////////////////////////////////////////////////////////

template <typename T>
T punto2d<T>::getX() const
{
	return _x;
}

template <typename T>
T punto2d<T>::getY() const
{
	return _y;
}


/////////////////////////////////////////////////////////////////////
// Modificatori
/////////////////////////////////////////////////////////////////////

template <typename T>
void punto2d<T>::setX(T x)
{
	_x = x;
}

template <typename T>
void punto2d<T>::setY(T y)
{
	_y = y;
}


/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati
/////////////////////////////////////////////////////////////////////

template <typename T>
punto2d<T> punto2d<T>::operator-() const
{
	return punto2d<T>(-getX(), -getY());
}

template <typename T>
punto2d<T>& punto2d<T>::operator++()
{
	setX(getX() + 1);
	setY(getY() + 1);
	return *this;
}

template <typename T>
punto2d<T> punto2d<T>::operator++(int)
{
	punto2d<T> temp(*this);
	setX(getX() + 1);
	setY(getY() + 1);
	return temp;
}

template <typename T>
punto2d<T>& punto2d<T>::operator--()
{
	setX(getX() - 1);
	setY(getY() - 1);
	return *this;
}

template <typename T>
punto2d<T> punto2d<T>::operator--(int)
{
	punto2d<T> temp(*this);
	setX(getX() - 1);
	setY(getY() - 1);
	return temp;
}

template <typename T>
punto2d<T> punto2d<T>::operator+(punto2d<T> p) const
{
	return punto2d<T>(getX() + p.getX(), getY() + p.getY());
}

template <typename T>
punto2d<T> punto2d<T>::operator-(punto2d<T> p) const
{
	return punto2d<T>(getX() - p.getX(), getY() - p.getY());
}

template <typename T>
punto2d<T> punto2d<T>::operator*(double s) const
{
	return punto2d<T>(s * getX(), s * getY());
}

template <typename T>
int punto2d<T>::operator==(punto2d<T> p) const
{
	return (getX() == p.getX() && getY() == p.getY());
}

template <typename T>
const punto2d<T>& punto2d<T>::operator=(const punto2d<T>& p)
{
	if (&p != this) {
		setX(p.getX());
		setY(p.getY());
	}
	return *this;
}

template <typename T>
ostream& operator<<(ostream& os, const punto2d<T>& p)
{
	os << "(" << p.getX() << "," << p.getY() << ")";
	return os;
}

template <typename T>
istream& operator>>(istream& is, punto2d<T>& p)
{
	double x = 0.0;
	double y = 0.0;
	is >> x >> y;
	p.setX(x);
	p.setY(y);
	return is;
}


/////////////////////////////////////////////////////////////////////
// Operazioni
/////////////////////////////////////////////////////////////////////

template <typename T>
double punto2d<T>::distanza(punto2d<T> p) const
{
	double deltaX = getX() - p.getX();
	double deltaY = getY() - p.getY();
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

template <typename T>
class poligono2d
{
public:

	// Costruttori
	poligono2d();
	poligono2d(int dim);
	poligono2d(punto2d<T> pti[], int dim);
	poligono2d(const poligono2d<T>& p);

	// Distruttore
	~poligono2d();

	// Selettori
	int get_num_vertici() const;
	const punto2d<T>* get_vertici() const;
	
	// Modificatori
	void set_poligono(punto2d<T> pti[], int dim);
	
	// Operatori sovraccaricati
	poligono2d<T> operator*(double s) const;
	const poligono2d<T>& operator=(const poligono2d<T>& p);
	punto2d<T>& operator[](int indice);
	template <typename S>
	friend ostream& operator<<(ostream& os, const poligono2d<S>& p);
	template <typename S>
	friend istream& operator>>(istream& is, poligono2d<S>& p);
	
	// Operazioni
	double get_perimetro() const;

private:
	punto2d<T>* _p;
	int _n;
};


/////////////////////////////////////////////////////////////////////
// Costruttori
/////////////////////////////////////////////////////////////////////

template <typename T>
poligono2d<T>::poligono2d()
	: _p(NULL), _n(0)
{
}

template <typename T>
poligono2d<T>::poligono2d(int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		punto2d<T>* p = new punto2d<T>[dim];
		if (p != NULL) {
			_p = p;
			_n = dim;
		}
	}
}

template <typename T>
poligono2d<T>::poligono2d(punto2d<T> pti[], int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		punto2d<T>* p = new punto2d<T>[dim];
		if (p != NULL) {
			for (int k = 0; k < dim; k++)
				p[k] = pti[k];
			_p = p;
			_n = dim;
		}
	}
}

template <typename T>
poligono2d<T>::poligono2d(const poligono2d<T>& p)
	: _p(NULL), _n(0)
{
	if (p._n > 0) {
		punto2d<T>* pol = new punto2d<T>[p._n];
		if (pol != NULL) {
			for (int k = 0; k < p._n; k++)
				pol[k] = p._p[k];
			_p = pol;
			_n = p._n;
		}
	}
}


/////////////////////////////////////////////////////////////////////
// Distruttore
/////////////////////////////////////////////////////////////////////

template <typename T>
poligono2d<T>::~poligono2d()
{
	if (_p != NULL) {
		delete [] _p;
	}
}


/////////////////////////////////////////////////////////////////////
// Selettori
/////////////////////////////////////////////////////////////////////

template <typename T>
int poligono2d<T>::get_num_vertici() const
{
	return _n;
}

template <typename T>
const punto2d<T>* poligono2d<T>::get_vertici() const
{
	return _p;
}


/////////////////////////////////////////////////////////////////////
// Modificatori
/////////////////////////////////////////////////////////////////////
	
template <typename T>
void poligono2d<T>::set_poligono(punto2d<T> pti[], int dim)
{
	if (dim > 0) {
		punto2d<T>* p = new punto2d<T>[dim];
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
// Operatori sovraccaricati
/////////////////////////////////////////////////////////////////////

template <typename T>
poligono2d<T> poligono2d<T>::operator*(double s) const
{
	poligono2d<T> p(*this);
	if (get_vertici() != NULL) {
		for (int k = 0; k < get_num_vertici(); k++)
			p[k]= get_vertici()[k] * s;
	}
	return p;
}

template <typename T>
const poligono2d<T>& poligono2d<T>::operator=(const poligono2d<T>& p)
{
	if (&p != this) {
		if (_p != NULL) {
			delete [] _p;
			_p = NULL;
		}
		_n = 0;
		int n = p.get_num_vertici();
		if (n > 0) {
			punto2d<T>* pnewpol = new punto2d<T>[n];
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

template <typename T>
punto2d<T>& poligono2d<T>::operator[](int indice)
{
	return _p[indice];
}


/////////////////////////////////////////////////////////////////////
// Operazioni
/////////////////////////////////////////////////////////////////////

template <typename T>
double poligono2d<T>::get_perimetro() const
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
// Funzioni amiche
////////////////////////////////////////////////////////////////////

template <typename T>
ostream& operator<<(ostream& os, const poligono2d<T>& p)
{
	const punto2d<T>* pt = p.get_vertici();
	if (pt != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			os << pt[k] << ' ';
	return os;
}

template <typename T>
istream& operator>>(istream& is, poligono2d<T>& p)
{
	if (p.get_vertici() != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			is >> p[k];
	return is;
}

int arrotonda(double x)
{
	return (int(x) + (x - int(x) >= 0.5));
}

int main()
{
	int numVertici;
	do {
		cout << "Inserire il numero di vertici di un poligono: ";
		cin >> numVertici;
		if (numVertici <= 0)
			cout << "Attenzione! Il numero di vertici deve essere un numero positivo" << endl;
	} while (numVertici <= 0);

	poligono2d<double> pol_d(numVertici);	
	cout << "Inserire le cordinate dei vertici del poligono:" << endl;
	cin >> pol_d;
	
	poligono2d<int> pol_i(numVertici);
	punto2d<int>* ppunti = new punto2d<int>[numVertici];
	if (ppunti == NULL) {
		cout << "Errore di allocazione" << endl;
		return -1;
	}
	const punto2d<double>* pvertici = pol_d.get_vertici();
	for (int i = 0; i < numVertici; i++) {
		ppunti[i].setX(arrotonda(pvertici[i].getX()));
		ppunti[i].setY(arrotonda(pvertici[i].getY()));
	}
	pol_i.set_poligono(ppunti, numVertici);
	
	double perimetro_d = pol_d.get_perimetro();
	cout << "Il perimetro del poligono costituito dai seguenti " << pol_d.get_num_vertici() << " vertici:" << endl;
	cout << pol_d << endl;
	cout << "e' lungo " << perimetro_d << endl;
	cout << endl;
	
	double perimetro_i = pol_i.get_perimetro();
	cout << "Il perimetro del poligono costituito dai seguenti " << pol_i.get_num_vertici() << " vertici:" << endl;
	cout << pol_i << endl;
	cout << "e' lungo " << perimetro_i << endl;
	cout << endl;
	
	double errore = (perimetro_d - perimetro_i) * (perimetro_d - perimetro_i);
	cout << "L'errore di arrotondamento vale: " << errore << endl;
	
	return 0;
}

```

Un possibile risultato dell'esecuzione sarà:
```
Inserire il numero di vertici di un poligono: 3
Inserire le cordinate dei vertici del poligono:
1 23
3 4
32 4
Il perimetro del poligono costituito dai seguenti 3 vertici:
(1,23) (3,4) (32,4) 
e' lungo 84.4643

Il perimetro del poligono costituito dai seguenti 3 vertici:
(1,23) (3,4) (32,4) 
e' lungo 84.4643

L'errore di arrotondamento vale: 0

```

### [Esercizio 15_3] - Poligono2d

Allo scopo di sviluppare un software per la geometria analitica si realizzi in linguaggio C++ il template di classe Retta, parametrizzato sul tipo T ed avente per attributi il coefficiente angolare _m e l’intercetta _q (entrambi di tipo T) di una retta sul piano cartesiano, secondo l’equazione y = mx + q. Si implementino, inoltre, i seguenti metodi:
	Il costruttore di default che inizializzi il valore di _m e di _q a zero, utilizzando la lista di inizializzazione. 
	Il costruttore con parametri che riceva come parametri il valore del coefficiente angolare m e dell’intercetta q (entrambi di tipo T) ed inizializzi i corrispondenti attributi della classe usando la lista di inizializzazione.
	Il costruttore di copia. 
	Il distruttore.
	I selettori (un metodo per ciascun attributo).
	I modificatori (un metodo per ciascun attributo).
	Il metodo inserisciDati per leggere da tastiera i valori del coefficiente angolare _m e dell’intercetta _q. Il metodo non restituisce alcun valore di ritorno.
	Il metodo stampaDati che stampi a video l’equazione della retta secondo il seguente formato:
 r: y = mx + q;
dove a m viene sostituito il valore corrente di _m e a q il valore corrente di _q. Il metodo non restituisce alcun valore di ritorno.
	Il metodo calcolaDistanza che riceva come parametri le coordinate (xP, yP) di un punto P (due valori di tipo T), calcoli e restituisca come valore di ritorno la distanza d di P dalla retta (un numero reale), calcolata come:
d=  |y_P-(mx_p+q)|/√(1+m^2 )
Si sviluppi, infine, la funzione main che operi nel modo seguente:
	Dopo aver chiesto all’utente di inserire da tastiera un numero intero n e avere verificato che n sia positivo, allochi dinamicamente un array R di n oggetti di classe Retta, assegnando il tipo double al parametro T. Nel caso in cui n sia negativo, main terminerà stampando a video un messaggio di errore.
	Scandisca l’array R e assegni i valori di _m e _q a ciascun elemento di R, chiamando il metodo inserisciDati.
	Chieda all’utente di inserire le coordinate (xQ, yQ) di un punto Q (due numeri reali), scandisca l’array R, invochi su ciascun elemento dell’array R la funzione calcolaDistanza e ne stampi a video il valore di ritorno (ovvero la distanza del punto Q da ciascuna delle rette contenute nell’array R).
	Deallochi l’array R e termini.



```cpp
#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class Retta {
public:
	Retta();
	Retta(T m, T q);
	Retta(const Retta& r);
	~Retta();

	T getM() const;
	T getQ() const;

	void setM(T m);
	void setQ(T q);

	void inserisciDati();
	void stampaDati() const;
	double calcolaDistanza(T xp, T yp) const;

private:
	T _m;
	T _q;
};

template <typename T>
Retta<T>::Retta() : _m(0), _q(0)
{
}

template <typename T>
Retta<T>::Retta(T m, T q) : _m(m), _q(q)
{
}

template <typename T>
Retta<T>::Retta(const Retta& r) : _m(r._m), _q(r._q)
{
}

template <typename T>
Retta<T>::~Retta() {
}

template <typename T>
T Retta<T>::getM() const {
	return _m;
}

template <typename T>
T Retta<T>::getQ() const {
	return _q;
}


template <typename T>
void Retta<T>::setM(T m) {
	_m = m;
}

template <typename T>
void Retta<T>::setQ(T q) {
	_q = q;
}

template <typename T>
double Retta<T>::calcolaDistanza(T xp, T yp) const {
	return abs(yp - (_m * xp + _q)) / sqrt(1 + _m * _m);
}

template <typename T>
void Retta<T>::inserisciDati() {
	cout << "Inserire il coefficente angolare: ";
	cin >> _m;
	cout << "Inserire l'intercetta: ";
	cin >> _q;
}

template <typename T>
void Retta<T>::stampaDati() const {
	cout << "r: y = " << _m << "x + " << _q << ";" << endl;
}

int main() {
	int n = 0;
	cout << "Inserire dimensione: ";
	cin >> n;
	if (n <= 0) {
		cout << "Errore" << endl;
		return -1;
	}

	Retta<double>* p = new Retta<double>[n];
	for (int i = 0; i < n; i++) {
		p[i].inserisciDati();
	}

	double xq = 0.0, yq = 0.0;
	cout << "Inserire coordinate: ";
	cin >> xq >> yq;
	for (int k = 0; k < n; k++)
		cout << p[k].calcolaDistanza(xq, yq) << endl;

	delete[] p;

	return 0;
}


```

Un possibile risultato dell'esecuzione sarà:
```
Inserire dimensione: 4
Inserire il coefficente angolare: 2
Inserire l'intercetta: 4 
Inserire il coefficente angolare: 5
Inserire l'intercetta: 2
Inserire il coefficente angolare: 4
Inserire l'intercetta: 5
Inserire il coefficente angolare: 5
Inserire l'intercetta: 223
Inserire coordinate: 12 2
11.6276
11.767
12.3693
55.1086

```