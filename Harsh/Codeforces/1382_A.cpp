// https://codeforces.com/problemset/problem/1382/A
#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    int m, n;
    while(test--){
        cin >> n >> m;

        int a[n], b[m];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];
        
        sort(a, a+n);
        sort(b, b+m);

        int i = 0, j = 0;
        while (i < n && j < m){
            if(a[i] == b[j]){
                cout << "YES\n";
                cout << 1 << " " << a[i] << endl;
                break;
            }
            else if(a[i] < b[j]){
                i++;
            }
            else{
                j++;
            }
        }

        if(i == n || j == m)
            cout << "NO\n";        
    }
    return 0;
}