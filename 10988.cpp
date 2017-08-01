#include <iostream>
#include <string.h>
//#include <stdio.h>
using namespace std;

bool check(char s[]) {

	int len = strlen(s);
	for (int i = 0; i < len/2; i++)
		if (s[i] != s[(len - 1) - i])
			return false;
	return true;
}

int main() {
	
	char input[101];
	cin.clear();
	cin.getline(input,101);

	cout << check(input) << endl;
	return 1;
}
