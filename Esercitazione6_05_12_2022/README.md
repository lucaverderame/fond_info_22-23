
# Sesta esercitazione - 05/12/22

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).


### [Esercizio 6_0] Scambio degli elementi di un array

Creare un programma che chieda all'utente di inserire dei numeri, li inserisca in un array, e scambi il numero minore con il maggiore.


> :warning: L'intero dim viene acquisito dall'utente e utilizzato in tutti i cicli for. Una eventuale modifica di questo intero potrebbe causare errori a runtime.

> :warning: L'array viene sempre passato ad una funzione per riferimento.

```cpp
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

```
> L'esecuzione del programma ha come risultato:

```cpp
Di quanti elementi vuoi che sia l'array? 4
Per favore, inserisci 4 numeri:  13 4 2 -5
Grazie. Ecco la lista di numeri con massimo e minimo invertiti: -5 4 2 13
```

### [Esercizio 6_1] Lettere in rima

Creare un programma che chieda all'utente di inserire due stringhe, e conti il numero di lettere che "fanno rima", ovvero il numero di lettere uguali in fondo alle due stringhe.

> :warning: Per lavorare con le stringhe, è necessario includere l'header cstring.


> :warning: La funzione cin.getline permette di acquisire una stringa fino a che l'utente immette il carattere passato come terzo argomento della funzione. Nel nostro caso utilizziamo ```\n```, ovvero finchè l'utente non va a capo premendo invio. 

```cpp
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int dim = 256;
    int contarima = 0, len1, len2, len;
    char stringa1[dim], stringa2[dim];
    cin.getline(stringa1, dim, '\n');
    cin.getline(stringa2, dim, '\n');
    len1 = strlen(stringa1);
    len2 = strlen(stringa2);

    if (len1 < len2)
        len = len1;
    else
        len = len2;

    for (int i=1; i<=len; i++){
        if(stringa1[len1-i]==stringa2[len2-i])
            contarima++;
        else
            break;
    }
    cout << "Le lettere che fanno rima sono: " << contarima << endl;
}
```
> L'esecuzione del programma ha come risultato:

```cpp
proviamo con questa frase
questo esercizio di base
Le lettere che fanno rima sono: 3
```

### [Esercizio 6_2] Programma che riempie un array di interi con numeri random.

Creare un programma che, dopo aver chiesto all'utente di inserire la dimensione di un array, li riempia con interi random compresi tra 0 e 99.

Potete utilizzare la funzione ```rand()``` per generare un intero random. Per limitarlo tra 0 e 99, basta considerare il modulo della divisione per 100: ```rand()%100;```

Per far sì che rand() sia realmente random, devo inizializzare il «seed» della funzione in maniera casuale. Posso farlo con: ```srand(time(NULL))```;

![alt text](https://media.geeksforgeeks.org/wp-content/uploads/20220725153315/randandsrand.png)

Per poter usare le funzioni rand e time, dovete includere anche gli header ctime e cstdlib.

Il carattere speciale ```'\b'``` torna indietro di uno spazio.


```cpp
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
```
> L'esecuzione del programma ha come risultato:

```cpp
Inserisci la dimensione dell'array: 5
Ecco l'array con numeri random: [0, 73, 66, 69, 19]
```

### [Esercizio 6_3] Moltiplicazione di array

Creare un programma che, dopo aver chiesto all'utente di inserire la dimensione e gli elementi di due array, li moltiplichi tra di loro e stampi il risultato finale. Utilizzare una funzione per moltiplicare gli array.

>:warning: Non è possibile moltiplicare direttamente gli array. E' necessario utilizzare un ciclo for.

```cpp
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
```
> L'esecuzione del programma ha come risultato:

```cpp
Inserisci la dimensione degli array: 2
Inserisci gli elementi del primo array: 2 4
Inserisci gli elementi del secondo array: 4 8
L'array finale e': [8, 32]
```


### [Esercizio 6_4] Inversione di array

Creare un programma che, dopo aver chiesto all'utente di inserire la dimensione e gli elementi di un array, lo inverta e stampi il risultato finale. Utilizzare una funzione per l'inversione dell'array.

```cpp
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
```
> L'esecuzione del programma ha come risultato:

```cpp
Inserisci la dimensione dell'array: 3
Inserisci gli elementi dell' array: 3 6 9
Ecco l'array invertito: [9, 6, 3]
```


### [Esercizio 6_5] Numero di doppie in una stringa

Creare un programma che chieda all'utente di inserire due stringhe, le concateni, elimini tutti i caratteri non alfabetici, e conti il numero di doppie contenute nella stringa complessiva.

Per concatenare due stringhe potete usare la funzione ```strcat(s,t)```.

Per vedere se un carattere è effettivamente una lettera dell'alfabeto, è possibile usare la funzione ```isalpha(c)```. La funzione restituisce 1 se è una lettera maiuscola, 2 se è una lettera minuscola, 0 se non è un carattere alfabetico.

```cpp
#include <iostream>
#include <cstring>

using namespace std;

int main(){
   const int dim = 256;
   int len, j=0, contadoppie =0;
   char stringa1[dim], stringa2[dim], stringa_res[dim];
   cout << "Inserisci due frasi: " << endl;
   cin.getline(stringa1, dim, '\n');
   cin.getline(stringa2, dim, '\n');
   strcat(stringa1, " ");
   strcat(stringa1,stringa2);
   len = strlen(stringa1);
   for (int i=0;i<len;i++){
        if ((isalpha(stringa1[i])>0) || stringa1[i]==' '){
            stringa_res[j]=stringa1[i];
            j++;
        }
   }
   stringa_res[j]='\0';
   len = strlen(stringa_res);
   for (int i=0;i<len-1;i++){
        if(stringa_res[i]==stringa_res[i+1])
            contadoppie++;
   }
   cout << "Il numero di doppie e': " << contadoppie;
}

```
> L'esecuzione del programma ha come risultato:

```cpp
Inserisci due frasi:
questa e' una prova. Inserisco due frasi!!!!!
Per contare il numero di doppie. Saranno 11?
Il numero di doppie e': 2
```
