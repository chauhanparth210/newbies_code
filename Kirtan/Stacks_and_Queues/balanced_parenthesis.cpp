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

//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

int n, t = 1;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	//cin>>t;
	while(t--){
        cout<<"Input string: "<<endl;
        cin>>s;

        stack<int> st;
        bool check = true;
        F0R(i,sz(s)){
            if(s[i] == '(') st.push(1);
            else{
                if(st.empty()) {check = false; break;}
                else st.pop();
            }
        }
        if(!st.empty()) check = false;

        check ? cout<<"Balanced Parenthesis"<<endl : cout<<"Non-balanced Parenthesis"<<endl;
	}
	return 0;
}

