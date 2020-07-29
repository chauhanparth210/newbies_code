#include<bits/stdc++.h>
using namespace std;

class Stack{
    int size;
    vector<int> v;

    public:
    Stack(){
        size = 0;
    }

    void push(int val){
        v.push_back(val);
        size++;
    }

    void pop(){
        size--;
        v.erase(v.begin() + size);
    }

    int top(){
        return v[size-1];
    }

    bool isEmpty(){
        return size == 0;
    }

    void show(){
        for(int i = 0; i < size; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

void stock_span(int a[], int span[], int n){

    memset(span, 0, sizeof(int)*n);
    Stack s;
   
    for(int i = 0; i < n; i++){
        if(!s.isEmpty()){
            while(!s.isEmpty() && a[s.top()] <= a[i]){
                span[i] = span[i] + span[s.top()];
                s.pop();
            }
        }
        s.push(i);
        span[i]++;
    }

   return;
}


int main(){
    
    int n;
    cin >> n;

    int a[n];  // = {100, 80, 60, 70, 60, 75, 85};
    int span[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    stock_span(a, span, n);

    for(int i = 0; i < n; i++){
        cout << span[i] << " ";
    }
    cout << endl;
    
    return 0;
}