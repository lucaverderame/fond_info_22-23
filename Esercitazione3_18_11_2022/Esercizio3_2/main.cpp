#include <iostream>

using namespace std;

/*
int main()
{
    int num;
    cout << "Ciao! Inserisci un numero: ";
    cin >> num ;

    for (int i=1; i < num; i++){
        for (int j=0; j<num; j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

//Estensione A

int main()
{
    int num;
    cout << "Ciao! Inserisci un numero: ";
    cin >> num ;

    for (int i=1; i < num; i++){
        for (int j=0;j<i;j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
*/

//Estensione B

int main()
{
    int num;
    cout << "Ciao! Inserisci un numero: ";
    cin >> num ;

    for (int i=1; i < num; i++){
        for (int j=0;j<i;j++){
            cout << "*";
        }
        for (int j=i;j<=num;j++){
            cout << j;
        }
        cout << endl;
    }
    return 0;
}

