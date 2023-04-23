## Tredicesima esercitazione - Sviluppo di classi con array, matrici e puntatori a memoria allocata dinamicamente

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).

### [Esercizio 13_1] - Copisteria

Il titolare di una copisteria desidera elaborare i dati relativi alle pagine stampate giornalmente da ciascuna stampante della sua copisteria. Il numero di pagine stampate è riportato in una collezione di file di testo. In particolare, esiste un file di testo per ciascuna stampante di cui la copisteria è dotata e per ciascun giorno di apertura. I dati all’interno di ogni file di testo sono organizzati come segue: la prima riga riporta il giorno, il mese e l’anno ai quali i dati si riferiscono (tre numeri interi), la seconda riga riporta il codice identificativo s della stampante (un numero intero), la terza riga riporta il numero n di operazioni di stampa che la stampante ha effettuato in quel giorno (un numero intero), le n righe successive riportano il numero di pagine stampate per ciascuna delle n operazioni di stampa effettuate (un numero intero per ciascuna riga).
Esempio
Il file stampe_20210420_2.txt, relativo alle pagine stampate dalla stampante numero 2 il 20/04/2021 è organizzato come segue:
20 4 2021
2
5
112
30
51
12
98
In tale giorno, la stampante numero 2 ha quindi effettuato 5 operazioni di stampa, per le quali le pagine stampate sono quelle riportate nel file (rispettivamente 112, 30, 51, 12 e 98).
Per elaborare tali dati, si sviluppi in linguaggio C++ la classe Stampe avente i seguenti attributi: un oggetto _d di tipo Data per rappresentare la data alla quale i dati si riferiscono (si può utilizzare la classe Data sviluppata nell’esercitazione precedente – Esercizio 12_2), il numero _s della stampante (un numero intero), il numero _n di operazioni di stampa effettuate (un numero intero), il puntatore _p ad un array di _n numeri interi contenente il numero di pagine stampate per ciascuna operazione di stampa. Si implementino, inoltre, i seguenti metodi:
-	Il costruttore di default che (utilizzando la lista di inizializzazione) inizializzi l’oggetto _d per mezzo del costruttore di default della classe Data, inizializzi a 0 il numero della stampante e il numero di operazioni di stampa effettuate e a NULL il puntatore _p.
-	Un costruttore con parametri che riceva in ingresso (ovvero come parametri) un oggetto d di classe Data, il numero s di una stampante della copisteria (un numero intero), un array pagine di numeri interi (passato al costruttore attraverso un puntatore a costante di tipo intero) e la sua dimensione n. Il costruttore alloca dinamicamente un array di n numeri interi. Se l’allocazione dinamica ha successo, il costruttore inizializza _n con il valore del parametro n, assegna a _p il puntatore all’array allocato e vi copia i valori degli elementi dell’array pagine, inizializza gli attributi dell’oggetto _d con i valori degli attributi dell’oggetto d e _s assegnandogli il valore del parametro s.  Altrimenti, tutti gli attributi sono inizializzati con gli stessi valori assegnati dal costruttore di default. Per semplicità si assuma che i valori passati come parametri siano validi. Nota: si possono eventualmente sfruttare i modificatori della classe Stampe.
-	Il costruttore di copia. Nel caso in cui l’allocazione dinamica fallisca, tutti gli attributi vengono inizializzati con gli stessi valori assegnati dal costruttore di default. 
Attenzione: nel caso in cui il puntatore _p contenuto nell’oggetto passato come parametro sia valido, il costruttore di copia dovrà effettuare la copia dell’intero array puntato _p (e non soltanto del puntatore!). 
Nota: si possono eventualmente sfruttare i modificatori della classe Stampe.
-	Il distruttore. 
Attenzione: nel caso in cui l’oggetto che viene distrutto contenga un puntatore _p valido, il distruttore dovrà effettuare la deallocazione dell’area di memoria puntata.
-	I selettori (uno per ciascun attributo). 
Attenzione: il selettore per l’array puntato da _p restituirà un puntatore a costante di tipo intero.
-	Il modificatore per la data alla quale i dati si riferiscono. 
-	Il modificatore per il numero della stampante e per l’array delle pagine stampate che riceva in ingresso (ovvero come parametri) il numero s della nuova stampante (un numero intero), un array di numeri interi pagine (passato al modificatore attraverso un puntatore a costante di tipo intero) contenente i nuovi valori delle pagine stampate e la sua dimensione n e restituisca come valore di ritorno un numero intero. Il modificatore opera come segue: dichiara un puntatore p ad un array di numeri interi, alloca dinamicamente un array di n numeri interi e ne assegna il puntatore a p. Se l’allocazione dinamica avviene con successo, il metodo assegna a ciascun elemento dell’array puntato da p il valore del corrispondente elemento dell’array pagine, dealloca (se esiste) l’array puntato da _p, assegna il valore di p al puntatore _p, il valore di n a _n, il valore di s a _s e termina restituendo 1. Altrimenti, il modificatore non modifica i dati e restituisce -1. Si assuma che i valori assunti dai parametri attuali passati al modificatore siano sempre validi.
-	Il metodo leggi che riceva come parametro una stringa di caratteri nomefile e restituisca come valore di ritorno un numero intero. La stringa nomefile rappresenta il nome di un file il cui formato è quello sopra specificato. Il metodo apre il file, legge i valori contenuti nella prima riga del file e li salva in un oggetto temporaneo d di classe Data, legge poi la seconda riga del file e ne salva il valore in una variabile temporanea s di tipo intero, legge quindi il numero n contenuto nella terza riga del file ed alloca dinamicamente un array di n numeri interi. Nel caso in cui l’allocazione vada a buon fine, il metodo dealloca la memoria eventualmente puntata da _p (verificando quindi che _p non sia un puntatore nullo), assegna a _p il puntatore alla memoria appena allocata, legge le righe successive del file e copia i valori nei corrispondenti elementi dell’array puntato da _p, chiude il file, assegna agli attributi dell’oggetto _d il valore degli attributi dell’oggetto temporaneo d (a tale scopo di può usare l’opportuno modificatore della classe Stampe), assegna all’attributo _s il valore della variabile temporanea s, assegna all’attributo _n il valore della variabile temporanea n e termina restituendo 1. Se l’allocazione dinamica fallisce il metodo non modifica il valore degli attributi e termina restituendo -1. Per semplicità si supponga che il file esista, non sia vuoto e che i dati in esso contenuti siano validi. 
Nota: si possono eventualmente sfruttare i modificatori della classe Stampe, ma al prezzo di una copia aggiuntiva dei dati nel modificatore per il numero della stampante e per l’array delle pagine stampate. Questo può eventualmente ridurre le prestazioni in caso di file molto grandi.
-	Il metodo stampa che stampi a video il valore corrente degli attributi secondo il seguente formato: “	<giorno>/<mese>/<anno>, stampante n. <numero stampante> 
numero di stampe effettuate: <numero stampe>
pagine stampate: <numero>, <numero>, <numero>, …, <numero>	“
dove <giorno>, <mese> e <anno> rappresentano rispettivamente i valori degli attributi dell’oggetto _d di classe Data, <numero stampante> rappresenta il valore di _s, <numero stampe> rappresenta il valore di _n e <numero> rappresenta il valore di ciascun elemento dell’array puntato da _p.
-	Il metodo totale_pagine che calcoli e restituisca il numero totale di pagine stampate (un numero intero). Il metodo calcola e restituisce la somma dei valori contenuti nell’array puntato da _p. Nel caso in cui il valore del puntatore _p non sia valido il metodo restituisce -1.
-	Il metodo intervallo_pagine che calcoli il numero minimo e il numero massimo di pagine stampate (due numeri interi). Il metodo restituisce tali valori come due parametri di uscita m e M (cioè due numeri interi passati per riferimento) e restituisce come valore di ritorno un numero intero. Il metodo scandisce l’array puntato da _p e ne calcola il valore minimo e il valore massimo. Quindi assegna ad m il minimo e ad M il massimo. Nel caso in cui il valore del puntatore _p non sia valido il metodo assegna il valore 0 a m ed M e restituisce -1, altrimenti restituisce 1.
Si scriva, infine, un programma che operi come segue:
1.	Chieda all’utente di inserire da tastiera il numero k di file da elaborare (un numero intero).
2.	Definisca un puntatore ps ad un oggetto di tipo Stampe, allochi dinamicamente un array di k oggetti di tipo Stampe e ne assegni il puntatore a ps. Nel caso in cui l’allocazione dinamica fallisca, il programma stampa a video un messaggio di errore e termina.
3.	Definisca la variabile pagine_totali (un numero intero) per rappresentare il numero totale di pagine stampate e la inizializzi a 0.
4.	Per ogni elemento dell’array puntato da ps:
o	Chieda all’utente di immettere da tastiera il nome del file da elaborare (una stringa contenente al massimo 127 caratteri più il carattere nullo)
o	Invochi il metodo leggi del corrispondente elemento dell’array, passando al metodo il nome del file immesso dall’utente.
o	Se la chiamata al metodo leggi fallisce, il programma stampa a video un messaggio di errore e termina. Altrimenti, il programma invoca il metodo stampa del medesimo oggetto per visualizzare i dati appena letti.
o	Invochi il metodo totale_pagine e sommi il valore restituito dal metodo al contenuto corrente della variabile pagine_totali.
5.	Stampi a video il numero totale di pagine stampate, cioè il valore della variabile pagine_totali.
6.	Deallochi l’array puntato da ps e termini.


