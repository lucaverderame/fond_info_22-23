#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
	// costruttori e distruttore
	Node(const T& data, Node<T>* next);
	Node(const Node<T>& node);
	~Node();

	// selettori
	const T& getData() const;
	Node<T>* getNext() const;

	// modificatori
	void setData(const T& data);
	void setNext(Node<T>* next);

private:
	Node();
	T _data;
	Node<T>* _next;
};

template <typename T>
class List {
public:
	// costruttori e distruttore
	List();
	List(const List<T>& l);
	~List();

	// selettori per gli attributi
	int isEmpty() const;
	int numItems() const;

	// inserimento di nuovi nodi
	void insertFront(const T& data);
	void insertBack(const T& data);
	void insertAfter(Node<T>* p, const T& data);

	// rimozione di nodi
	void removeFront();
	void removeBack();
	void removeAt(Node<T>* p);

	// attraversamento
	Node<T>* getHead() const;

	// operazioni
	void clear();
	Node<T>* find(const T& data) const;
	void print() const;

private:
	Node<T>* _head;
	int _numItems;
};


#include "List.cpp"

#endif // NODE_H
