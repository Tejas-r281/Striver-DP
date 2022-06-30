/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/
#include<bits/stdc++.h>
using namespace std;
int calculateans(vector<int> &nums, int index, int prev, vector<vector<int>> &dp)
{

    if (index == nums.size())
    {
        return 0;
    }

    int include = 0;
    int exclude = 0;
    if (dp[index][prev + 1] != -1)
    {
        return dp[index][prev + 1];
    }
    exclude = calculateans(nums, index + 1, prev, dp);
    if (prev == -1 or nums[index] > nums[prev])
    {
        include = 1 + calculateans(nums, index + 1, index, dp);
    }

    return dp[index][prev + 1] = max(include, exclude);
}

int tabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    //         here we are shifting the second parameter by 1 right because of prev=-1 , thats why we are doing +1 in every second parameter in the dp array
    for (int index = n - 1; index >= 0; index--)
    {
        for (int prev = index - 1; prev >= -1; prev--)
        {
            int include = 0;
            int exclude = 0;

            exclude = dp[index + 1][prev + 1];
            if (prev == -1 or nums[index] > nums[prev])
            {
                include = 1 + dp[index + 1][index + 1];
            }

            dp[index][prev + 1] = max(include, exclude);
        }
    }

    return dp[0][0];
}

int arraySolution(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> parent(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    dp[0] = 1;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

void printLcs(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> parent(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    dp[0] = 1;
    int ans = 1;
    int maxe = 0;
    int index = -1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                // dp[i]=max(dp[i],dp[j]+1);
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        if (dp[i] > maxe)
        {
            maxe = dp[i];
            index = i;
        }
        ans = max(ans, dp[i]);
    }

    cout << nums[index] << " ";

    while (index != parent[index])
    {
        cout << nums[parent[index]] << " ";
        index = parent[index];
    }
    cout << endl;
}

int LcsNlogN(vector<int> &nums)
{
    vector<int> dp;
    int n = nums.size();
    dp.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > dp.back())
        {
            dp.push_back(nums[i]);
        }
        else
        {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[it] = nums[i];
        }
    }
    return dp.size();
}

int lengthOfLIS(vector<int> &nums)
{

    int n = nums.size();

    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // int ans= calculateans(nums,0,-1,dp);
    // int ans= tabulation(nums);
    // int ans= arraySolution(nums);
    // printLcs(nums);
    int ans = LcsNlogN(nums);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>input(n);
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }

    cout<<lengthOfLIS(input)<<endl;
}