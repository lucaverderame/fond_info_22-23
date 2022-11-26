
#include <iostream>

using namespace std;

int contacifre (int a){
    int cifre = 0;
    while(a!=0){
        a=a/10;
        cifre++;
    }
    return cifre;
}

int main()
{
    int num;
    int cifre = 0;
    cout << "Inserisci numeri interi. Puoi uscire dal programma inserendo -1: " << endl;
    do {
        cin >> num;
        if (num == 0 || num == -1)
            continue;
        else
            cifre = cifre + contacifre (num);
    } while(num!=-1);
    cout << "Hai inserito un totale di: " << cifre << " cifre! " << endl;
    return 0;
}
