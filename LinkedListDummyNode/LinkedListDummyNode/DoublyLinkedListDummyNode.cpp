#include "DoublyLinkedListDummyNode.h"

template <class T>
DNode<T>::DNode(T data, DNode<T> *pre, DNode<T> *next) : data(data), previous(pre), next(next) {}

template <class T>
void DNode<T>::InputDNode(T data, DNode<T> *pre, DNode<T> *next) {

	this->data = data;
	this->previous = pre;
	this->next = next;

}

template <class T>
void DNode<T>::SetData(T data) {

	this->data = data;

}

template <class T>
void DNode<T>::SetPre(DNode<T> *pre) {

	this->previous = pre;

}

template <class T>
void DNode<T>::SetNext(DNode<T> *next) {

	this->next = next;

}

template <class T>
T DNode<T>::GetData() const{

	return data;

}

template <class T>
DNode<T> *DNode<T>::GetPre() const {

	return previous;

}

template <class T>
DNode<T> *DNode<T>::GetNext() const {

	return next;

}

template <class T>
DNode<T>::~DNode() {}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : length(0) {
	
	headDumNode = new DNode<T>();
	tailDumNode = new DNode<T>(0, headDumNode, nullptr);

	headDumNode->SetPre(nullptr);
	headDumNode->SetNext(tailDumNode);

	head = headDumNode;
	tail = tailDumNode;

}

template <class T>
void DoublyLinkedList<T>::AddDataHead() {

	T data;

	cout << "Input Data : ";
	cin >> data;

	DNode<T> *newNode = new DNode<T>(data, head, head->GetNext());

	head->GetNext()->SetPre(newNode);
	head->SetNext(newNode);

	length++;

}

template <class T>
void DoublyLinkedList<T>::AddDataTail() {

	T data;

	cout << "Input Data : ";
	cin >> data;

	DNode<T> *newNode = new DNode<T>(data, tail->GetPre(), tail);

	tail->GetPre()->SetNext(newNode);
	tail->SetPre(newNode);

	length++;

}

template <class T>
void DoublyLinkedList<T>::SortAddData(bool aOrD) { // true is ascending, false is descending

	T data;
	DNode<T> *newNode;
	DNode<T> *cur = head->GetNext();

	cout << "Input Data : ";
	cin >> data;

	while (cur->GetNext() != nullptr && WhosFirst(cur->GetData(), data, aOrD)) {

		cur = cur->GetNext();

	}

	newNode = new DNode<T>(data, cur->GetPre(), cur);
	cur->GetPre()->SetNext(newNode);
	cur->SetPre(newNode);

	length++;

}

template <class T>
T DoublyLinkedList<T>::SearchData() {

	T data;
	DNode<T> *cur = head->GetNext();

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
void DoublyLinkedList<T>::RemoveData() {

	T exist = SearchData();
	DNode<T> *cur = head->GetNext();

	if (exist == -1) {

		cout << "Not exist Same Data" << endl;
		return;

	}
	else {

		while (cur->GetNext() != nullptr) {

			if (cur->GetData() == exist) {

				cur->GetPre()->SetNext(cur->GetNext());
				cur->GetNext()->SetPre(cur->GetPre());

				delete cur;
				length--;

				break;

			}

			cur = cur->GetNext();

		}

	}

}

template <class T>
void DoublyLinkedList<T>::ShowAllData() const {

 	int cnt = 1;
	DNode<T> *cur = head->GetNext();

	while (cur->GetNext() != nullptr) {

		cout << cnt++ << ". " << cur->GetData() << endl;
		cur = cur->GetNext();

	}

}

template <class T>
int DoublyLinkedList<T>::GetLength() const {

	return length;

}

template <class T>
bool DoublyLinkedList<T>::WhosFirst(T d1, T d2, bool aOrD) const {

	if (aOrD == true) {

		if (d1 > d2)
			return false;
		else
			return true;

	}
	else {

		if (d1 > d2)
			return true;
		else
			return false;

	}

}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {

	DNode<T> *rNode = head->GetNext();
	DNode<T> *cur = rNode->GetNext();

	if (length == 0) {

		delete head, tail;

	}
	else {

		while (cur != nullptr) {

			cur = cur->GetNext();
			delete rNode;
			rNode = cur;

		}

		delete head;


	}
	
}