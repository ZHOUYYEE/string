#include "mystring.h"


mystring::mystring(int n, char ch) {
	store = new char[n + 1];
	for (int i = 0; i < n; i++) {
		store[i] = ch;
	}
	store[n] = '\0';
}


mystring::mystring(const char* s) {
	int n = strlen(s);
	store = new char[n + 1];
	strcpy(store, s);
}

mystring::~mystring() {
	if (store != NULL)
	delete[] store;
}

mystring::mystring(mystring& s) {
	int n = strlen(s.store);
	store = new char[n + 1];
	strcpy(store, s.store);
}


mystring& mystring::operator = (mystring&& b) {
	if (this == &b) {
		return *this;
	}
	if (store != NULL) {
		delete[] store;
	}
	store = new char[strlen(b.store) + 1];
	strcpy(store, b.store);
	return *this;
}



mystring& mystring::operator+= (mystring& b) {
	int n = strlen(store) + strlen(b.store);
	char* temp = store;
	store = new char[n + 1];
	strcpy(store, temp);
	strcat(store, b.store);
	if (temp != NULL) {
		delete[] temp;
	}
	return *this;
}


mystring& mystring::operator = (const char* b) {
	int n = strlen(b);
	if (store != NULL) {
		delete[] store;
	}
	store = new char[n + 1];
	strcpy(store, b);
	return *this;
}



mystring& mystring::operator += (const char* b) {
	int n = strlen(store) + strlen(b);
	char* temp = store;
	store = new char[n + 1];
	strcpy(store, temp);
	strcat(store, b);
	if (temp != NULL) {
		delete[] temp;
	}
	return *this;
}




mystring operator + (mystring& a, mystring& b) {
	mystring ans;
	int n = strlen(a.store) + strlen(b.store);
	ans.store = new char[n + 1];
	strcpy(ans.store, a.store);
	strcat(ans.store, b.store);
	return ans;
}


mystring operator + (mystring& a, const char* b) {
	mystring s;
	int n = strlen(a.store) + strlen(b);
	s.store = new char[n + 1];
	strcpy(s.store, a.store);
	strcat(s.store, b);
	return s;
}

ostream& operator <<(ostream& out, mystring& s) {
	out << s.store;
	return out;
}

istream& operator >>(istream& in, mystring& s) {
	char p[50];
	in.getline(p, 50);
	s = p;
	return in;
}


char mystring:: operator [] (int idx) {
	return store[idx];
}