```cpp
#include <iostream>
#include <fstream>
using namespace std;

//////////////////////////////////////////////////////////////////////////
// Interfaccia della classe data
//////////////////////////////////////////////////////////////////////////

class Data {
public:

	// Costruttori
	Data();
	Data(int giorno, int mese, int anno);
	Data(const Data& d);

	// Distruttore
	~Data();

	// Selettori
	int get_giorno() const;
	int get_mese() const;
	int get_anno() const;

	// Modificatori
	void set_giorno(int giorno);
	void set_mese(int mese);
	void set_anno(int anno);

	// Operazioni
	void inserisci();
	void stampa() const;
	Data successiva() const;
	Data precedente() const;

private:

	// Dati membro
	int _giorno;
	int _mese;
	int _anno;

	// Funzioni di supporto
	int num_giorni(int mese, int anno) const;
	int valida(int giorno, int mese, int anno) const;
};

//////////////////////////////////////////////////////////////////////////
// Costruttori della classe data
//////////////////////////////////////////////////////////////////////////

Data::Data()
{
	_giorno = 1;
	_mese = 1;
	_anno = 1900;
}

Data::Data(int giorno, int mese, int anno)
{
	if (valida(giorno, mese, anno)) {
		_giorno = giorno;
		_mese = mese;
		_anno = anno;
	}
	else {
		_giorno = 1;
		_mese = 1;
		_anno = 1900;
	}
}

Data::Data(const Data& d)
{
	_giorno = d._giorno;
	_mese = d._mese;
	_anno = d._anno;
}

//////////////////////////////////////////////////////////////////////////
// Distruttore della classe data
//////////////////////////////////////////////////////////////////////////

Data::~Data()
{
}

//////////////////////////////////////////////////////////////////////////
// Selettori della classe data
//////////////////////////////////////////////////////////////////////////

int Data::get_giorno() const
{
	return _giorno;
}

int Data::get_mese() const
{
	return _mese;
}

int Data::get_anno() const
{
	return _anno;
}

//////////////////////////////////////////////////////////////////////////
// Modificatori della classe data
//////////////////////////////////////////////////////////////////////////

void Data::set_giorno(int giorno)
{
	if (valida(giorno, _mese, _anno)) {
		_giorno = giorno;
	}
}

void Data::set_mese(int mese)
{
	if (valida(_giorno, mese, _anno)) {
		_mese = mese;
	}
}

void Data::set_anno(int anno)
{
	_anno = anno;
}

//////////////////////////////////////////////////////////////////////////
// Operazioni
//////////////////////////////////////////////////////////////////////////

void Data::inserisci()
{
	int g = 0; int m = 0; int a = 0;
	do {
		cout << "Inserire giorno: ";
		cin >> g;
		cout << "Inserire mese: ";
		cin >> m;
		cout << "Inserire anno: ";
		cin >> a;
		cout << endl;
		if (!valida(g, m, a))
			cout << "Attenzione: la data inserita non e' valida" << endl << endl;
	} while(!valida(g, m, a));
	set_giorno(g);
	set_mese(m);
	set_anno(a);
}

void Data::stampa() const
{
	cout << get_giorno() << "/" << get_mese() << "/" << get_anno();
}

Data Data::successiva() const
{

	int giorno_successiva = get_giorno() + 1;
	int mese_successiva = get_mese();
	int anno_successiva = get_anno();

	if (giorno_successiva > num_giorni(get_mese(), get_anno())) {
		giorno_successiva = 1;
		mese_successiva++;
		if (mese_successiva > 12) {
			mese_successiva = 1;
			anno_successiva++;
		}
	}

	return Data(giorno_successiva, mese_successiva, anno_successiva);
}

Data Data::precedente() const
{
	int giorno_precedente = get_giorno() - 1;
	int mese_precedente = get_mese();
	int anno_precedente = get_anno();

	if (giorno_precedente < 1) {
		mese_precedente--;
		if (mese_precedente < 1) {
			mese_precedente = 12;
			anno_precedente--;
		}
		giorno_precedente = num_giorni(mese_precedente, anno_precedente);
	}

	return Data(giorno_precedente, mese_precedente, anno_precedente);
}

//////////////////////////////////////////////////////////////////////////
// Funzioni di supporto della classe data
//////////////////////////////////////////////////////////////////////////

int Data::num_giorni(int mese, int anno) const
{
	switch (mese) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			if (((anno % 4 == 0) && (anno % 100 != 0)) || (anno % 400 == 0))
				return 29;
			else
				return 28;
		default:
			return 0;
	}
}

int Data::valida(int giorno, int mese, int anno) const
{
	if (mese < 1 || mese > 12)
		return 0;

	if (giorno < 1 || giorno > num_giorni(mese, anno))
		return 0;

	return 1;
}


//////////////////////////////////////////////////////////////////////////
// Interfaccia della classe stampe
//////////////////////////////////////////////////////////////////////////

class Stampe {
public:

    // Costruttori
    Stampe();
    Stampe(Data d, int s, const int* pagine, int n);
    Stampe(const Stampe& s);

    // Distruttore
    ~Stampe();

    // Selettori
    Data get_data() const;
    int get_stampante() const;
    int get_numero_stampe() const;
    const int* get_pagine_stampate() const;

    // Modificatori
    void set_data(Data d);
    int set_pagine_stampate(int s, const int* pagine, int n);

    // Operazioni
    int leggi(char nomefile[]);
    void stampa() const;
    int totale_pagine() const;
    int intervallo_pagine(int& m, int& M) const;

private:
    Data _d;
    int _s;
    int _n;
    int* _p;
};

//////////////////////////////////////////////////////////////////////////
// Costruttori della classe stampe
//////////////////////////////////////////////////////////////////////////

Stampe::Stampe() : _d(), _s(0), _n(0), _p(NULL)
{
}

Stampe::Stampe(Data d, int s, const int* pagine, int n)
    : _d(), _s(0), _n(0), _p(NULL)
{
    set_data(d);
    set_pagine_stampate(s, pagine, n);
}

Stampe::Stampe(const Stampe& s)
    : _d(), _s(0), _n(0), _p(NULL)
{
    int n_stampe = s.get_numero_stampe();
    if (n_stampe <= 0)
        return;

    set_data(s.get_data());
    set_pagine_stampate(s.get_stampante(),
                        s.get_pagine_stampate(),
                        n_stampe);
}

//////////////////////////////////////////////////////////////////////////
// Distruttore della classe stampe
//////////////////////////////////////////////////////////////////////////

Stampe::~Stampe()
{
    if (_p != NULL)
        delete[] _p;
}

//////////////////////////////////////////////////////////////////////////
// Selettori della classe stampe
//////////////////////////////////////////////////////////////////////////

Data Stampe::get_data() const
{
    return _d;
}

int Stampe::get_stampante() const
{
    return _s;
}

int Stampe::get_numero_stampe() const
{
    return _n;
}

const int* Stampe::get_pagine_stampate() const
{
    return _p;
}

//////////////////////////////////////////////////////////////////////////
// Modificatori della classe stampe
//////////////////////////////////////////////////////////////////////////

void Stampe::set_data(Data d)
{
    // si potr\u00e0 semplificare appena avremo fatto l'operatore di assegnamento!
    _d.set_giorno(d.get_giorno());
    _d.set_mese(d.get_mese());
    _d.set_anno(d.get_anno());
}

int Stampe::set_pagine_stampate(int s, const int* pagine, int n)
{
    int* p = new int[n];
    if (p != NULL) {
        for (int i = 0; i < n; i++)
            p[i] = pagine[i];
        if (_p != NULL)
            delete [] _p;
        _p = p;
        _n = n;
        _s = s;
        return 1;
    }
    return -1;
}

//////////////////////////////////////////////////////////////////////////
// Operazioni della classe stampe
//////////////////////////////////////////////////////////////////////////

int Stampe::leggi(char nomefile[])
{
    fstream fin;
    fin.open(nomefile, ios::in);

    // prima riga
    int giorno = 0; int mese = 0; int anno = 0;
    fin >> giorno >> mese >> anno;
    Data d(giorno, mese, anno);

    // seconda riga
    int s = 0;
    fin >> s;

    // terza riga
    int n = 0;
    fin >> n;
    int* p = new int[n];
    if (p == NULL)
        return -1;

    // righe successive
    for (int i = 0; i < n; i++)
        fin >> p[i];

    fin.close();

    if (_p != NULL)
        delete [] _p;
    _p = p;
    set_data(d);
    _s = s;
    _n = n;

    return 1;
}

void Stampe::stampa() const
{
    int n_stampe = get_numero_stampe();
    int id = get_stampante();
    const int* p = get_pagine_stampate();

    get_data().stampa();
    cout << ": stampante n. " << id << endl;
    cout << "pagine stampate: ";
    for (int i = 0; i < n_stampe - 1; i++)
        cout << p[i] << ", ";
    cout << p[n_stampe - 1] << endl;
}

int Stampe::totale_pagine() const
{
    int n_stampe = get_numero_stampe();
    const int* p = get_pagine_stampate();

    if (p == NULL)
        return -1;

    int totale = 0;
    for (int i = 0; i < n_stampe; i++)
        totale += p[i];
    return totale;
}

int Stampe::intervallo_pagine(int& m, int& M) const
{
    int n_stampe = get_numero_stampe();
    const int* p = get_pagine_stampate();

    if (p == NULL) {
        m = 0;
        M = 0;
        return -1;
    }

    m = p[0]; M = p[0];
    for (int i = 1; i < n_stampe; i++) {
        if (p[i] < m)
            m = p[i];
        if (p[i] > M)
            M = p[i];
    }
    return 1;
}


////////////////////////////////////////////////////////////////////
// Funzione main
////////////////////////////////////////////////////////////////////

int main ()
{
    int k = 0;
    do {
        cout << "Inserire il numero di file da elaborare: ";
        cin >> k;
        if (k <= 0)
            cout << "Attenzione: occorre inserire un numero positivo" << endl;
    } while (k <= 0);

    Stampe* ps = new Stampe[k];
    if (ps == NULL) {
        cout << "Attenzione: non e' stato possibile allocare la memoria" << endl;
        return -1;
    }

    int pagine_totali = 0;
    for (int i = 0; i < k; i++) {
        char file[128];
        cout << "Inserire il nome del file numero " << i + 1 << ": ";
        cin >> file;
        int r = ps[i].leggi(file);
        if (r == -1) {
            cout << "Attenzione: errore nella lettura del file" << endl;
            return -2;
        }
        ps[i].stampa();
        pagine_totali += ps[i].totale_pagine();
    }

    cout << "Sono state stampate in tutto " << pagine_totali << " pagine" << endl;

    delete [] ps;

    return 0;
}
```
Un possibile risultato dell'esecuzione sarà:
```
Inserire il numero di file da elaborare: 1
Inserire il nome del file numero 1: stampe_20210420_2.txt
20/4/2021: stampante n. 2
pagine stampate: 112, 30, 51, 12, 98
Sono state stampate in tutto 303 pagine
```

