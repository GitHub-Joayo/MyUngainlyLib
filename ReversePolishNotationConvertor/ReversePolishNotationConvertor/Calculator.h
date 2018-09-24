#pragma once

#include "ConvertorReversePolishNotation.h"

class Calculator : public ConvToRev {

private :
	int result;

public :
	Calculator();
	void Calculate(const string &str);
	char OpPlus(char d1, char d2);
	char OpMinus(char d1, char d2);
	char OpMul(char d1, char d2);
	char OpDiv(char d1, char d2);
	int AsciiToInt(char ch);
	char IntToAscii(int inte);
	int PrintResult() const;

};