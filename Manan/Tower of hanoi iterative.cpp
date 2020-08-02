#include<bits/stdc++.h>
using namespace std;

stack<int> source,aux,des;
int moves,n;
void towerofhanoi()
{
    if(n%2==0)
    {
        for(int i=0;i<moves;i++)
        {
            if(i%3==0)
            {
                if(aux.empty() || (!source.empty() && aux.top()>source.top()))
                {
                    cout<<"Move disk from source to auxiliary."<<endl;
                    aux.push(source.top());
                    source.pop();
                }
                else
                {
                    cout<<"Move disk from auxiliary to source."<<endl;
                    source.push(aux.top());
                    aux.pop();
                }
            }
            else if(i%3==1)
            {
                if(des.empty() || (!source.empty() && des.top()>source.top()))
                {
                    cout<<"Move disk from source to destination."<<endl;
                    des.push(source.top());
                    source.pop();
                }
                else
                {
                    cout<<"Move disk from destination to source."<<endl;
                    source.push(des.top());
                    des.pop();
                }
            }
            else
            {
                if(aux.empty() || (!des.empty() && aux.top()>des.top()))
                {
                    cout<<"Move disk from destination to auxiliary."<<endl;
                    aux.push(des.top());
                    des.pop();
                }
                else
                {
                    cout<<"Move disk from auxiliary to destination."<<endl;
                    des.push(aux.top());
                    aux.pop();
                }
            }
        }
    }
    else
    {
        for(int i=0;i<moves;i++)
        {
            if(i%3==0)
            {
                if(des.empty() || (!source.empty() && des.top()>source.top()))
                {
                    cout<<"Move disk from source to destination."<<endl;
                    des.push(source.top());
                    source.pop();
                }
                else
                {
                    cout<<"Move disk from destination to source."<<endl;
                    source.push(des.top());
                    des.pop();
                }
            }
            else if(i%3==1)
            {
                if(aux.empty() || (!source.empty() && aux.top()>source.top()))
                {
                    cout<<"Move disk from source to auxiliary."<<endl;
                    aux.push(source.top());
                    source.pop();
                }
                else
                {
                    cout<<"Move disk from auxiliary to source."<<endl;
                    source.push(aux.top());
                    aux.pop();
                }
            }
            else
            {
                if(aux.empty() || (!des.empty() && aux.top()>des.top()))
                {
                    cout<<"Move disk from destination to auxiliary."<<endl;
                    aux.push(des.top());
                    des.pop();
                }
                else
                {
                    cout<<"Move disk from auxiliary to destination."<<endl;
                    des.push(aux.top());
                    aux.pop();
                }
            }
        }
    }
}

int main()
{
    cout<<"Enter the number of disk : "<<endl;
    cin>>n;
    for(int i=n;i>0;i--)
    {
        source.push(i);
    }
    moves=pow(2,n)-1;
    towerofhanoi();
}
