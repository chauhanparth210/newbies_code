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

void reverse(ll** head) {
	ll* headRef = *head;
	ll* sp = headRef;
	ll* fp = sp->next;
	sp->next = NULL;
	while (fp != NULL) {
		ll* temp = new ll();
		temp->data = fp->data;
		temp->next = sp;
		fp = fp->next;
		sp = temp;
	}
	*head = sp;
}

int main()
{
#ifndef PRINTOUTPUT
	freopen("output.txt", "w", stdout);
#endif
	ll* head  = new ll();
	head = NULL;
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	reverse(&head);
	printll(head);
	return 0;
}