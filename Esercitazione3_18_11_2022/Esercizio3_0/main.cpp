# include <iostream>

int main()
{
  char op;
  float num1, num2;
  char flag = 'y';

  do {

    std::cout << "Inserisci l'operazione: ( es: 3 + 5): ";
    std::cin >> num1 >> op >>  num2;

    switch(op)
    {
      case '+':
        std::cout << num1+num2 << std::endl;
        break;

      case '-':
        std::cout << num1-num2 << std::endl;
        break;

      case '*':
        std::cout << num1*num2 << std::endl;
        break;

      case '/':
        if (num2 == 0){
          std::cout << "Errore! Non posso dividere per 0" << std::endl;
          break;
        }
        std::cout << num1/num2 << std::endl;
        break;

      default:
        std::cout << "Errore! Questo operatore non e' supportato";
        break;
    }

    std::cout << "Premi y per continuare, qualsiasi altra lettera per uscire ";
    std::cin >> flag;

  } while (flag == 'y');

  std::cout << "Esco dal programma";

  return 0;
}

