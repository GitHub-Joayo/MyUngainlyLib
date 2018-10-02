#pragma once

#include "Main.h"

template <class T>
class Data {

private :
	T data;

public :
	Data(T data = 0);
	void SetData(T data);
	T GetData() const;

};


template <class T>
class HeapAppliedArray : public Data<T> {

private :
	Data<T> *arrTree;
	int numOfData;
	bool aOrD;

public :
	HeapAppliedArray(int length = 101);
	void AddData(Data<T> data);
	T DeleteData();
	int GetParentsIdx(int idx) const;
	int GetLeftChiIdx(int idx) const;
	int GetRightChiIdx(int idx) const;
	int GetHiPriChiIdx(int idx) const;
	bool WhosFirst(T d1, T d2) const;
	bool IsItEmpty() const;
	void GetData();
	~HeapAppliedArray();

};