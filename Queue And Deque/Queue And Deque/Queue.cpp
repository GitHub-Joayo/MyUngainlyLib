#include "Queue.h"

template <class T>
Queue<T>::Queue() : length(0) {

	frontDumNode = new DNode<T>();
	rearDumNode = new DNode<T>(0, frontDumNode, nullptr);

	frontDumNode->SetPre(nullptr);
	frontDumNode->SetNext(rearDumNode);

	front = frontDumNode;
	rear = rearDumNode;

}

template <class T>
void Queue<T>::EnQue() {

	T data;

	cout << "Input Data : ";
	cin >> data;

	DNode<T> *newNode = new DNode<T>(data, front, front->GetNext());

	front->GetNext()->SetPre(newNode);
	front->SetNext(newNode);

	length++;

}

template <class T>
T Queue<T>::SearchData() {

	T data;
	DNode<T> *cur = front->GetNext();

	cout << "Input Data : ";
	cin >> data;

	while (cur->GetNext() != nullptr) {

		if (cur->GetData() == data && cur != tail)
			return cur->GetData();

		cur = cur->GetNext();

	}

	return -1;

}

template <class T>
T Queue<T>::DeQue() {

	T data = rear->GetPre()->GetData();
	DNode<T> *tmp = rear->GetPre();

	rear->SetPre(tmp->GetPre());
	tmp->GetPre()->SetNext(rear);

	delete tmp;

	length--;

	return data;

}

template <class T>
bool Queue<T>::IsEmpty() const {

	return front->GetNext() == rear ? true : false;

}

template <class T>
void Queue<T>::ShowAllData() const {

	int cnt = 1;
	DNode<T> *cur = front->GetNext();

	while (cur->GetNext() != nullptr) {

		cout << cnt++ << ". " << cur->GetData() << endl;
		cur = cur->GetNext();

	}

}

template <class T>
int Queue<T>::GetLength() const {

	return length;

}

template <class T>
Queue<T>::~Queue() {

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