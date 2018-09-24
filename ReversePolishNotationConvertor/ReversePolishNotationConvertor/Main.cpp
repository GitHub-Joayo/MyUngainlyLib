#include "Main.h"

#include "Calculator.h"

int main(void) {

	Calculator cal = Calculator();

	cal.Calculate("4 / (7 + 1 * 4)");
	cout << cal.OutputConvString() << endl;

	cout << cal.PrintResult() << endl;

	system("pause");

	return 0;

}