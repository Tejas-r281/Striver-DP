#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 1);
    vector<int> parent(n, 0);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int maxe = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 or nums[j] % nums[i] == 0)
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        if (maxe < dp[i])
        {
            maxe = dp[i];
            index = i;
        }
    }
    vector<int> result;
    result.push_back(nums[index]);
    while (index != parent[index])
    {
        result.push_back(nums[parent[index]]);
        index = parent[index];
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
  int n;
  cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int> result=largestDivisibleSubset(nums);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}