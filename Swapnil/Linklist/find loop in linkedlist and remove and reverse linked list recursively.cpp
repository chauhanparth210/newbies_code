
/*------------------------------CODE BY SWAPNIL DHOLA------------------------------*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int   ll;
typedef pair<ll,ll>     pll;
#define ordered_set         tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define printadv(a,i,j)     for(long long int k=i;k<=j;k++){cout<<a[k]<<" ";}cout<<endl
#define FAST                ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
#define printpll(a)         for(auto x:a){cout<<x.first<<" "<<x.second<<endl;}
#define inputadv(a,i,j)     for(long long int k=i;k<=j;k++){cin>>a[k];}
//#define print(a)            for(auto x:a){cout<<x<<" ";}cout<<endl
#define inputpll(a)         for(auto &x:a){cin>>x.ff;cin>>x.ss;}
#define pyn(x)              x==true?cout<<"YES\n";:cout<<"NO\n";
#define rlp(i,a,b)          for(long long int i=a;i>=b;i--)
#define lp(i,a,b)           for(long long int i=a;i<=b;i++)
#define input(a)            for(auto &x:a){cin>>x;}
#define precise(x)          fixed<<setprecision(x)
#define all(v)              v.begin(),v.end()
#define ub                  upper_bound
#define lb                  lower_bound
#define pf                  push_front
#define mp                  make_pair
#define pb                  push_back
#define mod                 1000000007
#define linf                LLONG_MAX
#define inf                 INT_MAX
#define ss                  second
#define sz                  size()
#define ff                  first
#define endl                '\n'
const ll N=2e5+5;
class node
{
public:
    int data;
    node* next;
};

void print(node* head)
{
    cout<<"Linked List: ";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
node* reverseknodes(node* head,int k)
{
    node* curr=head;
    node* prev=NULL;
    node* next=NULL;
    int cnt=0;
    while(curr!=NULL&&(cnt++)<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    if(next!=NULL)
    {
        head->next=reverseknodes(next,k);
    }
    return prev;
}
void insertion(node** head,int data)
{
    node* newnode=new node();
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        node* traverse = *head;
        while(traverse->next!=NULL)
        {
            traverse=traverse->next;
        }
        traverse->next=newnode;
    }
}
void deletion(node** head,int todelete)
{
    if((*head)->data==todelete)
    {
        node* deletenode=(*head);
        (*head)=(*head)->next;
        delete (deletenode);
    }
    else
    {
        node* prev=NULL;
        node* traverse=*head;
        while(traverse!=NULL)
        {
            if(traverse->data==todelete)
            {
                break;
            }
            prev=traverse;
            traverse=traverse->next;
        }
        if(prev!=NULL)
        {
            prev->next=prev->next->next;
            delete traverse;
        }
    }
}
void mergelist(node** list1,node** list2)
{
    node* traverse1=*list1;
    node* traverse2=*list2;
    node* curr1=*list1;
    node* next1=*list1;
    node* curr2=*list2;
    node* next2=*list2;
    while(traverse1!=NULL&&traverse2!=NULL)
    {
        next1=traverse1->next;
        next2=traverse2->next;
        traverse1->next=traverse2;
        traverse2->next=next1;
        traverse1=next1;
        traverse2=next2;
    }
    (*list2)=traverse2;
}
node* reverselinkedlist(node* curr,node*prev)
{
    if(curr->next==NULL)
    {
        curr->next=prev;
        return curr;
    }
    else
    {
        node* next=curr->next;
        curr->next=prev;
        return reverselinkedlist(next,curr);
    }
}
bool findloop_and_remove(node* head)
{
    node* slowptr=head;
    node* fastptr=head;
    while(fastptr!=NULL&&fastptr->next!=NULL)
    {
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
        if(fastptr==slowptr)
        {
            slowptr=head;
            while(slowptr->next!=fastptr->next)
            {
                slowptr=slowptr->next;
                fastptr=fastptr->next;
            }
            fastptr->next=NULL;
            return true;
        }
    }
    return false;
}
void solve()
{
    node* linkedlist=NULL;
    insertion(&linkedlist,10);
    insertion(&linkedlist,1);
    insertion(&linkedlist,20);
    insertion(&linkedlist,33);
    insertion(&linkedlist,23);
    insertion(&linkedlist,13);
    insertion(&linkedlist,134);
    insertion(&linkedlist,123);
    insertion(&linkedlist,234);
    insertion(&linkedlist,256);
    insertion(&linkedlist,65);
    insertion(&linkedlist,134);
    print(linkedlist);
    linkedlist=reverselinkedlist(linkedlist,NULL);
    print(linkedlist);
    if(findloop_and_remove(linkedlist))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    linkedlist->next->next->next->next->next->next->next->next->next->next->next->next=linkedlist->next->next->next->next;
    if(findloop_and_remove(linkedlist))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    print(linkedlist);
}
signed main()
{
   // FAST;
    ll t=1,i;
    //cin>>t;
    for(i=1;i<=t;i++)
    {
        solve();
    }
}


