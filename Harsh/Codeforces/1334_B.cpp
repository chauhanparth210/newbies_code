#include<bits/stdc++.h>
using namespace std;

void solve(){
    long int n, x;
    cin >> n >> x;
    long a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);

    if(a[n-1] < x){
        cout << 0 << endl;
        return;
    }

    long long sum[n];
    memset(sum, 0, sizeof(sum));
    sum[0] = a[0];
    
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1] + a[i];
    }

    int it = lower_bound(a, a+n, x) - a;
    long long temp_sum = 0;
    for(int i = 0; i < it; i++){
        if(i == 0){
            temp_sum = 0;
        }
        else{
            temp_sum = sum[i-1];
        }

        double avg = (1.0*sum[n-1] - temp_sum) / (n-i);
        
        if(avg >= x*1.0){
            cout << n-i << endl;
            return;
        }
    }

    cout << (n-it) << endl;
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