#include <bits/stdc++.h>
using namespace std;
/*
  Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
*/
int recursiveWildCard(string input, string required, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 and m < 0)
        return 1;
    if (m >= 0 and n < 0)
    {
        return 0;
    }
    if (n >= 0 and m < 0)
    {
        bool flag = true;
        for (int i = 0; i <= m; i++)
        {
            if (input[i] != '*')
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return 1;
        else
            return 0;
    }
    if (dp[n][m] != -1)
        return dp[n][m];

    if (input[n] == required[m] or input[n] == '?')
    {
        dp[n][m] = recursiveWildCard(input, required, n - 1, m - 1, dp);
    }

    else if (input[n] == '*')
    {
        dp[n][m] = recursiveWildCard(input, required, n - 1, m, dp) || recursiveWildCard(input, required, n, m - 1, dp);
    }
    else
    {
        dp[n][m] = 0;
    }
    return dp[n][m];
}
int tabulationWildCard(string input,string required)
{
    int n = input.length();
    int m = required.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
     for(int i=0;i<=m;i++)
     {
        dp[0][i]=0;
     }
     for(int i=0;i<=n;i++)
     {
         int flag = 1;
         for (int j = 0; j <= i; j++)
         {
             if (input[j] != '*')
             {
                 flag = 0;
                 break;
             }
         }
            if (flag)
                dp[i][0] =1;
            else
                dp[i][0] = 0;
     }
     dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if (input[i] == required[j] or input[i] == '?')
            {
                dp[i][j] = dp[i - 1][j- 1];
            }

            else if (input[i] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}
int main(){
    string input;
    string required;
    cin >> input;
    cin >> required;
    int n = input.length();
    int m = required.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = recursiveWildCard(input, required, n - 1, m - 1, dp);
    int ans1= tabulationWildCard(input,required);
    if (ans1 and ans)
        cout << "YES";
    else
        cout << "NO";
}