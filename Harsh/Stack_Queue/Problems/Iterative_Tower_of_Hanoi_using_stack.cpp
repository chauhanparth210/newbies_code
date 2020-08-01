#include<bits/stdc++.h>
using namespace std;

void Iterative_Tower_of_Hanoi(int n){
    
    stack<int> s[3];
    for(int i = n; i > 0; i--){
        s[0].push(i);
    }

    long total = pow(2, n);

    for(long i = 1; i < total; i++){
        if(n % 2 == 0){
            if(i % 3 == 1){
                if(s[1].empty() || (!s[0].empty() && s[1].top() > s[0].top())){
                    s[1].push(s[0].top());
                    cout << "Move " << s[0].top() << " from A to B\n";
                    s[0].pop();
                }
                else{
                    s[0].push(s[1].top());
                    cout << "Move " << s[1].top() << " from B to A\n";
                    s[1].pop();
                }
            }
            else if(i % 3 == 2){
                if(s[2].empty() || (!s[0].empty() && s[2].top() > s[0].top())){
                    s[2].push(s[0].top());
                    cout << "Move " << s[0].top() << " from A to C\n";
                    s[0].pop();
                }
                else{
                    s[0].push(s[2].top());
                    cout << "Move " << s[2].top() << " from C to A\n";
                    s[2].pop();
                }
            }
            else if(i % 3 == 0){
                if(s[2].empty() || (!s[1].empty() && s[2].top() > s[1].top())){
                    s[2].push(s[1].top());
                    cout << "Move " << s[1].top() << " from B to C\n";
                    s[1].pop();
                }
                else{
                    s[1].push(s[2].top());
                    cout << "Move " << s[2].top() << " from C to B\n";
                    s[2].pop();
                }
            }
        }
        else{
            if(i % 3 == 1){
                if(s[2].empty() || (!s[0].empty() && s[2].top() > s[0].top())){
                    s[2].push(s[0].top());
                    cout << "Move " << s[0].top() << " from A to C\n";
                    s[0].pop();
                }
                else{
                    s[0].push(s[2].top());
                    cout << "Move " << s[2].top() << " from C to A\n";
                    s[2].pop();
                }
            }
            else if(i % 3 == 2){
                if(s[1].empty() || (!s[0].empty() && s[1].top() > s[0].top())){
                    s[1].push(s[0].top());
                    cout << "Move " << s[0].top() << " from A to B\n";
                    s[0].pop();
                }
                else{
                    s[0].push(s[1].top());
                    cout << "Move " << s[1].top() << " from B to A\n";
                    s[1].pop();
                }
            }
            else if(i % 3 == 0){
                if(s[2].empty() || (!s[1].empty() && s[2].top() > s[1].top())){
                    s[2].push(s[1].top());
                    cout << "Move " << s[1].top() << " from B to C\n";
                    s[1].pop();
                }
                else{
                    s[1].push(s[2].top());
                    cout << "Move " << s[2].top() << " from C to B\n";
                    s[2].pop();
                }
            }
        }
    }

    return;
}


int main(){
    
    int n;
    cin >> n;

    Iterative_Tower_of_Hanoi(n);

    return 0;
}