
# Quarta esercitazione - 21/11/22

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).


## [Esercizio4_0] Programma per contare vocali e consonanti in una frase.

"Il programma consente all'utente di inserire una frase, e stampa a terminale il numero totale di caratteri, di vocali e di consonanti.
Possiamo riutilizzare parte del codice già sviluppato nell'esercitazione 2, per verificare se una lettera è una consonante o una vocale."

```cpp
#include <iostream>

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
    char a;
    int conta = 0;
    int contavocali = 0;
    int contaconsonanti = 0;
    cout << "Inserisci una frase, metti il punto quando hai finito: ";
    while (1){
        cin >> a;
        if (a == '.')
            break;
        if (controllo_vocale(a))
            contavocali++;
        else
            contaconsonanti++;
        conta++;
    }

    cout << "Hai inserito " << conta << " lettere, di cui " <<
    contavocali << " vocali e " << contaconsonanti << " consonanti." << endl;
}


```

> :exclamation: L'istruzione break permette di terminare un ciclo iterativo, saltando alla prima istruzione fuori dal ciclo.

> :exclamation: Utilizzare funzioni permette di riutilizzare codice già sviluppato in precedenza, e di rendere il codice più leggibile nella funzione main.

L'esecuzione del programma ha come risultato:

```cpp
Inserisci una frase, metti il punto quando hai finito: faccio una prova per vedere se funziona.
Hai inserito 33 lettere, di cui 16 vocali e 17 consonanti.
```

## [Assignment4_1] Riduzione di frazioni

"Il programma chiede all'utente di inserire due frazioni, e le riduce ai minimi termini."

In questo esercizio, vogliamo usare una funzione per effettuare la riduzione delle funzioni ai minimi termini. In questo caso può essere utile passare i parametri per riferimento, così da modificare anche i valori di numeratore e denominatore nella nostra funzione main.

```cpp
#include <iostream>

using namespace std;

void riduco(int& num, int& den){
    int minimo, mcd;
    if(num>den)
        minimo=num;
    else
        minimo=den;
    for (int i=1;i<=minimo;i++){
        if ((num%i==0) && (den%i==0)){
            mcd=i;
        }
    }
    num=num/mcd;
    den=den/mcd;
}

int main()
{
    int num1, num2, den1, den2;
    char op1, op2;
    cout << "Inserisci due frazioni:" << endl;
    cin >> num1 >> op1 >> den1;
    cin >> num2 >> op2 >> den2;
    riduco(num1, den1);
    riduco(num2, den2);
    cout << "La prima frazione si puo' ridurre a: " << num1 << op1 << den1 << endl;
    cout << "La seconda frazione si puo' ridurre a: " << num2 << op2 << den2 << endl;
    return 0;
}
```

L'esecuzione del programma ha come risultato:

```cpp
Inserisci due frazioni:
2/12
27/63
La prima frazione si puo' ridurre a: 1/6
La seconda frazione si puo' ridurre a: 3/7
```

### [Assignment4_2] Calcolo del numero di cifre

Scrivere un programma che chieda all'utente di inserire dei numeri interi, finché l'utente non inserisce -1 (per uscire dal ciclo).

A quel punto, il programma stampa il numero di cifre totale immesso dall'utente.

> :warning: Hint: usare un ciclo while (o do-while) per gestire l'inserimento dei numeri

> :warning: Hint: usare una funzione per contare il numero di cifre di ogni numero inserito (vedi Assignment 3_4)

```cpp

#include <iostream>

using namespace std;

int contacifre (int a){
    int cifre = 0;
    while(a!=0){
        a=a/10;
        cifre++;
    }
    return cifre;
}

int main()
{
    int num;
    int cifre = 0;
    cout << "Inserisci numeri interi. Puoi uscire dal programma inserendo -1: " << endl;
    do {
        cin >> num;
        if (num == 0 || num == -1)
            continue;
        else
            cifre = cifre + contacifre (num);
    } while(num!=-1);
    cout << "Hai inserito un totale di: " << cifre << " cifre! " << endl;
    return 0;
}
```

