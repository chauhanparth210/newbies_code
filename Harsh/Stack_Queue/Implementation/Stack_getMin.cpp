#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int size;
    vector<int> v, min_val;
};

void push(Stack *s, int val){
    s -> v.push_back(val);
    s -> size++;
    if(s -> min_val.size() == 0)
        s -> min_val.push_back(val);
    else 
        s -> min_val.push_back(min(val, s -> min_val[s -> min_val.size() - 1]));
    return;
}

void pop(Stack *s){
    s -> size--;
    s -> v.erase(s -> v.begin() + s -> size);
    s -> min_val.erase(s -> min_val.begin() + s -> min_val.size() - 1);
    return;
}

int top(Stack s){
    return s.v[s.size-1];
}

int getMin(Stack *s){
    return s -> min_val[s -> min_val.size() - 1];
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
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);

    show(s);
    cout << getMin(&s) << endl;
    pop(&s);
    cout << getMin(&s) << endl;
    show(s);
    pop(&s);

    show(s);

    return 0;
}