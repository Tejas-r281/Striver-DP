/*
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

Examples :

Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
Output : 5
Explanation:
The longest common substring is “Geeks” and is of length 5.
*/
#include <bits/stdc++.h>
using namespace std;

int recursiveSubstring(string input1, string input2, int n, int m, vector<vector<int>> &dp, int count)
{
    if (n < 0 || m < 0)
    {
        return count;
    }
    if (dp[n][m] != -1)
    {
        // return dp[n][m];
    }
    int temp = 0;
    if (input1[n] == input2[m])
    {
        temp = recursiveSubstring(input1, input2, n - 1, m - 1, dp, count + 1);
    }

    temp = max(temp, max(recursiveSubstring(input1, input2, n - 1, m, dp, 0), recursiveSubstring(input1, input2, n, m - 1, dp, 0)));

    return dp[n][m] = temp;
}

int tabulationSubstring(string input1, string input2)
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
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (input1[i - 1] == input2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main()
{
    string input1, input2;
    cin >> input1 >> input2;
    vector<vector<int>> dp(input1.length() + 1, vector<int>(input2.length() + 1, -1));
    int ans1 = recursiveSubstring(input1, input2, input1.length() - 1, input2.length() - 1, dp, 0);
    cout << ans1 << endl;

    int ans2 = tabulationSubstring(input1, input2);
    cout << ans2 << endl;
}