#pragma once

#include "Main.h"
#include "Stack.h"
#include "Stack.cpp"

class ConvToRev : public Stack<char> {

private :
	string ori;
	string out;

public :
	ConvToRev();
	void InputOrigin(const string &ori);
	void Convert();
	int RtPriority(char op) const;
	int WhatIsFirst(char op1, char op2);
	string OutPutOriString() const;
	string OutputConvString() const;

};