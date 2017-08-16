#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define a 8
bool is_safe(lli x,lli y,lli moves[a][a])
{
    if(x>=0&&y>=0&&x<a&&y<a&&moves[x][y]==0) return true;
    return false;
}
bool knight_moves(lli x,lli y,lli move,lli ara_x[a],lli ara_y[a],lli moves[a][a])
{
    if(move==a*a)
           return true;
    lli  next_x,next_y;
    for(lli i=0; i<a; i++)
    {

        next_x=x+ara_x[i];
        next_y=y+ara_y[i];
        if(is_safe(next_x,next_y,moves)==true)
        {
            moves[next_x][next_y]=move;
            if((knight_moves(next_x,next_y,move+1,ara_x,ara_y,moves))==true)return true;
            else     moves[next_x][next_y]=0;
        }
    }
    return false;
}
int main()
{

    lli moves[a][a]= {0};
    lli x[a]= {2,1,-1,-2,-2,-1,1,2};
    lli y[a]= {1,2,2,1,-1,-2,-2,-1};
    knight_moves(0,0,1,x,y,moves);
    for(lli i=0; i<a; i++)
    {
        for(lli j=0; j<a; j++)
           printf(" %2d ", moves[i][j]);
        printf("\n");

    }

}
