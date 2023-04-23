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