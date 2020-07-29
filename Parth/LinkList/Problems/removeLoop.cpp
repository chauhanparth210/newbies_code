#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ll {
	int data;
	ll* next;
};

void append(ll** head, int data) {
	ll* headRef = *head;
	ll* temp = new ll();
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL) {
		*head = temp;
		return;
	}
	while (headRef->next) {
		headRef = headRef->next;
	}

	headRef->next = temp;
	return;
}

void printll(ll* head) {
	while (head) {
		cout << head->data << endl;
		head = head->next;
	}
}

void removeLoop(ll* head, ll* sp) {
	ll* ref = sp;
	ll* ref2 = head;
	int count = 1;
	while (ref->next != sp) {
		ref = ref->next;
		count++;
	}
	ref = head;
	for (int i = 0; i < count; i++) {
		ref2 = ref2->next;
	}

	while (ref != ref2) {
		ref = ref->next;
		ref2 = ref2->next;
	}

	while (ref2->next != ref) {
		ref2 = ref2->next;
	}

	ref2->next = NULL;

	return;
}

void Loop(ll* head) {
	ll* sp = head;
	ll* fp = head;
	while (head != NULL && head->next != NULL && fp) {
		fp = fp->next->next;
		sp = sp->next;
		if (fp == sp) {
			// cout << "LOOP:" << true << endl;
			removeLoop(head, sp);
			return;
		}
	}
	cout << "NO LOOP" << endl;
	return;
}

int main() {
#ifndef READ
	freopen("output.txt", "w", stdout);
#endif
	ll* head = new ll();
	ll* sec = new ll();
	ll* third = new ll();
	ll* fo = new ll();
	ll* fiv = new ll();

	head ->data = 1 ;
	head->next = sec;

	sec ->data = 2 ;
	sec->next = third;

	third ->data = 3 ;
	third->next = fo;

	fo ->data = 4 ;
	fo->next = fiv;

	fiv->data = 5 ;
	fiv->next = sec;

	Loop(head);
	printll(head);

	return 0;
}