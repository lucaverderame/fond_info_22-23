#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int dim = 256;
    int contarima = 0, len1, len2, len;
    char stringa1[dim], stringa2[dim];
    cin.getline(stringa1, dim, '\n');
    cin.getline(stringa2, dim, '\n');
    len1 = strlen(stringa1);
    len2 = strlen(stringa2);

    if (len1 < len2)
        len = len1;
    else
        len = len2;

    for (int i=1; i<=len; i++){
        if(stringa1[len1-i]==stringa2[len2-i])
            contarima++;
        else
            break;
    }
    cout << "Le lettere che fanno rima sono: " << contarima << endl;
}
