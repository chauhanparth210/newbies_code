// https://codeforces.com/problemset/problem/1354/A
#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    long long a, b, c, d;
    while(test--){
        cin >> a >> b >> c >> d;

        if(a <= b){
            cout << b << endl;
            continue;
        }

        if(c-d <= 0){
            cout << -1 << endl;
            continue;
        }
        a = a - b;
        cout << b + (long long)(c * ceil(a*1.0/(c-d))) << endl;
    }

    return 0;
}