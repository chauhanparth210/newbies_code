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



int main()
{
    int choise;
    List LinkedList;
    while(true){
        cout << "1. Insert value \n2. Delete value \n3. Print value \n4 Exit \nEnter your choise: ";
        cin >> choise;

        switch (choise){
            case 1:{
                int val;
                cout << "\nEnter number: ";
                cin >> val;
                LinkedList.insert(val);
                break;
            }
            case 2:{
                int val;
                cout << "\nEnter number to delete: ";
                cin >> val;
                LinkedList.remove(val);
                break;
            }
            case 3:{
                LinkedList.show();
                break;
            }
            
            default:
                return 0;
        }
    }


    return 0;
}