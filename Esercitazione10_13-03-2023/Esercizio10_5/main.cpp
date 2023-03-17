#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int str_max_dim = 32;

struct studente {
	char* nome;
	char* cognome;
	int matricola;
};

studente* leggi (char* nome_file, int& n) {
	if (nome_file == NULL)
		return NULL;
		
	fstream fin;
	fin.open(nome_file, ios::in);
	if (!fin) 
		return NULL;
	
	fin >> n;
	if (fin.eof() || n <= 0)
		return NULL;
		
	studente* pdati = new studente[n];
	if (pdati == NULL)
		return NULL;
		
	char s[str_max_dim];
	for (studente* p = pdati; p < (pdati + n); p++) {
		fin >> s;
		p->nome = strdup(s);
		fin >> s;
		p->cognome = strdup(s);
		fin >> p->matricola;
	}
		
	fin.close();
	return pdati;
}

void stampa (studente* pdati, int n) {
	if (pdati != NULL)
		for (studente* p = pdati; p < (pdati + n); p++)
			cout << p->nome << " " << p->cognome << "\t" << p->matricola << endl;
}

studente* cerca(studente* pdati, int n, int matricola) {
    if (pdati != NULL) {
        for (studente* p = pdati; p < (pdati + n); p++)
            if (p->matricola == matricola) 
                return p;
    }
    return NULL;
}

void dealloca (studente* pdati, int n) {
	if (pdati != NULL) {
		for (studente* p = pdati; p < (pdati + n); p++) {
			delete[] p->nome;
			delete[] p->cognome;
		}
		delete[] pdati;	
	}
}

int main() { 
	char file[32];
	cout << "Inserire il nome di un file contente i dati richiesti: ";
	cin >> file;
	int d = 0;
	studente* pstudenti = leggi(file, d);
	if (pstudenti != NULL) {
		cout << "Dati relativi a " << d << " studenti: " << endl;
		stampa(pstudenti, d);
		// da commentare in caso di parte aggiuntiva
		//dealloca(pstudenti, d);
        
        // Parte aggiuntiva
        int m = 0;
        cout << "Inserire un numero di matricola: ";
        cin >> m;
        studente* p = cerca(pstudenti, d, m);
        if (p != NULL)
            cout << "Si tratta dello studente " << p->nome << " " << p->cognome << endl;
        else
            cout << "Non ci sono studenti con questo numero di matricola" << endl;        
	}
	return 0;  
}
