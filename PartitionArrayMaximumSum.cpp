/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
*/
#include<bits/stdc++.h>
using namespace std;
int calculate(vector<int> &arr, int start, int k, vector<int> &dp)
{
    if (start == arr.size())
    {
        return 0;
    }
    int ans = INT_MIN;

    int maxe = INT_MIN;
    int len = 0;
    if (dp[start] != -1)
    {
        return dp[start];
    }
    for (int k1 = start; k1 < min(start + k, (int)arr.size()); k1++)
    {
        maxe = max(maxe, arr[k1]);
        len++;
        int nextcall = calculate(arr, k1 + 1, k, dp);

        ans = max(ans, nextcall + len * maxe);
    }

    return dp[start] = ans;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{

    int n = arr.size();
    vector<int> dp(n, -1);
    int ans = calculate(arr, 0, k, dp);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin>>k;
    int result = maxSumAfterPartitioning(arr, k);
    cout << result;
}