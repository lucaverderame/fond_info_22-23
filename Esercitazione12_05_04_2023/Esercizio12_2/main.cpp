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
