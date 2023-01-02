#include <iostream>

using namespace std;

const int dim = 3;

void riempiMatrice(int a[dim][dim]){
   for (int i=0;i<dim;i++){
        cout << "Riga " << i << ": ";
        for (int j=0;j<dim;j++){
            cin >> a[i][j];
        }
   }
}

void stampaMatrice(int a[dim][dim]){
    for (int i=0;i<dim;i++){
        for (int j=0;j<dim;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void prodottoMatrici(int a[dim][dim], int b[dim][dim], int c[dim][dim]){
    for (int i=0;i<dim;i++){
        for (int j=0;j<dim;j++){
            c[i][j]=0;
            for (int k=0;k<dim;k++){
            c[i][j]=c[i][j] + a[i][k]*b[k][j];
            }
        }
    }
}


int main(){
   int a[dim][dim], b[dim][dim], c[dim][dim];

   cout << "Inserisci tutti gli elementi della matrice A: " << endl;
   riempiMatrice(a);
   cout << "La prima matrice e': " << endl;
   stampaMatrice(a);

   cout << "Inserisci tutti gli elementi della seconda matrice B: " << endl;
   riempiMatrice(b);
   cout << "La seconda matrice e': " << endl;
   stampaMatrice(b);

   prodottoMatrici(a, b, c);
   cout << "La matrice prodotto e': " << endl;
   stampaMatrice(c);
}

