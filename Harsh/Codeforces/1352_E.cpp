// https://codeforces.com/problemset/problem/1352/E
#include<bits/stdc++.h>
using namespace std;

bool check(int a[], long sum[], int n, int size){

    int l[2] = {0}, r[2] = {0};
    l[0] = 0, l[1] = n+1;
    r[0] = 1, r[1] = n+2;
    int lm[2] = {n, size};
    long suml = 0;

    for(int i = 0; i < 2; i++){

        if(l[i] == 0 && n == 0)
            continue;

        while(l[i] < r[i] && r[i] < lm[i]){
            if(l[i] == 0){
                suml = 0;
            }
            else{
                suml = sum[l[i]-1];
            }

            if(sum[r[i]] - suml == a[n]){
                return true;
            }
            else if(sum[r[i]] - suml > a[n]){
                l[i]++;
                if(l[i] == r[i]){
                    r[i]++;
                    if(i == 0 && r[i] == lm[i])
                        break;
                }
                    
            }
            else{
                r[i]++;
                if(i == 0 && r[i] == lm[i])
                    break;
            }
        }
    }
    return false;
}

int main(){

    int test = 1;
    cin >> test;

    int n;
    while(test--){
        cin >> n;

        int a[n];
        long sum[n];

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        sum[0] = a[0];
        for(int i = 1; i < n; i++){
            sum[i] = sum [i-1] + a[i];
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(check(a, sum, i, n)){
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}