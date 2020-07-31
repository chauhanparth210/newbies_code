// https://codeforces.com/problemset/problem/1352/F
#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    int n0, n1, n2;
    while(test--){
        cin >> n0 >> n1 >> n2;

        string s = "";
        for(int i = 0; i <= n0 && n0 != 0; i++){
            s = s + "0";
        }
        for(int i = 0; i <= n2 && n2 != 0; i++){
            s = s + "1";
        }

        if(n1 == 0){
            cout << s << endl;
            continue;
        }

        char ch[2] = {'0', '1'};
        if(n0 == 0){
            ch[0] = '1';
            ch[1] = '0';
            n1++;
        }
        if(n2 == 0)
            n1++;
        for(int i = 1; i < n1; i++){
                s = ch[i%2] + s;
        }

        cout << s << endl;
    }

    return 0;
}