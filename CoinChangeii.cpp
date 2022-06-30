/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.
*/

#include<bits/stdc++.h>
using namespace std;

int recursiveCount(vector<int>&value,int target,int n,vector<vector<int>>&memo)
{
    // base case just think about the case when n==0;that means only one element are there .
    if(n==0)
    {
        return target%value[0]==0;
    }

    if(memo[n][target]!=-1)
    {
        return memo[n][target];
    }
    int notinclude=0;
    int include=0;
    notinclude=recursiveCount(value,target,n-1,memo);
    if(value[n]<=target)
    {
        include=recursiveCount(value,target-value[n],n,memo);
    }
    return memo[n][target]=(notinclude+include);
}

int tabulationCount(vector<int>&input,int target)
{
    int n=input.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for(int i=0;i<=target;i++)
    {
        dp[0][i]=(i%input[0]==0);
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            int notinclude=0;
            int include=0;
            notinclude=dp[i-1][j];
            if(input[i]<=j)
            {
                include=dp[i][j-input[i]];
            }
            dp[i][j]=notinclude+include;
        }
    }
    return dp[n-1][target];
}

int main()
{
   int n;
   cin>>n;
    vector<int>value(n);
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    int target;
    cin>>target;
    vector<vector<int>>memo(n,vector<int>(target+1,-1));
    cout<<recursiveCount(value,target,n-1,memo)<<endl;
    cout<<tabulationCount(value,target)<<endl;
    return 0;
}