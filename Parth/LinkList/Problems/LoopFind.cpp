#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class ll {
public:
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


void loop(ll* head) {

	if (head->next == NULL || head == NULL) {
		cout << "IsLoop:" << false << endl;
		return;
	}

	ll* sp = head;
	ll* fp = head->next;

	while (fp->next) {
		fp = fp->next->next;
		sp = sp->next;
		if (fp == sp) {
			cout << "IsLoop:" << true << endl;
			return;
		}
	}
	cout << "IsLoop:" << false << endl;
}


int main()
{
#ifndef PRINTOUTPUT
	freopen("output.txt", "w", stdout);
#endif
	ll* head  = new ll();
	ll* sec  = new ll();
	ll* third = new ll();
	head ->data = 1;
	head->next = sec;
	sec ->data = 1;
	sec->next = head;
	// third->data = 1;
	// third->next = head;
	loop(head);
	return 0;
}