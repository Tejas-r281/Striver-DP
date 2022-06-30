/*
Problem Statement

A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
*/
#include<bits/stdc++.h>
using namespace std;

int recursiveTarget( vector<int>&weight,vector<int>&value,int n ,vector<vector<int>>&memo,int capacity)
{
    if(n==0)
    {
        if(weight[n]>capacity)
            return 0;
        else
            return value[n];
    }
    if(capacity==0)
        return 0;

    if(memo[n][capacity]!=-1)
        return memo[n][capacity];

    int Exclude =  recursiveTarget(weight,value,n-1,memo,capacity);
    int Include = 0;
    if(weight[n]<=capacity)
        Include = value[n] + recursiveTarget(weight,value,n-1,memo,capacity-weight[n]);
    memo[n][capacity] = max(Exclude,Include);
    return memo[n][capacity];

}

int tabulationCheck(vector<int>&weight,vector<int>&value, int capacity)
{
    int n = weight.size();
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));

    // Base case accroding to the recursive one
    for(int i=weight[0];i<=capacity;i++)
    {
        dp[0][i] = value[0];
    }
    if(capacity==0)
    {
        return 0;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            int taken=0;
            int notTaken=0;
            if(weight[i]<=j)
            {
                taken = value[i] + dp[i-1][j-weight[i]];
            }
            notTaken = dp[i-1][j];
            dp[i][j] = max(taken,notTaken);
        }
    }
    return dp[n-1][capacity];

}

int main()
{
    int n;
    cin >> n;
    vector<int>weight(n);
    vector<int>value(n);
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    int capacity;
    cin>>capacity;
    vector<vector<int>>memo(n,vector<int>(capacity+1,-1));
    int ans=recursiveTarget(weight,value,n-1,memo,capacity);
    cout<<ans<<endl;
    int ans2=tabulationCheck(weight,value,capacity);
    cout<<ans2<<endl;
    return 0;

}