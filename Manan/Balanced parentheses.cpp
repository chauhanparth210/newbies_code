#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<char> c;
    for(int i=0;i<s.size();i++)
    {
        if(c.empty())
        {
            c.push(s[i]);
            continue;
        }
        if(s[i]==')')
        {
            if(c.top()=='(')
            {
                c.pop();
            }
            else
                c.push(s[i]);
        }
        else if(s[i]=='}')
        {
            if(c.top()=='{')
            {
                c.pop();
            }
            else
                c.push(s[i]);
        }
        else if(s[i]==']')
        {
            if(c.top()=='[')
                c.pop();
            else
                c.push(s[i]);
        }
        else
            c.push(s[i]);
    }
    if(c.empty())
        cout<<"Balanced"<<endl;
    else
        cout<<"Not Balanced"<<endl;
}
