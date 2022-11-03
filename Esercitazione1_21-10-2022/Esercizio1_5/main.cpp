#include <iostream>

using namespace std;

int main()
{
    int euro, lire;
    const int conv = 1936;
    cout << "Inserisci il prezzo in euro: ";
    cin >> euro;
    lire = euro * conv;
    cout << "Il prezzo immesso equivale a " << lire << " lire!" << endl;
    return 0;
}
