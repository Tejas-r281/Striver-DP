/*
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
*/

#include <bits/stdc++.h>
using namespace std;

int recursiveDistinctSequence(string input1, string input2, int n, int m, vector<vector<int>> &dp)
{
    if (m < 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    int ans = 0;
    if (input1[n] == input2[m])
    {
        ans = (recursiveDistinctSequence(input1, input2, n - 1, m - 1, dp) + recursiveDistinctSequence(input1, input2, n - 1, m, dp));
    }
    else
    {
        ans = recursiveDistinctSequence(input1, input2, n - 1, m, dp);
    }
    return dp[n][m] = ans;
}

int tabulation(string input1, string input2)
{
    int n = input1.length();
    int m = input2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        // for any i whose j==0 then we should always put dp[i][0]=1;
                dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int ans = 0;
            if (input1[i - 1] == input2[j - 1])
            {
                ans = dp[i- 1][j- 1] + dp[i - 1][j];
            }
            else
            {
                ans = dp[i - 1][j];
            }
            dp[i][j] = ans;
        }
    }
    return dp[n][m];
}

int main()
{
    string input1, input2;
    cin >> input1 >> input2;

    int n = input1.length();
    int m = input2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int ans1 = recursiveDistinctSequence(input1, input2, n - 1, m - 1, dp);
    cout << ans1 << endl;

    int ans2 = tabulation(input1, input2);
    cout << ans2 << endl;
}