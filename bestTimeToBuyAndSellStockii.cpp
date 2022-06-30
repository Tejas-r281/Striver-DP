/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/
#include<bits/stdc++.h>
using namespace std;

int calculateans(vector<int> &price, int buyorsell, int index, vector<vector<int>> &dp)
{
    if (index == price.size())
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
        int ans1 = max(price[index] + calculateans(price, !buyorsell, index + 1, dp), calculateans(price, buyorsell, index + 1, dp));

        return dp[index][buyorsell] = ans1;
    }
}

int tabulation(vector<int> &price)
{
    int n = price.size();
    // vector<vector<int>>dp(n+1,vector<int>(2,0));
    vector<int> ahead(2, 0);
    vector<int> curr(2, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buyorsell = 0; buyorsell <= 1; buyorsell++)
        {
            if (buyorsell)
            {
                int ans = max(-price[index] + ahead[!buyorsell], ahead[buyorsell]);
                curr[buyorsell] = ans;
            }
            else
            {
                int ans1 = max(price[index] + ahead[!buyorsell], ahead[buyorsell]);

                curr[buyorsell] = ans1;
            }
        }
        ahead = curr;
    }

    return ahead[1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    int ans = calculateans(price, 1, 0, dp);
    int ans1 = tabulation(price);
    cout << ans << " " << ans1;
    return 0;
}

/*
In recursive + memoization
    time complexity= O(n*m)
    space complexity= O(n*m) +recurisve Stack

In dp
  time complexity= O(n*2)
  space complexity= O(2)
*/