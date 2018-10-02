#include "HeapAppliedArray.h"

template <class T>
Data<T>::Data(T data) : data(data) {}

template <class T>
void Data<T>::SetData(T data) {

	this->data = data;

}

template <class T>
T Data<T>::GetData() const {

	return data;

}

template <class T>
HeapAppliedArray<T>::HeapAppliedArray(int length) : numOfData(0) {

	int tmp = 0;

	cout << "1. Ascending" << endl << "2. Descending" << endl << "Input Number : ";
	cin >> tmp;

	while (tmp != 1 && tmp != 2) {

		cout << "Input Correct Value : ";
		cin >> tmp;

	}

	aOrD = (tmp == 1) ? true : false;

	arrTree = new Data<T>[length];

}

template <class T>
void HeapAppliedArray<T>::AddData(Data<T> data) {
	
	Data<T> tmpData;
	int tmpIdx = numOfData + 1;

	while (tmpIdx != 1) {

		if (WhosFirst(data.GetData(), arrTree[GetParentsIdx(tmpIdx)].GetData())) {
			
			arrTree[tmpIdx] = arrTree[GetParentsIdx(tmpIdx)];
			tmpIdx = GetParentsIdx(tmpIdx);

		}
		else
			break;

	}

	arrTree[tmpIdx] = data;

	numOfData++;

}

template <class T>
T HeapAppliedArray<T>::DeleteData() {

	T tmpData = arrTree[1].GetData();
	Data<T> lastElem = arrTree[numOfData];
	int parentIdx = 1;
	int childIdx = 0;

	while (childIdx = GetHiPriChiIdx(parentIdx)) {

		if (WhosFirst(lastElem.GetData(), arrTree[childIdx].GetData()))
			break;

		arrTree[parentIdx] = arrTree[GetHiPriChiIdx(parentIdx)];
		parentIdx = GetHiPriChiIdx(parentIdx);

	} 

	arrTree[parentIdx] = lastElem;
	numOfData--;

	return tmpData;

}

template <class T>
int HeapAppliedArray<T>::GetParentsIdx(int idx) const {

	return idx / 2;

}

template <class T>
int HeapAppliedArray<T>::GetLeftChiIdx(int idx) const {

	return idx * 2;

}

template <class T>
int HeapAppliedArray<T>::GetRightChiIdx(int idx) const {

	return idx * 2 + 1;

}

template <class T>
int HeapAppliedArray<T>::GetHiPriChiIdx(int idx) const {

	if (GetLeftChiIdx(idx) > numOfData)
		return 0;
	else if (arrTree[GetLeftChiIdx(idx)].GetData() == arrTree[GetRightChiIdx(idx)].GetData())
		return GetLeftChiIdx(idx);

	if (aOrD) {

		if (arrTree[GetLeftChiIdx(idx)].GetData() < arrTree[GetRightChiIdx(idx)].GetData())
			return GetLeftChiIdx(idx);
		else
			return GetRightChiIdx(idx);

	}
	else {

		if (arrTree[GetLeftChiIdx(idx)].GetData() > arrTree[GetRightChiIdx(idx)].GetData())
			return GetLeftChiIdx(idx);
		else
			return GetRightChiIdx(idx);

	}

}

template <class T>
bool HeapAppliedArray<T>::WhosFirst(T d1, T d2) const {

	if (aOrD)
		return (d1 < d2) ? true : false;
	else
		return (d1 < d2) ? false : true;

}

template <class T>
bool HeapAppliedArray<T>::IsItEmpty() const {

	if (numOfData == 0)
		return true;
	else
		return false;

}

template <class T>
HeapAppliedArray<T>::~HeapAppliedArray() {

	delete[] arrTree;

}

template <class T>
void HeapAppliedArray<T>::GetData() {

	for (int i = 1; i < numOfData + 1; i++)
		cout << arrTree[i].GetData() << endl;

}