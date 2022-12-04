#include <iostream>
using namespace std;

void funzioneScambio (int &a, int &b)
{
    int t=a;
    a=b;
    b=t;
}

int main()
{
    int n1;
    int n2;
    int n3;
    cin>>n1>>n2>>n3;
    
    if(n1>=n2)
    {
        funzioneScambio(n1,n2);
    }
    if(n1>=n3)
    {
        funzioneScambio(n1,n3);
    }
    if(n2>=n3)
    {
        funzioneScambio(n2,n3);
    }
    cout<<n1<<" "<<n2<<" "<<n3;
    
}