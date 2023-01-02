
# Settima esercitazione - 16/12/22

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).


### [Esercizio 7_0] Moltiplicazione tra matrici

Creare un programma che chieda all'utente di inserire gli elementi due matrici quadrate di dimensione 3, e ne calcoli il prodotto.


> :warning: Anche gli array bidimensionali vengono sempre passati per riferimento.

La moltiplicazione di due matrici avviene calcolando il prodotto delle righe della prima matrice per le colonne della seconda matrice. Per questa ragione è detta moltiplicazione righe per colonne.

Per un approfondimento matematico sul calcolo si rimanda a [questo indirizzo](https://www.andreaminini.org/matematica/algebra-lineare/moltiplicazione-tra-matrici).

```cpp
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



```
> L'esecuzione del programma ha come risultato:

```cpp
Inserisci tutti gli elementi della matrice A:
Riga 0: 1 2 3
Riga 1: 4 5 6
Riga 2: 7 8 9
La prima matrice e':
1 2 3
4 5 6
7 8 9
Inserisci tutti gli elementi della seconda matrice B:
Riga 0: 2 3 4
Riga 1: 3 4 5
Riga 2: 4 5 6
La seconda matrice e':
2 3 4
3 4 5
4 5 6
La matrice prodotto e':
20 26 32
47 62 77
74 98 122

```

### [Esercizio 7_1] Lettura e scrittura su file.

Scrivere un programma che prende in input un file "ciao.txt" e crea due file chiamati "consonanti.txt" e "vocali.txt" in cui ci sono rispettivamente solo le consonanti o le vocali presenti nel file "ciao.txt". Se il file "ciao.txt" contiene il testo "prova a fare l'esercizio", il file consonanti conterrà "prvfrlsrcz" mentre quello vocali conterrà "oaaaeeeiio".

La funzione ```eof```restituisce 1 se siamo arrivati alla fine del file mentre la funzione ```isalpha``` restituisce 1 (uppercase) o 2 (lowercase) se il carattere è un carattere alfabetico.

> :warning: Ricordarsi di creare nella cartella del progetto il file ciao.txt in modo che il programma possa eseguire correttamente.


```cpp
#include <iostream>
#include <fstream>

using namespace std;

int controllo_vocale (char carattere){
    int ritorno;
   switch (carattere){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            ritorno = 1;
            break;
        default:
            ritorno = 0;
            break;
    }
    return ritorno;
}

int main()
{
    fstream ingr, usc1, usc2;
    ingr.open("ciao.txt", ios::in);
    usc1.open("vocali.txt", ios::out);
    usc2.open("consonanti.txt", ios::out);
    char a;
    while(!ingr.eof()){
        ingr >> a;
        if(isalpha(a)>0){
            if (controllo_vocale(a)==1){
                usc1 << a;
            }
            else{
                usc2 << a;
            }
        }
    }
    ingr.close();
    usc1.close();
    usc2.close();
}


```
> L'esecuzione del programma ha come risultato la creazione di due nuovi file nella cartella del progetto denominati "vocali.txt" e "consonanti.txt".

### [Esercizio 7_2] Programma che riempie un array di interi con numeri random.

Scrivere un programma che chieda all'utente di inserire i valori di una matrice 4x4 e trovi la riga e la colonna con somma più alta.

L'idea è creare due array di dimensioni dim che possano contenere in ogni elemento i risultato della somma di ogni riga e il risultato della somma di ogni colonna; tali somme sono ottenibili tramite un ciclo for. A questo punto entrambi gli array vengono valutati usando ```trovamax``` che ha l'obiettivo di trovare l'elemento più grande all'interno di un array.


```cpp
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

```
> L'esecuzione del programma ha come risultato:

```cpp
Riempi una matrice quadrata 4 x 4 con numeri interi:
Riga 1: 1 2 3 4
Riga 2: 5 6 7 8
Riga 3: 2 3 4 5
Riga 4: 3 4 5 6
La riga con la somma piu' alta e' la : 2
La colonna con la somma piu' alta e': 4

```

### [Esercizio 7_3] Insertion Sort

Provare a scrivere un programma che implementi l'ordinamento di un array con algoritmo Insertion Sort. L'insertion Sort è un algoritmo di ordinamento che utilizza lo stesso metodo che un essere umano usa per ordinare le sue carte in mano.

L'algoritmo ha bisogno di due cicli for, uno più esterno su tutti gli elementi dell'array, quello più interno per calcolare il nuovo indice in cui inserire l'elemento.

Il passo successivo consiste nel far scorrere in avanti gli elementi dell'array, e inserire finalmente l'elemento nella posizione «corretta»

```cpp
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

```
> L'esecuzione del programma ha come risultato:

```cpp
Inserisci la dimensione dell'array: 50
Ecco l'array con numeri random: [91, 9, 1, 13, 45, 46, 3, 79, 28, 75, 26, 89, 59, 87, 42, 93, 56, 52, 67, 1, 17, 47, 75, 99, 90, 54, 51, 64, 5, 49, 79, 38, 18, 90, 50, 90, 92, 26, 54, 82, 0, 37, 95, 31, 13, 27, 33, 35, 83, 48]
Ecco l'array con numeri ordinati: [0, 1, 1, 3, 5, 9, 13, 13, 17, 18, 26, 26, 27, 28, 31, 33, 35, 37, 38, 42, 45, 46, 47, 48, 49, 50, 51, 52, 54, 54, 56, 59, 64, 67, 75, 75, 79, 79, 82, 83, 87, 89, 90, 90, 90, 91, 92, 93, 95, 99]

```


### [Esercizio 7_4] File e Array

Creare un programma che ricevuto in ingresso un file chiamato "input.txt" crei in uscita un file chiamato "output.txt" formato da tante righe quante sono le lettere dell'alfabeto e per ogni riga viene riportata una lettera e quante volte quella lettera compare nel file "input.txt".

> :warning: E' possibile creare un array di 26 interi, relativo ai contatori per le 26 lettere. Andando a leggere un carattere, è possibile incrementare l'elemento dell'array in posizione corretta utilizzando la codifica ascii.

```cpp
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    fstream fin("input.txt", ios::in);
    fstream fout("output.txt", ios::out);
    char c;
    int contaoccorrenze['z'-'a'+1]={0};
    if(!fin || !fout){
        cout << "Problema nell'apertura del file!" << endl;
        return -1;
    }

    while(!fin.eof()){
        c=' ';
        fin >> c;
        if((c>='a')&&(c<='z')) //se c è una lettera minuscola
        {
            int posizione=c-'a'; //individuo il numero progressivo della lettera nell'alfabeto
            contaoccorrenze[posizione]++; //conto uno in più per quella lettera
        }
        if((c>='A')&&(c<='Z')) //se c è una lettera maiuscola faccio la stessa cosa
        {
            int posizione=c-'A';
            contaoccorrenze[posizione]++;
        }
    }
    fin.close();

    for(int i=0;i<26;i++)
    {
        c='a'+i;
        fout<<c<<": "<<contaoccorrenze[i]<<endl;
    }
    fout.close();

    cout << "Il file e' stato generato!" << endl;
}
```
> L'esecuzione del programma ha come risultato:

```cpp
Il file e' stato generato!
```
