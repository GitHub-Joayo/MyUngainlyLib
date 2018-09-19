#include "StackAppliedLinkedList.h"

template <class T>
Node<T>::Node(T data, Node<T> *next) : data(data), nextNode(next) {}

template <class T>
void Node<T>::InputData(T data, Node *next) {

	this->data = data;
	this->nextNode = next;

}

template <class T>
void Node<T>::SetData(T data) {

	this->data = data;

}

template <class T>
void Node<T>::SetNext(Node<T> *next) {

	this->nextNode = next;

}

template <class T>
T Node<T>::GetData() const {

	return data;

}

template <class T>
Node<T> * Node<T>::GetNext() const {

	return nextNode;

}

template <class T>
void Node<T>::ShowData() const {

	cout << "Data : " << data << endl;

}

template <class T>
Node<T>::~Node() {}

template <class T>
Stack<T>::Stack() : length(0) {

	dummyNode = new Node<T>();
	head = dummyNode;

}

template <class T>
void Stack<T>::SInput() {

	T data;

	cout << "Input Data : ";
	cin >> data;

	Node<T> *newNode = new Node<T>(data, dummyNode->GetNext());
	dummyNode->SetNext(newNode);
	length++;

}

template <class T>
T Stack<T>::SPeek() const{

	return dummyNode->GetNext()->GetData();

}

template <class T>
T Stack<T>::SPop() {

	T data;
	Node<T> *cur = dummyNode->GetNext();

	dummyNode->SetNext(cur->GetNext());
	data = cur->GetData();
	delete cur;

	return data;

}

template <class T>
bool Stack<T>::IsEmpty() const {

	if (dummyNode->GetNext() == nullptr)
		return true;
	else
		return false;

}

template <class T>
int Stack<T>::SGetLen() const {

	return length;

}