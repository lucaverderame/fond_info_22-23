#include <iostream>
using namespace std;

int potenza(int base, int esponente) {
	if (esponente > 0)
		return base * potenza(base, esponente - 1);
	else
		return 1;
}

double potenza2(int base, int esponente) {
	if (esponente > 0)
		return base * potenza2(base, esponente - 1);
	else if (esponente < 0)
		return (1.0 / base) * potenza2(base, esponente + 1);
	else
		return 1;
}

int main()
{
	int n = 0;
	int m = 0;
	char c = 'n';

	do {
		cout << "Inserire il valore della base: ";
		cin >> m;
		cout << "Inserire il valore dell'esponente: ";
		cin >> n;
		if (n >= 0)
			cout << m << " elevato alla " << n << " vale " << potenza(m, n) << endl;
		else
			cout << m << " elevato alla " << n << " vale " << potenza2(m, n) << endl;
		cout << endl;
		do {
			cout << "Continuare (s/n)? ";
			cin >> c;
			if (c != 's' && c != 'n')
				cout << "Attenzione: inserire s oppure n";
		} while (c != 's' && c != 'n');
	} while (c == 's');

	return 0;
}


