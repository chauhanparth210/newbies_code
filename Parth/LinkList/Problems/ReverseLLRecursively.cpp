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

ll* reverse(ll* curr, ll* prev) {
	if (curr->next == NULL) {
		curr->next = prev;
		return curr;
	}
	ll* nextLL = curr->next;
	curr->next = prev;
	prev = curr;
	return reverse(nextLL, curr);
}

ll* swap(ll* curr, ll* nextL, ll* head) {
	nextL->next = curr;
	curr->next = NULL;
	if (curr == head) return nextL;
	return curr;
}

ll* swapPairs(ll* head) {

	if (head == NULL || head->next == NULL) {
		return head;
	}

	bool isFirst = true;

	ll* ans = head;
	ll* sp = head;
	ll* fp = head->next;

	while (fp) {
		if (isFirst) {
			ans = swap(sp, fp, head);
			sp = head->next;
			isFirst  = false;
			// printll(head);
		} else {
			sp = swap(sp, fp, head);
		}
		if (fp->next->next == NULL) {
			break;
		}
		fp = fp->next->next;
		sp = sp->next;
	}

	return ans;
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
	// head = reverse(head, NULL );
	head = swapPairs(head);
	printll(head);
	return 0;
}