#include "Main.h"
#include "LinkedListDummyNode.h"
#include "LinkedListDummyNode.cpp"
#include "DoublyLinkedListDummyNode.h"
#include "DoublyLinkedListDummyNode.cpp"

int main(void) {

	/* Linked List test
	LinkedList<int> test;

	test.SortedAdd(1);
	test.SortedAdd(1);
	test.SortedAdd(1);

	test.ShowAllData();

	test.SearchData();

	test.RemoveData();

	test.ShowAllData();
	*/

	/**/
	DoublyLinkedList<int> tmp;

	tmp.SortAddData(1);
	tmp.SortAddData(1);
	tmp.SortAddData(1);
	tmp.SortAddData(1);

	tmp.ShowAllData();
	

	system("pause");

	return 0;

}