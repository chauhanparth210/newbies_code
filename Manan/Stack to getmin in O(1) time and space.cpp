#include<bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int min_ele;
    stack<int> s;
    void getmin()
    {
        if(s.empty())
            cout<<"Stack is empty!!"<<endl;
        else
        {
            cout<<"Minimum element is : "<<min_ele<<endl;
        }
        return;
    }
    void push(int x)
    {
        if(s.empty())
        {
            min_ele=x;
            s.push(x);
        }
        else
        {
            if(x>=min_ele)
            {
                s.push(x);
            }
            else
            {
                s.push(2*x-min_ele);
                min_ele=x;
            }
        }
        cout<<"Number inserted is : "<<x<<endl;
        return;
    }
    void pop()
    {
        if(s.empty())
            cout<<"Stack is Empty!!"<<endl;
        else
        {
            if(s.top()<min_ele)
            {
                cout<<"Top element removed : "<<min_ele<<endl;
                min_ele=2*min_ele-s.top();
                s.pop();
            }
            else
            {
                cout<<"Top element removed : "<<s.top()<<endl;
                s.pop();
            }
        }
    }
    void peek()
    {
        if(s.empty())
        {
            cout<<"Stack is empty!!"<<endl;
        }
        else
        {
            if(s.top()<min_ele)
            {
                cout<<"Top element is : "<<min_ele<<endl;
            }
            else
            {
                cout<<"Top element is : "<<s.top()<<endl;
            }
        }
        return;
    }
};

int main()
{
    Stack s;

    s.push(3);
    s.push(5);
    s.getmin();

    cout<<endl;
    s.push(2);
    s.push(1);
    s.getmin();

    cout<<endl;
    s.push(1);
    s.push(-1);
    s.getmin();

    cout<<endl;
    s.pop();
    s.getmin();

    cout<<endl;
    s.pop();
    s.getmin();

    cout<<endl;
    s.pop();
    s.getmin();

    cout<<endl;
    s.pop();
    s.getmin();

    cout<<endl;
    s.pop();
    s.getmin();

    cout<<endl;
    s.pop();
    s.getmin();
}
