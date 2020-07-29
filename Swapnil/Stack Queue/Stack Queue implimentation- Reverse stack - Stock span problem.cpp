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
#define print(a)            for(auto x:a){cout<<x<<" ";}cout<<endl
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
class Stack
{
public:
    vector<int> a;
    void push(int x)
    {
        a.pb(x);
    }
    void pop()
    {
        if(a.sz==0)
        {
            cout<<"Stack is empty\n";
            return;
        }
        a.pop_back();
    }
    int top()
    {
        if(a.sz==0)
        {
            cout<<"Stack is empty\n";
            return -1;
        }
        return a[a.sz-1];
    }
    void printstack()
    {
        print(a);
    }
};
class Queue
{
public:
    Stack s1,s2;
    void enqueue(int num)
    {
        while(s1.a.sz!=0)
        {
            ll x=s1.top();
            s1.pop();
            s2.push(x);
        }
        s2.push(num);
        while(s2.a.sz!=0)
        {
            ll x=s2.top();
            s2.pop();
            s1.push(x);
        }
    }
    void dequeue()
    {
        if(s1.a.sz==0)
        {
            cout<<"Queue is empty\n";
            return;
        }
        s1.pop();
    }
    int top()
    {
        if(s1.a.sz==0)
        {
            return -1;
        }
        return s1.a[s1.a.sz-1];
    }
    void printqueue()
    {
        print(s1.a);
    }
};
void reversestack(Stack& s)
{
    Queue q;
    while(s.a.sz!=0)
    {
        ll x=s.top();
        s.pop();
        q.enqueue(x);
    }
    while(q.s1.a.sz!=0)
    {
        ll x=q.top();
        q.dequeue();
        s.push(x);
    }
}
void solve()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.printstack();
    reversestack(s);
    s.printstack();
    vector<int> a;
    a.pb(5);
    a.pb(4);
    a.pb(3);
    a.pb(2);
    a.pb(1);
    a.pb(2);
    a.pb(3);
    a.pb(4);
    a.pb(5);
    vector<int> answer(a.sz,0);
    Stack b;
    for(int i=0;i<a.sz;i++)
    {
        while(b.a.sz!=0&&a[b.top()]<=a[i])
        {
            b.pop();
        }
        if(b.a.sz==0)
        {
            answer[i]=i+1;
        }
        else
        {
            answer[i]=i-b.top();
        }
        b.push(i);
    }
    print(answer);
}
signed main()
{
    FAST;
    ll t=1,i;
    //cin>>t;
    for(i=1;i<=t;i++)
    {
        solve();
    }
}

