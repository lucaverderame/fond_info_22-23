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
