/*
Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.
Example 1:
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
*/
#include<bits/stdc++.h>
using namespace std;

int calculate(vector<int> &cuts, int start, int end, vector<vector<int>> &dp)
{
    if (start > end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;
    for (int k = start; k <= end; k++)
    {
        int leftans = calculate(cuts, start, k - 1, dp);
        int rightans = calculate(cuts, k + 1, end, dp);
        int aditionalans = cuts[end + 1] - cuts[start - 1];
        ans = min(ans, leftans + rightans + aditionalans);
    }

    return dp[start][end] = ans;
}

int minCost(int n, vector<int> &cuts)
{

    int m = cuts.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    sort(cuts.begin(), cuts.end());
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    int ans = calculate(cuts, 1, m, dp);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> cuts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cuts[i];
    }
    int result = minCost(n, cuts);
    cout << result;
    return 0;
}