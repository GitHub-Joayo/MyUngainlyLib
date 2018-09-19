#include "LinkedListDummyNode.h"

template <class T>
Node<T>::Node(T data, Node<T> *next) : data(data), nextNode(next) {}

template <class T>
void Node<T>::InputData(T data, Node *next) {

	this->data = data;
	this->nextNode = next;

}

template <class T>
void Node<T>::SetData(T data) {

	this->data = data;

}

template <class T>
void Node<T>::SetNext(Node<T> *next) {

	this->nextNode = next;

}

template <class T>
T Node<T>::GetData() const {

	return data;

}

template <class T>
Node<T> * Node<T>::GetNext() const {

	return nextNode;

}

template <class T>
void Node<T>::ShowData() const {

	cout << "Data : " << data << endl;

}

template <class T>
Node<T>::~Node() {}

template <class T>
LinkedList<T>::LinkedList() : length(0) {

	dummyNode = new Node<T>();

	head = dummyNode;
	cur = dummyNode;

}

template <class T>
void LinkedList<T>::AddData() {

	T inputData;
	Node<T> *tmp;

	cout << "Input Data : ";
	cin >> inputData;

	tmp = new Node<T>(inputData, dummyNode->GetNext());

	dummyNode->SetNext(tmp);

	length++;

}

template <class T>
void LinkedList<T>::SortedAdd(bool aOrD) { // true is ascending, false is descending

	T inputData;
	Node<T> *tmp;
	Node<T> *before = dummyNode;

	cout << "Input Data : ";
	cin >> inputData;

	cur = dummyNode->GetNext();

	while (cur != nullptr && WhosFirst(cur->GetData(), inputData, aOrD)) {

		before = cur;
		cur = cur->GetNext();

	}

	tmp = new Node<T>(inputData, cur);
	before->SetNext(tmp);
	length++;

}

template <class T>
T LinkedList<T>::SearchData() {

	T searchData;

	cout << "Input Data to Search : ";
	cin >> searchData;

	cur = dummyNode->GetNext();

	 do {

		if (cur->GetData() == searchData)
			return cur->GetData();
			
		cur = cur->GetNext();

	} while (cur != nullptr);

	return 0;

}

template <class T>
bool LinkedList<T>::RemoveData() {

	T exist = SearchData();

	if (exist == 0) {

		cout << "Not Exist Same Data" << endl;
		return false;

	}
	else {

		Node<T> *before;

		before = dummyNode;
		cur = dummyNode->GetNext();

		do {

			if (cur->GetData() == exist) {

				before->SetNext(cur->GetNext());
				delete cur;
				cur = before;
				length--;

				return true;

			}

			before = cur;
			cur = cur->GetNext();

		} while (cur != nullptr);

	}

	return false;

}

template <class T>
void LinkedList<T>::ShowAllData() {

	int cnt = 1;

	cur = dummyNode;

	do {

		cur = cur->GetNext();
		cout << cnt++ << ". " << cur->GetData() << endl;

	} while (cur->GetNext() != nullptr);

}

template <class T>
int LinkedList<T>::GetLength() const {

	return length;

}

template <class T>
bool LinkedList<T>::WhosFirst(T d1, T d2, bool aOrD) const { // Apply to sorted Add

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
LinkedList<T>::~LinkedList() {

	Node<T> *rNode = dummyNode->GetNext();

	cur = rNode;

	do {

		cur = cur->GetNext();
		delete rNode;
		rNode = cur;

	} while (cur != nullptr);

	delete dummyNode;

}