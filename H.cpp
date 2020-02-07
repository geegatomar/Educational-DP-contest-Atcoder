#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll mod = (1e9 + 7);
vector<vector<char> > grid;
vector<vector<ll> > ans;
int main()
{
    ll h,w;    
    cin>>h>>w;
    grid.resize(h,vector<char> (w));
    ans.resize(h,vector<ll> (w));
    for(ll i=0;i<h;i++)
    {
        for(ll j=0;j<w;j++)
        {
            cin>>grid[i][j];
        }
    }
    ans[0][0]=1;
    for(ll i=1;i<h;i++)
    {
        if(grid[i][0] == '#')
        ans[i][0]=0;
        else
        ans[i][0]=ans[i-1][0];
    }
    for(ll i=1;i<w;i++)
    {
        if(grid[0][i]=='#')
        ans[0][i]=0;
        else
        ans[0][i]=ans[0][i-1];
    }
    for(ll i=1;i<h;i++)
    {
        for(ll j=1;j<w;j++)
        {
            if(grid[i][j] == '#')
            ans[i][j]=0;
            else
            ans[i][j]=(ans[i-1][j] + ans[i][j-1])%mod;
        }
    }
    cout<<ans[h-1][w-1];
    return 0;
}

