#include<bits/stdc++.h>
using namespace std;

void Next_smaller_element(int a[], int ans[], int n){
    stack<int> s;

    for(int i = n-1; i > -1; i--){
        if(!s.empty()){
            while(!s.empty() && a[s.top()] >= a[i]){
                s.pop();
            }
        }
        ans[i] = (s.empty()? -1: s.top());
        s.push(i);
    }
   
}


int main(){
    
    int n;
    cin >> n;

    int a[n]; // = {100, 80, 60, 70, 60, 75, 85};

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans[n];    
    Next_smaller_element(a, ans, n);

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}