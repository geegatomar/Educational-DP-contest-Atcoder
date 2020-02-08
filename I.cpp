#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n;
    cin>>n;
    vector<double> prob(n);
    for(ll i=0;i<n;i++)
    cin>>prob[i];
    // columns represents number of heads
    vector<vector<double> > prob_table(n,vector<double> (n+1,0.0));
    prob_table[0][0]=1-prob[0];
    prob_table[0][1]=prob[0];
    for(ll i=1;i<n;i++)
    {
        prob_table[i][0]=(1.0-prob[i])*prob_table[i-1][0];
    }
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            prob_table[i][j]=prob[i]*prob_table[i-1][j-1] + (1.0-prob[i])*prob_table[i-1][j];
        }
    }
    /*for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<=n;j++)
        cout<<prob_table[i][j]<<" ";
        cout<<"\n";
    }*/
    double final_ans=0.0;
    for(ll i=(n+1)/2;i<=n;i++)
    final_ans+=prob_table[n-1][i];
    cout<<setprecision(10)<<final_ans;
    return 0;
}

