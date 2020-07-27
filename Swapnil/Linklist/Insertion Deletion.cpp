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
    node* prev;
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

void insertion(node** head,int data)
{
    node* newnode=new node();
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
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
        newnode->prev=traverse;
    }
}
void deletion(node** head,int todelete)
{
    if((*head)->data==todelete)
    {
        (*head)=(*head)->next;
        node* deletenode=(*head)->prev;
        (*head)->prev=NULL;
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
            if(prev->next!=NULL)
                prev->next->prev=prev;
            delete traverse;
        }
    }
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
    deletion(&linkedlist,10);
    deletion(&linkedlist,134);
    deletion(&linkedlist,134);
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

