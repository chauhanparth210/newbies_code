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
    vi min_el;
public:
    void push(int x){
        stackk.pb(x);
        if(sz(stackk) == 1) min_el.pb(x);
        else if(min_el[sz(min_el) - 1] > x) min_el.pb(x);
        else min_el.pb(min_el[sz(min_el) - 1]);
    }
    void pop(){
        if(sz(stackk) != 0){ stackk.pop_back(); min_el.pop_back();}
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
    confirm get_Min(){
        if(sz(min_el) != 0){
            confirm c;
            c.val = min_el[sz(min_el) - 1];
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
};


int main(){
    Stack st;
    cout<<"Stack"<<endl;
    st.push(4);
    st.push(2);
    st.push(3);
    st.push(1);
    st.print_stack();

    confirm temp;
    temp = st.get_Min();
    if(temp.sgn) cout<<temp.val<<endl;
    else cout<<temp.error_msg<<endl;

    st.pop();
    temp = st.get_Min();
    st.print_stack();
    if(temp.sgn) cout<<temp.val<<endl;
    else cout<<temp.error_msg<<endl;
    st.pop();
    st.pop();
    st.pop();
    temp = st.get_Min();
    if(temp.sgn) cout<<temp.val<<endl;
    else cout<<temp.error_msg<<endl;

    return 0;
}
