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

        if(head -> val == n)
        {
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

node* reverse_list(node* head, int steps){

    if(head == NULL)    return head;

    node *prv = NULL, *cnt = head, *next = head -> next;
   
    int count = 0;
    while(cnt != NULL && count < steps){
            cnt -> next = prv;
            prv = cnt;
            cnt = next;
            if(next != NULL)
                next = next -> next;
            count++;
    }
    
    head -> next = reverse_list(cnt, steps);

    return prv;
}



int main()
{
    List LinkedList1;

    LinkedList1.insert(1);
    LinkedList1.insert(2);
    LinkedList1.insert(3);
    LinkedList1.insert(4);
    LinkedList1.insert(5);
    LinkedList1.insert(6);
    LinkedList1.insert(7);
    LinkedList1.insert(8);
    LinkedList1.insert(9);

    node *head = reverse_list(LinkedList1.getHead(), 3);
    LinkedList1.setHead(head);
    LinkedList1.show();
    return 0;
}