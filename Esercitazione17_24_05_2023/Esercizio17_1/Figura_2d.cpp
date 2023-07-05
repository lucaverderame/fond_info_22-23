////////////////////////////////////////////////////////////
// Costruttori e distruttore
////////////////////////////////////////////////////////////

Figura2D::Figura2D()
	: _poligoni()
{
}

Figura2D::Figura2D(int dim, Poligono2d p[])
	: _poligoni()
{
	for (int i = 0; i < dim; i++)
		_poligoni.insertBack(p[i]);
}

Figura2D::Figura2D(const Figura2D& f)
	: _poligoni(f._poligoni)
{
}

Figura2D::~Figura2D()
{
}


////////////////////////////////////////////////////////////
// Selettori
////////////////////////////////////////////////////////////

int Figura2D::GetNumPoligoni() const
{
	return _poligoni.numItems();
}

const Poligono2d* Figura2D::GetPoligono(int i) const
{
	if (i >= 0 && i < _poligoni.numItems()) {
		int k = 0;
		Node<Poligono2d>* p = _poligoni.getHead();
		while (k < i) {
			p = p->getNext();
			k++;
		}
		return &(p->getData());
	}
	return NULL;
}


////////////////////////////////////////////////////////////
// Modificatori
////////////////////////////////////////////////////////////

void Figura2D::SetPoligono(int i, const Poligono2d& p)
{
	if (i >= 0 && i < _poligoni.numItems()) {
		int k = 0;
		Node<Poligono2d>* q = _poligoni.getHead();
		while (k < i) {
			q = q->getNext();
			k++;
		}
		q->setData(p);
	}
}


////////////////////////////////////////////////////////////
// Operatori
////////////////////////////////////////////////////////////

void Figura2D::InserisciPoligono(const Poligono2d& p)
{
	_poligoni.insertBack(p);
}

void Figura2D::EliminaPoligono(int i)
{
	if (i >= 0 && i < _poligoni.numItems()) {
		int k = 0;
		Node<Poligono2d>* p = _poligoni.getHead();
		while (k < i) {
			p = p->getNext();
			k++;
		}
		_poligoni.removeAt(p);
	}
}

const Figura2D& Figura2D::operator = (const Figura2D& f)
{
	if (&f != this) {
		_poligoni.clear();
		Node<Poligono2d>* p = f._poligoni.getHead();
		while (p != NULL) {
			_poligoni.insertBack(p->getData());
			p = p->getNext();
		}
	}
	return *this;
}

Figura2D Figura2D::operator * (double s)
{
	Figura2D f(*this);
	Node<Poligono2d>* p = f._poligoni.getHead();
	while (p != NULL) {
		Poligono2d pol(p->getData());
		pol = pol * s;
		p->setData(pol);
		p = p->getNext();
	}
	return f;
}

ostream& operator << (ostream& os, const Figura2D& f)
{
	Node<Poligono2d>* p = f._poligoni.getHead();
	while (p != NULL) {
		os << p->getData() << endl;
		p = p->getNext();
	}
	return os;
}

istream& operator >> (istream& is, Figura2D& f)
{
	f._poligoni.clear();
	int n = 0; int m = 0;
	is >> n;
	for (int i = 0; i < n; i++) {
		is >> m;
		Poligono2d p(m);
		is >> p;
		f._poligoni.insertBack(p);
	}
	return is;
}



