#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void NSR(vector<int> arr, vector<int>& right) {
	stack<pair<int, int>> s;
	for (int i = arr.size() - 1; i >= 0; i--) {
		if (s.empty() == true) {
			right.push_back(-1);
		} else if (arr[i] >= s.top().first) {
			right.push_back(s.top().second);
		} else if (s.empty() != true && arr[i] < s.top().first) {
			while (s.empty() != true && arr[i] < s.top().first) {
				s.pop();
			}
			if (s.empty() == true) {
				right.push_back(-1);
			} else {
				right.push_back(s.top().second);
			}
		}
		s.push(make_pair(arr[i], i));
	}
	reverse(right.begin(), right.end());
}

void NSL(vector<int> arr, vector<int>& left) {
	stack<pair<int, int>> s;
	for (int i = 0 ; i < arr.size() ; i++) {
		if (s.empty() == true) {
			left.push_back(-1);
		} else if (arr[i] >= s.top().first) {
			left.push_back(s.top().second);
		} else if (s.empty() != true && arr[i] < s.top().first) {
			while (s.empty() != true && arr[i] < s.top().first) {
				s.pop();
			}
			if (s.empty() == true) {
				left.push_back(-1);
			} else {
				left.push_back(s.top().second);
			}
		}
		s.push(make_pair(arr[i], i));
	}
}


int MAH(vector<int> arr) {
	int m = -999999;
	vector<int> left, right, area, width;
	NSR(arr, right);
	NSL(arr, left);
	for (int i = 0; i < arr.size(); i++) {
		width.push_back(right[i] - left[i] - 1);
	}
	for (int i = 0; i <= arr.size() - 1; i++) {
		area.push_back(arr[i]*width[i]);
		if (m < area[i]) {
			m = area[i];
		}
	}
	return m;
}

int main() {
#ifndef READ_FILE
	freopen("output.txt", "w", stdout);
#endif
	vector<int> arr {10, 20, 50, 20, 60, 100, 120, 10, 5, 0};
	int area = MAH(arr);
	cout << area << endl;
	return 0;
}