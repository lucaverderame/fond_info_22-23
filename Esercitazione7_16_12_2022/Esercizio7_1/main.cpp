#include <iostream>
#include <fstream>

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
    fstream ingr, usc1, usc2;
    ingr.open("ciao.txt", ios::in);
    usc1.open("vocali.txt", ios::out);
    usc2.open("consonanti.txt", ios::out);
    char a;
    while(!ingr.eof()){
        ingr >> a;
        if(isalpha(a)>0){
            if (controllo_vocale(a)==1){
                usc1 << a;
            }
            else{
                usc2 << a;
            }
        }
    }
    ingr.close();
    usc1.close();
    usc2.close();
}

