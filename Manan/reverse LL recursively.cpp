#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};
void insertionAtEnd(node** n,int d)
{
    node* m=new node;

    m->data=d;
    m->next=NULL;

    node* last=*n;

    if(*n==NULL)
    {
        *n=m;
        return;
    }

    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=m;
    return;
}
void insertionAtBegin(node** head,int d)
{
    node* m=new node();
    m->data=d;
    m->next=*head;

    *head=m;
}
void deletion(node* head,int d)
{
    node* pre;
    node* after;
    node* temp;
    temp=head;
    while(temp->data!=d)
    {
        pre=temp;
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"NOT FOUND"<<endl;
            break;
        }
    }
    pre->next=temp->next;
}
node* rec_rev(node* head,node* pre)
{
    if(head->next==NULL)
    {
        head->next=pre;
        return head;
    }
    node* next1;
    next1=head->next;
    head->next=pre;
    pre=head;
    return rec_rev(next1,pre);
}
void output(node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}
int main()
{
    node* head=NULL;

    for(int i=1;i<=5;i++)
        insertionAtEnd(&head,i);

    output(head);

    /*for(int i=6;i<=10;i++)
        insertionAtBegin(&head,i);

    cout<<endl;
    output(head);

    deletion(head,11);
    cout<<endl;
    output(head);*/

    //recursive recursion
    node* pre=NULL;
    head=rec_rev(head,pre);
    cout<<endl;
    output(head);
}
