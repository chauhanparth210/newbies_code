//https://codeforces.com/problemset/problem/1328/C
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    string a = "1", b = "1";
    cin >> s;

    int flag = 0;
    for(int i = 1; i < n; i++){

        if(s[i] == '2' && flag == 0){
            a = a + "1";
            b = b + "1";
        }
        else if(s[i] == '2' && flag == 1){
            a = a + "0";
            b = b + "2";
        }
        else if(s[i] == '1' && flag == 0){
            a = a + "1";
            b = b + "0";
            flag = 1;
        }
        else if(s[i] == '1' && flag == 1){
            a = a + "0";
            b = b + "1";
        }
        else{
            a = a + "0";
            b = b + "0";
        }
    }

    cout << a << endl << b << endl;

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