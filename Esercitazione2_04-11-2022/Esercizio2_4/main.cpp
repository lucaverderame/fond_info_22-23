#include <iostream>

using namespace std;

int main()
{
    int giorno, mese;
    cout << "Inserisci il giorno e il mese dell'anno" << endl;
    cin >> giorno >> mese;

    if(mese == 1 | mese == 3 | mese == 5 | mese == 7 | mese == 8 | mese == 10 | mese == 12)
    {
        if (giorno >31 | giorno <0){
                cout << "La data e' sbagliata!";
                return 0;
            }
    }
    else if(mese == 4 | mese == 6 | mese == 9 | mese == 11)
    {
        if (giorno >30 | giorno <0){
                cout << "La data e' sbagliata!";
                return 0;
            }
    }
    else if(mese == 2)
    {
        if (giorno >29 | giorno <0){
                cout << "La data e' sbagliata!";
                return 0;
            }
    }
    else{
            cout << "Questo mese non esiste!";
            return 0;
    }

    if(mese == 1 | mese == 2){
        cout << "Inverno!";
        return 0;
    }

    if(mese == 3){
        if (giorno >=20)
                cout << "Primavera";
            else
                cout << "Inverno";
        return 0;
    }

    if(mese == 4 | mese == 5){
        cout << "Primavera!";
        return 0;
    }

    if(mese == 6){
        if (giorno >=21)
                cout << "Estate";
            else
                cout << "Primavera";
        return 0;
    }

    if(mese == 7 | mese == 8){
        cout << "Estate!";
        return 0;
    }

    if(mese == 9){
        if (giorno >=22)
                cout << "Autunno";
            else
                cout << "Estate";
        return 0;
    }

    if(mese == 10 | mese == 11){
        cout << "Autunno!";
        return 0;
    }

    if(mese == 12){
        if (giorno >=21)
                cout << "Inverno";
            else
                cout << "Autunno";
        return 0;
    }

}
