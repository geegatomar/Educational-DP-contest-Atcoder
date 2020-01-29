#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n;
    vector<vector<int> > activities(n,vector<int> (3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>activities[i][j];
        }
    }
    vector<vector<int> > ans(n,vector<int> (3));
    ans[0][0]=activities[0][0];
    ans[0][1]=activities[0][1];
    ans[0][2]=activities[0][2];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            ans[i][j]=activities[i][j] + max(ans[i-1][(j+1)%3],ans[i-1][(j+2)%3]);
        }
    }
    int an=0;
    for(int i=0;i<3;i++)
    an = max(an,ans[n-1][i]);
    cout<<an;
    return 0;
}

