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