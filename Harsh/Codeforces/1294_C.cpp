// https://codeforces.com/problemset/problem/1294/C
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int test;
    cin >> test;

    while(test--){
        long long n;
        cin >> n;

        int flag = 0;
        long long temp = n;
        for(long long i = 2; i <= floor(cbrt(n)); i++){
            temp = n;
            if(temp % i == 0){
                temp = temp / i;
                for(long long j = 2; j <= floor(sqrt(temp)); j++){
                    if(i != j && temp % j == 0){
                        if(j != temp/j){
                            cout << "YES\n" << i << " " << j << " " << temp/j << endl;
                            flag = 1;
                            break;
                        }
                    }
                }

                if(flag == 1)
                    break;
            }
        }

        if(flag == 0)
            cout << "NO\n";
    }
    return 0;
}