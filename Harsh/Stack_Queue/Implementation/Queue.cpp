#include<bits/stdc++.h>
using namespace std;

class Queue{
    vector<int> v;
    //int size;

    public:
    Queue(){}

    void enqueue(int val){
        v.push_back(val);
    }

    void dequeue(){
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

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.show();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << q.front() << endl;
    q.show();
    return 0;
}