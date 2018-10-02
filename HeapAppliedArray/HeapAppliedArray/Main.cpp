#include "Main.h"

#include "HeapAppliedArray.h"
#include "HeapAppliedArray.cpp"

int main(void) {

	HeapAppliedArray<int> test = HeapAppliedArray<int>();

	for (int i = 0; i < 5; i++) {

		int data = 0;

		cin >> data;

		Data<int> newData = Data<int>(data);

		test.AddData(newData);

	}

	cout << endl;
	test.GetData();
	cout << endl;

	for (int i = 0; i < 5; i++) {

		cout << test.DeleteData() << endl;

	}

	system("pause");
	
	return 0;

}