#include<bits/stdc++.h>
using namespace std;

long solve(string s, int n){

    long count = 0;
    long ans = 0;
    int first_p = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            count--;
        }
        else{
            count++;
        }
        
        if(count > 0 && first_p == -1){
            first_p = i;
            
        }
        else if(first_p != -1 && count == 0){
            ans = ans + i - first_p + 1;
            first_p = -1;
            
        }
    }

    if(count == 0)
        return ans;
    
    return -1;
}

int main(){

    long n;
    cin >> n;

    string s;
    cin >> s;

    cout << solve(s, n) << endl;
    

    return 0;
}