//https://codeforces.com/problemset/problem/1293/A
#include<bits/stdc++.h>
using namespace std;

void solve(){
    long n, s, k;
    cin >> n >> s >> k;

    long a[k];
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    sort(a, a+k);

    long itr = lower_bound(a, a+k, s) - a;
    if(a[itr] != s){
        cout << 0 << endl;
    }
    else{
        itr++;
        long itl = itr - 2;
        long lp, rp;
        int flagl = 0, flagr = 0;
        for(long i = s+1; i <= n; i++){
            if(itr == k)
                itr = k-1;
            if(a[itr] == i){
                itr++;
            }
            else if(a[itr] != i){
                rp = i;
                flagr = 1;
              //  cout << "r " << rp << endl;
                break;
            }
            
        }

        for(long i = s-1; i > 0; i--){
            if(itl == -1)
                itl = 0;
            if(a[itl] == i){
                itl --;
            }
            else if(a[itl] != i){
                lp = i;
                flagl = 1;
              //  cout << "l " << lp << endl;
                break;
            }
            
        }


        if(flagl == 0)
            cout << rp-s << endl;
        else if(flagr == 0)
            cout << s - lp << endl;
        else
            cout << min(rp-s, s-lp) << endl;
    }

}


int main(){

    int test;
    cin >> test;

    while(test--){
        solve();
    }
    return 0;
}