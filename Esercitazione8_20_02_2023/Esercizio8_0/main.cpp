#include <iostream>

using namespace std;

struct libro
{
    int pagine;
    int codice;
    float costo;
};

libro inserisciLibro()
{
    libro l;
    cout << "inserisci il numero di pagine: ";
    cin >> l.pagine;
    cout << "inserisci il codice: ";
    cin >> l.codice;
    cout << "inserisci il costo: ";
    cin >> l.costo;
    return l;
}

void confrontaScambia(libro &la,libro &lb)
{
    if(la.costo/la.pagine>lb.costo/lb.pagine)
    {
        libro ltemp=la;
        la=lb;
        lb=ltemp;
    }
}

void stampaLibro(libro l)
{
    cout << "pagine " << l.pagine << " ";
    cout << "codice " << l.codice << " ";
    cout << "costo " << l.costo << " " << endl;
}

int main()
{
  libro l1,l2,l3;
  l1=inserisciLibro();
  l2=inserisciLibro();
  l3=inserisciLibro();
  confrontaScambia(l1,l2);
  confrontaScambia(l1,l3);
  confrontaScambia(l2,l3);
  stampaLibro(l1);
  stampaLibro(l2);
  stampaLibro(l3);
}