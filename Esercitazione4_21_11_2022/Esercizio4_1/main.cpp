#include <iostream>

using namespace std;

void riduco(int& num, int& den){
    int minimo, mcd;
    if(num>den)
        minimo=num;
    else
        minimo=den;
    for (int i=1;i<=minimo;i++){
        if ((num%i==0) && (den%i==0)){
            mcd=i;
        }
    }
    num=num/mcd;
    den=den/mcd;
}

int main()
{
    int num1, num2, den1, den2;
    char op1, op2;
    cout << "Inserisci due frazioni:" << endl;
    cin >> num1 >> op1 >> den1;
    cin >> num2 >> op2 >> den2;
    riduco(num1, den1);
    riduco(num2, den2);
    cout << "La prima frazione si puo' ridurre a: " << num1 << op1 << den1 << endl;
    cout << "La seconda frazione si puo' ridurre a: " << num2 << op2 << den2 << endl;
    return 0;
}

