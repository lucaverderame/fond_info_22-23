#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void riempiArrRandom(int arr[], int dim){
    for (int i=0;i<dim;i++){
        arr[i]=rand()%100;
    }
}

void stampaArr(int arr[], int dim){
    cout << "[";
    for (int i=0;i<dim;i++){
        cout << arr[i] << ", ";
    }
     cout << "\b\b]\n";
}

void insertionSort(int arr[], int dim){
    for (int i=1;i<dim;i++){
        int insertionpoint = i;
        int temp = arr[i];
        for (int j=i-1;j>=0;j--){
            if(arr[j]>arr[i])
                 insertionpoint = j;
        }
        for (int j=i-1;j>=insertionpoint;j--){
            arr[j+1]=arr[j];
        }
        arr[insertionpoint]=temp;
    }
}

int main(){
    srand(time(NULL));
    int dim;
    cout << "Inserisci la dimensione dell'array: ";
    cin >> dim;
    int arr[dim];
    riempiArrRandom(arr, dim);
    cout << "Ecco l'array con numeri random: ";
    stampaArr(arr,dim);
    insertionSort(arr,dim);
    cout << "Ecco l'array con numeri ordinati: ";
    stampaArr(arr,dim);
}
