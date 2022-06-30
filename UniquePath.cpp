/*
You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].

To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].
*/

#include<bits/stdc++.h>
using namespace std;

// top down approach
int recursiveCount(int m , int n , vector<vector<int>>&memo)
{
    if(n==0 and m==0)
    {
        return 1;
    }
    if(n<0 or m<0)
    {
        return 0;
    }

    if(memo[n][m]!=-1)
    {
        return memo[n][m];
    }
    int upSideCall= recursiveCount(m,n-1,memo);
    int leftSideCall= recursiveCount(m-1,n,memo);

    memo[n][m]=upSideCall+leftSideCall;
}

/*
for bottom up approach
1. Declare the base case
2. express all the states(changing variable) in for loops
3. copy the recurrence relation
*/

int dpCount(int m, int n)
{
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // dp[0][0]=1;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=(j-1>=0?dp[i][j-1]:0)+ (i-1>=0?dp[i-1][j]:0);
            }
        }
    }
    return dp[n][m];
}


int main()
{
    int m,n;
    cin>>m>>n;

    vector<vector<int>>memo(n+1,vector<int>(m+1,-1));

    int ans1=recursiveCount(m-1,n-1,memo);
    int ans2=dpCount(m-1,n-1);

    cout<<ans1<<" "<<ans2<<endl;
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