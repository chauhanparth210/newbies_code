#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    long long int n;
    while(test--){
        cin >> n;

        long long int a = n - (n/2) - 1; 
        long long ans = 8 * (a * (a+1) * (2*a+1) / 6);

        cout << ans << endl;        
    }

    return 0;
}