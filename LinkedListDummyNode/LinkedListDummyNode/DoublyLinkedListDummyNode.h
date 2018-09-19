#pragma once

#include "Main.h"

template <class T>
class DNode {

private :
	DNode<T> *previous;
	T data;
	DNode<T> *next;

public :
	DNode(T data = 0, DNode<T> *pre = nullptr, DNode<T> *next = nullptr);
	void InputDNode(T data, DNode<T> *pre, DNode<T> *next);
	void SetData(T data);
	void SetPre(DNode<T> *pre);
	void SetNext(DNode<T> *next);
	T GetData() const;
	DNode<T> * GetPre() const;
	DNode<T> * GetNext() const;
	~DNode();

};

template <class T>
class DoublyLinkedList : public DNode<T> {

private :
	DNode<T> *head;
	DNode<T> *tail;
	DNode<T> *headDumNode;
	DNode<T> *tailDumNode;
	int length;

public :
	DoublyLinkedList();
	void AddDataHead();
	void AddDataTail();
	void SortAddData(bool aOrD);
	T SearchData();
	void RemoveData();
	void ShowAllData() const;
	int GetLength() const;
	bool WhosFirst(T d1, T d2, bool aOrD) const;
	~DoublyLinkedList();

};