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

int max_histogram_area(int a[], int n){
    
    int l_min[n], r_min[n];

    Stack s;
    for(int i = 0; i < n; i++){
        while(!s.isEmpty() && a[s.top()] >= a[i]){
            s.pop();
        }
        l_min[i] = (!s.isEmpty()? s.top(): i-1);
        s.push(i);
    }
    

    Stack s1;
    for(int i = n-1; i > -1; i--){
        while(!s1.isEmpty() && a[s1.top()] >= a[i]){
            s1.pop();
        }
        r_min[i] = (!s1.isEmpty()? s1.top(): i+1);
        s1.push(i);
    }

    int mx_area = INT_MIN;
    for(int i = 0; i < n; i++){
        int area = a[i] * (r_min[i] - l_min[i] - 1);
        mx_area = max(mx_area, area);
    }
    return mx_area;
}


int main(){
    
    int n;
    cin >> n;

    int a[n];  // = {100, 80, 60, 70, 60, 75, 85};

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    cout << max_histogram_area(a, n) << endl;
    
    return 0;
}