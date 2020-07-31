// https://codeforces.com/problemset/problem/1382/B
#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    int n;
    while(test--){
        cin >> n;

        int a[2*n + 1];
        for(int i = 1; i <= 2*n; i++)
            cin >> a[i];
        
        bool check[n+1];
        memset(check, false, n+1);
        vector<int> v;

        v.push_back(a[1]);
        check[a[1]] = true;
        for(int i = 2; i <= 2*n; i++){
            if(!check[a[i]]){
                v.push_back(a[i]);
                check[a[i]] = true;
            }
        }

        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;

    }
    return 0;
}