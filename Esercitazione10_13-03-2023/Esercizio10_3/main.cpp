#include <iostream>
#include <fstream>
using namespace std;

const int num_mesi = 12;
const int dim_str = 11;
const int dim_data = 3;

int main() 
{
	const char* mesi[num_mesi] = { "gennaio", "febbraio", "marzo", "aprile",
		"maggio", "giugno", "luglio", "agosto", "settembre",
		"ottobre", "novembre", "dicembre" };
    
    int mese = 0; int anno = 0;
    cout << "Inserire mese e anno: " << endl;
    cout << "Mese: ";
    cin >> mese;
    cout << "Anno: ";
    cin >> anno;
	
	fstream fin, fout;
	fin.open("Date.txt", ios::in);
    fout.open("DateRecenti.txt", ios::out);
	
	char str[dim_str];
	while (!fin.eof()) {
		fin >> str;
		int k = 0; int n = 0;
		int data[dim_data] = {0, 0, 0}; int h = 0;
		while (str[k] != '\0') {
			if (str[k] == '/') {
				data[h] = n;
				h++;
				n = 0;
			}
			else
				n = n * 10 + (str[k] - '0');
			k++;
		}
		data[h] = n;
		cout << data[0] << " " << mesi[data[1] - 1] << " " << data[2] << endl;
        if (data[2] > anno || (data[2] == anno && data[1] > mese))
            fout << data[0] << " " << mesi[data[1] - 1] << " " << data[2] << endl;
	}

	fin.close();
    fout.close();
	return 0;
}
