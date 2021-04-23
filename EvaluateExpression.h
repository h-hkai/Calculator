//
// Created by Rainbow on 2021/4/11.
//

#ifndef CALCULATOR2_EVALUATEEXPRESSION_H
#define CALCULATOR2_EVALUATEEXPRESSION_H

#include "Stack.h"
#include "Stack.cpp"
#include "BigInt.h"
#include "String.h"

#include <map>

class EvaluateExpression {
public:
	EvaluateExpression();
	~EvaluateExpression();
	void proccess();
	void calculate(char c);
	bool isOPTR(char c);
	void initMap();

protected:
private:
	String input;
	double res;
	Stack<BigInt> OPND;
	Stack<char> OPTR;
	std::map<char, int> priority;
};

#endif//CALCULATOR2_EVALUATEEXPRESSION_H
