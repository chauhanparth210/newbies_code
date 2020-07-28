#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    int n;
    while(test--){
        cin >> n;

        string s, s1 = "abacaba";
        cin >> s;

        int found = s.find(s1);
        int n = s.size();
        
        if(found != -1){
            found = s.find(s1, found+1);
           // cout << found << endl;
            if(found == -1){
                cout << "YES\n";
                for(int i = 0; i < n; i++){
                    cout << (s[i] == '?'? 'x': s[i]);
                }
                cout << endl;
            }
            else{
                cout << "NO\n";
            }
            continue;
        }

        int flag = 0;
        for(int i = 0; i < n; i++){

            if(flag == 1 || i+6 >= n){
                if(s[i] == '?')
                    s[i] = 'x';
                continue;
            }
            string temp = "";
            for(int j = 0; j < 7; j++){
                if(s[i+j] == s1[j] || s[i+j] == '?'){
                    temp = temp + s[i+j];
                    s[i+j] = s1[j];
                }
                else{
                    break;
                }
            }
            
            if(temp.size() == 7){
                int j = (i-6 > -1? i-6: 0);
                for(j; j < i+7 && j+6 < n; j++){   
                    if(j == i)
                        continue;         
                    string sub_s1 = s.substr(j, 7);
                    if(sub_s1 == s1){
                        for(int k = 0; k < 7; k++){
                            s[i+k] = temp[k];
                        }
                        s[i] = (s[i]=='?'? 'x': s[i]);
                        break;
                    }
                }
                if(j >= i+7 || j+6 >= n){
                    flag = 1;
                    i = i+6;
                }   
            }
            else{
                for(int k = 0; k < temp.size(); k++){
                    s[i+k] = temp[k];
                }
                s[i] = (s[i]=='?'? 'x': s[i]);
            }
        }

        if(flag == 0)
            cout << "NO\n";
        else{
            cout << "YES\n";
            cout << s << endl;
        }

        
    }
    return 0;
}