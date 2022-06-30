#include<bits/stdc++.h>
using namespace std;



int recursiveFib(int n,vector<int>&memo)
{
    if(n<=1)
    {
        return 1;
    }
    if(memo[n]!=-1)
    {
        return memo[n];
    }

    return recursiveFib(n-1,memo)+recursiveFib(n-2,memo);
}
/*

In tabulation approach

we need to calculate our answer through give base case

*/
int dpFib(int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}


int main()
{
    int n;
    cin>>n;
     vector<int>memo(n+1,-1);
    int ans1=recursiveFib(n,memo);
    int ans2=dpFib(n);
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