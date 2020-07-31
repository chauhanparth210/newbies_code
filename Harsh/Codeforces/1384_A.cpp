// https://codeforces.com/problemset/problem/1384/A
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){

    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        string str ="a";
        for(int i = 1; i < a[0]; i++)
            str = str + 'a';
       
        cout << str << endl;

        int count = 1;
        char ch = 'a';
        for(int i = 1; i < n; i++){

            if(a[i-1] <= a[i]){
                
                if(a[i] == 0 || a[i] - a[i-1] > 0){
                    count++;
                    char c = (char)(96 + count);
                    if(c == ch)
                        count++;
                }
                
                if(count == 27)
                    count = 1;

                str = str.substr(0, a[i-1]);
               // cout << str.size() << endl;

                if(str == "" && a[i] == 0)
                    str = (char)(96 + count);

                for(int j = 0; j < a[i]-a[i-1]; j++)
                    str = str + (char)(96 + count);
                cout << str << endl;
            }
            else{
                cout << str << endl;
                ch = str[a[i]];
                str = str.substr(0, a[i]);
            }
        }

        str = str.substr(0, a[n-1]);
        if(str == "")
            str = (char)(96 + count + 1);
        cout << str << endl;
    }
    

    return 0;
}