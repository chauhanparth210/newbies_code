#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    long long a[3];
    while(test--){
        cin >> a[0] >> a[1] >> a[2];

        sort(a, a+3);
        if(a[2] == a[1]){
            cout << "YES\n";
            cout << a[2] << " " << a[0] << " " << (a[0]-1==0?1:a[0]-1) << endl;
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}