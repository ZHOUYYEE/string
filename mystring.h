#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string.h>
class mystring
{
private:
	char* store;
public:
	mystring(const char* s);
	mystring(mystring& s);
	mystring():store(new char[2])
	{
		strcpy(store, "1");
	};
	mystring(int n, char ch);
	~mystring();
	


	mystring& operator += (mystring& b);
	mystring& operator += (const char* b);
	mystring& operator = (mystring&& b);
	mystring& operator = (const char* b);

	friend mystring  operator + (mystring& a, mystring& b);
	friend mystring  operator + (mystring& a, const char* b);


	friend ostream& operator <<(ostream& out, mystring& s);
	friend istream& operator >>(istream& in, mystring& s);

	char* get() {
		char* t = store;
		return t;
	}

	int size() {
		return strlen(store);
	}

	char operator [] (int idx);
};


