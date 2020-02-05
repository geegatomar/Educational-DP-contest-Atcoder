#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI >     VVI;
typedef long long int     LL;
typedef unsigned long long int ULL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define DRT() int t; si(t); while(t--)

#define PlUSWRAP(index,n) index = (index+1)%n        //index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n     //index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)    //Round off d to nearest integer

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int n,m;
vector<vector<int> > g;
vector<bool> visited;
vector<int> dist;
vector<int> intime;
vector<int> dp;
vector<II> outtime;
vector<int> indegree;
int tt=0;
int ans=0;
void dfs(int s)
{
    visited[s] = true;
    tt++;
    intime[s] = tt;
    for(auto it : g[s])
    {
        if(!visited[it])
            dfs(it);
    }
    tt++;
    outtime[s] = MP(tt,s);
}
bool comp(const II &a,const II &b)
{
    return a.F > b.F;
}
void initialise()
{
    g.resize(n);
    dist.resize(n,0);
    visited.resize(n,false);
    intime.resize(n);
    outtime.resize(n);
    indegree.resize(n);
    dp.resize(n);
}
int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    off;
    cin>>n>>m;int u,v;
    initialise();
    rep(i,0,m)
    {
        cin>>u>>v;
        u--;v--;
        g[u].PB(v);
        indegree[v]++;
    }
    rep(i,0,n)
    {
        if((indegree[i] == 0) && (!visited[i]))
        {
            dfs(i); // topological sort
        }
    }
    // now sort the outtime in descending order;
    sort(ALL(outtime),comp);
    // now we can apply dp on the sorted order so that now we can get the correct order 
    // and that won't cause any problems
    dp[outtime[0].S] = 0;
    rep(i,0,n-1)
    {
        // for all the vertices u->v update the distance value of v
        for(auto it : g[outtime[i].S])
            dp[it] = max(dp[it],dp[outtime[i].S]+1);
    }
    int ans = 0;
    rep(i,0,n)
    ans = max(ans,dp[i]);
    cout<<ans;
    return 0;
}

