#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Q {
	int front, rear, size;
	int *arr;
};

Q* createQueue(int size) {
	Q* q = new Q();
	q->front = -1;
	q->rear = -1;
	q->size = size;
	q->arr = new int[size];
	return q;
}

int isEmpty(Q* q) {
	if (q->front == -1 && q->rear == -1) return 1;
	return 0;
}

int isFull(Q* q) {
	if (q->front == q->size - 1) return 1;
	return 0;
}

void enqueue(Q* q, int data) {
	if (isFull(q)) {
		cout << "Queue:FULL" << endl;
		return;
	}
	if (q->front == q->rear && q->front == -1) {
		q->front++;
		q->rear++;
		q->arr[q->rear] = data;
		return;
	}
	q->rear++;
	q->arr[q->rear] = data;
	return;
}

void dequeue(Q* q) {
	if (isEmpty(q)) {
		cout << "Queue:EMPTY" << endl;
		return;
	}
	if (q->front == q->rear) {
		q->front  = -1;
		q->rear = -1;
		return;
	}
	q->rear--;
	return;
}

int getFront(Q* q) {
	return q->arr[q->front];
}

int getBack(Q* q) {
	return q->arr[q->rear];
}

void printQ(Q* q) {
	for (int i = q->front; i <= q->rear; i++) {
		cout << q->arr[i] << " ";
	}
}

int main() {
#ifndef READ_FILE
	freopen("output.txt", "w", stdout);
#endif
	Q* q = createQueue(10);
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	printQ(q);
	dequeue(q);
	printQ(q);
	return 0;
}