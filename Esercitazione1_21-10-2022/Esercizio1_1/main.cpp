#include <iostream>


int main()
{
    int number1, number2;
    std::cout << "Inserire un numero intero: ";
    std::cin >> number1;
    std::cout << "Inserire un altro numero intero: ";
    std::cin >> number2;
    int somma = number1 + number2;
    std::cout << "La somma dei due numeri è: " << somma << std::endl;
    return 0;
}
