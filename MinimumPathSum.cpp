/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
*/

#include <bits/stdc++.h>
using namespace std;

int recursiveMinimuCost(vector<vector<int>> &input, int n, int m, vector<vector<int>> &memo)
{

    if (n == 0 and m == 0)
    {
        return input[n][m];
    }
    if (n < 0 or m < 0)
    {
        return 1e9;
    }
    if (memo[n][m] != -1)
    {
        return memo[n][m];
    }
    int left = recursiveMinimuCost(input, n, m - 1, memo);
    int up = recursiveMinimuCost(input, n - 1, m, memo);
    memo[n][m] = min(left, up) + input[n][m];
    return memo[n][m];
}

int dpMinimumCost(vector<vector<int>> &input)
{
    int n = input.size();
    int m = input[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = input[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i==0 and j==0)
            {
                dp[i][j]=input[i][j];
            }
            else
            {
                dp[i][j] = min((i - 1 >= 0 ? dp[i - 1][j] : 1e9), (j - 1 >= 0 ? dp[i][j - 1] : 1e9)) + input[i][j];
            }

        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> input(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> input[i][j];
        }
    }
    vector<vector<int>> memo(n, vector<int>(m, -1));
    cout << recursiveMinimuCost(input, n - 1, m - 1, memo) << endl;
    cout << dpMinimumCost(input) << endl;
}


/*
In recursive + memoization

    time complexity: O(mn)
    space complexity: O(mn) for memoization and O(n+m) recusion stack

In dp

    time complexity: O(mn)
    space complexity: O(mn)

*/