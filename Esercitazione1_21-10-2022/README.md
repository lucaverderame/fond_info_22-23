
# Prima esercitazione - 21/10/22

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).

## [Esercizio1_0] Programma "Hello World"


```cpp
#include <iostream>

int main() {
  // stampa a schermo la stringa tra virgolette
  std::cout << "Hello, World!";
  return 0;
}
```

Il risultato dell'esecuzione del programma è:

```shell
Hello, World!
```

E' il classico esempio, che trovate quando inizializzate un progetto in Code::Blocks

Ma come funziona?


* `// stampa a schermo la stringa tra virgolette`
  In C++, ogni linea di codice che inizia con `//` è un commento. I commenti servono solo a far capire meglio il codice a tutti coloro che lo leggono (compreso il programmatore stesso che lo ha scritto!).
  E' completamente ignorato dal compilatore C++-
* `#include <iostream>`
  `#include` è una direttiva per il preprocessore, usata per includere file nel nostro programma. In questo esempio, serve ad includere il contenuto del file iostream. 
  In particolare, questo ci serve per usare  le librerie standard di I/O di C++, che oltre a mettere alle istruzioni C scanf e printf, mette a disposizione del programmatore anche un nuovo sistema di gestione delle operazioni di I/O piu' adatto alla programmazione orientata agli oggetti. 
  Per adesso, ricordatevi di aggiungere `#include <iostream>` se volete usare cout per stampare qualcosa sul terminale.
* `int main() {...}`
  Ogni programma in C++ deve avere la funzione `main()`. Le parentesi graffe indicano l'inizio e la fine della funzione. L'esecuzione del codice inizia da questa funzione. 
