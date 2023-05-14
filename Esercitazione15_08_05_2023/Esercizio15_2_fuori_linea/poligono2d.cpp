
/////////////////////////////////////////////////////////////////////
// Costruttori
/////////////////////////////////////////////////////////////////////

template <typename T>
poligono2d<T>::poligono2d()
	: _p(NULL), _n(0)
{
}

template <typename T>
poligono2d<T>::poligono2d(int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		punto2d<T>* p = new punto2d<T>[dim];
		if (p != NULL) {
			_p = p;
			_n = dim;
		}
	}
}

template <typename T>
poligono2d<T>::poligono2d(punto2d<T> pti[], int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		punto2d<T>* p = new punto2d<T>[dim];
		if (p != NULL) {
			for (int k = 0; k < dim; k++)
				p[k] = pti[k];
			_p = p;
			_n = dim;
		}
	}
}

template <typename T>
poligono2d<T>::poligono2d(const poligono2d<T>& p)
	: _p(NULL), _n(0)
{
	if (p._n > 0) {
		punto2d<T>* pol = new punto2d<T>[p._n];
		if (pol != NULL) {
			for (int k = 0; k < p._n; k++)
				pol[k] = p._p[k];
			_p = pol;
			_n = p._n;
		}
	}
}


/////////////////////////////////////////////////////////////////////
// Distruttore
/////////////////////////////////////////////////////////////////////

template <typename T>
poligono2d<T>::~poligono2d()
{
	if (_p != NULL) {
		delete [] _p;
	}
}


/////////////////////////////////////////////////////////////////////
// Selettori
/////////////////////////////////////////////////////////////////////

template <typename T>
int poligono2d<T>::get_num_vertici() const
{
	return _n;
}

template <typename T>
const punto2d<T>* poligono2d<T>::get_vertici() const
{
	return _p;
}


/////////////////////////////////////////////////////////////////////
// Modificatori
/////////////////////////////////////////////////////////////////////

template <typename T>
void poligono2d<T>::set_poligono(punto2d<T> pti[], int dim)
{
	if (dim > 0) {
		punto2d<T>* p = new punto2d<T>[dim];
		if (p != NULL) {
			for (int k = 0; k < dim; k++)
				p[k] = pti[k];
			if (_p != NULL)
				delete [] _p;
			_p = p;
			_n = dim;
		}
	}
}


/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati
/////////////////////////////////////////////////////////////////////

template <typename T>
poligono2d<T> poligono2d<T>::operator*(double s) const
{
	poligono2d<T> p(*this);
	if (get_vertici() != NULL) {
		for (int k = 0; k < get_num_vertici(); k++)
			p[k]= get_vertici()[k] * s;
	}
	return p;
}

template <typename T>
const poligono2d<T>& poligono2d<T>::operator=(const poligono2d<T>& p)
{
	if (&p != this) {
		if (_p != NULL) {
			delete [] _p;
			_p = NULL;
		}
		_n = 0;
		int n = p.get_num_vertici();
		if (n > 0) {
			punto2d<T>* pnewpol = new punto2d<T>[n];
			if (pnewpol != NULL) {
				for (int k = 0; k < n; k++)
					pnewpol[k] = (p._p)[k];
				_p = pnewpol;
				_n = n;
			}
		}
	}
	return *this;
}

template <typename T>
punto2d<T>& poligono2d<T>::operator[](int indice)
{
	return _p[indice];
}


/////////////////////////////////////////////////////////////////////
// Operazioni
/////////////////////////////////////////////////////////////////////

template <typename T>
double poligono2d<T>::get_perimetro() const
{
	double perimetro = 0.0;
	if (get_vertici() != NULL) {
		for (int k = 0; k < (get_num_vertici() - 1); k++)
			perimetro += (get_vertici()[k]).distanza(get_vertici()[k + 1]);
		perimetro += (get_vertici()[0]).distanza(get_vertici()[get_num_vertici() - 1]);
	}
	return perimetro;
}


////////////////////////////////////////////////////////////////////
// Funzioni amiche
////////////////////////////////////////////////////////////////////

template <typename T>
ostream& operator<<(ostream& os, const poligono2d<T>& p)
{
	const punto2d<T>* pt = p.get_vertici();
	if (pt != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			os << pt[k] << ' ';
	return os;
}

template <typename T>
istream& operator>>(istream& is, poligono2d<T>& p)
{
	if (p.get_vertici() != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			is >> p[k];
	return is;
}

