## Dodicesima esercitazione - Introduzione alle Classi

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).

### [Esercizio 12_1] - Introduzione alle Classi

Allo scopo di gestire l'acquisizione di dati da un sensore meteorologico che rileva la temperatura (misurata in gradi Celsius) e la pressione (misurata in hPa) dell'aria, si sviluppi in C++ la classe rilevamento avente i seguenti attributi: un numero reale _temperatura e un numero reale _pressione. Si implementino, inoltre, i seguenti metodi:

Il costruttore di default che inizializzi a zero entrambi gli attributi. A scopo didattico, aggiungere nel corpo del costruttore la stampa a video del seguente messaggio: "Questo e' il costruttore di default della classe rilevamento".

Un costruttore con parametri che riceva in ingresso (ovvero come parametri) due numeri reali t e p e inizializzi l'attributo _temperatura al valore di t e l'attributo _pressione al valore di p. Per semplicità, si assuma che i valori assunti da t e da p siano sempre validi. A scopo didattico, aggiungere nel corpo del costruttore la stampa a video del seguente messaggio "Questo e' il primo costruttore con parametri della classe rilevamento".

Un costruttore con parametri che riceva in ingresso (ovvero come parametri) un array dati di due numeri reali e inizializzi l'attributo _temperatura al valore del primo elemento dell'array dati e l'attributo _pressione al valore del secondo elemento dell'array dati. Per semplicità, si assuma che i valori assunti dagli elementi dell'array dati siano sempre validi. A scopo didattico, aggiungere nel corpo del costruttore la stampa a video del seguente messaggio "Questo e' il secondo costruttore con parametri della classe rilevamento".

Il costruttore di copia. A scopo didattico, aggiungere nel corpo del costruttore la stampa a video del messaggio "Questo e' il costruttore di copia della classe rilevamento."

La funzione stampa_rilevamento che stampi a video i valori degli attributi secondo il seguente formato: "Rilevamento: temperatura = x C, pressione = y hPa" dove al posto di x e y vengono sostituiti i valori correnti degli attributi _temperatura e _pressione, rispettivamente. La funzione non restituisce alcun valore di ritorno.

Si scriva, infine, la funzione main che operi come segue:

Dichiari un oggetto r1 di tipo rilevamento, stampando i valori di temperatura e pressione;

Dichiari un oggetto r2 di tipo rilevamento, inizializzandolo con i valori 20.0 per la temperatura e 1000.0 per la pressione, stampando i valori di temperatura e pressione;

Dichiari un array ril di due numeri reali, inizializzi i due elementi di ril rispettivamente ai valori 15.0 e 1010.0, stampando i valori di temperatura e pressione;

Dichiari un oggetto r4 di tipo rilevamento, inizializzandolo come copia di r1, stampando i valori di temperatura e pressione;

```cpp
#include <iostream>
using namespace std;

// Classe rilevamento
class rilevamento {
public:
    rilevamento();
    rilevamento(double t, double p);
    rilevamento(double dati[2]);
    rilevamento(const rilevamento& r);
    void stampa_rilevamento();
private:
    double _temperatura;
    double _pressione;
};

 rilevamento::rilevamento()
{
    _temperatura = 0.0;
    _pressione = 0.0;
    cout << "Questo e' il costruttore di default" << endl;
}

 rilevamento::rilevamento(double t, double p)
{
    _temperatura = t;
    _pressione = p;
    cout << "Questo e' il costruttore con parametri" << endl;
}

 rilevamento::rilevamento(double dati[2])
{
    _temperatura = dati[0];
    _pressione = dati[1];
    cout << "Questo e' il costruttore con parametri" << endl;
}

 rilevamento::rilevamento(const rilevamento& r)
{
    _temperatura = r._temperatura;
    _pressione = r._pressione;
    cout << "Questo e' il costruttore di copia" << endl;
}

void rilevamento::stampa_rilevamento()
{
    cout << "Rilevamento: temperatura = "
         << _temperatura << " C, pressione = "
         << _pressione << " hPa" << endl;

}

int main()
{
    cout << "Parte 1: " << endl;
    rilevamento r1;
    r1.stampa_rilevamento();

    cout << "Parte 2: " << endl;
    rilevamento r2(15.0, 1060.0);
    r2.stampa_rilevamento();

    cout << "Parte 3: " << endl;
    double ril[2] = {20.0, 1065.0};
    rilevamento r3(ril);
    r3.stampa_rilevamento();

        cout << "Parte 4: " << endl;
    rilevamento r4(r1);
    r4.stampa_rilevamento();

    return 0;
}
```
Un possibile risultato dell'esecuzione sarà:
```
Parte 1: 
Questo e' il costruttore di default
Rilevamento: temperatura = 0 C, pressione = 0 hPa
Parte 2: 
Questo e' il costruttore con parametri
Rilevamento: temperatura = 15 C, pressione = 1060 hPa
Parte 3: 
Questo e' il costruttore con parametri
Rilevamento: temperatura = 20 C, pressione = 1065 hPa
Parte 4: 
Questo e' il costruttore di copia
Rilevamento: temperatura = 0 C, pressione = 0 hPa
```

