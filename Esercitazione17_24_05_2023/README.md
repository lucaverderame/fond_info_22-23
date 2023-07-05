## Diciasettesima esercitazione - Esercizi Liste

In questa cartella trovate tutto il materiale utilizzato per l'esercitazione; in ognuna delle sotto-cartelle avete a disposizione il file con la soluzione degli esercizi mentre nel prosieguo di questo readme avete il commento ad ognuno degli esercizi, corredato dalla sua soluzione ed un esempio di esecuzione. Le slide utilizzate a supporto dell'esercitazione le trovate invece sulla pagina del corso di AulaWeb a [questo indirizzo](https://2022.aulaweb.unige.it/course/view.php?id=4289).

### [Esercizio 17_1] - Figura2D

Si progetti e si implementi in linguaggio C++ la classe Figura2D per rappresentare una figura complessa come una collezione di poligoni bidimensionali. Internamente alla classe, una figura sarà rappresentata da una lista di oggetti della classe Poligono2D; la classe Figura2D conterrà cioè, come attributo, una lista _poligoni di oggetti di classe Poligono2D. A tale scopo, si riutilizzi la classe sviluppata nelle esercitazioni precedenti. La classe Figura2D implementerà inoltre i seguenti metodi:
-	Il costruttore di default.
-	Un costruttore con parametri che riceva un array p di oggetti di tipo Poligono2D e la sua dimensione n (un numero intero) e inizializzi la figura inserendo nella lista _poligoni gli elementi dell’array p.
-	Il costruttore di copia.
-	Il distruttore.
-	Un metodo per ottenere il numero di poligoni che compongono la figura.
-	Un metodo che riceva come parametro un numero intero i e restituisca come valore di ritorno un puntatore a costante all’i-esimo poligono della figura. Nel caso in cui il valore dell’indice i non sia valido, il metodo restituisce NULL.
-	Un metodo che riceva come parametro un numero intero i e un oggetto p di classe Poligono2D e sostituisca l’i-esimo poligono contenuto nella lista _poligoni con il poligono p passato come parametro al metodo. Nel caso in cui il valore dell’indice i non sia valido, la lista _poligoni non viene modificata.
-	Un metodo per aggiungere alla figura un nuovo poligono (passato come parametro).
-	Un metodo che riceva come parametro un numero intero i ed elimini l’i-esimo poligono dalla figura, rimuovendolo dalla lista _poligoni. Nel caso in cui il valore dell’indice i non sia valido, la lista _poligoni non viene modificata.
-	L’operatore di assegnamento.
-	L’operatore di moltiplicazione per scalare.
-	Gli operatori di inserimento ed estrazione.
Si scriva quindi un programma C++ per verificare il corretto funzionamento della classe sviluppata. Dopo aver dichiarato una variabile f di tipo Figura2D, il programma visualizzerà un menù per consentire all’utente di selezionare una delle seguenti operazioni: aggiungere un poligono alla figura f, rimuovere un poligono dalla figura f, ottenere e stampare a video il numero di poligoni di cui la figura f si compone, stampare i dati relativi alla figura f, uscire dal programma. L’utente potrà ripetere la selezione, finché non sceglie di uscire dal programma. 
Nota: per l’implementazione della classe Figura2D, si può riutilizzare il template di classe List che trovate allegato all’esercitazione e che rispecchia l’implementazione di una lista semplicemente concatenata contenuta nei lucidi presentati a lezione.

> :warning: Per la soluzione si veda la Cartella Esercizio17_1

Un possibile risultato dell'esecuzione sarà:

```

Operazioni disponibile: 
1. Aggiungere un poligono alla figura
2. Rimuovere un poligono dalla figura
3. Ottenere il numero di poligoni di cui la figura si compone
4. Stampare i dati relativi alla figura
5. Uscire dal programma
Scegliere l'operazione: 1
Inserire il numero di vertici del nuovo poligono: 4
Inserire i vertici del poligono: 
1 1
2 2
3 3
4 4

Operazioni disponibile: 
1. Aggiungere un poligono alla figura
2. Rimuovere un poligono dalla figura
3. Ottenere il numero di poligoni di cui la figura si compone
4. Stampare i dati relativi alla figura
5. Uscire dal programma
Scegliere l'operazione: 3
Figura composta da 1 poligoni

Operazioni disponibile: 
1. Aggiungere un poligono alla figura
2. Rimuovere un poligono dalla figura
3. Ottenere il numero di poligoni di cui la figura si compone
4. Stampare i dati relativi alla figura
5. Uscire dal programma
Scegliere l'operazione: 4
Figura composta da 1 poligoni
Poligoni che compongono la figura:
(1,1) (2,2) (3,3) (4,4) 

Operazioni disponibile: 
1. Aggiungere un poligono alla figura
2. Rimuovere un poligono dalla figura
3. Ottenere il numero di poligoni di cui la figura si compone
4. Stampare i dati relativi alla figura
5. Uscire dal programma
Scegliere l'operazione: 2
Inserire l'indice del poligono da rimuovere: 
0

Operazioni disponibile: 
1. Aggiungere un poligono alla figura
2. Rimuovere un poligono dalla figura
3. Ottenere il numero di poligoni di cui la figura si compone
4. Stampare i dati relativi alla figura
5. Uscire dal programma
Scegliere l'operazione: 5


```

### [Esercizio 17_2] - Notazione Inversa Polacca

La Notazione Polacca Inversa (Reverse Polish Notation, RPN) è un linguaggio per operazioni aritmetiche in cui l’operatore segue gli operandi. La RPN consente di effettuare qualsiasi tipo di operazione, con il vantaggio di eliminare i problemi dovuti alle parentesi e alla precedenza degli operatori. Ad esempio, l’espressione RPN “3 5 +” corrisponde all’espressione in notazione inﬁssa “3 + 5”, l’espressione “15 2 3 + /” corrisponde a 15 / (2 + 3), mentre l’espressione “15 2 + 3 /” corrisponde a (15 + 2) / 3.
Per valutare un’espressione scritta secondo la RPN, si può utilizzare una pila. In particolare, si leggono da sinistra verso destra i componenti (operandi e operatori) dell’espressione RPN e si applicano le seguenti regole:
-	Se il componente è un operando, lo si inserisce nella pila. 
-	Se il componente è un operatore lo si applica ad un numero appropriato di elementi prelevati dalla pila (per esempio due per la somma). Il risultato viene poi inserito nella pila.
Al termine della lettura dell’espressione, l’elemento di testa della pila contiene il risultato finale.
Scrivere un programma C++ che apra in lettura il file “operazioni.txt” contenente in ciascuna sua riga un’operazione espressa in RPN (il numero di righe di cui è composto il file non è noto al programmatore), legga ciascuna riga in un’opportuna stringa di caratteri, calcoli il risultato dell’espressione applicando il metodo sopra illustrato e scriva il risultato nel file “risultati.txt”. Terminata la scansione del file “operazioni.txt”, il programma chiude entrambi i file e, prima di terminare, stampa a video il numero di operazioni eseguite. Per semplicità, si supponga che ciascuna riga del file “operazioni.txt” contenga al più 127 caratteri, che gli operandi siano numeri interi (il risultato potrà tuttavia essere un numero reale), che le operazioni ammesse siano le quattro usuali operazioni aritmetiche rappresentate dai caratteri ‘+’, ‘-‘,’*’ e ‘/’ e che i dati contenuti nelle righe del file siano validi.

Esempio:

File operazioni.txt		File risultati.txt
1 2 +					3
10 2 / 5 *				25
4 8 2 - *				24

Nota: per l’implementazione della pila, si può riutilizzare il template di classe List che trovate allegato all’esercitazione e che rispecchia l’implementazione di una lista semplicemente concatenata contenuta nei lucidi presentati a lezione. Per implementare la politica LIFO che governa la pila, l’inserimento (push) e la rimozione (pop) di nodi si farà sempre in testa.

> :warning: Per la soluzione si veda la Cartella Esercizio17_2


Un possibile risultato dell'esecuzione sarà:

```
Operazione: 1 2 +
Risultato: 3
Operazione: 10 2 / 5 *
Risultato: 25
Operazione: 4 8 2 - *
Risultato: 24
Operazione: 2 10 / 5 *
Risultato: 1
Operazione: 4 2 8 - *
Risultato: -24
Operazione: 4 8 2 * -
Risultato: -12
Operazione: 8 2 + 8 3 - * 2 /
Risultato: 25
Operazione: 2 4 - 6 4 + * 200 /
Risultato: -0.1
Eseguite 8 operazioni
```