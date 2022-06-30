#include<bits/stdc++.h>
using namespace std;

int recursiveTarget(vector<int>&input,int n,vector<vector<int>>&memo,int target)
{
    if(target==0)
    {
        return 1;
    }
    if(n==0)
    {
        return input[n]==target;
    }

    if(memo[n][target]!=-1)
    {
        return memo[n][target];
    }
    int nottaken=0;
    int taken=0;
    nottaken=recursiveTarget(input,n-1,memo,target);//that means 0 to n-1th index tak kitna subset hai
    if(input[n]<=target)
    {
        taken=recursiveTarget(input,n-1,memo,target-input[n]);//that means nth index kitna subset hai
    }
    memo[n][target]=taken+nottaken;

    return memo[n][target];
}

int tabulationCheck(vector<int>&input,int target)
{
    int n=input.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    dp[0][input[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            int nottaken=dp[i-1][j];
            int taken=0;
            if(input[i]<=j)
            {
                taken=dp[i-1][j-input[i]];
            }
            dp[i][j]=taken+nottaken;
        }
    }
    return dp[n-1][target];
}

int main()
{
    int n;
    cin>>n;
    vector<int> input(n);
    int target;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    cin>>target;
    vector<vector<int>> memo(n,vector<int>(target+1,-1));

    int ans1= recursiveTarget(input,n-1,memo,target);

    int ans2=tabulationCheck(input,target);
    cout<<ans1<<" "<<ans2<<endl;
}