### [Esercizio 12_2] - Classe Data

Si progetti e si implementi la classe C++ Data per la gestione delle informazioni relative alle date. La classe conterrà i seguenti attributi: giorno, mese e anno (tre numeri interi). Si implementino, inoltre, i seguenti metodi:
-	Il costruttore di default che inizializzi gli attributi in modo che da impostare la data al 1/1/1900. Si può scegliere se implementare il costruttore usando oppure non usando la lista di inizializzazione.
-	Un costruttore con parametri che riceva in ingresso (ovvero come parametri) tre numeri interi che rappresentino il giorno, il mese e l’anno di una data e li assegni ai corrispondenti attributi della classe Data. Per semplicità si assuma che i valori assunti dai parametri attuali siano sempre validi. Si può scegliere se implementare il costruttore usando oppure non usando la lista di inizializzazione.
-	Il costruttore di copia. Si può scegliere se implementare il costruttore usando oppure non usando la lista di inizializzazione.
-	Il distruttore.
-	I selettori (uno per ciascun attributo).
-	I modificatori (uno per ciascun attributo). Per semplicità si assuma che i valori assunti dai parametri attuali passati ai modificatori siano sempre validi.
-	Un metodo per inserire una data da tastiera. Per semplicità si assuma che i valori inseriti da tastiera siano sempre validi.
-	Un metodo per stampare a video la data, secondo il formato “g/m/a” dove a g, m e a vengono sostituiti i valori correnti degli attributi corrispondenti della classe Data.
-	Un metodo che calcoli e restituisca la data relativa al giorno immediatamente precedente. 
-	Un metodo che calcoli e restituisca la data relativa al giorno immediatamente seguente. 
Si scriva quindi un programma C++ per verificare il corretto funzionamento della classe Data. 
Il programma chiederà all’utente di immettere da tastiera una data e stamperà a video la data stessa, la data del giorno precedente e quella del giorno successivo.

>:warning: Per fare di più: implementare le verifiche della validità precedentemente omesse. Modificare di conseguenza il costruttore con parametri, i modificatori e il metodo per inserire una data da tastiera in modo tale che accertino che il valore passato od ottenuto per il mese sia compreso tra 1 e 12 e, successivamente, che il valore passato od ottenuto per il giorno sia compreso tra 1 e il numero di giorni di cui si compone il mese specificato. A tale scopo, si può aggiungere un metodo, con accesso limitato ai metodi della classe, che riceva in ingresso un numero intero compreso tra 1 e 12, calcoli e restituisca come valore di ritorno il numero di giorni del mese passato come parametro. In caso di dati non validi, il costruttore con parametri inizializzerà gli attributi della classe alla data 1/1/1900, i modificatori non modificheranno il valore degli attributi e il metodo per inserire una data da tastiera continuerà a chiedere all’utente di inserire i dati finché non si ottengano dei dati validi.

```cpp
#include <iostream>
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
// Costruttori
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
// Distruttore
//////////////////////////////////////////////////////////////////////////

Data::~Data()
{
}

//////////////////////////////////////////////////////////////////////////
// Selettori
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
// Modificatori
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
// Funzioni di supporto
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
// Funzione main
//////////////////////////////////////////////////////////////////////////

int main()
{
	Data d;

	cout << "Inserire una data" << endl;
	d.inserisci();
	cout << "La data che hai inserito e': ";
	d.stampa();
	cout << endl << endl;

	cout << "La data successiva a quella inserita e' ";
	d.successiva().stampa();
	cout << endl << endl;

	cout << "La data precedente a quella inserita e' ";
	d.precedente().stampa();
	cout << endl << endl;

	return 0;
}
```

