/*
you have to take only 1 or 2 steps

then count number of ways to reach N  and return it ;

*/
#include<bits/stdc++.h>
using namespace std;

int recursiveCount(int n,vector<int>&memo)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(memo[n]!=-1)
    {
        return memo[n];
    }

    return recursiveCount(n-1,memo)+recursiveCount(n-2,memo);
}

int dpCount(int n )
{
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+ (i-2>=0?dp[i-2]:0);
    }
    return dp[n];
}


int main()
{
    int n;
    cin>>n;
  vector<int>memo(n+1,-1);
  int ans1= recursiveCount(n,memo);
  int ans2= dpCount(n);

  cout<<ans1<<" "<<ans2<<endl;
}

/*

In recusive + memoization


time complexity: O(n)
space complexity: O(n) for array  + O(n) because of recursion stack


In dp


time complexity: O(n)
space complexity: O(n)

*/