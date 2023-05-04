#include "mystring.h"
#include <stdio.h>

int main() {
	mystring s = "holle ";
	mystring ss = "worle";
	ss = s + ss;
	cout << s.size() << endl << ss;
	return 0;
}