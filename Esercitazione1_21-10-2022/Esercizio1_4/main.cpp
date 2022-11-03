#include <iostream>

using namespace std;

int main()
{
    int num1, num2, quoziente, resto;
    cout << "Inserisci il primo numero: ";
    cin >> num1;
    cout << "Inserisci un altro numero: ";
    cin >> num2;
    quoziente = num1 / num2;
    resto = num1 % num2;
    cout << "La divisione tra i due numeri ha come quoziente " << quoziente <<
        " e come resto " << resto << endl;
    return 0;
}
