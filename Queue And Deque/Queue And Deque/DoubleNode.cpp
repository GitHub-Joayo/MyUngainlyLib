#include "DoubleNode.h"

template <class T>
DNode<T>::DNode(T data, DNode<T> *pre, DNode<T> *next) : data(data), previous(pre), next(next) {}

template <class T>
void DNode<T>::InputDNode(T data, DNode<T> *pre, DNode<T> *next) {

	this->data = data;
	this->previous = pre;
	this->next = next;

}

template <class T>
void DNode<T>::SetData(T data) {

	this->data = data;

}

template <class T>
void DNode<T>::SetPre(DNode<T> *pre) {

	this->previous = pre;

}

template <class T>
void DNode<T>::SetNext(DNode<T> *next) {

	this->next = next;

}

template <class T>
T DNode<T>::GetData() const {

	return data;

}

template <class T>
DNode<T> *DNode<T>::GetPre() const {

	return previous;

}

template <class T>
DNode<T> *DNode<T>::GetNext() const {

	return next;

}

template <class T>
DNode<T>::~DNode() {}
