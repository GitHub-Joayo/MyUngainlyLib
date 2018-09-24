#pragma once

template <class T>
class DNode {

private:
	DNode<T> *previous;
	T data;
	DNode<T> *next;

public:
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