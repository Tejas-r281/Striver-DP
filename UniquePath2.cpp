/*
Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
For Example :
Consider the maze below :
0 0 0
0 -1 0
0 0 0

There are two ways to reach the bottom left corner -

(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

Hence the answer for the above test case is 2.
*/
#include <bits/stdc++.h>
using namespace std;


// top down approach
int recursiveCount(int m, int n,vector<vector<int>>&input, vector<vector<int>> &memo)
{
    if(n>=0 and m>=0 and input[n][m]==-1)
    {
        return 0;
    }
    if (n == 0 and m == 0)
    {
        return 1;
    }
    if (n < 0 or m < 0)
    {
        return 0;
    }



    if (memo[n][m] != -1)
    {
        return memo[n][m];
    }
    int upSideCall = recursiveCount(m, n - 1,input, memo);
    int leftSideCall = recursiveCount(m - 1, n,input, memo);

    memo[n][m] = upSideCall + leftSideCall;
}

/*
for bottom up approach
1. Declare the base case
2. express all the states(changing variable) in for loops
3. copy the recurrence relation
*/

int dpCount(int m, int n,vector<vector<int>>&input)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // dp[0][0]=1;

    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (input[i][j]==-1)
            {
                dp[i][j] = 0;
            }
            else if(i==0 and j==0)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j] = (j - 1 >= 0 ? dp[i][j - 1] : 0) + (i - 1 >= 0 ? dp[i - 1][j] : 0);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>>input(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>input[i][j];
        }
    }

    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

    int ans1 = recursiveCount(m - 1, n - 1,input, memo);
    int ans2 = dpCount(m - 1, n - 1,input);

    cout << ans1 << " " << ans2 << endl;
    // cout<<ans1<<endl;
}
/*
In recusive + memoization
time complexity: O(mn)
space complexity: O(mn) for memoization and O(n+m) recusion stack

In dp
time complexity: O(mn)
space complexity: O(mn)
*/