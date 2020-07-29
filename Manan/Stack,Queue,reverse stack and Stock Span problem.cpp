#include<bits/stdc++.h>
using namespace std;

class Stack
{
public:
    vector<int> a;
    void push(int x)
    {
        a.push_back(x);
    }
    void pop()
    {
        if(a.size()==0)
        {
            cout<<"Stack is already empty!!"<<endl;
        }
        else
        {
            a.pop_back();
        }
    }
    int top()
    {
        if(a.size()==0)
        {
            cout<<"Stack is already empty!!"<<endl;
        }
        else
        {
            return a[a.size()-1];
        }
    }
    bool isEmpty()
    {
        if(a.size()==0)
        {
            return true;
        }
        else
            return false;
    }
    void output_S()
    {
        cout<<"Stack : ";
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};

class Queue
{
public:
    vector<int> a;
    void Enqueue(int x)
    {
        a.push_back(x);
    }
    void Dequeue()
    {
        if(a.size()==0)
        {
            cout<<"Queue is already Empty!!"<<endl;
        }
        else
            a.erase(a.begin());
    }
    int Front()
    {
        if(a.size()==0)
        {
            cout<<"Queue is already Empty!!"<<endl;
        }
        else
            return a[a.size()-1];
    }
    int Rear()
    {
        if(a.size()==0)
        {
            cout<<"Queue is already Empty!!"<<endl;
        }
        else
            return a[0];
    }
    bool isEmpty()
    {
        if(a.size()==0)
            return true;
        else
            return false;
    }
    void output_Q()
    {
        cout<<"Queue : ";
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};

void reverse_S(Stack& s)
{
    vector<int> a;
    while(!s.isEmpty())
    {
        a.push_back(s.top());
        s.pop();
    }
    for(int i=0;i<a.size();i++)
    {
        s.push(a[i]);
    }
}
int Stock_Span(Stack& s,int x)
{
    int ans=0;
    vector<int> store;
    while(!s.isEmpty())
    {
        int d=s.top();
        if(x>=d)
        {
            store.push_back(d);
            ans++;
            s.pop();
        }
        else
        {
            break;
        }
    }
    if(store.size()>0)
    {
        for(int i=store.size()-1;i>=0;i--)
        {
            s.push(store[i]);
        }
    }
    s.push(x);
    ans++;
    return ans;
}
int main()
{
    Stack s;

    for(int i=1;i<=10;i++)
        s.push(i);

    s.output_S();

    for(int i=1;i<=5;i++)
        s.pop();

    s.output_S();

    int first=s.top();
    cout<<"Top element : "<<first<<endl;

    if(s.isEmpty())
        cout<<"Stack is Empty"<<endl;
    else
        cout<<"Stack is not Empty"<<endl;

    cout<<endl<<endl;

    Queue q;

    for(int i=1;i<=10;i++)
        q.Enqueue(i);

    q.output_Q();

    for(int i=1;i<=5;i++)
        q.Dequeue();

    q.output_Q();

    first=q.Front();
    cout<<"Last element : "<<first<<endl;

    first=q.Rear();
    cout<<"First element : "<<first<<endl;

    if(q.isEmpty())
        cout<<"Queue is Empty"<<endl;
    else
        cout<<"Queue is not Empty"<<endl;

    cout<<endl<<endl;

    //reverse stack
    s.output_S();

    reverse_S(s);

    cout<<"Reversed ";
    s.output_S();

    cout<<endl<<endl;

    //Stock Span Problem
    while(!s.isEmpty())
    {
        s.pop();
    }

    //cout<<"Enter number of days : "<<endl;
    //int n;
    //cin>>n;
    vector<int> a;
    //cout<<"Enter the price for each day : "<<endl;
    /*for(int i=0;i<n;i++)
        cin>>a[i];*/
    a.push_back(100);
    a.push_back(80);
    a.push_back(60);
    a.push_back(70);
    a.push_back(60);
    a.push_back(75);
    a.push_back(85);

    vector<int> ans(a.size());
    int cnt;
    for(int i=0;i<a.size();i++)
    {
        cnt=Stock_Span(s,a[i]);
        ans[i]=cnt;
    }

    cout<<"Question : ";
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Answer   : ";
    for(int i=0;i<a.size();i++)
        cout<<ans[i]<<" ";

    cout<<endl<<endl;
}
