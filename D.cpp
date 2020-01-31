#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{
    ll n,w;
    cin>>n>>w;
    vector<ll> weight(n);
    vector<ll> value(n);
    for(ll i=0;i<n;i++)
    {
        cin>>weight[i];
        cin>>value[i];
    }
    vector<vector<ll> > ans(n,vector<ll> (w+1,0));
    for(ll i=weight[0];i<=w;i++)
    ans[0][i]=value[0];
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<=w;j++)
        {
            if((j-weight[i]) >= 0)
            {
                ans[i][j]=max(ans[i-1][j],value[i]+ans[i-1][j-weight[i]]);
            }
            else
            ans[i][j]=ans[i-1][j];
        }
    }
    ll an=0;
    for(ll i=1;i<=w;i++)
    an = max(an,ans[n-1][i]);
    cout<<an;
    return 0;
}

