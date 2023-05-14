#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>
using namespace std;

template<typename T>
class array {

public:

	// Costruttori
	array();
	array(int n);
	array(int n, T data[]);
	array(const array& a);

	// Distruttore
	~array();

	// Selettori
	int get_size() const;
	const T* get_value(int index) const;
	const T* get_array() const;

	// Modificatori
	int set_size(int n);
	int set_value(int index, const T& data);
	int set_array(T data[], int n);

	// Operazioni
	void print() const;
	void read();

	// Operatori sovraccaricati
	const array& operator = (const array& a);
	T& operator [] (int index);

private:
	T* _pdata;
	int _dim;
};

#include "array.cpp"

#endif

