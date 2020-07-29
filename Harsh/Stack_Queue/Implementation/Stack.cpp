#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int size;
    vector<int> v;
};

void push(Stack *s, int val){
    s -> v.push_back(val);
    s -> size++;
    return;
}

void pop(Stack *s){
    s -> size--;
    s -> v.erase(s -> v.begin() + s -> size);
    return;
}

int top(Stack s){
    return s.v[s.size-1];
}

bool isEmpty(Stack s){
    return s.size == 0;
}

void show(Stack s){
    for(int i = 0; i < s.size; i++){
        cout << s.v[i] << " ";
    }
    cout << endl;
}

int main(){
    
    Stack s;
    s.size = 0;
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);

    show(s);
    pop(&s);
    cout << top(s) << endl;
    pop(&s);

    show(s);
    pop(&s);

    show(s);

    return 0;
}