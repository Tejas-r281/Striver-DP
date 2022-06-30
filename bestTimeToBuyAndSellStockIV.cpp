/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
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
int tabulation(vector<int> &prices, int k)
{
    int n = prices.size();

    vector<vector<int>> ahead(k + 1, vector<int>(2, 0));
    vector<vector<int>> curr(k + 1, vector<int>(2, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int trans = 1; trans < k + 1; trans++)
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

    return curr[k][1];
}

int main()
{
    int n;
    cin>>n;
    vector<int> prices(n,0);

    for(int i=0; i<n; i++)
    {
        cin>>prices[i];
    }
    int k;
    cin>>k;

     vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
     int ans1= recursive(prices,0,k,1,dp);
    int ans = tabulation(prices, k);
    cout<<ans1<<endl;
    cout<<ans<<endl;
}

/*
In recursion +memoization
  time complexity: O(n*k*2);
  space complexity: O(n*k*2)+ recursion stack;

In tabulation
    time complexity: O(n*k*2);
    space complexity: O(k*2);
*/