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

    void setHead(node* new_head){
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

node* reverse_list(node *head, node* &new_head){
    
    if(head == NULL)    return NULL;

    node *itr = reverse_list(head -> next, new_head);
    if(itr != NULL){
        itr -> next = head;
        head -> next = NULL;
    }
    else {
        new_head = head;
    }
        
    return head;
}


int main()
{
    List LinkedList;

    LinkedList.insert(1);
    LinkedList.insert(2);
    LinkedList.insert(3);
    LinkedList.insert(4);
    LinkedList.insert(5);
    LinkedList.insert(6);
    LinkedList.insert(7);
    LinkedList.insert(8);
    LinkedList.insert(9);

    node *head;
    node *last = reverse_list(LinkedList.getHead(), head);
    LinkedList.setHead(head);
    LinkedList.show();
    //show1();

    return 0;
}