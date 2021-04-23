//
// Created by Rainbow on 2021/4/11.
//

#ifndef CALCULATOR2_STACK_H
#define CALCULATOR2_STACK_H

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#include <iostream>
#include <stdlib.h>

template<typename T>
class Stack {
public:
	Stack();
	~Stack();
	void push(T &x);
	void pop();
	T getTop();
	bool isEmpty();

protected:
private:
	T *top; // top pointer
	T *base;//
	int stacksize;
};

#endif//CALCULATOR2_STACK_H
