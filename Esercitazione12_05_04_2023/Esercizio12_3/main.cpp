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
