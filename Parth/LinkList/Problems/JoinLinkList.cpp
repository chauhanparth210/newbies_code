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
	return;
}

ll* join(ll* l1, ll* l2) {
	ll* ans = new ll();
	ans = NULL;

	while (l1 && l2) {
		if (l1->data >= l2->data) {
			append(&ans, l2->data);
			l2 = l2->next;
		} else {
			append(&ans, l1->data);
			l1 = l1->next;
		}
	}

	while (l1) {
		append(&ans, l1->data);
		l1 = l1->next;
	}

	while (l2) {
		append(&ans, l2->data);
		l2 = l2->next;
	}

	return ans;
}

int main() {
#ifndef OPEN_FILE
	freopen("output.txt", "w", stdout);
#endif
	ll* l1 = new ll();
	ll* l2 = new ll();
	l1 = NULL;
	l2 = NULL;

	append(&l1, 1);
	append(&l1, 4);
	append(&l1, 6);
	append(&l1, 10);

	append(&l2, 0);
	// append(&l2, 5);
	append(&l2, 5);
	append(&l2, 10);

	// printll(l1);
	// printll(l2);
	printll(join(l1, l2));
	return 0;
}