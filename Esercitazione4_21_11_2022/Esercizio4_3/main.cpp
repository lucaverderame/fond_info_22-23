#include <iostream>

using namespace std;

void timeconv (int& minuti, int& sec, int& ms){
    sec = ms/1000;
    minuti = sec/60;
    sec = sec%60;
    ms = ms%1000;
}

int main()
{
    int ms1, ms2;
    int sec1, sec2;
    int min1, min2;
    cout << "Inserisci un tempo in millisecondi: ";
    cin >> ms1;
    while (ms1 <0){
        cout << "Per favore, inserisci un numero positivo: ";
        cin >> ms1;
    }
    cout << "Inserisci un altro tempo in millisecondi: ";
    cin >> ms2;
    while (ms2 <0){
        cout << "Per favore, inserisci un numero positivo: ";
        cin >> ms2;
    }
    timeconv(min1, sec1, ms1);
    timeconv(min2, sec2, ms2);
    if (min1 == min2){
        cout << "I tempi immessi corrispondono agli stessi minuti!" << endl;
    }
    cout << min1 << " minuti, " << sec1 << " secondi, " << ms1 << " millisecondi" << endl;
    cout << min2 << " minuti, " << sec2 << " secondi, " << ms2 << " millisecondi" << endl;
}
