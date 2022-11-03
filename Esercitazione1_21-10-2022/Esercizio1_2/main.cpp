#include <iostream>

using namespace std;

int main()
{
    int num1, num2, num3, num4, num5, media;
    cout << "Inserisci il primo numero: ";
    cin >> num1;
    cout << "Inserisci il secondo numero: ";
    cin >> num2;
    cout << "Inserisci il terzo numero: ";
    cin >> num3;
    cout << "Inserisci il quarto numero: ";
    cin >> num4;
    cout << "Inserisci il quinto numero: ";
    cin >> num5;
    media = (num1 + num2 + num3 + num4 + num5)/5;
    cout << "La media dei 5 numeri immessi e' " << media << endl;
    return 0;
}
