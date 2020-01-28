#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> height(n);
    for(int i=0;i<n;i++)
    cin>>height[i];
    
    vector<int> ans(n);
    ans[0]=0;
    ans[1]=abs(height[1]-height[0]);
    for(int i=2;i<n;i++)
    {
        int a=INT_MAX;
        for(int j=1;j<=k&&(i-j)>=0;j++)
        {
            a = min(a,abs(height[i-j]-height[i])+ans[i-j]);
        }
        ans[i]=a;
    }
    cout<<ans[n-1];
}

