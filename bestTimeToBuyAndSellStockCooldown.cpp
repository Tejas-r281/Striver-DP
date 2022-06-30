/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
#include<bits/stdc++.h>
using namespace std;
int calculateans(vector<int> &price, int buyorsell, int index, vector<vector<int>> &dp)
{
    if (index >= price.size())
    {
        return 0;
    }
    if (dp[index][buyorsell] != -1)
    {
        return dp[index][buyorsell];
    }
    if (buyorsell)
    {
        int ans = max(-price[index] + calculateans(price, !buyorsell, index + 1, dp), calculateans(price, buyorsell, index + 1, dp));
        return dp[index][buyorsell] = ans;
    }
    else
    {
        int ans1 = max(price[index] + calculateans(price, !buyorsell, index + 2, dp), calculateans(price, buyorsell, index + 1, dp));

        return dp[index][buyorsell] = ans1;
    }
}

int tabulation(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    // space optimization
    //  vector<int>ahead(2,0);
    //  vector<int>curr(2,0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buyorsell = 0; buyorsell <= 1; buyorsell++)
        {
            if (buyorsell)
            {
                int ans = max(-price[index] + dp[index + 1][!buyorsell], dp[index + 1][buyorsell]);
                dp[index][buyorsell] = ans;
            }
            else
            {
                int ans1 = max(price[index] + dp[index + 2][!buyorsell], dp[index + 1][buyorsell]);
                dp[index][buyorsell] = ans1;
            }
        }
        // ahead=curr;
    }

    return dp[0][1];
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
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    int ans=calculateans(input,0,0,dp);
    cout<<ans<<endl;
    int ans1=tabulation(input);
    cout<<ans1<<endl;
}

/*
In recursion +memoization
  time complexity: O(n*2);
  space complexity: O(n*2)+ recursion stack;

In tabulation
    time complexity: O(n*2);
    space complexity: O(n*2);
*/