Un possibile risultato dell'esecuzione sarà:
```
Inserire una data
Inserire giorno: 12
Inserire mese: 04
Inserire anno: 2021

La data che hai inserito e': 12/4/2021

La data successiva a quella inserita e' 13/4/2021

La data precedente a quella inserita e' 11/4/2021
```

### [Esercizio 12_3] - Classe Partita

Si progetti ed implementi una classe C++ Partita per la gestione (semplificata) delle informazioni relative ad una partita di calcio. La classe conterrà i seguenti attributi: la data in cui la partita è stata disputata (un oggetto di classe Data di cui all’Esercizio 2), i nomi delle squadre che hanno disputato la partita (due stringhe contenenti al massimo 32 caratteri), il numero di goal segnati da ciascuna squadra (un numero intero), il numero di giocatori espulsi (un numero intero) e il numero di giocatori ammoniti (un numero intero). Si implementino, inoltre, i seguenti metodi:
-	Il costruttore di default, utilizzando la lista di inizializzazione almeno per l’attributo relativo alla data in cui la partita è stata disputata. Il costruttore inizializzerà a “squadra_1” e “squadra_2” il nome delle due squadre e a zero gli altri attributi.
-	Un costruttore con parametri che riceva in ingresso (ovvero come parametri) la data in cui la partita è stata disputata (un oggetto di classe Data), i nomi delle squadre che hanno disputato la partita (due stringhe di caratteri), il numero di goal segnati da ciascuna squadra (un numero intero), il numero di giocatori espulsi (un numero intero) e il numero di giocatori ammoniti (un numero intero) e assegni tali valori ai corrispondenti attributi della classe Partita. In caso di dati non validi per il numero di goal segnati da ciascuna squadra, per il numero di giocatori espulsi e per il numero di giocatori ammoniti il costruttore assegnerà zero al corrispondente attributo della classe Partita. Il costruttore utilizzerà la lista di inizializzazione almeno per l’attributo relativo alla data in cui la partita è stata disputata.
-	Il costruttore di copia, utilizzando la lista di inizializzazione almeno per l’attributo relativo alla data in cui la partita è stata disputata.
-	Il distruttore.
-	I selettori (uno per ciascun attributo).
-	I modificatori (uno per ciascun attributo). In caso di valori non validi dei parametri attuali, 
i modificatori per il numero di goal segnati da ciascuna squadra, per il numero di giocatori espulsi e per il numero di giocatori ammoniti non modificano il valore dei corrispondenti attributi.
-	Un metodo per consentire all’utente di inserire da tastiera le informazioni relative ad una partita. Nel caso l’utente inserisca un valore non valido, il metodo continua a chiedere all’utente di inserire il valore finché non venga inserito un valore valido.
-	Un metodo per stampare a video le informazioni relative ad una partita, secondo il seguente formato: “gg/mm/aa, squadra_1 – squadra_2: goal_1 – goal_2, espulsi: numero_espulsi, ammoniti: numero_ammoniti”, dove al posto di squadra_1, squadra_2, goal_1, goal_2, numero_espulsi e numero_ammoniti il metodo sostituirà il valore corrente del corrispondente attributo della classe Partita.
Si scriva quindi un programma C++ per verificare il corretto funzionamento della classe Partita. Il programma chiederà all’utente di immettere le informazioni relative ad una partita e quindi le ristamperà a video.

