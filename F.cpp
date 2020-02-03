#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    string s,t;
    cin>>s;
    cin>>t;
    ll row = s.length();
    ll col = t.length();
    vector<vector<ll> > dp(row+1, vector<ll> (col+1));
    dp[0][0]=0;
    for(int i=0;i<=row;i++)
    dp[i][0]=0;
    for(int i=0;i<=col;i++)
    dp[0][i]=0;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(s[i-1] == t[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=row,j=col;
    string ans="";
    while(i!=0 && j!=0)
    {
        if(dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else if(dp[i][j] == dp[i][j-1])
        {
            j--;
        }
        else if(dp[i][j] == dp[i-1][j-1]+1)
        {
            ans+=s[i-1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}

