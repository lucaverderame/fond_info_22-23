
////////////////////////////////////////////////////////////
// CLASS NODE
////////////////////////////////////////////////////////////

// costruttori e distruttore
template <typename T>
Node<T>::Node()
	: _data(), _next(0)
{
}

template <typename T>
Node<T>::Node(const T& data, Node<T>* next)
	: _data(data), _next(next)
{
}

template <typename T>
Node<T>::Node(const Node<T>& node)
	: _data(node._data), _next(node._next)
{
}

template <typename T>
Node<T>::~Node()
{
}

// selettori
template <typename T>
inline const T& Node<T>::getData() const
{
	return _data;
}

template <typename T>
inline Node<T>* Node<T>::getNext() const
{
	return _next;
}


// modificatori
template <typename T>
void Node<T>::setData(const T& data){
	_data = data;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	_next = next;
}


////////////////////////////////////////////////////////////
// CLASS LIST
////////////////////////////////////////////////////////////

// costruttori e distruttore
template <typename T>
List<T>::List() : _head(0), _numItems(0)
{
}

template <typename T>
List<T>::List(const List<T>& l) : _head(0), _numItems(l._numItems)
{
	if (l._head != 0) {
		Node<T>* p = l.getHead();
		_head = new Node<T>(*p);
		Node<T>* q = _head;
		p = p->getNext();
		while (p != 0) {
			Node<T>* pNew = new Node<T>(p->getData(), 0);
			q->setNext(pNew);
			q = pNew;
			p = p->getNext();
		}
	}

}

template <typename T>
List<T>::~List()
{
	clear();
	_head = 0;
	_numItems = 0;
}

// selettori per gli attributi
template <typename T>
int List<T>::isEmpty() const
{
	return (_head == 0);
}

template <typename T>
int List<T>::numItems() const
{
	return _numItems;
}

// inserimento di nuovi nodi
template <typename T>
void List<T>::insertFront(const T& data)
{
	Node<T>* pNew = new Node<T>(data, _head);
	_head = pNew;
	_numItems++;
}

template <typename T>
void List<T>::insertBack(const T& data)
{
	if (_head != 0) {
		Node<T>* pNew = new Node<T>(data, 0);
		Node<T>* p = _head;
		while (p->getNext() != 0)
			p = p->getNext();
		p->setNext(pNew);
		_numItems++;
	}
	else
		insertFront(data);
}

template <typename T>
void List<T>::insertAfter(Node<T>* p, const T& data)
{
	if (p != 0) {
		Node<T>* pNew = new Node<T>(data, p->getNext());
		p->setNext(pNew);
		_numItems++;
	}
}

// rimozione di nodi
template <typename T>
void List<T>::removeFront()
{
	if (_head != 0) {
		Node<T>* p = _head;
		_head = _head->getNext();
		delete p;
		_numItems--;
	}
}

template <typename T>
void List<T>::removeBack()
{
	if (_head != 0) {
		if (_head->getNext() != 0) {
			Node<T>* p = _head->getNext();
			Node<T>* q = _head;
			while (p->getNext() != 0) {
				q = q->getNext();
				p = p->getNext();
			}
			q->setNext(0);
			delete p;
		}
		else  {
			delete _head;
			_head = 0;
		}
		_numItems--;
	}
}

template <typename T>
void List<T>::removeAt(Node<T>* p)
{
	if (_head != 0) {
		Node<T>* q = _head;
		if (q == p) removeFront();
		else {
			while (q->getNext() != 0 && q->getNext() != p)
				q = q->getNext();
			if (q->getNext() != 0) {
				q->setNext(p->getNext());
				delete p;
				_numItems--;
			}
		}
	}
}

// attraversamento
template <typename T>
Node<T>* List<T>::getHead() const
{
	return _head;
}

// operatori
template <typename T>
void List<T>::clear()
{
	Node<T>* p = getHead();
	while (p != 0) {
		Node<T>* q = p;
		p = p->getNext();
		delete q;
	}
	_head = 0;
	_numItems = 0;
}

template <typename T>
Node<T>* List<T>::find(const T& data) const
{
	Node<T>* p = _head;
	while (p != 0) {
		if (p->getData() == data)
			return p;
		p = p->getNext();
	}
	return 0;
}

template <typename T>
void List<T>::print() const
{
	Node<T>* p = _head;
	if (p != 0) {
		cout << p->getData();
		p = p->getNext();
	}
	while (p != 0) {
		cout << ", " << p->getData();
		p = p->getNext();
	}
}

