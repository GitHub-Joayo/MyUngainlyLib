#include "ConvertorReversePolishNotation.h"

ConvToRev::ConvToRev() : ori(string()), out(string()) {}

void ConvToRev::InputOrigin(const string &ori) {

	this->ori = ori;

}

void ConvToRev::Convert() {

	Stack tmp = Stack();

	for (int i = 0; i < ori.length() + 1; i++) {

		if (isdigit(ori[i])) {
			
			out += ori[i];

		}
		else {

			if (ori[i] != ' ') {

				switch (ori[i]) {

				case '(' :
					tmp.SInput(ori[i]);
					break;

				case ')' :
					while (tmp.SPeek() != '(') {

						out += tmp.SPop();

					}
					tmp.SPop();
					break;

				case '+' : case '-' :
				case '*' : case '/' :
					while (!tmp.IsEmpty() && WhatIsFirst(tmp.SPeek(), ori[i]) >= 0) {

						out += tmp.SPop();

					}
					tmp.SInput(ori[i]);
					break;

				}

			}

		}

	}

	while (!tmp.IsEmpty()) {

		out += tmp.SPop();

	}

}

int ConvToRev::RtPriority(char op) const {

	switch (op) {

	case '(' :
		return 0;

	case '+' :
	case '-' :
		return 1;

	case '*' :
	case '/' :
		return 2;

	default :
		return -1;

	}

}

int ConvToRev::WhatIsFirst(char op1, char op2) {

	int op1Prec = RtPriority(op1);
	int op2Prec = RtPriority(op2);

	return op1Prec > op2Prec ? 1 : op1Prec < op2Prec ? -1 : 0;

}

string ConvToRev::OutPutOriString() const {

	return ori;

}

string ConvToRev::OutputConvString() const {

	return out;

}