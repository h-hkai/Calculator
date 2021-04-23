//
// Created by Rainbow on 2021/4/11.
//

template<typename T>
Stack<T>::Stack() {
	//this->base = (T *)malloc(STACK_INIT_SIZE * sizeof(T));
	this->base = new T[STACK_INIT_SIZE];
	if (!this->base) {
		std::cout << "内存分配失败！" << std::endl;
		return;
	}
	this->top = this->base;
	this->stacksize = STACK_INIT_SIZE;
}

template<typename T>
Stack<T>::~Stack() {
	//std::cout << "执行析构函数！" << std::endl;
	free(this->base);
	this->base = nullptr;
	this->top = nullptr;
	this->stacksize = 0;
}

template<typename T>
void Stack<T>::push(T &x) {
	if (this->top - this->base >= this->stacksize) {
		//this->base = (T *)malloc((this->stacksize + STACKINCREMENT) * sizeof(T));
		this->base = new T[this->stacksize + STACKINCREMENT];
		if (!this->base) {
			std::cout << "内存分配失败！" << std::endl;
			return;
		}
		this->top = this->base + this->stacksize;
		this->stacksize += STACKINCREMENT;
	}
	*this->top = x;
	++this->top;
}

template<typename T>
void Stack<T>::pop() {
	if (this->base == this->top) {
		std::cout << "栈已空，调用失败！" << std::endl;
		return;
	}
	--this->top;
}

template<typename T>
T Stack<T>::getTop() {
	if (this->base == this->top) {
		std::cout << "栈已空，调用失败！";
		exit(0);
	}
	T temp = *(this->top - 1);
	return temp;
}

template<typename T>
bool Stack<T>::isEmpty() {
	if (this->base == this->top) return true;
	return false;
}
