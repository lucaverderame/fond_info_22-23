#include <iostream>

using namespace std;

void moltiplica_array(int arr1[], int arr2[], int arr_ris[], int dim){
    for (int i=0;i<dim;i++){
        arr_ris[i]=arr1[i]*arr2[i];
    }

}

int main()
{
    int dim;
    cout << "Inserisci la dimensione degli array: ";
    cin >> dim;
    int arr1[dim], arr2[dim], arr_ris[dim];
    cout << "Inserisci gli elementi del primo array: ";
    for (int i=0;i<dim;i++){
        cin >> arr1[i];
    }
    cout << "Inserisci gli elementi del secondo array: ";
    for (int i=0;i<dim;i++){
        cin >> arr2[i];
    }
    moltiplica_array(arr1, arr2, arr_ris, dim);
    cout << "L'array finale e': [";
    for (int i=0;i<dim;i++){
        cout << arr_ris[i] << ", ";
    }
    cout << "\b\b]";

    return 0;
}