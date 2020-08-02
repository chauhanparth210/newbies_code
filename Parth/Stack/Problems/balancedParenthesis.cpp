#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
#ifndef READ_FILE
	freopen("output.txt", "w", stdout);
#endif
	string s1, s2;
	stack<char> s;
	s1 = "[]";
	for (int i = 0; i <= s1.length(); i++) {
		if (s.empty() == true) {
			s.push(s1.at(i));
		} else if (s.top() == '['  && s1.at(i) == ']') {
			s.pop();
		}
	}
	if (s.empty() == true) {
		cout << "BALANCED";
	} else {
		cout << "NOT_BALANCED";
	}
	cout << s.top();
	return 0;
}