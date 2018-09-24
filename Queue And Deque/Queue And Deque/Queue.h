#pragma once

#include "Main.h"

template <class T>
class Queue : public DNode<T> {

private:
	DNode<T> *front;
	DNode<T> *rear;
	DNode<T> *frontDumNode;
	DNode<T> *rearDumNode;
	int length;

public:
	Queue();
	void EnQue();
	T SearchData();
	T DeQue();
	bool IsEmpty() const;
	void ShowAllData() const;
	int GetLength() const;
	~Queue();

};