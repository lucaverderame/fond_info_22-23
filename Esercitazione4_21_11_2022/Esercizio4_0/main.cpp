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

