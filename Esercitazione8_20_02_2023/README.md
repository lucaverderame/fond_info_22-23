
# Ottava esercitazione - 20/02/23

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).


### [Esercizio 8_0] Strutture

Creare la struttura libro, in cui ogni libro ha un codice numerico (numero intero) che lo caratterizza, un numero di pagine e un costo. Si memorizzino i dati di tre libri e si calcoli il costo medio per pagina dei libri e si stampino i dati dei tre libri in ordine crescente di costo per pagina.

Implementare l'esercizio utilizzando tre funzioni, inserisciLibro, confrontaScambia, stampaLibro.

```cpp
#include <iostream>

using namespace std;

struct libro
{
    int pagine;
    int codice;
    float costo;
};

libro inserisciLibro()
{
    libro l;
    cout << "inserisci il numero di pagine: ";
    cin >> l.pagine;
    cout << "inserisci il codice: ";
    cin >> l.codice;
    cout << "inserisci il costo: ";
    cin >> l.costo;
    return l;
}

void confrontaScambia(libro &la,libro &lb)
{
    if(la.costo/la.pagine>lb.costo/lb.pagine)
    {
        libro ltemp=la;
        la=lb;
        lb=ltemp;
    }
}

void stampaLibro(libro l)
{
    cout << "pagine " << l.pagine << " ";
    cout << "codice " << l.codice << " ";
    cout << "costo " << l.costo << " " << endl;
}

int main()
{
  libro l1,l2,l3;
  l1=inserisciLibro();
  l2=inserisciLibro();
  l3=inserisciLibro();
  confrontaScambia(l1,l2);
  confrontaScambia(l1,l3);
  confrontaScambia(l2,l3);
  stampaLibro(l1);
  stampaLibro(l2);
  stampaLibro(l3);
}
```

```
> L'esecuzione del programma ha come risultato:

```cpp 
inserisci il numero di pagine:12
inserisci il codice:34
inserisci il costo:1432
inserisci il numero di pagine:56
inserisci il codice:34564
inserisci il costo:12343
inserisci il numero di pagine:1432
inserisci il codice:12343
inserisci il costo:23454

```

### [Esercizio 8_1] Array di Strutture

Scrivere un programma che prenda in ingresso un file di testo che descrive l'inventario di una libreria, con quattro campi: titolo del libro, autore, pagine, costo (vedi slide per l'esempio).

Il programma chiede quindi all'utente di inserire il titolo di un libro, restituendo le altre informazioni (autore, pagine, costo) se il libro e' presente nell'inventario.

> :warning: Nel caso di uno stream in lettura, è possibile usare la funzione getline per modificare il carattere terminatore della stringa.


```cpp
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int dim = 256;

struct libro
{
    char titolo[dim];
    char autore[dim];
    char prezzo[dim];
    char pagine[dim];
};

int main()
{
  fstream fin("libri.txt", ios::in);
  if(!fin){
    cout << "Errore nell'apertura del file" << endl;
    return -1;
  }

  char temp[dim];
  int conta = -1;
  while(!fin.eof()){
    fin.getline(temp,dim,'\n');
    conta++;
  }
  libro inventario[conta];
  fin.close();
  fin.open("libri.txt", ios::in);
  int i = 0;
  while(!fin.eof()){
    fin.getline(inventario[i].titolo,dim,',');
    fin.getline(inventario[i].autore,dim,',');
    fin.getline(inventario[i].pagine,dim,',');
    fin.getline(inventario[i].prezzo,dim,'\n');
    i++;
  }
  fin.close();
  cout << "Di quale libro vuoi avere info?" << endl;
  cin.getline(temp, dim, '\n');

  int found = 0;
  for(int i=0;i<conta;i++){
    if (strcmp(temp,inventario[i].titolo) == 0){
        cout << "Il libro e' presente nel catalogo" << endl;
        cout << "Il suo autore e': " << inventario[i].autore << endl;
        cout << "Il libro ha " << inventario[i].pagine << " pagine" << endl;
        cout << "Il libro costa " << inventario[i].prezzo << endl;
        found = 1;
        break;
    }
  }
  if (found == 0){
    cout << "Il libro non e' in catalogo" << endl;
  }
}
```
> L'esecuzione del programma ha come risultato:

```cpp 
Di quale libro vuoi avere info?
Il giovane Holden
Il libro e' presente nel catalogo
Il suo autore e':  J.D. Salinger
Il libro ha  225 pagine
Il libro costa  15

