#include <iostream>
using namespace std;

template<typename T>
class MyArray {

public:

	// Costruttori
	MyArray();
	MyArray(int n);
	MyArray(int n, T data[]);
	MyArray(const MyArray& a);

	// Distruttore
	~MyArray();

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
	const MyArray& operator = (const MyArray& a);
	T& operator [] (int index);

private:
	T* _pdata;
	int _dim;
};
/////////////////////////////////////////////////////////////////////
// Costruttori
/////////////////////////////////////////////////////////////////////

template<typename T>
MyArray<T>::MyArray() {
	_pdata = NULL;
	_dim = 0;
}

template<typename T>
MyArray<T>::MyArray(int n)
	: _pdata(NULL), _dim(0)
{
	if (n > 0) {
		T* p = new T[n];
		if (p != NULL) {
			_pdata = p;
			_dim = n;
		}
	}
}

template<typename T>
MyArray<T>::MyArray(int n, T data[])
	: _pdata(NULL), _dim(0)
{
	if (n > 0) {
		T* p = new T[n];
		if (p != NULL) {
			_pdata = p;
			_dim = n;
			for (int i = 0; i < n; i++)
				_pdata[i] = data[i];
		}
	}
}

template<typename T>
MyArray<T>::MyArray(const MyArray& a)
	: _pdata(NULL), _dim(0)
{
	int n = a._dim;
	if (n > 0) {
		T* p = new T[n];
		if (p != NULL) {
			_pdata = p;
			_dim = n;
			for (int i = 0; i < n; i++)
				_pdata[i] = a._pdata[i];
		}
	}
}


/////////////////////////////////////////////////////////////////////
// Distruttore
/////////////////////////////////////////////////////////////////////

template<typename T>
MyArray<T>::~MyArray() {
	if (_pdata != NULL)
		delete[] _pdata;
}


/////////////////////////////////////////////////////////////////////
// Selettori
/////////////////////////////////////////////////////////////////////

template<typename T>
int MyArray<T>::get_size() const {
	return _dim;
}

template<typename T>
const T* MyArray<T>::get_value(int index) const {
	if (index >= 0 && index < _dim - 1 && _pdata != NULL) {
		return _pdata[index];
	}
	return NULL;
}

template<typename T>
const T* MyArray<T>::get_array() const
{
	return _pdata;
}


/////////////////////////////////////////////////////////////////////
// Modificatori
/////////////////////////////////////////////////////////////////////

template<typename T>
int MyArray<T>::set_size(int n) {
	if (n <= 0)
		return 0;

	T* p = new T[n];
	if (p == NULL)
		return 0;

	if (_pdata != NULL) {
		for (int i = 0; i < min(_dim, n); i++)
			p[i] = _pdata[i];
		delete[] _pdata;
	}
	_pdata = p;
	_dim = n;
	return 1;
}

template<typename T>
int MyArray<T>::set_value(int index, const T& data) {
	if (index >= 0 && index < _dim - 1 && _pdata != NULL) {
		_pdata[index] = data;
		return 1;
	}
	return 0;
}

template<typename T>
int MyArray<T>::set_array(T data[], int n) {
	if (n == _dim && _pdata != NULL) {
		for(int i = 0; i < n; i++)
			_pdata[i] = data[i];
		return 0;
	}
	return 1;
}


/////////////////////////////////////////////////////////////////////
// Operazioni
/////////////////////////////////////////////////////////////////////

template<typename T>
void MyArray<T>::print() const {
	if (_pdata != NULL) {
		cout << "{";
		for (int i = 0; i < _dim - 1; i++)
			cout << _pdata[i] << ", ";
		cout << _pdata[_dim - 1] << "}" << endl;
	}
}

template<typename T>
void MyArray<T>::read() {
	if (_pdata != NULL) {
		for (int i = 0; i < _dim; i++) {
			cout << "Inserire elemento " << i + 1 << endl;
			cin >> _pdata[i];
		}
	}
}


/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati
/////////////////////////////////////////////////////////////////////

template<typename T>
const MyArray<T>& MyArray<T>::operator = (const MyArray<T>& a) {
	if (this != &a) {
		if (_pdata != NULL) {
			delete[] _pdata;
		}
		int n = a._dim;
		if (n > 0) {
			T* p = new T[n];
			if (p != NULL) {
				_pdata = p;
				_dim = n;
				for (int i = 0; i < n; i++)
					_pdata[i] = a._pdata[i];
			}
			else {
				_pdata = NULL;
				_dim = 0;
			}
		}
		else {
			_pdata = NULL;
			_dim = 0;
		}
	}
	return *this;
}

template<typename T>
T& MyArray<T>::operator [] (int index) {
	return _pdata[index];
}


int main() {

	const int dim = 10;
	MyArray<int> a(dim);

	cout << "Inserire " << dim << " numeri interi:" << endl;
	a.read();
	cout << "Hai inserito i seguenti numeri: ";
	a.print();

	int somma = 0;
	for (int k = 0; k < dim; k++)
		somma += a[k];
	cout << "Somma degli elementi inseriti: " << somma << endl;

	return 0;
}