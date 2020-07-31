// https://codeforces.com/problemset/problem/1381/A1
#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    int n;
    while(test--){
        cin >> n;

        string a, b;
        cin >> a >> b;

        vector<int> v;
        for(int i = n-1; i > -1; i--){
            if(a[i] != b[i]){
                if(a[0] == b[i]){
                    v.push_back(0);
                    a[0] = (a[0] == '0'? '1': '0');
                    //cout << a << endl;
                }
                reverse(a.begin(), a.begin()+i+1);
                for(int j = 0; j <= i; j++){
                    a[j] = (a[j] == '0'? '1': '0');
                }
                //cout << a << endl;
                v.push_back(i);
            }
        }
        cout << v.size();
        for(int i = 0; i < v.size(); i++){
            cout << " " << v[i]+1;
        }
        cout << endl;
    }
    return 0;
}