L'esecuzione del programma ha come risultato:

```cpp
Inserisci numeri interi. Puoi uscire dal programma inserendo -1:
154
-23
212
-1
Hai inserito un totale di: 8 cifre!
```
### [Assignment4_3] Calcolo di minuti e secondi

Creare un programma che, dopo aver chiesto all'utente di inserire due tempi dati in millisecondi, restituisca per entrambi l'equivalente in termini di minuti, secondi, millisecondi, e controlli se corrispondono agli stessi minuti.

> :warning: Hint: usare una funzione passando i parametri per riferimento.

```cpp
#include <iostream>

using namespace std;

int timeconv (int& minuti, int& sec, int& ms){
    sec = ms/1000;
    minuti = sec/60;
    sec = sec%60;
    ms = ms%1000;
}

int main()
{
    int ms1, ms2;
    int sec1, sec2;
    int min1, min2;
    cout << "Inserisci un tempo in millisecondi: ";
    cin >> ms1;
    while (ms1 <0){
        cout << "Per favore, inserisci un numero positivo: ";
        cin >> ms1;
    }
    cout << "Inserisci un altro tempo in millisecondi: ";
    cin >> ms2;
    while (ms2 <0){
        cout << "Per favore, inserisci un numero positivo: ";
        cin >> ms2;
    }
    timeconv(min1, sec1, ms1);
    timeconv(min2, sec2, ms2);
    if (min1 == min2){
        cout << "I tempi immessi corrispondono agli stessi minuti!" << endl;
    }
    cout << min1 << " minuti, " << sec1 << " secondi, " << ms1 << " millisecondi" << endl;
    cout << min2 << " minuti, " << sec2 << " secondi, " << ms2 << " millisecondi" << endl;
}
```

L'esecuzione del programma ha come risultato:

```cpp
Inserisci un tempo in millisecondi: 100500
Inserisci un altro tempo in millisecondi: 110050
I tempi immessi corrispondono agli stessi minuti!
1 minuti, 40 secondi, 500 millisecondi
1 minuti, 50 secondi, 50 millisecondi
```

### [Assignment4_4] Programma per calcolare il numero di cifre di un numero

Scrivere un programma che chieda all'utente di inserire tre numeri (non necessariamente interi), e restituisca la differenza tra il numero più grande e il numero più piccolo immesso dall'utente.

> :warning: Hint: E' possibile creare una funzione che restituisca la differenza dei tre numeri, e a sua volta chiami una funzione per il calcolo del massimo, e una per il calcolo del minimo.

```cpp
#include <iostream>

using namespace std;

double trovaminimo (double a1, double a2, double a3){
    double minimo;
    if (a1 < a2){
        if (a1 < a3)
            minimo = a1;
        else
            minimo = a3;
    }
    else {
        if (a2 < a3)
            minimo = a2;
        else
            minimo = a3;
    }
    return minimo;
}

double trovamassimo (double a1, double a2, double a3){
    double massimo;
    if (a1 > a2){
        if (a1 > a3)
            massimo = a1;
        else
            massimo = a3;
    }
    else {
        if (a2 > a3)
            massimo = a2;
        else
            massimo = a3;
    }
    return massimo;
}

double differenza (double a1, double a2, double a3){
    double minimo, massimo, diff;
    minimo = trovaminimo (a1, a2, a3);
    massimo = trovamassimo (a1, a2, a3);
    diff = massimo - minimo;
    return diff;
}

int main()
{
    double num1, num2, num3;
    cout << "Inserisci tre numeri: " << endl;
    cin >> num1 >> num2 >> num3;
    cout << "La differenza tra il numero piu' grande e il piccolo e': " << differenza(num1, num2, num3);
}
```
L'esecuzione del programma ha come risultato:

```cpp
Inserisci tre numeri:
43
76
-14
La differenza tra il numero piu' grande e il piccolo e': 90
```
