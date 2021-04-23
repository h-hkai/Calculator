#include "String.h"

String::String() { this->str = ""; }
String::String(std::string s) { this->str = s; }

String::~String() {}

std::ostream &operator<<(std::ostream &os, const String &s) {
	os << s.str << std::endl;
	return os;
}

std::istream &operator>>(std::istream &is, String &s) {
	is >> s.str;
	return is;
}

void String::swap(String &s) {
	std::string temp = s.str;
	s.str = this->str;
	this->str = temp;
}

void String::reverse() {
	std::string s1 = this->str;
	std::string s2 = "";
	for (int i = s1.length() - 1; i >= 0; --i) {
		s2 += s1[i];
	}
	this->str = s2;
}

int String::length() { return this->str.length(); }

String String::substr(int begin, int len) {
	String temp;
	int index = begin;
	while (len > 0) {
		temp.str += this->str[index];
		len--;
		index++;
	}
	return temp;
}

String String::substr(int begin) {
	String temp;
	for (int i = begin; i < this->str.length(); ++i) temp.str += this->str[i];
	return temp;
}

bool String::operator>(String s) {
	std::string s1 = this->str;
	std::string s2 = s.str;
	for (int i = 0; i < s1.length(); ++i) {
		if (s1[i] != '0')
			return true;
	}
	return false;
}

bool String::operator>=(String s) {
	std::string s1 = this->str;
	std::string s2 = s.str;
	if (s1 == s2)
		return true;
	if (s1.length() > s2.length())
		return true;
	else if (s1.length() == s2.length()) {
		for (int i = 0; i < s1.length(); ++i) {
			if (s1[i] > s2[i])
				return true;
			else if (s1[i] < s2[i])
				return false;
		}
	}
	return false;
}

String &String::operator=(std::string s) {
	this->str = s;
	return *this;
}

char &String::operator[](unsigned int x) {
	return this->str[x];
}

bool String::operator<(String s) {
	std::string s1 = this->str;
	std::string s2 = s.str;
	if (s1.length() < s2.length())
		return true;
	else if (s1.length() == s2.length()) {
		for (int i = 0; i < s1.length(); ++i) {
			if (s1[i] < s2[i])
				return true;
			else if (s1[i] > s2[i])
				return false;
		}
	}
	return false;
}

bool String::operator<=(String s) {
	std::string s1 = this->str;
	std::string s2 = s.str;
	if (s1 == s2)
		return true;
	if (s1.length() < s2.length())
		return true;
	else if (s1.length() == s2.length()) {
		for (int i = 0; i < s1.length(); ++i) {
			if (s1[i] < s2[i])
				return true;
			else if (s1[i] > s2[i])
				return false;
		}
	}
	return false;
}

bool String::operator==(String s) {
	for (int i = 0; i < this->str.length(); ++i)
		if (this->str[i] != '0') return false;
	return true;
}

String String::operator+(std::string s) {
	String temp;
	temp.str = this->str + s;
	return temp;
}

String String::operator+(String s) {
	String temp;
	temp.str = this->str + s.str;
	return temp;
}

void String::operator+=(std::string s) {
	this->str = this->str + s;
}

void String::operator+=(String s) {
	this->str = this->str + s.str;
}

void String::operator+=(int x) {
	this->str = this->str + std::to_string(x);
}

void String::lstrip() {
	std::string s = this->str;
	int i;
	for (i = 0; i < s.length(); ++i) {
		if (s[i] != '0')
			break;
	}
	if (i == s.length())
		this->str = "0";
	else
		this->str = s.substr(i);
}
void String::addSign() {
	this->str = "-" + this->str;
}
