//
// Created by Rainbow on 2021/4/11.
//

#include "EvaluateExpression.h"


EvaluateExpression::EvaluateExpression() {
	this->initMap();
}

EvaluateExpression::~EvaluateExpression() {
	//dtor
}

void EvaluateExpression::proccess() {
	std::cout << "请输入一个表达式: " << std::endl;
	std::cin >> this->input;
	char t = '#';
	this->OPTR.push(t);
	int len = this->input.length();
	// 如果输入的表达式没有=，则自动添加
	if (this->input[len-1] != '=') {
		this->input += "=";
		len += 1;
	}
	String temp;
	for (int i = 0; i < len; ++i) {
		if (this->input[i] == '=') {
			if (temp.length() > 0) {
				BigInt num(temp);
				this->OPND.push(num);
			}
			this->calculate('#');
			break;
		}
		if (!this->isOPTR(this->input[i])) {
			temp += std::to_string(this->input[i] - '0');
		}
		else {
			if (temp.length() > 0) {
				BigInt num(temp);
				this->OPND.push(num);
				temp = "";
			}
			this->calculate(this->input[i]);
		}
	}
	std::cout << this->OPND.getTop() << std::endl;
}

void EvaluateExpression::calculate(char c) {
	char temp = this->OPTR.getTop();
	if (c == '(') {
		this->OPTR.push(c);
		return;
	}
	while (EvaluateExpression::priority[temp] >= EvaluateExpression::priority[c]) {
		if (temp == '#' && c == '#') break;
		if (temp == '(' && c == ')') {
			this->OPTR.pop();
			return;
		}
		BigInt num1 = this->OPND.getTop();
		this->OPND.pop();
		BigInt num2 = this->OPND.getTop();
		this->OPND.pop();
		BigInt num3;
		switch (temp) {
			case '+':
				num3 = num2 + num1;
				break;
			case '-':
				num3 = num2 - num1;
				break;
			case '*':
				num3 = num2 * num1;
				break;
			case '/':
				num3 = num2 / num1;
				break;
		}
		this->OPND.push(num3);
		this->OPTR.pop();
		temp = this->OPTR.getTop();
	}
	this->OPTR.push(c);
}

bool EvaluateExpression::isOPTR(char c) {
	if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}
void EvaluateExpression::initMap() {
	this->priority['#'] = 0;
	this->priority['('] = 1;
	this->priority[')'] = 1;
	this->priority['+'] = 2;
	this->priority['-'] = 2;
	this->priority['*'] = 3;
	this->priority['/'] = 3;
}