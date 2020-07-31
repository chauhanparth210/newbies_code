#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int p1, p0 = -1, c1, c0 = -1;
    int flag = 0;
    while(n--){
        cin >> p1 >> c1;

        if(p1 == p0 && c1 == c0)
            continue;
        
        int dp = p1-p0;
        int dc = c1-c0;

        if(dp < dc || p1 <= p0 || c1 < c0 || p1 < c1){
            flag = 1;
        }
        p0 = p1;
        c0 = c1;
    }

    if(flag == 1)
        cout << "NO\n";
    else 
        cout << "YES\n";
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