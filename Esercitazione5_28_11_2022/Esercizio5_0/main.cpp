#include <iostream>
using namespace std;

int coppia(int n1,int n2, int n3)
{
    int valore=-1;
    if(n1==n2){valore=n1;}
    if(n1==n3){valore=n1;}
    if(n2==n3){valore=n2;}
    return valore;
}

int main()
{

    int x1,x2,x3,y1,y2,y3;
    cout<<"Inserisci la prima tripla:"<<endl;
    cin>>x1>>x2>>x3;
    cout<<"Inserisci la seconda tripla:"<<endl;
    cin>>y1>>y2>>y3;

    if((coppia(x1,x2,x3) == -1) & (coppia(y1,y2,y3)==-1))
    {
        cout<<"Entrambe le triple non hanno coppie valide";
    }
    else if(coppia(x1,x2,x3)>coppia(y1,y2,y3))
    {
        cout<<"La prima tripla ha la coppia di numeri più grande";
    }
    else if(coppia(x1,x2,x3)<coppia(y1,y2,y3))
    {
        cout<<"La seconda tripla ha la coppia di numeri più grande";
    }
    else
    {
        cout<<"Le triple sono equivalenti";
    }
}
