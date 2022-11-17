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
