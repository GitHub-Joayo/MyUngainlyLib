#include "Main.h"
#include "StackAppliedLinkedList.h"
#include "StackAppliedLinkedList.cpp"

int main(void) {

	Stack<int> stack;

	cout << stack.IsEmpty() << endl;

	stack.SInput();
	stack.SInput();

	cout << stack.SPeek() << endl;

	stack.SInput();

	cout << stack.SPeek() << endl;

	cout << stack.SPop() << endl;
	cout << stack.SPop() << endl;

	cout << stack.SPeek() << endl;

	system("pause");

	return 0;

}