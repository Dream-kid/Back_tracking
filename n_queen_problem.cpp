#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define a 8
bool can_go(lli step,lli s,lli ara[a][a])
{
    lli m=s-step;
    lli n=s+step;
    for(lli i=0; i<a; i++)
    {
        for(lli j=0; j<a; j++)
        {
            if(i+j==n||i-j==m)
            {
                if(ara[i][j]) return false;
            }
        }
    }
    for(lli i=0; i<a; i++)
    {
        if(ara[i][step]) return false;
        if(ara[s][i]) return false;
    }
    return true;
}
bool back_tracking(lli ara[a][a],lli step)
{
    if(step>=a) return true;
    for(lli i=0; i<a; i++)
    {
        if(can_go(step,i,ara)==true)
        {
            ara[i][step]=1;
            if(back_tracking(ara,step+1)==true)return true;
            ara[i][step]=0;
        }
    }
    return false;
}
preque(lli ara[a][a])
{
    lli    step=0;
    back_tracking(ara,step);
    for(lli i=0; i<a; i++)
    {
        for(lli j=0; j<a; j++)
            cout<<ara[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    lli ara[a][a]= {0};
    preque(ara);
}
