#include<bits/stdc++.h>
using namespace std;

bool Balanced_Parenthesis(string str){
    stack<int> s;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            s.push(i);
        }
        else{
            if(!s.empty())
                s.pop();
            else 
                return false;
        }
    }

    return true;
}


int main(){
    
    string str;
    cin >> str;

    cout << Balanced_Parenthesis(str) << endl;

    return 0;
}