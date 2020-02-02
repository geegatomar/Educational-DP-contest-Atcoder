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
    ll sum_value=0;
    for(ll i=0;i<n;i++)
    sum_value+= value[i];
    vector<ll> dp(sum_value+1,1e18);
    dp[0]=0;
    for(ll i =0;i<n;i++)
    {
        for(ll j=sum_value-value[i];j>=0;j--)
        {
            dp[j+value[i]] = min(dp[j+value[i]],dp[j]+weight[i]);
        }
    }
    ll ans = -1;
    for(ll i=1;i<=sum_value;i++)
    {
        if(dp[i] <= w)
        {
            ans = max(ans,i);
        }
    }
    cout<<ans;
    return 0;
}

