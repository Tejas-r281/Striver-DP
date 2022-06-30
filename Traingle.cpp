/*
Problem Statement
You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.
The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.
For Example :
If the array given is 'TRIANGLE' = [[1], [2,3], [3,6,7], [8,9,6,1]] the triangle array will look like:

1
2,3
3,6,7
8,9,6,10

For the given triangle array the minimum sum path would be 1->2->3->8. Hence the answer would be 14.
*/
#include <bits/stdc++.h>
using namespace std;

/*
In this question , in recursive we will start from top to bottom
*/

int recursiveTraingle(vector<vector<int>> &input, int row, int col, vector<vector<int>> &memo)
{
    if (col > row)
    {
        return 1e9;
    }
    if (row == input.size() - 1)
    {
        return input[row][col];
    }

    if (memo[row][col] != -1)
    {
        return memo[row][col];
    }

    int down = recursiveTraingle(input, row + 1, col, memo);
    int diag = recursiveTraingle(input, row + 1, col + 1, memo);
    memo[row][col] = min(down, diag) + input[row][col];
    return memo[row][col];
}

int dpTraingle(vector<vector<int>> &input)
{
    int n = input.size();

    /*
    As this is opposite of recursion then this will start from bottom to top

    Now we have to check States in Dp because of variable ending point .

    for  i=3 then possible j= 0 1 2 3
    for i=2 then possible j= 0 1 2
    for i=1 then possible j= 0 1
    for i=0 then possible j= 0
     for different i or row we have different states of j .
    */
    //    now write base case from bottom
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = input[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            int down = dp[i + 1][j];
            int diag = dp[i + 1][j + 1];
            dp[i][j] = min(down, diag) + input[i][j];
        }
    }

    return dp[0][0];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> input(n);
    for (int i = 0; i < n; i++)
    {
        input[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            cin >> input[i][j];
        }
    }
    vector<vector<int>> memo(n, vector<int>(n, -1));

    int ans1 = recursiveTraingle(input, 0, 0, memo);
    int ans2 = dpTraingle(input);
    cout << ans1 << " " << ans2 << endl;
}

