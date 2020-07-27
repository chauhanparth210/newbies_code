#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *next;
};

class List{
    node *head;
    
    public:
    List(){
        head = NULL;
    }

    node* getHead(){
        return head;
    }

    void setHead(node *new_head){
        head = new_head;
    }

    void insert(int val){
        
        node *temp = (node*) malloc(sizeof(node));
        temp -> val = val;
        temp -> next = NULL;

        if(head == NULL)
            head = temp;
        else{
            node *itr = head;

            while(itr -> next != NULL)
                itr = itr -> next;

            itr -> next = temp;
        }
       // return head;
    }

    void show(){

        if(head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        node *itr = head;
        while (itr != NULL){
            cout << itr -> val << " ";
            itr = itr -> next;
        }
        cout << endl;        
    }

    void remove(int n){

        if(head == NULL){
            cout << "List is empty\n";
            return;
        }

        if(head -> val == n){
            node *temp = head;
            head = head -> next;
            free(temp);
            return;
        }

        node *cnt = head -> next;
        node *prv = head;
        while(cnt != NULL && cnt -> val != n){
            prv = cnt;
            cnt = cnt -> next;
        }

        if(cnt == NULL){
            cout << n << " is not in list\n";
            return;
        }
        prv -> next = cnt -> next;
        free(cnt);        
    }
};

node* merge_LinkedList(node *head1, node *head2){

    if(head1 == NULL)   return head2;
    if(head2 == NULL)   return head1;

    node* itr1 = head1;
    node* itr2 = head2;
    node* ans, *itr;

    if(head1 -> val < head2 -> val){
        ans = head1;
        itr1 = head1 -> next;
    }
    else{
        ans = head2;
        itr2 = head2 -> next;
    }
        

    itr = ans;    
    while(itr1 != NULL && itr2 != NULL){

        if(itr1 -> val <= itr2 -> val){
            itr -> next = itr1;
            itr1 = itr1 -> next;
        }
        else{
            itr -> next = itr2;
            itr2 = itr2 -> next;
        }
        itr = itr -> next;
    }
    
    if(itr1 != NULL)
        itr -> next = itr1;
    if(itr2 != NULL)
        itr -> next = itr2;

    return ans;
}

int main()
{
    List LinkedList1, LinkedList2, LinkedList3;

    LinkedList1.insert(1);
    LinkedList1.insert(2);
    LinkedList1.insert(3);
    LinkedList1.insert(4);
    LinkedList1.insert(5);

    LinkedList2.insert(1);
    LinkedList2.insert(3);
    LinkedList2.insert(4);
    LinkedList2.insert(7);

    node *head3 = merge_LinkedList(LinkedList1.getHead(), LinkedList2.getHead());
    LinkedList3.setHead(head3);
    LinkedList3.show();

    return 0;
}