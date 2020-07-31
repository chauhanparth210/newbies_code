#include<bits/stdc++.h>
using namespace std;

void solve(){
    long int n, k;
    cin >> n >> k;

    int fp = -1, sp = -1;
    for(int i = 1; i <= n; i++){
        if(k == i){
            fp = i+1;
            sp = i;
            break;
        }
        else if(k > i){
            k = k - i;
        }
        else{
            fp = i+1;
            sp = k;
            break;
        }
    }

    string s = "";
    for(int i = n; i > 0; i--){
        if(i == fp || i == sp){
            s = s + 'b';
        }
        else{
            s = s + 'a';
        }
    }

    cout << s << endl;   

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