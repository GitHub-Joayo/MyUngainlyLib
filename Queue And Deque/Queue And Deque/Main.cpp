#include "Main.h"
#include "Queue.h"
#include "Queue.cpp"
#include "Deque.h"
#include "Deque.cpp"

int main(void) {

	Deque<int> test = Deque<int>();

	test.AddDataFront();
	test.AddDataFront();
	test.AddDataFront();

	test.AddDataRear();
	test.AddDataRear();
	test.AddDataRear();

	test.ShowAllData();

	cout << test.PopDataFront();
	cout << test.PopDataFront() << endl;

	cout << test.PopDataRear();
	cout << test.PopDataRear() << endl;

	test.ShowAllData();

	system("pause");

	return 0;

}