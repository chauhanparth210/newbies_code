#include<bits/stdc++.h>
using namespace std;

void Next_Greater(vector<int> a)
{
    cout<<"Next Greater : ";
    stack<int> s;
    vector<int> ans(a.size());
    s.push(0);
    int i=1;
    while(1)
    {
        int next=i;
        if(s.empty())
        {
            s.push(next);
            i++;
        }
        else if(a[next]>a[s.top()])
        {
            ans[s.top()]=a[next];
            s.pop();
        }
        else
        {
            s.push(next);
            i++;
        }
        if(i==a.size())
            break;
    }
    while(!s.empty())
    {
        ans[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

void Next_Smaller(vector<int> a)
{
    cout<<"Next Smaller : ";
    stack<int> s;
    vector<int> ans(a.size());
    s.push(0);
    int i=1;
    while(1)
    {
        int next=i;
        if(s.empty())
        {
            s.push(next);
            i++;
        }
        else if(a[next]<a[s.top()])
        {
            ans[s.top()]=a[next];
            s.pop();
        }
        else
        {
            s.push(next);
            i++;
        }
        if(i==a.size())
            break;
    }
    while(!s.empty())
    {
        ans[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    stack<int> s;
    cout<<"Enter number of elements : "<<endl;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    Next_Greater(a);

    Next_Smaller(a);

    cout<<endl;
}
