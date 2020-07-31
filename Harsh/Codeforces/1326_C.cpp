// https://codeforces.com/problemset/problem/1326/C
#include<bits/stdc++.h>
using namespace std;

#define mod 998244353

int main(){

    long long n, k;
    cin >> n >> k;

    long long a[n];
    for(long int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long sum = ((n * (n+1)) - ((n-k) * (n-k+1))) / 2;

    long int ps[k];
    long int j = 0;
    for(long int i = 0; i < n; i++){
        if(a[i] > n-k){
            ps[j++] = i;
        }
    }

    sort(ps, ps+k);

    long long total = 1;
    for(long int i = 1; i < k; i++){
        total = (total * (ps[i] - ps[i-1])) % mod;
    }

    cout << sum << " " << total;

    return 0;
}