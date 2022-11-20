
# Terza esercitazione - 18/11/22

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).


## [Esercizio3_0] Calcolatrice do-while

"Il programma consente all'utente di inserire due numeri e un'operazione, e stampa a terminale il risultato dell'operazione. Una volta eseguita l'operazione, il programma chiede all'utente se continuare o interrompere. Nel primo caso, chiede nuovamente di inserire numeri e operazione."

```cpp
# include <iostream>

int main()
{
  char op;
  float num1, num2;
  char flag = 'y';

  do {

    std::cout << "Inserisci l'operazione: ( es: 3 + 5): ";
    std::cin >> num1 >> op >>  num2;

    switch(op)
    {
      case '+':
        std::cout << num1+num2 << std::endl;
        break;

      case '-':
        std::cout << num1-num2 << std::endl;
        break;

      case '*':
        std::cout << num1*num2 << std::endl;
        break;

      case '/':
        if (num2 == 0){
          std::cout << "Errore! Non posso dividere per 0" << std::endl;
          break;
        }
        std::cout << num1/num2 << std::endl;
        break;

      default:
        std::cout << "Errore! Questo operatore non e' supportato";
        break;
    }

    std::cout << "Premi y per continuare, qualsiasi altra lettera per uscire ";
    std::cin >> flag;

  } while (flag == 'y');

  std::cout << "Esco dal programma";

  return 0;
}
```

Il programma consente all'utente di inserire due numeri e un'operazione, e stampa a terminale il risultato dell'operazione. Una volta eseguita l'operazione, il programma chiede all'utente se continuare o interrompere. Nel primo caso, chiede nuovamente di inserire numeri e operazione.

> :exclamation: Il ciclo do-while esegue il corpo dell'iterazione almeno una volta, ma il ciclo viene ripetuto solo se la condizione è verificata.

L'esecuzione del programma ha come risultato:

```cpp
Inserisci l'operazione: ( es: 3 + 5): 12 / 0
Errore! Non posso dividere per 0
Premi y per continuare, qualsiasi altra lettera per uscire y
Inserisci l'operazione: ( es: 3 + 5): 12 / 10
1.2
Premi y per continuare, qualsiasi altra lettera per uscire y
Inserisci l'operazione: ( es: 3 + 5): 7 * 8
56
Premi y per continuare, qualsiasi altra lettera per uscire n
Esco dal programma
```

## [Assignment3_1] Calcolatore di numeri primi

"Creare un programma che fa inserire all'utente 4 caratteri e verifica che ci sia almeno una lettera minuscola, una maiuscola e una cifra. Utilizzare l'operatore condizionale if."

```cpp

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

```

> :exclamation: I cicli possono essere anche annidati, ossia possiamo avere un ciclo for (o while) all'interno di un altro ciclo for (o while)


L'esecuzione del programma ha come risultato:

```cpp
Inserisci un numero intero maggiore di 1: 100
I numeri primi compresi tra 0 e il numero immesso sono: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
```

### [Assignment3_2] Programma per stampare un pattern

Sviluppare un programma che chieda all'utente un numero e stampi a terminale un pattern predefinito a seconda del numero inserito.

```cpp
#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Ciao! Inserisci un numero: ";
    cin >> num ;

    for (int i=0; i < num; i++){
        for (int j=0; j<num; j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
```

L'esecuzione del programma ha come risultato:

```cpp
Ciao! Inserisci un numero: 8
********
********
********
********
********
********
********
********

```

> :warning: Con piccole modifiche nei cicli for, si possono ottenere pattern diversi.

***Estensione A***

```cpp
int main()
{
    int num;
    cout << "Ciao! Inserisci un numero: ";
    cin >> num ;

    for (int i=1; i < num; i++){
        for (int j=0;j<i;j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
```

Con il secondo ciclo stampiamo un numero di * pari al numero corrente di riga.

L'esecuzione del programma ha come risultato:

```cpp
Ciao! Inserisci un numero: 8
*
**
***
****
*****
******
*******
********
```

***Estensione B***

```cpp
int main()
{
    int num;
    cout << "Ciao! Inserisci un numero: ";
    cin >> num ;

    for (int i=1; i < num; i++){
        for (int j=0;j<i;j++){
            cout << "*";
        }
        for (int j=i;j<num;j++){
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
```

Aggiungendo un terzo ciclo che parte da i e arriva fino a num copriamo gli spazi rimasti con i numeri progressivi.

L'esecuzione del programma ha come risultato:

```cpp
Ciao! Inserisci un numero: 8
*2345678
**345678
***34567
****4567
*****567
******67
*******7
********
```



### [Assignment3_3] Programma per calcolare numeri pari e dispari

Scrivere un programma che permetta all'utente di inserire una serie di numeri positivi interi, finché non viene inserito il valore -1: a quel punto, il programma dice quanti numeri pari e dispari sono stati immessi.

```cpp
#include <iostream>

using namespace std;

int main()
{
    int num;
    int contapari = 0;
    int contadispari = 0;

    do{
        cout << "Inserisci un numero intero maggiore di zero (-1 per uscire): ";
        cin >> num ;
        if (num == -1) {
            cout << "Grazie! " << endl;
        }
        else if (num <= 0){
            cout << "Numero non valido" << endl;
        }
        else if(num%2==0){
            contapari++;
        }
        else{
            contadispari++;
        }
    }while(num !=-1);

    cout << "Hai immesso " << contapari << " numeri pari!" << endl;
    cout << "Hai immesso " << contadispari << " numeri dispari!" << endl;
    return 0;
}


```

 Il ciclo do-while può essere molto utile per descrivere in forma compatta iterazioni che sicuramente si devono ripetere almeno una volta.

L'esecuzione del programma ha come risultato:

```cpp
Inserisci un numero intero maggiore di zero (-1 per uscire): 10
Inserisci un numero intero maggiore di zero (-1 per uscire): 4
Inserisci un numero intero maggiore di zero (-1 per uscire): 8
Inserisci un numero intero maggiore di zero (-1 per uscire): 3
Inserisci un numero intero maggiore di zero (-1 per uscire): 7
Inserisci un numero intero maggiore di zero (-1 per uscire): -1
Grazie!
Hai immesso 3 numeri pari!
Hai immesso 2 numeri dispari!

```

### [Assignment3_4] Programma per calcolare il numero di cifre di un numero

Scrivere un programma che chieda all'utente di inserire un numero intero e calcoli di quante cifre è composto (hint: usare un ciclo while).

```cpp
#include <iostream>

using namespace std;

int main()
{
    int num;
    int contacifre = 0;

    do {
    cout << "Inserire un numero intero maggiore di zero: ";
    cin >> num;
    } while (num<=0);

    while(num>0){
        num=num/10;
        contacifre++;
    }

    cout << "Il numero immesso ha " << contacifre << " cifre!" << endl;

    return 0;
}
```
L'esecuzione del programma ha come risultato:

```cpp
Inserire un numero intero maggiore di zero: -5
Inserire un numero intero maggiore di zero: 15623
Il numero immesso ha 5 cifre!
```
