
# Seconda esercitazione - 04/11/22

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).


## [Esercizio2_0] Risolutore di equazioni di secondo grado

```cpp
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //risolutore di equazioni di secondo grado
    double a, b, c;
    double root1, root2;
    cout << "Inserisci i coefficienti dell'equazione di secondo grado: ax^2 + bx + c = 0" << endl;
    cin >> a >> b >> c;
    if (a == 0){
        if (b == 0) {
            if (c==0)
                {
                // se i tre coefficienti sono 0, qualsiasi valore di x risolve l'equazione
                cout << "L'equazione ha infinite soluzioni" << endl;
                }
            else
                {
                // l'equazione è di tipo c = 0, con c!=0.
                cout << "L'equazione non ha soluzione" << endl;
                }
            }
        else{
            // risolviamo l'equazione di primo grado
            root1 = -c/b;
            cout << "L'equazione ha una soluzione reale: x = " << root1 << endl;
        }
    }
    else {
        if ((pow(b,2)-4*a*c)>=0){
            root1 = (-b - sqrt(pow(b,2)-4*a*c))/(2*a);
            root2 = (-b + sqrt(pow(b,2)-4*a*c))/(2*a);
            if (root1==root2){
                cout << "L'equazione ha due soluzione reali e coincidenti: x = " << root1 << endl;
            }
            else{
                cout << "L'equazione ha due soluzione reali distinte: x = " << root1 << " e x = "
                    << root2 << endl;
            }
        }
        else{
            // se il discriminante è minore di zero, l'equazione non ha soluzioni reali
            cout << "L'equazione non ha soluzioni reali!" << endl;
        }
    }
    return 0;
}
```
L'esecuzione del programma ha come risultato:

```cpp
Inserisci i coefficienti dell'equazione di secondo grado: ax^2 + bx + c = 0
4
12
6
L'equazione ha due soluzione reali distinte: x = -2.36603 e x = -0.633975
```

Il programma prevede l'utilizzo di istruzioni condizionali e variabili di tipo double per esplorare tutti i possibili casi da valutare per la soluzione di un'equazione di secondo grado.

> :exclamation: Uno degli errori più comuni per chi inizia a programmare consiste nel confondere l'operatore assegnamento (```=```) con l'operatore di uguaglianza (```==```). L'assegnamento (```=```) è utilizzato per assegnare un valore ad una variabile. L'operatore di uguaglianza (```==```) è utilizzato per verificare se due variabili hanno lo stesso valore.


> :warning: Nel caso di programmi più complessi, può essere utile inserire dei commenti nel codice, per aumentarne la leggibilità. Uno dei possibili modi di farlo è utilizzare ```//```

### math.h VS cmath.

La libreria C++ include le stesse definizioni di quella C, con le seguenti differenze:

- Ogni header ha lo stesso nome di quello utilizzato in C, ma con un prefisso "c" e nessuna estensione. Per esempio, l'equivalente in C++ dell'header stdlib.h e cstdlib.

- Ogni elemento della libreria è definito nel namespace std.

Raccomandiamo l'uso di cmath quando si usa il C++.

E' possibile esplorare le librerie C++ [qui](http://www.cplusplus.com/reference/)


## [Assignment2_1] Programma che controlla l'immissione di una password

"Creare un programma che fa inserire all'utente 4 caratteri e verifica che ci sia almeno una lettera minuscola, una maiuscola e una cifra. Utilizzare l'operatore condizionale if."

**Condiderazioni per la risoluzione dell'esercizio:**

Per l'esercizio è necessario tenere presente che:
* Il valore ASCII dei caratteri minuscoli va da 97 to 122
* Il valore ASCII dei caratteri maiuscoli va da 65 to 90
* Il valore ASCII delle cifre va da 48 a 57.

