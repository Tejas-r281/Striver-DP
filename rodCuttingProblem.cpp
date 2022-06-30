/*
Problem Statement
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.
*/
#include <bits/stdc++.h>
using namespace std;

int recursiveCal(vector<int> &value, int index, int capacity, vector<vector<int>> &memo)
{
    // here length will index+1 because index is 0 based that is why we are doing +1;
    /*
    Here we are trying to make different combination of length to equal to capacity . That means reverse of the problem given;
    */
    //    base case if you have only one element then ? if you capacity=10 and n=0 then you have only one choice to cut the rod in length equal to 1. because index=0 is equal to length 1;
    if (index == 0)
    {
        return value[0] * capacity;
    }

    int include = 0;
    int exclude = 0;
    if (memo[index][capacity] != -1)
    {
        return memo[index][capacity];
    }
    exclude = 0 + recursiveCal(value, index - 1, capacity,memo);
    int length = index+ 1;
    if (capacity >= length)
    {
        include = recursiveCal(value, index, capacity - length,memo) + value[index];
    }
    return memo[index][capacity] = max(include, exclude);
}

int tabulationCheck(vector<int>&value)
{
    int n = value.size();
    int capacity = n + 1;
    vector<vector<int>>dp(n, vector<int>(capacity, 0));
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=value[0]*i;
    }

    for(int i=1;i<n;i++)
    {
        // states in dp , just think at i , what could be possible value of capacity i thin it would be 0 to n .
        for(int j=0;j<=n;j++)
        {
            int include = 0;
            int exclude = 0;
            exclude = 0 + dp[i-1][j];
            int length = i + 1;
            if (j >= length)
            {
                include = dp[i][j-length]+value[i];
            }
           dp[i][j] = max(include, exclude);
        }
    }
    return dp[n-1][n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> memo(n, vector<int>(n + 1, -1));

    int ans1 = recursiveCal(v, n - 1, n, memo);
    cout << ans1 << endl;

    int ans2 = tabulationCheck(v);
    cout << ans2 << endl;
}