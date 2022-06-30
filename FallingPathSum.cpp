/*
You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.

From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col), we can move in three directions i.e.
*/

#include <bits/stdc++.h>
using namespace std;

int recursiveFallsumUTIL(vector<vector<int>> &mat, int n, int m, vector<vector<int>> &memo)
{
    if (m < 0 or m >= mat[0].size())
    {
        return -1e8;
    }
    if (n == 0)
    {
        return mat[0][m];
    }
    if (memo[n][m] != -1)
    {
        return memo[n][m];
    }
    // we have to move upper , upper right diagonal , upper left diagonal
    int up, up_right, up_left;
    up = up_right = up_left = INT_MIN;

    up = recursiveFallsumUTIL(mat, n - 1, m, memo) + mat[n][m];

    up_right = recursiveFallsumUTIL(mat, n - 1, m + 1, memo) + mat[n][m];

    up_left = recursiveFallsumUTIL(mat, n - 1, m - 1, memo) + mat[n][m];

    memo[n][m] = max(max(up, up_right), up_left);
    return memo[n][m];
}
/*
  In this recursive approach i need to traverse every col in last row for getting answer.
  In this question starting or ending point not fixed.

*/
int recursiveFallingSum(vector<vector<int>> &input, int n, int m, vector<vector<int>> &memo)
{
    int ans = INT_MIN;

    for (int i = 0; i <= m; i++)
    {
        ans = max(ans, recursiveFallsumUTIL(input, n, i, memo));
    }
    return ans;
}

int dpFallingSum(vector<vector<int>>&input)
{
    int n = input.size();
    int m = input[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    /*
    Since tabulations completely opposite of recursion , here we start from starting

    lets think about states in the dp
    
    for i=0  what would be possible of j =0, 1,2......m;
    for i=1  what would be possible of j =0, 1,2......m;
    for i=2  what would be possible of j =0, 1,2......m;
    for i=3  what would be possible of j =0, 1,2......m;

    */
    //    base case ==> destination + outofbound;

    for(int j=0;j<m;j++)
    {
        dp[0][j]=input[0][j];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int up, up_right, up_left;
            up = up_right = up_left = INT_MIN;
            up = dp[i-1][j] + input[i][j];
            if(j+1<m)
            {
                up_right = dp[i-1][j+1] + input[i][j];
            }
            if(j-1>=0)
            {
                up_left = dp[i-1][j-1] + input[i][j];
            }
            dp[i][j] = max(max(up,up_right),up_left);
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<m;i++)
    {
        ans=max(ans,dp[n-1][i]);
    }
    return ans;

}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> memo(n, vector<int>(m, -1));

    int ans1 = recursiveFallingSum(mat, n - 1, m - 1, memo);
    int ans2= dpFallingSum(mat);
    cout<<ans1<<" "<<ans2<<endl;
    // cout << ans1 << endl;
}

/*

In recursive + memoization

     time complexity = O(n*m)
    space complexity = O(n*m)for memoization array  + O(n) for recursion stack


In dp

    time complexity = O(n*m)
    space complexity = O(n*m)

*/