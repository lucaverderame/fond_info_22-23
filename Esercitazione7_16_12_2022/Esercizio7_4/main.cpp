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