```cpp
#include <iostream>
#include <cstring>
using namespace std;

//////////////////////////////////////////////////////////////////////////
// Costanti
//////////////////////////////////////////////////////////////////////////

const int lunghezza_stringhe = 32;

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
// Costruttori
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
// Distruttore
//////////////////////////////////////////////////////////////////////////

Data::~Data()
{
}

//////////////////////////////////////////////////////////////////////////
// Selettori
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
// Modificatori
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
// Funzioni di supporto
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
// Interfaccia della classe partita
//////////////////////////////////////////////////////////////////////////

class Partita
{
public:

	// Costruttori
	Partita();
	Partita(Data d, char squadra1[], char squadra2[], int goal_squadra1, int goal_squadra2, int num_espulsi, int num_ammoniti);
	Partita(const Partita& p);

	// Distruttore
	~Partita();

	// Selettori
	Data get_data() const;
	const char* get_squadra1() const;
	const char* get_squadra2() const;
	int get_goal_squadra1() const;
	int get_goal_squadra2() const;
	int get_num_espulsi() const;
	int get_num_ammoniti() const;

	// Modificatori
	void set_data(Data d);
	void set_squadra1(char squadra[]);
	void set_squadra2(char squadra[]);
	void set_goal_squadra1(int num_goal);
	void set_goal_squadra2(int num_goal);
	void set_num_espulsi(int num_espulsi);
	void set_num_ammoniti(int num_ammoniti);

	// Operazioni
	void inserisci();
	void stampa() const;

private:
	Data _data_partita;
	char _squadra1[lunghezza_stringhe];
	char _squadra2[lunghezza_stringhe];
	int _goal_squadra1;
	int _goal_squadra2;
	int _num_espulsi;
	int _num_ammoniti;
};

//////////////////////////////////////////////////////////////////////////
// Costruttori della classe partita
//////////////////////////////////////////////////////////////////////////

Partita::Partita()
	: _data_partita()
{
	strcpy(_squadra1, "squadra_1");
	strcpy(_squadra2, "squadra_2");
	_goal_squadra1 = 0;
	_goal_squadra2 = 0;
	_num_espulsi = 0;
	_num_ammoniti = 0;
}

Partita::Partita(Data d, char squadra1[], char squadra2[], int goal_squadra1, int goal_squadra2, int num_espulsi, int num_ammoniti)
	: _data_partita(d)
{
	strcpy(_squadra1, squadra1);
	strcpy(_squadra2, squadra2);
	if (goal_squadra1 >= 0)
		_goal_squadra1 = goal_squadra1;
	else
		_goal_squadra1 = 0;
	if (goal_squadra2 >= 0)
		_goal_squadra2 = goal_squadra2;
	else
		_goal_squadra2 = 0;
	if (num_espulsi >= 0)
		_num_espulsi = num_espulsi;
	else
		_num_espulsi = 0;
	if (num_espulsi >= 0)
		_num_ammoniti = num_ammoniti;
	else
		_num_ammoniti = 0;
}

Partita::Partita(const Partita& p)
	: _data_partita(p._data_partita)
{
	strcpy(_squadra1, p._squadra1);
	strcpy(_squadra2, p._squadra2);
	_goal_squadra1 = p._goal_squadra1;
	_goal_squadra2 = p._goal_squadra2;
	_num_espulsi = p._num_espulsi;
	_num_ammoniti = p._num_ammoniti;
}

//////////////////////////////////////////////////////////////////////////
// Distruttore della classe partita
//////////////////////////////////////////////////////////////////////////

Partita::~Partita()
{
}

//////////////////////////////////////////////////////////////////////////
// Selettori della classe partita
//////////////////////////////////////////////////////////////////////////

Data Partita::get_data() const
{
	return _data_partita;
}

const char* Partita::get_squadra1() const
{
	return _squadra1;
}

const char* Partita::get_squadra2() const
{
	return _squadra2;
}

int Partita::get_goal_squadra1() const
{
	return _goal_squadra1;
}

int Partita::get_goal_squadra2() const
{
	return _goal_squadra2;
}

int Partita::get_num_espulsi() const
{
	return _num_espulsi;
}

int Partita::get_num_ammoniti() const
{
	return _num_ammoniti;
}

//////////////////////////////////////////////////////////////////////////
// Modificatori della classe partita
//////////////////////////////////////////////////////////////////////////

void Partita::set_data(Data d)
{
	_data_partita = d;
}

void Partita::set_squadra1(char squadra[])
{
	strcpy(_squadra1, squadra);
}

void Partita::set_squadra2(char squadra[])
{
	strcpy(_squadra2, squadra);
}

void Partita::set_goal_squadra1(int num_goal)
{
	if (num_goal >= 0) {
		_goal_squadra1 = num_goal;
	}
}

void Partita::set_goal_squadra2(int num_goal)
{
	if (num_goal >= 0) {
		_goal_squadra2 = num_goal;
	}
}

void Partita::set_num_espulsi(int num_espulsi)
{
	if (num_espulsi >= 0) {
		_num_espulsi = num_espulsi;
	}
}

void Partita::set_num_ammoniti(int num_ammoniti)
{
	if (num_ammoniti >= 0) {
		_num_ammoniti = num_ammoniti;
	}
}

//////////////////////////////////////////////////////////////////////////
// Operazioni della classe partita
//////////////////////////////////////////////////////////////////////////

void Partita::inserisci()
{
	cout << "*** Inserire la data della partita ***" << endl;
	Data d;
	d.inserisci();
	set_data(d);

	cout << "*** Inserire i nomi delle squadre ***" << endl;
	char squadra1[lunghezza_stringhe] = "";
	cout << "Inserire la prima squadra: ";
	cin.get();
	cin.getline(squadra1, lunghezza_stringhe, '\n');
	set_squadra1(squadra1);

	char squadra2[lunghezza_stringhe] = "";
	cout << "Inserire la seconda squadra: ";
	cin.getline(squadra2, lunghezza_stringhe, '\n');
	set_squadra2(squadra2);

	cout << endl << "*** Inserire il risultato ***" << endl;
	int goal1 = 0; int goal2 = 0;
	do {
		cout << "Goal segnati dalla prima squadra: ";
		cin >> goal1;
		cout << "Goal segnati dalla seconda squadra: ";
		cin >> goal2;
		if (goal1 < 0 || goal2 < 0)
			cout << "Attenzione, il numero di goal non puo' essere un numero negativo" << endl;
	} while (goal1 < 0 || goal2 < 0);
	set_goal_squadra1(goal1);
	set_goal_squadra2(goal2);

	cout << endl << "*** Inserire il numero di espulsi e ammoniti ***" << endl;
	int num_espulsi = 0;
	do {
		cout << "Inserire il numero di espulsi: ";
		cin >> num_espulsi;
		if (num_espulsi < 0)
			cout << "Attenzione, il numero di espulsi non puo' essere un numero negativo" << endl;
	} while (num_espulsi < 0);
	set_num_espulsi(num_espulsi);
	int num_ammoniti = 0;
	do {
		cout << "Inserire il numero di ammoniti: ";
		cin >> num_ammoniti;
		if (num_ammoniti < 0)
			cout << "Attenzione, il numero di ammoniti non puo' essere un numero negativo" << endl;
	} while (num_ammoniti < 0);
	set_num_ammoniti(num_ammoniti);
}

void Partita::stampa() const
{
	_data_partita.stampa();
	cout << ", " << get_squadra1() << " - " << get_squadra2() << ": "
	     << get_goal_squadra1() << " - " << get_goal_squadra2()
	     << ", espulsi: " << get_num_espulsi()
		 << ", ammoniti: " << get_num_ammoniti() << endl;
}

//////////////////////////////////////////////////////////////////////////
// Funzione main
//////////////////////////////////////////////////////////////////////////

int main()
{
	Partita p;

	cout << "Inserire le informazioni relative a una partita" << endl << endl;
	p.inserisci();
	cout << endl << "Le informazioni inserite sono:" << endl;
	p.stampa();
	cout << endl;

	return 0;
}
```

Un possibile risultato dell'esecuzione sarà:
```
Inserire le informazioni relative a una partita

*** Inserire la data della partita ***
Inserire giorno: 12
Inserire mese: 3
Inserire anno: 2023

*** Inserire i nomi delle squadre ***
Inserire la prima squadra: Milan
Inserire la seconda squadra: Inter

*** Inserire il risultato ***
Goal segnati dalla prima squadra: 2
Goal segnati dalla seconda squadra: 4 

*** Inserire il numero di espulsi e ammoniti ***
Inserire il numero di espulsi: 2
Inserire il numero di ammoniti: 1

Le informazioni inserite sono:
12/3/2023, Milan - Inter: 2 - 4, espulsi: 2, ammoniti: 1


```