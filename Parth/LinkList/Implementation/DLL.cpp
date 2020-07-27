#include <iostream>
#include <bits/stdc++.h>

using namespace std;

////NOTE:WHEN YOU ARE POINTING TO HEAD THEN ONLY YOU NEED TWO POINTER//////

class DLL {
public:
	int data;
	DLL* next;
	DLL* prev;
};

void fprintDLL(DLL* head) {
	while (head) {
		cout << head->data << endl;
		head = head->next;
	}
	return;
}

void rprintDLL(DLL* tail) {
	while (tail) {
		cout << tail->data << endl;
		tail = tail->prev;
	}
	return;
}

////////////INSERTION///////////////

DLL* append(DLL** head, int data) {
	DLL* headRef = *head;
	DLL* temp = new DLL();
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL) {
		*head = temp;
		temp->prev = NULL;
		return temp;
	}

	while (headRef->next != NULL)
		headRef = headRef->next;

	headRef->next = temp;
	temp->prev = headRef;
	return temp;
}

DLL* addFront(DLL** head, int data) {
	DLL* headRef = *head;
	DLL* temp = new DLL();
	temp->data = data;
	if (*head == NULL) {
		*head = temp;
		temp->prev = NULL;
		temp->next = NULL;
		return temp;
	}
	headRef->prev = temp;
	temp->prev = NULL;
	temp->next = headRef;
	*head = temp;
	return temp;
}

void addGivenPosition(DLL** head, int data, int position) {
	DLL* fp = *head;
	if (position < 0) {
		cout << "NOT POSSIBLE";
		goto END;
	} else if (position == 0) {
		DLL* headRef = addFront(&fp, data);
		*head = headRef;
		return;
	} else {
		while (position-- > 0) {
			fp = fp->next;
		}
		DLL* temp = new DLL();
		DLL* sp = fp->prev;
		temp->data = data;
		sp->next = temp;
		temp->next = fp;
		temp->prev = sp;
		fp->prev = temp;
		return;
	}
END: return;
}

////////////DELETION///////////////

void deleteFront(DLL** head) {
	DLL* headRef = *head;
	if (headRef == NULL) {
		return;
	}
	if (headRef->next == NULL) {
		free(headRef);
	}
	headRef = headRef->next;
	headRef->prev = NULL;
	* head = headRef;
}

void deleteEnd(DLL* head) {
	while (head->next) {
		head = head->next;
	}
	head = head->prev;
	head->next = NULL;
	free(head->next);
}



int main() {
#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	DLL*  head = new DLL();
	DLL* sec = new DLL();
	DLL* third = new DLL();
	head = NULL;

	append(&head, 1);
	append(&head, 2);
	// append(&head, 3);
	DLL* tail = append(&head, 4);
	addFront(&head, 0);
	addGivenPosition(&head, 3, 3);
	deleteEnd(head);
	deleteFront(&head);
	fprintDLL(head);
	// rprintDLL(tail);
	return 0;
}