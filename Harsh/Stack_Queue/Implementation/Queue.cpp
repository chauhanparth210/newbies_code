#include<bits/stdc++.h>
using namespace std;

class Queue{
    vector<int> v;
    //int size;

    public:
    Queue(){}

    void push(int val){
        v.push_back(val);
    }

    void pop(){
        v.erase(v.begin());
    }

    int front(){
        if(v.size() > 0)
        return v[0];
    }

    bool isEmpty(){
        return v.size() == 0;
    }

    void show(){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.show();

    q.pop();
    q.pop();
    q.pop();

    cout << q.front() << endl;
    q.show();
    return 0;
}