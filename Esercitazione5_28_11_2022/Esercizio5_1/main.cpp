#include <iostream>
using namespace std;

int cifra(int n)
{
    while(n>10)
    {
        n=n/10;
    }
    return n;
}


int main()
{
    int n1,n2;
    cin>>n1>>n2;
    if(cifra(n1*n2)<cifra(n1+n2))
    {
        cout<<"minore";
    }
    else
    {
        cout<<"non minore";
    }
}