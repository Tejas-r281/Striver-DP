/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/
#include<bits/stdc++.h>
using namespace std;

int recursiveEditDistance(string input1,string input2,int n,int m,vector<vector<int>>&dp)
{
   if(n<0 and m<0)
   {
    return 0;
   }
   if(n<0 and m>=0)
   {
    return m+1;
   }
    if(n>=0 and m<0)
    {
     return n+1;
    }
    if(dp[n][m]!=-1)
    {
     return dp[n][m];
    }
    int ans=0;
    if(input1[n]==input2[m])
    {
     ans=recursiveEditDistance(input1,input2,n-1,m-1,dp);
    }
    else
    {
     ans=min(recursiveEditDistance(input1,input2,n-1,m,dp),min(recursiveEditDistance(input1,input2,n,m-1,dp),recursiveEditDistance(input1,input2,n-1,m-1,dp)))+1;
    }
    return dp[n][m]=ans;
}

int tabulationEditDistance(string input1, string input2)
{
    vector<vector<int>>dp(input1.length()+1,vector<int>(input2.length()+1,0));
    int n= input1.size();
    int m= input2.size();
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=i+1;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=i+1;
    }
    dp[0][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int ans=0;
            if(input1[i-1]==input2[j-1])
            {
                ans=dp[i-1][j-1];
            }
            else
            {
                ans=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            }
            dp[i][j]=ans;
        }
    }
    return dp[n][m];
}

int main()
{
    string input1,input2;
    cin>>input1>>input2;
    vector<vector<int>> dp(input1.length()+1,vector<int>(input2.length()+1,-1));

    int ans=recursiveEditDistance(input1,input2,input1.length()-1,input2.length()-1,dp);
    cout<<ans<<endl;
    ans=tabulationEditDistance(input1,input2);
    cout<<ans<<endl;
}