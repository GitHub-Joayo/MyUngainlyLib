#pragma once

#include "Main.h"

template <class T>
class Node {

private:
	T data;
	Node<T> *nextNode;

public:
	Node(T data = 0, Node<T> *next = nullptr);
	void InputData(T data, Node *next);
	void SetData(T data);
	void SetNext(Node<T> *next);
	T GetData() const;
	Node<T> * GetNext() const;
	void ShowData() const;
	~Node();

};

template <class T>
class Stack : public Node<T> {

private:
	Node<T> *head;
	Node<T> *dummyNode;
	int length;

public:
	Stack();
	void SInput(T data);
	T SPeek() const;
	T SPop();
	bool IsEmpty() const;
	int SGetLen() const;
	~Stack();

};