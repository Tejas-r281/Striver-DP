/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/
#include <bits/stdc++.h>
using namespace std;

int recursiveCherryPickup(vector<vector<int>> &input, int i1, int j1, int j2, vector<vector<vector<int>>> &memo)
{
    if (i1 < 0 or i1 >= input.size() or j1 < 0 or j1 >= input[0].size() or j2 < 0 or j2 >= input[0].size())
    {
        return -1e8;
    }
    if (i1 == input.size() - 1)
    {
        if (j1 == j2)
        {
            return input[i1][j1];
        }
        else
        {
            return (input[i1][j1] + input[i1][j2]);
        }
    }

    if (memo[i1][j1][j2] != -1)
    {
        return memo[i1][j1][j2];
    }
    int ans = INT_MIN;
    for (int jj1 = -1; jj1 <= 1; jj1++)
    {
        for (int jj2 = -1; jj2 <= 1; jj2++)
        {
            int newj1 = j1 + jj1;
            int newj2 = j2 + jj2;
            int temp = 0;
            if (j1 == j2)
            {
                temp = recursiveCherryPickup(input, i1 + 1, newj1, newj2, memo) + input[i1][j1];
            }
            else
            {
                temp = recursiveCherryPickup(input, i1 + 1, newj1, newj2, memo) + input[i1][j1] + input[i1][j2];
            }

            ans = max(ans, temp);
        }
    }
    memo[i1][j1][j2] = ans;
    return ans;
}
bool isvalid(int j1, int j2, int n, int m)
{
    if (j1 < 0 or j1 >= m or j2 < 0 or j2 >= m)
    {
        return false;
    }
    return true;
}

int dpCherryPickup(vector<vector<int>> &input)
{
    int n = input.size();
    int m = input[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    // first we need to write base , it will be motivated from recursion base case
    /*
    states like for i==n-1 then possible value of j1 and j2 may be they both point to same point or they may be on different point in same row or either they exchange their positions.
    */
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                dp[n - 1][j1][j2] = input[n - 1][j1];
            }
            else
            {
                dp[n - 1][j1][j2] = input[n - 1][j1] + input[n - 1][j2];
            }
        }
    }
    //   now total three different states are there i,j1,j2 then three loops will be

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int ans = INT_MIN;
                for (int jj1 = -1; jj1 <= 1; jj1++)
                {
                    for (int jj2 = -1; jj2 <= 1; jj2++)
                    {
                        int newj1 = j1 + jj1;
                        int newj2 = j2 + jj2;
                        if (!isvalid(newj1, newj2, n, m))
                        {
                            continue;
                        }
                        int temp = 0;
                        if (j1 == j2)
                        {

                            temp = dp[i + 1][newj1][newj2] + input[i][j1];
                        }
                        else
                        {

                            temp = dp[i + 1][newj1][newj2] + input[i][j1] + input[i][j2];
                        }

                        ans = max(ans, temp);
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }

    int result = 0;
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            result = max(result, dp[0][j1][j2]);
        }
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> input(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> input[i][j];
        }
    }
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(m, -1)));

    int ans1 = recursiveCherryPickup(input, 0, 0, m - 1, memo);
    cout << ans1 << endl;
    int ans2 = dpCherryPickup(input);
    cout << ans2 << endl;
}