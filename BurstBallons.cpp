/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.
*/
#include<bits/stdc++.h>
using namespace std;

int calculate(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
{
    if (start > end)
    {
        return 0;
    }

    int ans = INT_MIN;
    //  we are starting from bottom that means there will be only one element in the array and their left and right side will be
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    for (int k = start; k <= end; k++)
    {
        int leftans = calculate(nums, start, k - 1, dp);
        int rightans = calculate(nums, k + 1, end, dp);

        int additional = nums[start - 1] * nums[k] * nums[end + 1];

        ans = max(ans, leftans + rightans + additional);
    }
    return dp[start][end] = ans;
}

int maxCoins(vector<int> &nums)
{

    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = calculate(nums, 1, n, dp);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int result = maxCoins(nums);
    cout << result;
    return 0;
}


// This question based on Matrix chain multiplication
