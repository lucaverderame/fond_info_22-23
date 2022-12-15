#include <iostream>

using namespace std;

void inverti_array(int arr[], int dim){
    int arr_temp[dim];
    for (int i=0;i<dim;i++){
        arr_temp[i]=arr[dim-1-i];
    }
    for (int i=0;i<dim;i++){
        arr[i]=arr_temp[i];
    }
}

int main(){
    int dim;
    cout << "Inserisci la dimensione dell'array: ";
    cin >> dim;
    int arr[dim];
    cout << "Inserisci gli elementi dell' array: ";
    for (int i=0;i<dim;i++){
        cin >> arr[i];
    }
    inverti_array(arr, dim);
    cout << "Ecco l'array invertito: [";
        for (int i=0;i<dim;i++){
        cout << arr[i] << ", ";
    }
    cout << "\b\b]";
    return 0;
}