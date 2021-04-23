#ifndef STRING_H
#define STRING_H

#include <string>
#include <iostream>

class String {
private:
    std::string str;

public:
    friend class BigInt;
    String();
	String(std::string s);
    ~String();
    void swap(String& s);
    void reverse();
    int length();
    String substr(int begin, int len);
    String substr(int begin);
    String operator+(std::string s);
	String operator+(String s);
    void operator+=(std::string s);
	void operator+=(String s);
	void operator+=(int x);
    bool operator>(String s);
    bool operator>=(String s);
    bool operator<(String s);
	bool operator<=(String s);
    bool operator==(String s);
    String& operator=(std::string s);
    char& operator[](unsigned int x);
    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);
	void lstrip();
	void addSign();
};

#endif
