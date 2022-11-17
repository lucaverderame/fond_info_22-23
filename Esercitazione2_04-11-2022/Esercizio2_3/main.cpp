#include <iostream>

using namespace std;

int main()
{
    double num, num_conv;
    char a;
    cout << "Convertitore Euro-Lire / Lire-Euro" << endl;
    cout << "Premi l per convertire un valore da euro a lire, " <<
            "e per convertire un valore da lire a euro" << endl;
    cin >> a;
    if (a == 'l'){
        cout << "Inserisci la cifra in euro: ";
        cin >> num;
        num_conv = num * 1936.27;
        cout << "La cifra in lire e' " << num_conv << endl;
    }
    else if (a == 'e'){
        cout << "Inserisci la cifra in lire: ";
        cin >> num;
        num_conv = num / 1936.27;
        cout << "La cifra in euro e' " << num_conv << endl;
    }
    else {
        cout << "La lettera immessa e' sbagliata!" << endl;
    }
    return 0;
}
