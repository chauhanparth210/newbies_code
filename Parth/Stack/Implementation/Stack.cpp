#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct sk {
	int *arr;
	int size;
	int top;
};

sk* createStack(int size) {
	sk* stk = new sk();
	stk->top = -1;
	stk->arr = new int[size];
	stk->size = size;
	return stk;
}

int isFull(sk* stk) {
	if (stk->size - 1 == stk->top) return 1;
	return 0;
}

int isEmpty(sk* stk) {
	if (stk->top == -1) return 1;
	return 0;
}

void push(sk* stk, int data) {
	if (isFull(stk)) {
		cout << "STACK IS FULL" << endl;
		return;
	}
	stk->top++;
	stk->arr[stk->top] = data;
	return;
}

void pop(sk* stk) {
	if (isEmpty(stk)) {
		cout << "STACK IS EMPTY" << endl;
		return;
	}
	stk->top--;
	return;
}

int top(sk* stk) {
	return stk->arr[stk->top];
}

void printS(sk* stk) {
	int n = stk->top;
	for (int i = 0; i <= n; i++) {
		cout << stk->arr[i] << endl;
	}
}


void reveserStk(sk* stk) {
	int n = stk->top;
	int temp;
	for (int i = 0; i < n / 2; i++) {
		temp = stk->arr[i];
		stk->arr[i] = stk->arr[n - i];
		stk->arr[n - i] = temp;
	}
}

int main() {
#ifndef READ_FILE
	freopen("output.txt", "w", stdout);
#endif
	sk* stk = createStack(10);
	push(stk, 1);
	push(stk, 2);
	push(stk, 3);
	cout << "TOP:" << top(stk) << endl;
	printS(stk);
	cout << endl;
	reveserStk(stk);
	printS(stk);
	return 0;
}