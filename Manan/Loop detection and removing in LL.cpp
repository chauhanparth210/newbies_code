#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    int flag;
};
void insertionAtEnd(node** n,int d)
{
    node* m=new node;

    m->data=d;
    m->next=NULL;
    m->flag=0;

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
bool loop(node* head)
{
    node* temp=head;
    node* pre;
    while(temp!=NULL)
    {
        if(temp->flag==1)
        {
            pre->next=NULL;
            return true;
        }
        else
        {
            temp->flag=1;
        }
        pre=temp;
        temp=temp->next;
    }
    return false;
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
    cout<<endl;

    //loop detection and removing if found

    head->next->next->next->next->next=head->next;//connecting node with value 2 with node with value 5

    if(loop(head))
        cout<<"Loop was found and it has been removed"<<endl;
    else
        cout<<"Loop not found"<<endl;

    output(head);

}
