// https://codeforces.com/problemset/problem/1352/B
#include<bits/stdc++.h>
using namespace std;

void solve(){

    long int n, k;
    cin >> n >> k;

    long val = n / k;
    n = n % k;

    if(val == 0){
        cout << "NO\n";
        return;
    }
    if(n % 2 == 0){
        cout << "YES\n" << val + n;
        for(int i = 1; i < k; i++){
            cout << " " << val;
        }
        cout << endl;
        return;
    }
    if(n % 2 == 1){
        if(k % 2 == 1 && val > 1){
            cout << "YES\n" << val + n;
            for(int i = 1; i < k; i+=2){
                cout << " " << val - 1 << " " << val + 1;
            }
            cout << endl;
        }
        else{
            cout << "NO\n";
        }
        return;
    }   
}


int main(){

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}