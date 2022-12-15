#include <iostream>
#include <cstring>

using namespace std;

int main(){
   const int dim = 256;
   int len, j=0, contadoppie =0;
   char stringa1[dim], stringa2[dim], stringa_res[dim];
   cout << "Inserisci due frasi: " << endl;
   cin.getline(stringa1, dim, '\n');
   cin.getline(stringa2, dim, '\n');
   strcat(stringa1, " ");
   strcat(stringa1,stringa2);
   len = strlen(stringa1);
   for (int i=0;i<len;i++){
        if ((isalpha(stringa1[i])>0) || stringa1[i]==' '){
            stringa_res[j]=stringa1[i];
            j++;
        }
   }
   stringa_res[j]='\0';
   len = strlen(stringa_res);
   for (int i=0;i<len-1;i++){
        if(stringa_res[i]==stringa_res[i+1])
            contadoppie++;
   }
   cout << "Il numero di doppie e': " << contadoppie;
}