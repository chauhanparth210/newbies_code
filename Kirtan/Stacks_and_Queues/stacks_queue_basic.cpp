// Author: Kyrtan
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
        F0Rd(i,sz(stackk)) cout<<stackk[i]<<"<---";
        cout<<"end"<<endl;
    }
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
        cout<<"start--->";
        FOR(i,first,last) cout<<queuee[i]<<"--->";
        cout<<"end"<<endl;
    }
};

void reverse_stack(Stack &s){
    Queue temp;
    while((s.top()).sgn){
        temp.enqueue((s.top()).val);
        s.pop();
    }
    while((temp.front_queue()).sgn){
        s.push((temp.front_queue()).val);
        temp.dequeue();
    }
}

int main(){
    Stack st;
    cout<<"Stack"<<endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.print_stack();

    confirm temp;
    temp = st.top();
    if(temp.sgn) cout<<temp.val<<endl;
    else cout<<temp.error_msg<<endl;

    st.pop();
    st.pop();
    st.print_stack();
    st.pop();
    st.pop();
    temp = st.top();
    if(temp.sgn) cout<<temp.val<<endl;
    else cout<<temp.error_msg<<endl;

    cout<<endl<<"Queue"<<endl;
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.print_queue();

    temp = q.front_queue();
    if(temp.sgn) cout<<temp.val<<endl;
    else cout<<temp.error_msg<<endl;

    q.dequeue();
    q.dequeue();
    q.print_queue();
    q.dequeue();
    q.dequeue();
    temp = q.front_queue();
    if(temp.sgn) cout<<temp.val<<endl;
    else cout<<temp.error_msg<<endl;

    Stack st2;
    cout<<"Stack"<<endl;
    st2.push(1);
    st2.push(2);
    st2.push(3);
    st2.push(4);
    st2.print_stack();
    reverse_stack(st2);
    cout<<"Stack Reversed:"<<endl;
    st2.print_stack();

    //Stock-Span Problem
    int n;
    cout<<"Input number of days: ";
    cin>>n;

    vi vec(n),ans(n,0);
    cout<<"Input stocks on each day: ";
    F0R(i,n) cin>>vec[i];
    Stack st3;

    F0R(i,n){
        if((st3.top()).sgn){
            while(vec[(st3.top()).val] <= vec[i]) st3.pop();

            if((st3.top()).sgn) ans[i] = i - (st3.top()).val;
            else ans[i] = 1;

            st3.push(i);
        }
        else{ st3.push(i); ans[i] = 1;}
    }

    F0R(i,n) cout<<ans[i]<<" ";

    return 0;
}
