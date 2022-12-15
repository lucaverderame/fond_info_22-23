#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
    srand(time(NULL));
    int dim;
    cout << "Inserisci la dimensione dell'array: ";
    cin >> dim;
    int arr[dim];
    for (int i=0;i<dim;i++){
        arr[i]=rand()%100;
    }
    cout << "Ecco l'array con numeri random: [";
     for (int i=0;i<dim;i++){
        cout << arr[i] << ", ";
    }
    cout << "\b\b]";
    return 0;
}