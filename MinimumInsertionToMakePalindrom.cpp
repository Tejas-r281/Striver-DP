/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
*/
#include <bits/stdc++.h>
using namespace std;

int recursiveLcs(string input1, string input2, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];

    if (input1[n] == input2[m])
        return dp[n][m] = 1 + recursiveLcs(input1, input2, n - 1, m - 1, dp);
    else
        return dp[n][m] = max(recursiveLcs(input1, input2, n - 1, m, dp), recursiveLcs(input1, input2, n, m - 1, dp));
}

int tabulationLcs(string input1, string input2)
{
    int n = input1.length();
    int m = input2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (input1[i - 1] == input2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string input1, input2;
    cin >> input1;
    input2 = input1;
    reverse(input2.begin(), input2.end());
    vector<vector<int>> dp(input1.length() + 1, vector<int>(input2.length() + 1, -1));
    int ans1 = recursiveLcs(input1, input2, input1.size() - 1, input2.size() - 1, dp);
    cout <<input1.size()-ans1 << endl;

    int ans2 = tabulationLcs(input1, input2);
    cout << input1.size()-ans2 << endl;
}