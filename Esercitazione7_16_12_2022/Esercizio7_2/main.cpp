#include <iostream>

using namespace std;
const int dim = 4;

int trovamax(int a[], int dim){
    int index_max = 0;
    for (int i=1;i<dim;i++){
        if (a[i]>a[index_max]){
            index_max=i;
        }
    }
    return index_max;
}

int main(){
   int a[dim][dim];
   int riga_max;
   int colonna_max;
   int sommarighe[dim]={0};
   int sommacolonne[dim]={0};

   cout << "Riempi una matrice quadrata 4 x 4 con numeri interi: " << endl;
   for (int i=0;i<dim;i++){
        cout << "Riga " << i+1 <<": ";
        for (int j=0;j<dim;j++){
            cin >> a[i][j];
        }
   }
   for (int i=0;i<dim;i++){
        for (int j=0;j<dim;j++){
            sommarighe[i]=sommarighe[i]+a[i][j];
            sommacolonne[i]=sommacolonne[i]+a[j][i];
        }
   }
    riga_max = trovamax(sommarighe, dim);
    colonna_max = trovamax(sommacolonne, dim);

    cout << "La riga con la somma piu' alta e' la : " << riga_max+1 << endl;
    cout << "La colonna con la somma piu' alta e': " << colonna_max+1 << endl;

   return 0;
}
