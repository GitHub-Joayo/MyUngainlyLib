#pragma once

#include "Main.h"

template <class T>
class Deque : public DNode<T> {

private:
	DNode<T> *front;
	DNode<T> *rear;
	DNode<T> *frontDumNode;
	DNode<T> *rearDumNode;
	int length;

public:
	Deque();
	void AddDataFront();
	void AddDataRear();
	T SearchData();
	T PopDataFront();
	T PopDataRear();
	void ShowAllData() const;
	int GetLength() const;
	~Deque();

};