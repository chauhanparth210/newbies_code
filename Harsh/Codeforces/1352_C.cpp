#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    long long n, k;
    while(test--){
        cin >> n >> k;

        if(k < n){
            cout << k << endl;
            continue;
        }

        long long temp = k / (n-1);
        k = k % (n-1);
        if (k == 0)
            k = -1;
        cout << (temp * n) + k << endl;


    }

    return 0;
}