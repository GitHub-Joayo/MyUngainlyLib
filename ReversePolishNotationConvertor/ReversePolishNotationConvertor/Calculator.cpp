#include "Calculator.h"

Calculator::Calculator() : result(0) {}

void Calculator::Calculate(const string &str) {

	Stack stack = Stack();

	InputOrigin(str);
	Convert();

	string tmp = OutputConvString();

	for (int i = 0; i < (tmp.length() + 1); i++) {

		if (isdigit(tmp[i])) {

			stack.SInput(tmp[i]);

		}
		else {

			switch (tmp[i]) {
			case '+' :
				stack.SInput(OpPlus(stack.SPop(), stack.SPop()));
				break;

			case '-' :
				stack.SInput(OpMinus(stack.SPop(), stack.SPop()));
				break;

			case '*' :
				stack.SInput(OpMul(stack.SPop(), stack.SPop()));
				break;

			case '/' :
				stack.SInput(OpDiv(stack.SPop(), stack.SPop()));
				break;

			default :
				break;

			}

		}

	}
	
	result = AsciiToInt(stack.SPop());

}

char Calculator::OpPlus(char op1, char op2) {

	int iop1 = AsciiToInt(op1);
	int iop2 = AsciiToInt(op2);

	return IntToAscii(iop1 + iop2);

}

char Calculator::OpMinus(char op1, char op2) {

	int iop1 = AsciiToInt(op1);
	int iop2 = AsciiToInt(op2);

	return IntToAscii(iop1 - iop2);

}

char Calculator::OpMul(char op1, char op2) {

	int iop1 = AsciiToInt(op1);
	int iop2 = AsciiToInt(op2);

	return IntToAscii(iop1 * iop2);

}

char Calculator::OpDiv(char op1, char op2) {

	int iop1 = AsciiToInt(op1);
	int iop2 = AsciiToInt(op2);

	return IntToAscii(iop1 / iop2);

}

int Calculator::AsciiToInt(char ch) {

	return ch - '0';

}

char Calculator::IntToAscii(int in) {

	return in + '0';

}

int Calculator::PrintResult() const {

	return result;

}