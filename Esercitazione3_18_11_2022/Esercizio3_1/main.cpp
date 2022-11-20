# include <iostream>

using namespace std;

int main()
{
    int num, primo;
    do{
        cout << "Inserisci un numero intero maggiore di 1: " ;
        cin >> num;
    } while (num <1);
    cout << "I numeri primi compresi tra 0 e il numero immesso sono: ";
    for (int i=2; i<=num; i++){
        primo = 1;
        for (int j=i-1; j>1; j--){
            if (i%j==0){
                primo = 0;
            }
        }
        if (primo == 1){
            cout << i << " ";
        }
    }
  return 0;
}

