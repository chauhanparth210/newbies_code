#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef READ_FILE
	freopen("output.txt", "w", stdout);
#endif
	vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
	stack<pair<int, int>> s;
	vector<int> v;

	for (int i = 0; i < arr.size(); i++) {
		if (s.size() == 0) {
			v.push_back(-1);
		}
		if (s.size() > 0 && s.top().first > arr[i]) {
			v.push_back(s.top().second);
		}
		else if (s.size() > 0 && s.top().first <= arr[i]) {
			while (s.size() > 0 && s.top().first <= arr[i]) {
				s.pop();
			}
			if (s.size() == 0) {
				v.push_back(-1);
			} else {
				v.push_back(s.top().second);
			}
		}
		s.push({arr[i], i});
	}

	for (int i = 0; i < v.size(); i++) {
		cout << i - v[i] << " ";
	}

	return 0;
}