//https://uva.onlinejudge.org/external/7/750.pdf
#include <list>
#include <set>
#include <map>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <limits>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <bitset>
#include <numeric>
#include <cassert>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

#define sf scanf
#define pf printf
#define pi 2*acos(0.0)
#define ull unsigned long long
#define all(v) v.begin(),v.end()

#define sii(t) scanf("%d",&t)
#define ssssii(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define sssii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define ssii(a,b) scanf("%d%d",&a,&b)
#define sll(t) scanf("%lld",&t)
#define ssll(a,b) scanf("%lld%lld",&a,&b)
#define ssd(a,b) scanf("%lf%lf",&a,&b)
#define sssll(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define ssslf(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define ssssll(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Case1(no) printf("Case %d:\n",++no)
#define Case2(no) printf("Case %d: ",++no)
#define nl puts("")
#define pll(a) printf("%lld\n",a)
#define ppll(a,b) printf("%lld %lld\n",a,b)
#define pii(a) printf("%d\n",a)
#define ppii(a,b) printf("%d %d\n",a,b)


#define ff first
#define pb push_back
#define mp make_pair
#define se second
#define pb push_back
#define ST(v) sort(all(v))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define cover(a,d) memset(a,d,sizeof(a))
#define output freopen("out.txt","w",stdout)
#define input freopen("in.txt","r",stdin)
#define flop(m,n,q)             for(ll i=m;i<=n;i+=q)
#define optimize ios::sync_with_stdio(0), cin.tie(0)
////============ CONSTANT ===============////
#define mx  (100010)
#define inf 100010
#define eps 1e-9
#define mod1  1000000009
/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
const int fx[]= {-2, -2, -1, -1,  1,  1,  2,  2}; // Knights Move
const int fy[]= {-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
typedef long long ll;
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
//float __attribute__((aligned(32)))


////=====================================////
///-----SOURAV CHAKRABORTY-----///
///== KUET CSE 16 ==///
////=====================================////
// for substring search
/* b[10000];
void kmpPreprocess(char *substr)
{
    const int m = strlen(substr);
    int i = 0, j = -1;

    b[i] = -1;
    while(i < m)
    {
        while(j >= 0 && substr[i] != substr[j])
            j = b[j];

        i++;
        j++;
        b[i] = j;
    }
}

int kmp(char *str, char *substr)
{
    int i=0, j=0, count = 0;
    const int n = strlen(str);
    const int m = strlen(substr);
    kmpPreprocess(substr);
    while (i<n)
    {
        while (j>=0 && str[i]!=substr[j])
            j=b[j];

        i++;
        j++;

        if (j==m)
        {
            count++;
            j=b[j];
        }
    }
    return count;
}*/
/*
ll visited[inf+10];
//prime generator seive
void prime_generator()
{
    for(ll i=3; i*i<=inf; i+=2)
    {
        for(ll j=i*i; j<=inf; j+=2*i)
        {
            visited[j]=1;
        }
    }
    visited[0]=2;
    ll j=1;
    for(ll i=3; i<=inf; i+=2)
    {
        if(visited[i]==0)
        {
            visited[j]=i;
            j++;
        }
    }
}
*/
//string multiply
string multiply( string a, int b )
{
    // a contains the biginteger in reversed form
    int carry = 0;
    for( int i = 0; i < a.size(); i++ )
    {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry )
    {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}

// big mod
ll big_mod(ll base, ll power, ll mod)
{
    if(power==0)
        return 1;

    else if(power%2==1)
    {
        ll p1 = base % mod;
        ll p2 = (big_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2==0)
    {
        ll p1 = (big_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
}
// extended euclidean algorithm modulo inverse
void EE(ll a, ll b, ll& x, ll& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    ll temp = x;
    x = y;
    y = temp - y*(a/b);
}
ll inverse(ll a, ll m)
{
    ll x,y;
    EE(a,m,x,y);
    if(x<0)
        x += m;
    return x;
}
//fabonaci
/*map<ll, ll> F;
F[0]=F[1]=1;
ll f(ll n)
{
    if (F.count(n)) return F[n];
    ll k=n/2;
    if (n%2==0)   // n=2*k
    {
        return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % mod1;
    }
    else     // n=2*k+1
    {
    o    return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % mod1;
    }
}
*/
//---------------------------real code--------------------------------------------------------//
ll mark[10][10];
ll mark1[10][10];
ll X,Y;
bool is_safe(ll y,ll x)
{
    if(y==Y)
    {
        if(x!=X)
            return false;
    }
    if(mark1[y][x]||x>=9||y>=9||x<=0||y<=0)
        return false;
    return true;
}

ll cross(ll y,ll x,ll val)
{
    for(ll i=1; i<=8; i++)
    {
        for(ll j=1; j<=8; j++)
        {
            if(i==y||j==x||i-j==y-x||i+j==y+x)
                mark1[i][j]+=val;
        }
    }
}
string p;
vector<string>v;
void calc()
{
    p="";
    for(ll i=1; i<=8; i++)
    {
        for(ll j=1; j<=8; j++)
        {
            if(mark[j][i])
                p+=(j+'0');
        }
    }
    v.pb(p);
}
ll chess(ll y,ll o)
{
    if(y==9)
    {
        calc();
        return false;
    }
    for(ll i=1; i<=8; i++)
    {
        if(is_safe(y,i))
        {
            mark[y][i]=1;
            cross(y,i,1);
            if(chess(y+1,i))
            {
                return true;
            }
            else
            {
                mark[y][i]=0;
                cross(y,i,-1);
            }
        }
    }
    return false;
}
int main()
{
    // input;
    //output;
    ll a,b,io=0;
    sll(a);
    while(a--)
    {
        if(io)
            pf("\n");
        io++;
        ssll(Y,X);
        chess(1,0);
        sort(v.begin(),v.end());
        pf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        for(ll i=0; i<v.size(); i++)
        {
            p=v[i];
            if(i<9)
                pf(" ");
            pf("%lld     ",i+1);
            for(ll k=0; k<p.size(); k++)
                pf(" %c",p[k]);
            pf("\n");
        }
        cover(mark,0);
        cover(mark1,0);
        v.clear();
    }
}
