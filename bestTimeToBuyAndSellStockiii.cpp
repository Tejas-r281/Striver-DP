/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include<bits/stdc++.h>
using namespace std;

int recursive(vector<int> &prices, int index, int trans, int buyorsell, vector<vector<vector<int>>> &dp)
{
    if (index == prices.size() or trans == 0)
    {
        return 0;
    }

    if (dp[index][trans][buyorsell] != -1)
    {
        return dp[index][trans][buyorsell];
    }

    if (buyorsell)
    {
        int ans = 0;
        ans = max(-prices[index] + recursive(prices, index + 1, trans, !buyorsell, dp), recursive(prices, index + 1, trans, buyorsell, dp));
        return dp[index][trans][buyorsell] = ans;
    }
    else
    {
        int ans = 0;
        ans = max(prices[index] + recursive(prices, index + 1, trans - 1, !buyorsell, dp), recursive(prices, index + 1, trans, buyorsell, dp));
        return dp[index][trans][buyorsell] = ans;
    }
}

int tabulation(vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
    /*      here my matrix size is of n*3*2;
           we can matrix of size 3*2

    */
    vector<vector<int>> ahead(3, vector<int>(2, 0));
    vector<vector<int>> curr(3, vector<int>(2, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int trans = 1; trans < 3; trans++)
        {
            for (int buyorsell = 0; buyorsell < 2; buyorsell++)
            {
                if (buyorsell)
                {
                    int ans = 0;
                    ans = max(-prices[index] + ahead[trans][!buyorsell], ahead[trans][buyorsell]);
                    curr[trans][buyorsell] = ans;
                }
                else
                {
                    int ans = 0;
                    ans = max(prices[index] + ahead[trans - 1][!buyorsell], ahead[trans][buyorsell]);
                    curr[trans][buyorsell] = ans;
                }
            }
        }
        ahead = curr;
    }

    return curr[2][1];
}

int main()
{
    int n;
    cin>>n;
    vector<int>input(n);
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
    int ans=recursive(input,0,3,1,dp);
    cout<<ans<<endl;
    int ans1=tabulation(input);
    cout<<ans1<<endl;
}

/*
In recursion + memoization
  time complexity= O(n*3*2);
  space complexity= O(n*3*2)+ recusive stack

In tabulation
    time complexity= O(n*3*2);
    space complexity= O(3*2);
*/