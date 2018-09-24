#include "Deque.h"

template <class T>
Deque<T>::Deque() : length(0) {

	frontDumNode = new DNode<T>();
	rearDumNode = new DNode<T>(0, frontDumNode, nullptr);

	frontDumNode->SetPre(nullptr);
	frontDumNode->SetNext(rearDumNode);

	front = frontDumNode;
	rear = rearDumNode;

}

template <class T>
void Deque<T>::AddDataFront() {

	T data;

	cout << "Input Data : ";
	cin >> data;

	DNode<T> *newNode = new DNode<T>(data, front, front->GetNext());

	front->GetNext()->SetPre(newNode);
	front->SetNext(newNode);

	length++;

}

template <class T>
void Deque<T>::AddDataRear() {

	T data;

	cout << "Input Data : ";
	cin >> data;

	DNode<T> *newNode = new DNode<T>(data, rear->GetPre(), rear);

	rear->GetPre()->SetNext(newNode);
	rear->SetPre(newNode);

	length++;

}

template <class T>
T Deque<T>::SearchData() {

	T data;
	DNode<T> *cur = front->GetNext();

	cout << "Input Data : ";
	cin >> data;

	while (cur->GetNext() != nullptr) {

		if (cur->GetData() == data && cur != rear)
			return cur->GetData();

		cur = cur->GetNext();

	}

	return -1;

}

template <class T>
T Deque<T>::PopDataFront() {

	T data = front->GetNext()->GetData();
	DNode<T> *tmp = front->GetNext();

	front->SetNext(tmp->GetNext());
	tmp->GetNext()->SetPre(front);

	delete tmp;

	length--;

	return data;

}

template <class T>
T Deque<T>::PopDataRear() {

	T data = rear->GetPre()->GetData();
	DNode<T> *tmp = rear->GetPre();

	rear->SetPre(tmp->GetPre());
	tmp->GetPre()->SetNext(rear);

	delete tmp;

	length--;

	return data;

}

template <class T>
void Deque<T>::ShowAllData() const {

	int cnt = 1;
	DNode<T> *cur = front->GetNext();

	while (cur->GetNext() != nullptr) {

		cout << cnt++ << ". " << cur->GetData() << endl;
		cur = cur->GetNext();

	}

}

template <class T>
int Deque<T>::GetLength() const {

	return length;

}

template <class T>
Deque<T>::~Deque() {

	DNode<T> *rNode = front->GetNext();
	DNode<T> *cur = rNode->GetNext();

	if (length == 0) {

		delete front, rear;

	}
	else {

		while (cur != nullptr) {

			cur = cur->GetNext();
			delete rNode;
			rNode = cur;

		}

		delete front;


	}

}