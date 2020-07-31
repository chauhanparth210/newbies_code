#include<bits/stdc++.h>
using namespace std;

void solve(){

    long a, b, c, n;
    cin >> a >> b >> c >> n;

    long mx = max(a, max(c, b));
    n = n - (mx - a) - (mx - b) - (mx - c);

    if(n >= 0 && n % 3 == 0) 
        cout << "YES\n";
    else 
        cout << "NO\n";

    return;   
}

int main(){

    int test;
    cin >> test;

    while(test--){
        solve();
    }
    return 0;
}