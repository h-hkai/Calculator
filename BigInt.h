#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>

#include "String.h"

#define Zero String("0")
#define INF String("INF")
#define UNDEFIN String("UNDEFIN")

class BigInt {
private:
    String num;

public:
    BigInt();
    BigInt(String s);
    ~BigInt();
    int length();
    friend std::ostream &operator<<(std::ostream &os, const BigInt &n);
    friend std::istream &operator>>(std::istream &is, BigInt &n);
    BigInt operator+(BigInt n);
    BigInt operator-(BigInt n);
    BigInt operator*(BigInt n);
    String operator*(int n);
    BigInt operator/(BigInt n);
	BigInt operator%(BigInt n);
};

#endif
