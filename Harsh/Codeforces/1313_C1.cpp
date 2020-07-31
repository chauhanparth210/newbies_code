// https://codeforces.com/problemset/problem/1313/C1
#include<bits/stdc++.h>
using namespace std;

void solve(long m[], int n, long ans[]){

    long temp[n];
    long long mx_sum = INT_MIN, sum = 0;
    for(int i = 0; i < n; i++){
        temp[i] = m[i];
        sum = m[i];
        for(int j = i-1; j > -1; j--){
            if(m[j] <= temp[j+1]){
                temp[j] = m[j];
                sum += m[j];
            }
            else{
                temp[j] = temp[j+1];
                sum += temp[j+1];
            }
        }

        for(int j = i+1; j < n; j++){
            if(m[j] <= temp[j-1]){
                temp[j] = m[j];
                sum += m[j];
            }
            else{
                temp[j] = temp[j-1];
                sum += temp[j-1];
            }
        }

        if(sum > mx_sum){
            for(int i = 0; i < n; i++)
                ans[i] = temp[i];
            mx_sum = sum;
        }
    }
   
}

int main(){

    int n;
    cin >> n;

    long a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long ans[n];

    solve(a, n, ans);
    
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}