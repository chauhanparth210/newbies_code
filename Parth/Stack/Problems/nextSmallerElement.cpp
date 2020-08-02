#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef READ_FILE
	freopen("output.txt", "w", stdout);
#endif
	stack<int> s;
	vector<int> v;
	int arr[] = {4, 8, 5, 2, 25};
	for (int i = 4; i >= 0; i--) {
		if (s.empty() == true) {
			v.push_back(-1);
		} else if (arr[i] >= s.top()) {
			v.push_back(s.top());
		} else if (s.empty() != true && arr[i] < s.top()) {
			while (s.empty() != true && arr[i] < s.top()) {
				s.pop();
			}
			if (s.empty() == true) {
				v.push_back(-1);
			} else {
				v.push_back(s.top());
			}
		}
		s.push(arr[i]);
	}
	reverse(v.begin(), v.end());
	for (auto a : v) {
		cout << a << " ";
	}

	return 0;
}