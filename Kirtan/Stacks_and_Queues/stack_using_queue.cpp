// Author: Kyrtan
//Topic: Stack Using 2 Queue
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

//template <class T> using Tree = tree<T, null_type, less<T>, intrb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 200005;

class confirm{
public:
    int val;
    bool sgn;
    string error_msg = "String/Queue is empty :P";
};

class Queue{
private:
    vi queuee;
    int first = 0;
    int last = 0;
public:
    void enqueue(int x){
        queuee.pb(x);
        last++;
    }
    void dequeue(){
        if(first != last) first++;
        else cout<<"Queue is empty :P"<<endl;
    }
    confirm front_queue(){
        if(first != last){
            confirm c;
            c.val = queuee[first];
            c.sgn = true;
            return c;
        }
        else{
            confirm c;
            c.val = 0;
            c.sgn = false;
            return c;
        }
    }
    void print_queue(){
        cout<<"top---";
        FOR(i,first,last) cout<<queuee[i]<<"---";
        cout<<"bottom"<<endl;
    }
    void operator= (Queue const &obj){
        first = obj.first;
        last = obj.last;
        queuee = obj.queuee;
    }
};

class Stack{
private:
    Queue q1;
    Queue q2;
public:
    void push(int x){
        q1.enqueue(x);
        while((q2.front_queue()).sgn){
            q1.enqueue((q2.front_queue()).val);
            q2.dequeue();
        }
        q2 = q1;
        Queue q;
        q1 = q;
    }
    void pop(){
        if((q2.front_queue()).sgn) q2.dequeue();
        else cout<<"Stack is empty :P"<<endl;
    }
    confirm top(){
        if((q2.front_queue()).sgn){
            confirm c;
            c.val = (q2.front_queue()).val;
            c.sgn = true;
            return c;
        }
        else{
            confirm c;
            c.val = 0;
            c.sgn = false;
            return c;
        }
    }
    void print_stack(){
        q2.print_queue();
    }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.print_stack();
    if((st.top()).sgn) cout<<((st.top()).val)<<endl;
    else cout<<(st.top()).error_msg;
    st.pop();
    st.pop();
    st.print_stack();
    st.pop();
    if((st.top()).sgn) cout<<((st.top()).val)<<endl;
    else cout<<(st.top()).error_msg;
    st.pop();
    if((st.top()).sgn) cout<<((st.top()).val)<<endl;
    else cout<<(st.top()).error_msg;

    return 0;
}

