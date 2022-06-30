/*
You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with weight capacity ‘W’. You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.
For Example
Let us say we have 'N' = 3 items and a knapsack of capacity 'W' =  10
'PROFIT' = { 5, 11, 13 }
'WEIGHT' = { 2, 4, 6 }

We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 i.e ‘27’. Therefore maximum profit = 27.
*/
#include<bits/stdc++.h>
using namespace std;

int recursiveCal(vector<int>&value,vector<int>&wt,vector<vector<int>>&memo,int n,int w)
{
    if(n==0)
    {
        int ans=(w/wt[0])*value[0];
        return ans;
    }
    if(memo[n][w]!=-1)
    {
        return memo[n][w];
    }
    int include=0;
    int exclude=0;
    exclude=recursiveCal(value,wt,memo,n-1,w);
    if(w>=wt[n])
    {
        include=recursiveCal(value,wt,memo,n,w-wt[n])+value[n];
    }
    memo[n][w]=max(include,exclude);
    return memo[n][w];
}

int tabulationCal(vector<int>&value,vector<int>&wt,int w)
{
    int n=value.size();
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int i=0;i<=w;i++)
    {
        dp[0][i]=(i/wt[0])*value[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            int include = 0;
            int exclude = 0;
            exclude = dp[i- 1][j];
            if (j >= wt[i])
            {
                include = dp[i][j-wt[i]]+value[i];
            }
            dp[i][j]=max(include,exclude);
        }
    }
    return dp[n-1][w];
}

int main()
{
    int n,w;
    cin>>n>>w;
    vector<int> v(n);
    vector<int> wt(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    vector<vector<int>>memo(n,vector<int>(w+1,-1));

    int ans1= recursiveCal(v,wt,memo,n-1,w);
    cout<<ans1<<endl;

    int ans2= tabulationCal(v,wt,w);
    cout<<ans2<<endl;

    return 0;

}