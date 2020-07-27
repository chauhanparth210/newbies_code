#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class ll {
public:
	int data;
	ll* next;
};

void printLL(ll* head) {
	while (head) {
		cout << head->data << endl;
		head =  head->next;
	}
	return;
}

//////INSERTION//////

void append(ll** head, int data) {
	ll* headRef = *head;
	ll* temp = new ll();
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL) {
		*head = temp;
		return;
	}
	while (headRef ->next != NULL) {
		headRef = headRef->next;
	}
	headRef->next  = temp;
	return;
}

void addFront(ll** head, int data) {
	ll* headRef = *head;
	ll* temp = new ll();
	temp->data = data;
	if (*head == NULL) {
		*head = temp;
		return;
	}
	temp->next = headRef;
	*head = temp;
	return;
}

void addGivenPosition(ll* head, int data, int position) {
	ll* fp = head;
	ll* sp = head;
	ll* temp = new ll();
	temp->data = data;
	fp = fp->next;
	if (position < 0) {
		cout << "NOT POSSIBLE";
		goto END;
	}
	else {
		while (position-- > 1) {
			fp = fp->next;
			sp = sp->next;
		}
		sp->next = temp;
		temp->next = fp;
	}
END: return;
}

//////DELETETION//////
void dfront(ll** head) {
	ll* headRef = *head;
	if (*head ==  NULL) {
		return;
	} else if (headRef->next == NULL) {
		free(headRef);
		return;
	} else {
		headRef = headRef->next;
		*head = headRef;
	}
	return;
}

void dend(ll* head) {
	ll* fp = head;
	ll* sp = head;
	if (head == NULL) {
		return;
	}
	else {
		fp = fp->next;
		while (fp->next != NULL) {
			fp  = fp ->next;
			sp = sp->next;
		}
		sp->next = NULL;
		free(fp);
	}
	return;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
#endif
	ll* head = new ll();
	head = NULL;
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	addGivenPosition(head, 5, 4);
	dfront(&head);
	dend(head);
	dend(head);
	printLL(head);
	return 0;
}