* `std::cout << "Hello World!";`
  `std::cout` stampa il contenuto all'interno delle virgolette. Deve essere seguito dall'operatore `<<` seguito da una stringa di testo ("Hello World!", nell'esempio).
* `return 0;`
   Lo statement `return 0;` è l'istruzione che termina la funzione main().

> :exclamation: Dobbiamo includere iostream per poter utilizzare std::cout

> :exclamation: Nota: `;` va sempre inserito per indicare la fine di un'istruzione.


#### [Esercizio1_1] Programma per sommare due numeri


```cpp
#include <iostream>

int main()
{
    int number1, number2;
    std::cout << "Inserire un numero intero: ";
    std::cin >> number1;
    std::cout << "Inserire un altro numero intero: ";
    std::cin >> number2;
    int somma = number1 + number2;
    std::cout << "La somma dei due numeri è: " << somma << std::endl;
    return 0;
}

```

L'esecuzione del programma ha come risultato:

```cpp
Inserire un numero intero: 5
Inserire un altro numero intero: 7
La somma dei due numeri e': 12
```

In questo esempio, gli interi immessi dall'utente sono memorizzati in una variabile.
Ad una terza variabile intera viene assegnata la somma dei due numeri. 
Infine, quest'ultima variabile viene stampata a schermo.

> :exclamation: Nel caso di variabili con nomi composti, usate la convenzione camelCase. Usate nomi di funzioni e variabili con la lettera minuscola.

## [Esercizio1_2] Creare un programma in c++ che chieda all'utente di inserire cinque interi e ne stampi a terminale la media (approssimandola ad intero)


```cpp
#include <iostream>

using namespace std;

int main()
{
    int num1, num2, num3, num4, num5, media;
    cout << "Inserisci il primo numero: ";
    cin >> num1;
    cout << "Inserisci il secondo numero: ";
    cin >> num2;
    cout << "Inserisci il terzo numero: ";
    cin >> num3;
    cout << "Inserisci il quarto numero: ";
    cin >> num4;
    cout << "Inserisci il quinto numero: ";
    cin >> num5;
    media = (num1 + num2 + num3 + num4 + num5)/5;
    cout << "La media dei 5 numeri immessi e' " << media << endl;
    return 0;
}
```

L'esecuzione del programma ha come risultato:

```cpp
Inserisci il primo numero: 30
Inserisci il secondo numero: 20
Inserisci il terzo numero: 10
Inserisci il quarto numero: 15
Inserisci il quinto numero: 30
La media dei 5 numeri immessi e' 21
```

L'esercizio non presenta particolari difficoltà rispetto ai precedenti. Si noti che la variabile "media" è un intero; la divisione tra interi restituisce come risultato il quoziente della divisione.

## [Esercizio1_3] Creare un programma in c++ che chieda all'utente di immettere la lunghezza (intera) di due cateti di un triangolo rettangolo e stampi a terminale il quadrato dell'ipotenusa. 



```cpp
#include <iostream>

using namespace std;

int main()
{
    int cateto1, cateto2, quadratoIpotenusa;
    cout << "Inserisci la lunghezza di un cateto: ";
    cin >> cateto1;
    cout << "Inserisci la lunghezza del secondo cateto: ";
    cin >> cateto2;
    quadratoIpotenusa = cateto1 * cateto1 + cateto2 * cateto2;
    cout << "Il quadrato dell'ipotenusa e' pari a " << quadratoIpotenusa << endl;
    return 0;
}
```

L'esecuzione del programma ha come risultato:

```cpp
Inserisci la lunghezza di un cateto: 3
Inserisci la lunghezza del secondo cateto: 4
Il quadrato dell'ipotenusa e' pari a 25
```

Il programma sfrutta gli operatori di moltiplicazione e di somma.

> :exclamation: Si noti che l'elevazione a potenza di un numero può essere effettuata anche sfruttando l'operatore pow, con la sintassi std::pow (base, esponente). In questo caso deve però essere incluso anche l'header cmath


## [Esercizio1_4] Creare un programma in c++ che chieda all'utente di immettere due interi, divida il primo numero per il secondo, e stampi a terminale il quoziente e il resto

```cpp
#include <iostream>

using namespace std;

int main()
{
    int num1, num2, quoziente, resto;
    cout << "Inserisci il primo numero: ";
    cin >> num1;
    cout << "Inserisci un altro numero: ";
    cin >> num2;
    quoziente = num1 / num2;
    resto = num1 % num2;
    cout << "La divisione tra i due numeri ha come quoziente " << quoziente <<
        " e come resto " << resto << endl;
    return 0;
}
```

> L'esecuzione del programma ha come risultato:

```cpp
Inserisci il primo numero: 63
Inserisci un altro numero: 10
La divisione tra i due numeri ha come quoziente 6 e come resto 3
```
La divisione implementata tra interi da come risultato un quoziente e un resto. Gli operatori algebrici in C++ possono dare un solo risultato per volta, per cui per il calcolo della divisione tra int ci sono due operatori: l'operatore quoziente / e l'operatore modulo %. 

Il simbolo / serve per il calcolo del quoziente della divisione intera tra due valori interi. 

Il simbolo % serve per il calcolo del resto (o quoto) della divisione tra due valori.

> :exclamation: Lo stesso simbolo '/' in C++ si usa anche nelle divisioni tra numeri con la virgola, non importa se siano essi float o double, e numeri con la virgola e numeri interi.

## [Esercizio1_5] Realizzare un convertitore Euro -> Lire, utilizzando come fattore di conversione l'intero costante 1936.


```cpp
#include <iostream>

using namespace std;

int main()
{
    int euro, lire;
    const int conv = 1936;
    cout << "Inserisci il prezzo in euro: ";
    cin >> euro;
    lire = euro * conv;
    cout << "Il prezzo immesso equivale a " << lire << " lire!" << endl;
    return 0;
}
```

L'esecuzione del programma ha come risultato:

```cpp
Inserisci il prezzo in euro: 10
Il prezzo immesso equivale a 19360 lire!
```

Come il nome stesso suggerisce, const rende la variabile intera a cui è applicata immutabile. L'uso più ovvio è quello della definizione di valori costanti che rimangono immutati per l'intera esecuzione del programma.

Data l'immutabilità di una variabile const, la sua inizializzazione deve essere contestuale alla dichiarazione. Ad esempio il frammento seguente genererà un errore di compilazione:

```
const double phi; 
phi = 1.6180339887; // errore
```