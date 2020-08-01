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

int n, moves;
stack<int> home, dest, aux;

void towerOfHanoi(){
    if(n % 2 == 1){
        F0R(i,moves){
            if(i%3 == 0){
                if(dest.empty() || (!home.empty() && dest.top() > home.top())){
                    cout<<"move disk "<<home.top()<<" from A to C"<<endl;
                    dest.push(home.top());
                    home.pop();
                }
                else{
                    cout<<"move disk "<<dest.top()<<" from C to A"<<endl;
                    home.push(dest.top());
                    dest.pop();
                }
            }
            else if(i % 3 == 1){
                if(aux.empty() || (!home.empty() && aux.top() > home.top())){
                    cout<<"move disk "<<home.top()<<" from A to B"<<endl;
                    aux.push(home.top());
                    home.pop();
                }
                else{
                    cout<<"move disk "<<aux.top()<<" from B to A"<<endl;
                    home.push(aux.top());
                    aux.pop();
                }
            }
            else{
                if(aux.empty() || (!dest.empty() && aux.top() > dest.top())){
                    cout<<"move disk "<<dest.top()<<" from C to B"<<endl;
                    aux.push(dest.top());
                    dest.pop();
                }
                else{
                    cout<<"move disk "<<aux.top()<<" from B to C"<<endl;
                    dest.push(aux.top());
                    aux.pop();
                }
            }
        }
    }
    else{
        F0R(i,moves){
            if(i%3 == 0){
                if(aux.empty() || (!home.empty() && aux.top() > home.top())){
                    cout<<"move disk "<<home.top()<<" from A to B"<<endl;
                    aux.push(home.top());
                    home.pop();
                }
                else{
                    cout<<"move disk "<<aux.top()<<" from B to A"<<endl;
                    home.push(aux.top());
                    aux.pop();
                }
            }
            else if(i % 3 == 1){
                if(dest.empty() || (!home.empty() && dest.top() > home.top())){
                    cout<<"move disk "<<home.top()<<" from A to C"<<endl;
                    dest.push(home.top());
                    home.pop();
                }
                else{
                    cout<<"move disk "<<dest.top()<<" from C to A"<<endl;
                    home.push(dest.top());
                    dest.pop();
                }
            }
            else{
                if(aux.empty() || (!dest.empty() && aux.top() > dest.top())){
                    cout<<"move disk "<<dest.top()<<" from C to B"<<endl;
                    aux.push(dest.top());
                    dest.pop();
                }
                else{
                    cout<<"move disk "<<aux.top()<<" from B to C"<<endl;
                    dest.push(aux.top());
                    aux.pop();
                }
            }
        }
    }
}

int main(){
    cout<<"Input of number of disks: ";
    cin>>n;
    FORd(i,1,n + 1) home.push(i);

    moves = pow(2,n) - 1;

    towerOfHanoi();

    return 0;
}
