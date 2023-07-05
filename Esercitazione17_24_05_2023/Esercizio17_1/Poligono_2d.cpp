/////////////////////////////////////////////////////////////////////
// Costruttori della classe poligono2d
/////////////////////////////////////////////////////////////////////

Poligono2d::Poligono2d()
	: _p(NULL), _n(0)
{
}

Poligono2d::Poligono2d(int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		Punto2d* p = new Punto2d[dim];
		if (p != NULL) {
			_p = p;
			_n = dim;
		}
	}
}

Poligono2d::Poligono2d(Punto2d pti[], int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		Punto2d* p = new Punto2d[dim];
		if (p != NULL) {
			for (int k = 0; k < dim; k++)
				p[k] = pti[k];
			_p = p;
			_n = dim;
		}
	}
}

Poligono2d::Poligono2d(const Poligono2d& p)
	: _p(NULL), _n(0)
{
	if (p._n > 0) {
		Punto2d* pol = new Punto2d[p._n];
		if (pol != NULL) {
			for (int k = 0; k < p._n; k++)
				pol[k] = p._p[k];
			_p = pol;
			_n = p._n;
		}
	}
}

/////////////////////////////////////////////////////////////////////
// Distruttore della classe poligono2d
/////////////////////////////////////////////////////////////////////

Poligono2d::~Poligono2d()
{
	if (_p != NULL) {
		delete [] _p;
	}
}

/////////////////////////////////////////////////////////////////////
// Selettori della classe poligono2d
/////////////////////////////////////////////////////////////////////

int Poligono2d::get_num_vertici() const
{
	return _n;
}

const Punto2d* Poligono2d::get_vertici() const
{
	return _p;
}

/////////////////////////////////////////////////////////////////////
// Modificatori della classe poligono2d
/////////////////////////////////////////////////////////////////////

void Poligono2d::set_poligono(Punto2d pti[], int dim)
{
	if (dim > 0) {
		Punto2d* p = new Punto2d[dim];
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
// Operatori sovraccaricati della classe poligono2d
/////////////////////////////////////////////////////////////////////

Poligono2d Poligono2d::operator*(double s) const
{
	Poligono2d p(*this);
	if (get_vertici() != NULL) {
		for (int k = 0; k < get_num_vertici(); k++)
			p[k]= get_vertici()[k] * s;
	}
	return p;
}

const Poligono2d& Poligono2d::operator=(const Poligono2d& p)
{
	if (&p != this) {
		if (_p != NULL) {
			delete [] _p;
			_p = NULL;
		}
		_n = 0;
		int n = p.get_num_vertici();
		if (n > 0) {
			Punto2d* pnewpol = new Punto2d[n];
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

Punto2d& Poligono2d::operator[](int indice)
{
	return _p[indice];
}

/////////////////////////////////////////////////////////////////////
// Operazioni della classe poligono2d
/////////////////////////////////////////////////////////////////////

double Poligono2d::get_perimetro() const
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
// Funzioni amiche della classe poligono2d
////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& os, const Poligono2d& p)
{
	const Punto2d* pt = p.get_vertici();
	if (pt != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			os << pt[k] << ' ';
	return os;
}

istream& operator>>(istream& is, Poligono2d& p)
{
	if (p.get_vertici() != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			is >> p[k];
	return is;
}
