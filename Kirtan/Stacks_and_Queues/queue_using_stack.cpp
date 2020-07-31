// Author: Kyrtan
//Topic: Queue Using 2 Stacks
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

class Stack{
private:
    vi stackk;
public:
    void push(int x){
        stackk.pb(x);
    }
    void pop(){
        if(sz(stackk) != 0) stackk.pop_back();
        else cout<<"Stack is empty :P"<<endl;
    }
    confirm top(){
        if(sz(stackk) != 0){
            confirm c;
            c.val = stackk[sz(stackk) - 1];
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
        cout<<"First to remove---";
        F0Rd(i,sz(stackk)) cout<<stackk[i]<<"---";
        cout<<"Last to remove"<<endl;
    }
    void operator= (Stack const &obj){
        stackk = obj.stackk;
    }
};

class Queue{
private:
    Stack st1;
    Stack st2;
public:
    void enqueue(int x){
        while((st2.top()).sgn){
            st1.push((st2.top()).val);
            st2.pop();
        }
        st1.push(x);
        while((st1.top()).sgn){
            st2.push((st1.top()).val);
            st1.pop();
        }
    }
    void dequeue(){
        if((st2.top()).sgn) st2.pop();
        else cout<<"Queue is empty :P"<<endl;
    }
    confirm front_queue(){
        if((st2.top()).sgn){
            confirm c;
            c.val = (st2.top()).val;
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
        st2.print_stack();
    }
};

int main(){
    Queue qq;
    qq.enqueue(1);
    qq.print_queue();
    qq.enqueue(2);
    qq.print_queue();
    qq.enqueue(3);
    qq.print_queue();
    qq.enqueue(4);
    qq.print_queue();
    if((qq.front_queue()).sgn) cout<<((qq.front_queue()).val)<<endl;
    else cout<<(qq.front_queue()).error_msg;
    qq.dequeue();
    qq.dequeue();
    qq.print_queue();
    qq.dequeue();
    if((qq.front_queue()).sgn) cout<<((qq.front_queue()).val)<<endl;
    else cout<<(qq.front_queue()).error_msg;
    qq.dequeue();
    if((qq.front_queue()).sgn) cout<<((qq.front_queue()).val)<<endl;
    else cout<<(qq.front_queue()).error_msg;

    return 0;
}