[Qui](https://www.oppo.it/tabelle/tabella_ascii.htm) potete trovare una tabella riassuntiva.

Ricorda inoltre che gli operatori logici possono essere utili per raggruppare alcune condizioni e evitare l'utilizzo di operatori condizionali in cascata.

```cpp

#include <iostream>

using namespace std;

int main()
{
    char a ,b, c, d;
    cout << "Inserisci una password di quattro caratteri:" << endl;
    cin >> a >> b >> c >> d;
    int minuscolo = (a>=97 && a<= 122) || (b>=97 && b<= 122) || (c>=97 && c<= 122) || (d>=97 && d<= 122);
    int maiuscolo = (a>=65 && a<= 90) || (b>=65 && b<= 90) || (c>=65 && c<= 90) || (d>=65 && d<= 90);
    int cifra = (a>=48 && a<= 57) || (b>=48 && b<= 57) || (c>=48 && c<= 57) || (d>=48 && d<= 57);

    if (minuscolo && maiuscolo && cifra){
        cout << "Password OK!" << endl;
    }
    else{
        cout << "La password non va bene" << endl;
    }

    return 0;
}
```
La soluzione dell'esercizio prevede che il sistema verifichi prima la presenza di un carattere minuscolo in uno qualsiasi dei 4 caratteri (da qui l'utilizzo dell'operatore OR ||); per fare questa cosa si verifica che la conversione in ASCII del carattere inserito sia tra 97 e 122 (lettere minuscole). Se una qualsiasi delle condizioni è vera, il valore di minuscolo sarà pari a 1.
Con lo stesso ragionamento, viene fatto lo stesso controllo per la lettera maiuscola e per la cifra.
Infine se tutte le condizioni sono rispettate (ovvero in AND &&) allora il sistema stamperà il messaggio di ok. 

L'esecuzione del programma ha come risultato:

```cpp
Inserisci una password di quattro caratteri:
P4ss
Password OK!
```

### [Assignment2_2] Programma che controlla l'immissione di una vocale

Creare un programma che fa inserire all'utente un carattere, e verifica che il carattere immesso sia una vocale o meno, utilizzando lo statement "if".

```cpp
#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout << "Inserisci una lettera:" << endl;
    cin >> ch;
    if(ch == 'a' || ch == 'A') cout << "Hai inserito una vocale!" << endl;
    else if(ch == 'e' || ch == 'E') cout << "Hai inserito una vocale!" << endl;
    else if(ch == 'i' || ch == 'I') cout << "Hai inserito una vocale!" << endl;
    else if(ch == 'o' || ch == 'O') cout << "Hai inserito una vocale!" << endl;
    else if(ch == 'u' || ch == 'U') cout << "Hai inserito una vocale!" << endl;
    else cout << "Non hai inserito una vocale!" << endl;
    return 0;
}
```

L'esecuzione del programma ha come risultato:

```cpp
Inserisci una lettera:
I
Hai inserito una vocale!
```

Se nessuna delle etichette ha un valore corrispondente a quello dell'espressione, il flusso viene rediretto all'else finale.

Lettere maiuscole e minuscole hanno codifiche ASCII diverse, e vanno quindi considerate come casi separati.

> :warning: Usando l'operatore switch (che vedrete nelle prossime lezioni) il codice potrà essere modificato per essere più leggibile; 


### [Assignment2_3] Convertitore lire - euro / euro - lire

Creare un programma che chieda all'utente se vuole immettere un valore in euro o in lire, acquisisca il valore dall'utente e restituisca il valore convertito nell'altra valuta.

```cpp
#include <iostream>

using namespace std;

int main()
{
    double num, num_conv;
    char a;
    cout << "Convertitore Euro-Lire / Lire-Euro" << endl;
    cout << "Premi l per convertire un valore da euro a lire, " <<
            "e per convertire un valore da lire a euro" << endl;
    cin >> a;
    if (a == 'l'){
        cout << "Inserisci la cifra in euro: ";
        cin >> num;
        num_conv = num * 1936.27;
        cout << "La cifra in lire e' " << num_conv << endl;
    }
    else if (a == 'e'){
        cout << "Inserisci la cifra in lire: ";
        cin >> num;
        num_conv = num / 1936.27;
        cout << "La cifra in euro e' " << num_conv << endl;
    }
    else {
        cout << "La lettera immessa e' sbagliata!" << endl;
    }
    return 0;
}
```

L'esecuzione del programma ha come risultato:

```cpp
Convertitore Euro-Lire / Lire-Euro
Premi l per convertire un valore da euro a lire, e per convertire un valore da lire a euro
e
Inserisci la cifra in lire: 20000
La cifra in euro e' 10.3291
```

### [Assignment2_4] Calcolatore di stagione

Scrivere un programma che chieda all'utente di immettere due interi, relativi al giorno e al mese, e restituisca la stagione corrispondente. Utilizzare l'operatore if.
Nella soluzione proposta, viene prima verificata l'esattezza della data, poi viene calcolata la stagione, tenendo conto degli equinozi (marzo e settembre) e dei solstizi (giugno e dicembre) 

```cpp
#include <iostream>

using namespace std;

int main()
{
    int giorno, mese;
    cout << "Inserisci il giorno e il mese dell'anno" << endl;
    cin >> giorno >> mese;

    if(mese == 1 | mese == 3 | mese == 5 | mese == 7 | mese == 8 | mese == 10 | mese == 12)
    {
        if (giorno >31 || giorno <0){
                cout << "La data e' sbagliata!";
                return 0;
            }
    }
    else if(mese == 4 | mese == 6 | mese == 9 | mese == 11)
    {
        if (giorno >30 || giorno <0){
                cout << "La data e' sbagliata!";
                return 0;
            }
    }
    else if(mese == 2)
    {
        if (giorno >29 || giorno <0){
                cout << "La data e' sbagliata!";
                return 0;
            }
    }
    else{
            cout << "Questo mese non esiste!";
            return 0;
    }

    if(mese == 1 | mese == 2){
        cout << "Inverno!";
        return 0;
    }

    if(mese == 3){
        if (giorno >=20)
                cout << "Primavera";
            else
                cout << "Inverno";
        return 0;
    }

    if(mese == 4 | mese == 5){
        cout << "Primavera!";
        return 0;
    }

    if(mese == 6){
        if (giorno >=21)
                cout << "Estate";
            else
                cout << "Primavera";
        return 0;
    }

    if(mese == 7 | mese == 8){
        cout << "Estate!";
        return 0;
    }

    if(mese == 9){
        if (giorno >=22)
                cout << "Autunno";
            else
                cout << "Estate";
        return 0;
    }

    if(mese == 10 | mese == 11){
        cout << "Autunno!";
        return 0;
    }

    if(mese == 12){
        if (giorno >=21)
                cout << "Inverno";
            else
                cout << "Autunno";
        return 0;
    }

}

```
L'esecuzione del programma ha come risultato:

```cpp
Inserisci il giorno e il mese dell'anno
29 2
Inverno!
```

> :warning: Usando l'operatore switch (che vedrete nelle prossime lezioni) il codice potrà essere modificato per essere più leggibile; 
