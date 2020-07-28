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

void make_loop(node *head){

    if(head == NULL)    return;
    node *itr = head;
    int n = 1;
    while(itr -> next != NULL){
        itr = itr -> next;
        n++;
    }
    srand(time(0)); 
    int pos = (rand()  % n) + 1;

    cout << pos << endl;
    node *itr2 = head;
    pos--;
    while (pos--){
        itr2 = itr2 -> next;
    }

    itr -> next = itr2;
}

node* find_loop(node *head){
    
    if(head == NULL)    return NULL;

    node *slow = head;
    node *fast = head -> next;
    bool flag = false;

    while (fast != NULL){
        if(slow == fast){
            flag = true;
            break;
        }            
        else{
            slow = slow -> next;
            fast = fast -> next;
            if(fast != NULL)
                fast = fast -> next;
        }
    }
    
    if(flag == true){
        int count = 1;
        node *itr = slow -> next;
        while(itr != slow){
            itr = itr -> next;
            count++;
        }
        node *itr1 = head;
        node *itr2 = head;
        int i = count;
        while(i--){
            itr2 = itr2 -> next;
        }
        while(itr1 != itr2){
            itr1 = itr1 -> next;
            itr2 = itr2 -> next;
        }
        return itr1; // first loop node
    }
    
    return NULL;
}


void remove_loop(node *head){

    node *itr = find_loop(head);

    if(itr != NULL){
        node *itr1 = itr;
        while (itr1 -> next != itr){
            itr1 = itr1 -> next;
        }
        itr1 -> next = NULL;        
    }
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

    make_loop(LinkedList.getHead());
    node* nd = find_loop(LinkedList.getHead());
    if(nd != NULL){
        cout << nd -> val << endl;
        remove_loop(LinkedList.getHead());
        LinkedList.show();
    }
    else{
        cout << "false\n";
    }
    
    return 0;
}