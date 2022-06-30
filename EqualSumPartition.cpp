/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/
#include <bits/stdc++.h>
using namespace std;

int recursiveTarget(vector<int> &input, int n, int target)
{
    if (target == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return input[n] == target ? 1 : 0;
    }
    int taken = 0;
    int notaken = 0;

    notaken = recursiveTarget(input, n - 1, target);

    if (input[n] <= target)
    {
        taken = recursiveTarget(input, n - 1, target - input[n]);
    }

    return taken || notaken;
}

int tabulationCheck(vector<int> &input, int target)
{
    int n = input.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][input[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool nottaken = dp[i - 1][j];
            bool taken = false;
            if (input[i] <= j)
            {
                taken = dp[i - 1][j - input[i]];
            }
            dp[i][j] = taken || nottaken;
        }
    }
    return dp[n - 1][target];
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        sum+=input[i];
    }
    int target;

    if(sum%2==1)
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        target=sum/2;
    }
    int ans1 = recursiveTarget(input, n - 1, target);
    cout << ans1 << endl;
    int ans2 = tabulationCheck(input, target);
    cout << ans2 << endl;
}
/*
complexity will be same as previous question
*/
