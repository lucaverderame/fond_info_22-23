#include <iostream>

using namespace std;

double trovaminimo (double a1, double a2, double a3){
    double minimo;
    if (a1 < a2){
        if (a1 < a3)
            minimo = a1;
        else
            minimo = a3;
    }
    else {
        if (a2 < a3)
            minimo = a2;
        else
            minimo = a3;
    }
    return minimo;
}

double trovamassimo (double a1, double a2, double a3){
    double massimo;
    if (a1 > a2){
        if (a1 > a3)
            massimo = a1;
        else
            massimo = a3;
    }
    else {
        if (a2 > a3)
            massimo = a2;
        else
            massimo = a3;
    }
    return massimo;
}

double differenza (double a1, double a2, double a3){
    double minimo, massimo, diff;
    minimo = trovaminimo (a1, a2, a3);
    massimo = trovamassimo (a1, a2, a3);
    diff = massimo - minimo;
    return diff;
}

int main()
{
    double num1, num2, num3;
    cout << "Inserisci tre numeri: " << endl;
    cin >> num1 >> num2 >> num3;
    cout << "La differenza tra il numero piu' grande e il piccolo e': " << differenza(num1, num2, num3);
}
