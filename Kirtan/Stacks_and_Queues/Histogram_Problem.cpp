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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	//cin>>t;
	while(t--){
        cout<<"Input number of columns in Histogram: "<<endl;
        cin>>n;
        vl a(n);

        cout<<"Input the lengths of each column: "<<endl;
        F0R(i,n) cin>>a[i];

        stack<ll> st;
        ll ans = 0;

        vl left(n,0), right(n,0);
        F0R(i,n){
           while(!st.empty() && a[st.top()] >= a[i]) st.pop();

           if(st.empty()) left[i] = i;
           else left[i] = i - st.top() - 1;

           st.push(i);
        }

        stack<ll> st2;
        F0Rd(i,n){
           while(!st2.empty() && a[st2.top()] >= a[i]) st2.pop();

           if(st2.empty()) right[i] = n - i - 1;
           else right[i] = st2.top() - i - 1;

           st2.push(i);
        }

        F0R(i,n) ans = max(ans, (left[i] + right[i] + 1)*a[i]);
        cout<<"ans: "<<ans<<endl;
	}
	return 0;
}