### [Esercizio 13_2] - Azienda

Un’azienda ha otto dipartimenti. I dipendenti che lavorano in ciascun dipartimento possono appartenere ad una di cinque diverse classi stipendiali. Allo scopo di gestire i dipendenti dell’azienda, si realizzi in linguaggio C++ la classe Dipendenti avente i seguenti attributi: un array _s di cinque numeri reali per rappresentare lo stipendio corrispondente a ciascuna delle cinque classi stipendiali e una matrice di numeri interi _D di otto righe e cinque colonne i cui elementi rappresentano, per ciascun dipartimento, il numero di dipendenti appartenenti a ciascuna classe stipendiale. Se, ad esempio, l’elemento nella terza riga e quarta colonna di _D valesse 10, significherebbe che nel terzo dipartimento lavorano 10 dipendenti appartenenti alla quarta classe stipendiale. Si implementino, inoltre, i seguenti metodi:
-	Il costruttore di default che inizializzi a zero tutti gli elementi dell’array _s e della matrice _D. 
-	Il costruttore con parametri che riceva come parametri un array di cinque numeri reali e una matrice di numeri interi di otto righe e cinque colonne e li assegni rispettivamente all’array _s e alla matrice _D. Per semplicità si supponga che i valori passati al costruttore siano sempre validi.
-	Il costruttore di copia. 
-	Il distruttore.
-	I selettori per l’array _s e per la matrice _D. Il selettore per _s restituirà come valore di ritorno un puntatore a costante all’array stesso. Il selettore per _D riceverà in ingresso (ovvero come parametri) due numeri interi h e k e restituirà come valore di ritorno l’elemento della matrice _D di indici h e k (un numero intero). Nel caso in cui il valore di almeno uno dei due parametri h e k non fosse valido, il metodo restituirà -1.
-	I modificatori per l’array _s e per la matrice _D. Per semplicità, si supponga che l’array passato come parametro al modificatore per _s e la matrice passata come parametro al modificatore per _D abbiano le dimensioni corrette e che i loro elementi assumano valori validi.
-	Il metodo totaleDipendenti che calcoli e restituisca come valore di ritorno il numero totale dei dipendenti dell’azienda (un numero intero dato dalla somma degli elementi della matrice _D).
-	Il metodo estremiStipendio che calcoli e restituisca come parametri di uscita (ovvero passati per riferimento) gli indici dei due dipartimenti (due numeri interi) per i quali l’azienda spende l’ammontare massimo e l’ammontare minimo per gli stipendi dei dipendenti. Il metodo non restituisce alcun valore di ritorno.
Si scriva quindi la funzione main che operi nel modo seguente:
-	Dichiari un array stp di cinque numeri reali e una matrice di numeri interi Dip di otto righe e cinque colonne.
-	Apra in lettura il file Dati.txt. Tale file contiene nella prima riga cinque numeri reali che rappresentano gli stipendi associati a ciascuna classe stipendiale e nelle otto righe successive, per ciascuna riga, cinque numeri interi che rappresentano il numero di dipendenti inquadrati in ciascuna classe stipendiale per il dipartimento corrispondente alla riga in esame. Per semplicità si supponga che i valori contenuti nel file siano validi. Nel caso in cui il file Dati.txt non esista, main termina con valore di ritorno -1.
-	Legga la prima riga del file Dati.txt assegnandone i valori agli elementi dell’array stp e le righe successive assegnandone i valori agli elementi della matrice Dip.
-	Utilizzando il costruttore con parametri, allochi dinamicamente un oggetto pdip di tipo Dipendenti, passando l’array stp e la matrice Dip come parametri al costruttore.
-	Invochi su tale oggetto i metodi totaleDipendenti ed estremiStipendio e stampi a video il risultato.
-	Deallochi l’oggetto pdip e termini.