```

### [Esercizio 8_2]  Struttura Persona.

Il programma definisce una struct persona con campi nome, età, altezza e peso. Successivamente, chiede all'utente di inserire i dati di tre persone. Infine, restituisce il nome della persona più alta e della persona più giovane.

> :warning: E' possibile risolvere l'esercizio con un array di strutture persona, o utilizzando tre struct persona. Utilizzando gli array, è però più semplice risalire alla persona più alta e quella più giovane.


```cpp
#include <iostream>

using namespace std;

const int dim = 256;

struct persona
{
    char nome[dim];
    int altezza;
    int eta;
    int peso;
};

int main()
{
  int num = 3;
  persona persone[num];
  for (int i=0;i<num;i++){
    cout << "inserisci il nome della persona " << i+1 << ": ";
    cin >> persone[i].nome;
    cout << "inserisci l'altezza: ";
    cin >> persone[i].altezza;
    cout << "inserisci l'eta': ";
    cin >> persone[i].eta;
    cout << "inserisce il peso: ";
    cin >> persone[i].peso;
  }
  int alt_max = 0;
  int eta_min = 0;
  for (int i=1;i<num;i++){
    if(persone[i].altezza > persone[alt_max].altezza){
        alt_max = i;
    }
    if(persone[i].eta < persone[eta_min].peso){
        eta_min = i;
    }
  }

  cout << "La persona piu' alta e': " << persone[alt_max].nome << endl;
  cout << "La persona piu' giovane e': " << persone[eta_min].nome << endl;
}

```
> L'esecuzione del programma ha come risultato:

```cpp
inserisci il nome della persona 1: Massimo
inserisci l'altezza: 170
inserisci l'eta': 31
inserisce il peso: 72
inserisci il nome della persona 2: Jane
inserisci l'altezza: 165
inserisci l'eta': 26
inserisce il peso: 57
inserisci il nome della persona 3: Mike
inserisci l'altezza: 160
inserisci l'eta': 23
inserisce il peso: 65
La persona piu' alta e': Massimo
La persona piu' giovane e': Mike

```

### [Esercizio 8_3] Array di struttura e file.

Il programma definisce una struct data che memorizza giorno, mese e anno. Legge poi dal file input.txt 5 date di nascita (in ogni riga del file ci saranno giorno, mese e anno separati da spazi), fa inserire all'utente la data odierna e verifica quante date di nascita corrispondono a maggiorenni.

```cpp
#include <fstream>
#include <iostream>

using namespace std;

struct dataCompleanno
{
    int giorno;
    int mese;
    int anno;
};

int main()
{
    int dim = 5;
    dataCompleanno arrayDate[dim];
    fstream fin("date.txt", ios::in);
    for(int i=0;i<dim;i++)
    {
        fin>>arrayDate[i].giorno;
        fin>>arrayDate[i].mese;
        fin>>arrayDate[i].anno;
    }
    fin.close();

    dataCompleanno oggi;
    cout<<"inserisci la data di oggi ";
    cin>>oggi.giorno>>oggi.mese>>oggi.anno;

    int maggiorenni=0;
    for(int i=0;i<dim;i++)
    {
        if(oggi.anno-arrayDate[i].anno>18)
        {
            maggiorenni++;
        }
        else
        {
            if(oggi.anno-arrayDate[i].anno==18)
            {
                if(oggi.mese-arrayDate[i].mese>0)
                {
                    maggiorenni++;
                }
                else
                {
                    if(oggi.mese-arrayDate[i].mese==0)
                    {
                        if(oggi.giorno-arrayDate[i].giorno>=0)
                        {
                            maggiorenni++;
                        }
                    }
                }
            }
        }
    }

    cout<<"ci sono "<<maggiorenni<<" maggiorenni";
}
```
> L'esecuzione del programma ha come risultato:

```cpp
inserisci la data di oggi 14 12 2021
ci sono 3 maggiorenni

```