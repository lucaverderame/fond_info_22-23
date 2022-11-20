#include <iostream>

using namespace std;

int main()
{
    int num;
    int contacifre = 0;

    do {
    cout << "Inserire un numero intero maggiore di zero: ";
    cin >> num;
    } while (num<=0);

    while(num>0){
        num=num/10;
        contacifre++;
    }

    cout << "Il numero immesso ha " << contacifre << " cifre!" << endl;

    return 0;
}
