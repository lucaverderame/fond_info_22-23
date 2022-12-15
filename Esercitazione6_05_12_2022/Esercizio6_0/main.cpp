#include <iostream>

using namespace std;

void ordina_array(double arr[], int dim){
    double minimo = arr[0];
    int index_min = 0;
    double massimo = arr[0];
    int index_max = 0;
    for (int i=1;i<dim;i++){
        if (arr[i]<minimo){
            minimo=arr[i];
            index_min = i;
        }
        if (arr[i] > massimo){
            massimo = arr[i];
            index_max = i;
        }
    }
    double temp = arr[index_min];
    arr[index_min] = arr[index_max];
    arr[index_max] = temp;
}

int main()
{
    int dim;
    cout << "Di quanti elementi vuoi che sia l'array? ";
    cin >> dim;
    double arr[dim];
     cout << "Per favore, inserisci " << dim << " numeri: ";
    for (int i=0;i<dim;i++){
        cin >> arr[i];
    }
    ordina_array (arr, dim);
    cout << "Grazie. Ecco la lista di numeri con massimo e minimo invertiti: ";
    for (int i=0;i<dim;i++){
        cout << arr[i] << " ";
    }
}
