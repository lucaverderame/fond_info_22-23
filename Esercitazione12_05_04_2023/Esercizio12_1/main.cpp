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
    rilevamento r2(20.0, 1000.0);
    r2.stampa_rilevamento();

    cout << "Parte 3: " << endl;
    double ril[2] = {15.0, 1010.0};
    rilevamento r3(ril);
    r3.stampa_rilevamento();

        cout << "Parte 4: " << endl;
    rilevamento r4(r1);
    r4.stampa_rilevamento();

    return 0;
}


