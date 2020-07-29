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


void Reverse(Stack *s){
    vector<int> v;

    while (!s -> isEmpty()){
        v.push_back(s -> top());
        s -> pop();
    }

    for(int i = 0; i < v.size(); i++){
        s -> push(v[i]);
    }
}

int main(){
    
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.show();

    Reverse(&s);
    s.show();
    return 0;
}