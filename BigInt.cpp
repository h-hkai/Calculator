#include "BigInt.h"

#include <iostream>

BigInt::BigInt() { this->num = ""; }

BigInt::BigInt(String s) { this->num = s.str; }

BigInt::~BigInt() {}

int BigInt::length() { return this->num.length(); }

std::ostream &operator<<(std::ostream &os, const BigInt &n) {
	os << n.num << std::endl;
	return os;
}

std::istream &operator>>(std::istream &is, BigInt &n) {
	is >> n.num;
	return is;
}

BigInt BigInt::operator+(BigInt n) {
	BigInt ans;
	String s1, s2;
	s1 = this->num;
	s2 = n.num;
	s1.reverse();
	s2.reverse();
	int i = 0, carry = 0;
	int n1, n2, sum;
	if (s1.length() < s2.length()) {
		s1.swap(s2);
	}
	while (i < s2.length()) {
		n1 = s1[i] - '0';
		n2 = s2[i] - '0';
		sum = n1 + n2 + carry;
		carry = sum / 10;
		s1[i++] = sum % 10 + '0';
	}
	while (i < s1.length()) {
		n1 = s1[i] - '0';
		sum = n1 + carry;
		carry = sum / 10;
		s1[i++] = sum % 10 + '0';
	}
	if (carry > 0) {
		s1 = s1 + "1";
	}
	s1.reverse();
	ans.num = s1;
	return ans;
}

BigInt BigInt::operator-(BigInt n) {
	BigInt ans;
	String s1, s2;
	s1 = this->num;
	s2 = n.num;
	bool isNegative = false;
	if (s1 < s2) {
		isNegative = true;
		s1.swap(s2);
	}
	s1.reverse();
	s2.reverse();
	int i = 0, borrow = 0;
	int n1, n2, sub;
	while (i < s2.length()) {
		n1 = s1[i] - '0' - borrow;
		n2 = s2[i] - '0';
		if (n1 - n2 < 0) {
			n1 += 10;
			borrow = 1;
		} else {
			borrow = 0;
		}
		sub = n1 - n2;
		s1[i++] = sub + '0';
	}
	while (i < s1.length()) {
		n1 = s1[i] - '0' - borrow;
		if (n1 < 0)
			n1 = 9, borrow = 1;
		else
			borrow = 0;
		s1[i++] = n1 + '0';
	}
	if (s1[i - 1] == '0') {
		s1 = s1.substr(0, s1.length() - 1);
	}
	s1.reverse();
	s1.lstrip();
	if (isNegative)
		s1.addSign();
	ans.num = s1;
	return ans;
}

BigInt BigInt::operator*(BigInt n) {
	BigInt ans;
	String s1, s2;
	s1 = this->num;
	s2 = n.num;
	s1.reverse();
	s2.reverse();
	int carry;
	int n1, n2, mul;
	for (int i = 0; i < s1.length(); ++i) {
		n1 = s1[i] - '0';
		String stemp;
		carry = 0;
		for (int j = 0; j < s2.length(); ++j) {
			n2 = s2[j] - '0';
			mul = n1 * n2 + carry;
			carry = mul / 10;
			stemp.str += mul % 10 + '0';
		}
		if (carry > 0) {
			stemp.str += carry + '0';
		}
		stemp.reverse();
		// 在所得结果后面进行补0
		for (int k = 0; k < i; ++k) {
			stemp = stemp + "0";
		}
		BigInt temp(stemp);
		ans = ans + temp;
	}
	ans.num.lstrip();
	return ans;
}

String BigInt::operator*(int n) {
	String s;
	String ans;
	s = this->num;
	s.reverse();
	int t, mul, carry = 0;
	for (int i = 0; i < s.length(); ++i) {
		t = s[i] - '0';
		mul = t * n + carry;
		carry = mul / 10;
		ans += (mul % 10);
	}
	if (carry > 0)
		ans += carry;
	ans.reverse();
	return ans;
}

BigInt BigInt::operator/(BigInt n) {
	if (n.num == Zero)
		return BigInt(INF);
	// 除数
	String s1 = n.num;
	// 被除数
	String s2 = this->num;
	// 用来截取被除数的前一部分

	String s3;
	String ans;
	BigInt remainder;
	int i, j;
	while (s1 <= s2) {
		for (i = 1; i <= s2.length(); ++i) {
			s3 = s2.substr(0, i);
			if (s3 >= s1)
				break;
		}
		int len1 = s3.length();
		int len2 = remainder.length();
		if (len2 > 0) {
			for (int k = len2 + 1; k < len1; ++k)
				ans += 0;
		}
		String temp;
		for (j = 9; j >= 1; --j) {
			temp = n * j;
			if (temp <= s3)
				break;
		}
		ans += j;
		BigInt b1(s3);
		BigInt b2(temp);
		remainder = b1 - b2;
		if (remainder.num > Zero)
			s2 = remainder.num + s2.substr(i);
		else if (s2.substr(i) > Zero)
			s2 = s2.substr(i);
		else {
			s2 = s2.substr(i);
			ans += s2;
			break;
		}
	}
	int len1 = s2.length();
	int len2 = remainder.length();
	for (i = len2; i < len1; ++i) ans += 0;
	ans.lstrip();
	return BigInt(ans);
}
BigInt BigInt::operator%(BigInt n) {
	if (n.num == Zero)
		return BigInt(UNDEFIN);
	String s1 = n.num;
	String s2 = this->num;
	String s3;
	String ans;
	BigInt remainder;
	int i, j;
	while (s1 <= s2) {
		for (i = 1; i <= s2.length(); ++i) {
			s3 = s2.substr(0, i);
			if (s3 >= s1)
				break;
		}
		int len1 = s3.length();
		int len2 = remainder.length();
		if (len2 > 0) {
			for (int k = len2 + 1; k < len1; ++k)
				ans += 0;
		}
		String temp;
		for (j = 9; j >= 1; --j) {
			temp = n * j;
			if (temp <= s3)
				break;
		}
		ans += j;
		BigInt b1(s3);
		BigInt b2(temp);
		remainder = b1 - b2;
		if (remainder.num > Zero)
			s2 = remainder.num + s2.substr(i);
		else if (s2.substr(i) > Zero)
			s2 = s2.substr(i);
		else {
			s2 = s2.substr(i);
			ans += s2;
			break;
		}
	}
	s2.lstrip();
	return BigInt(s2);
}