```cpp
#include <iostream>
#include <fstream>

using namespace std;

const int nr = 8;
const int nc = 5;

class Dipendenti {
public:
	Dipendenti();
	Dipendenti(double s[nc], int D[nr][nc]);
	Dipendenti(const Dipendenti& d);
	~Dipendenti();
	const double* getStipendi() const;
	int getDipendenti(int h, int k) const;
	void setStipendi(double s[nc]);
	void setDipendenti(int D[nr][nc]);
	int totaleDipendenti() const;
	void estremiStipendio(int& dipMax, int& dipMin) const;

private:
	double _s[nc];
	int _D[nr][nc];
};

Dipendenti::Dipendenti() {
	for (int k = 0; k < nc; k++)
		_s[k] = 0.0;
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_D[i][j] = 0;
}

Dipendenti::Dipendenti(double s[nc], int D[nr][nc]) {
	for (int k = 0; k < nc; k++)
		_s[k] = s[k];
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_D[i][j] = D[i][j];
}

Dipendenti::Dipendenti(const Dipendenti& d) {
	for (int k = 0; k < nc; k++)
		_s[k] = d._s[k];
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_D[i][j] = d._D[i][j];
}

Dipendenti::~Dipendenti() {
}

const double* Dipendenti::getStipendi() const {
	return _s;
}

int Dipendenti::getDipendenti(int h, int k) const {
	if ((h >= 0 && h < nr) && (k >= 0 && k < nc))
		return _D[h][k];
	return -1;
}

void Dipendenti::setStipendi(double s[nc]) {
	for (int k = 0; k < nc; k++)
		_s[k] = s[k];
}

void Dipendenti::setDipendenti(int D[nr][nc]) {
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			_D[i][j] = _D[i][j];
}

int Dipendenti::totaleDipendenti() const {
	int somma = 0;
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			somma += _D[i][j];
	return somma;
}

void Dipendenti::estremiStipendio(int& dipMax, int& dipMin) const {
	double stip[nr];
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			stip[i] += _s[j] * _D[i][j];

	double Min = stip[0]; double Max = stip[0];
	int iMin = 0; int iMax = 0;
	for (int k = 0; k < nr; k++) {
		if (stip[k] > Max) {
				iMax = k;
				Max = stip[k];
		}
		if (stip[k] < Min) {
			iMin = k;
			Min = stip[k];
		}
	}
	dipMax = iMax;
	dipMin = iMin;
}


int main() {
	double stp[nc] = { 0.0 };
	int Dip[nr][nc] = { 0 };
	fstream fin;
	fin.open("Dati.txt", ios::in);
	if (!fin) return -1;
	for (int k = 0; k < nc; k++)
		fin >> stp[k];
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nc; j++)
			fin >> Dip[i][j];
	fin.close();
	Dipendenti* pdip = new Dipendenti(stp, Dip);
	int DMin = 0; int DMax = 0;
	cout << "Numero dipendenti: " << pdip->totaleDipendenti() << endl;
	pdip->estremiStipendio(DMax, DMin);
	cout << "Dipartimento piu' costoso: " << DMax + 1 << endl;
	cout << "Dipartimento meno costoso: " << DMin + 1 << endl;
	delete pdip;
	return 0;
}
```

Un possibile risultato dell'esecuzione sarà:
```
Numero dipendenti: 561
Dipartimento piu' costoso: 6
Dipartimento meno costoso: 1
```