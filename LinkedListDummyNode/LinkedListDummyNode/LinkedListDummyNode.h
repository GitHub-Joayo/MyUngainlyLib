#pragma once

#include "Main.h"

template <class T>
class Node {

private :
	T data;
	Node<T> *nextNode;

public :
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
class LinkedList : public Node<T> {

private :
	Node<T> *head;
	Node<T> *cur;
	Node<T> *dummyNode;
	int length;

public :
	LinkedList();
	void AddData();
	void SortedAdd(bool aOrD);
	T SearchData();
	bool RemoveData();
	void ShowAllData();
	int GetLength() const;
	bool WhosFirst(T d1, T d2, bool aOrD) const;
	~LinkedList();

};