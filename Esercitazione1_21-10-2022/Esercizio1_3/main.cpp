#include <iostream>

using namespace std;

int main()
{
    int cateto1, cateto2, quadratoIpotenusa;
    cout << "Inserisci la lunghezza di un cateto: ";
    cin >> cateto1;
    cout << "Inserisci la lunghezza del secondo cateto: ";
    cin >> cateto2;
    quadratoIpotenusa = cateto1 * cateto1 + cateto2 * cateto2;
    cout << "Il quadrato dell'ipotenusa e' pari a " << quadratoIpotenusa << endl;
    return 0;
}
