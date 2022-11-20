#include <iostream>

using namespace std;

int main()
{
    int num;
    int contapari = 0;
    int contadispari = 0;

    do{
        cout << "Inserisci un numero intero maggiore di zero (-1 per uscire): ";
        cin >> num ;
        if (num == -1) {
            cout << "Grazie! " << endl;
        }
        else if (num <= 0){
            cout << "Numero non valido" << endl;
        }
        else if(num%2==0){
            contapari++;
        }
        else{
            contadispari++;
        }
    }while(num !=-1);

    cout << "Hai immesso " << contapari << " numeri pari!" << endl;
    cout << "Hai immesso " << contadispari << " numeri dispari!" << endl;
    return 0;
}
