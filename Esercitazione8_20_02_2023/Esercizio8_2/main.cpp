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