// https://codeforces.com/problemset/problem/1293/B
#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    float ans = 0.0;
    while (n){
        ans = ans + (1.0/n);
        n--;
    }
    printf("%.4f", ans);   

    return;   
}

int main(){

    int test = 1;
    //cin >> test;

    while(test--){
        solve();
    }
    return 0;
}