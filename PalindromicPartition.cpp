/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
#include<bits/stdc++.h>
using namespace std;


bool ispalindrome(string &input, int start, int end)
{
    while (start < end)
    {
        if (input[start] != input[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int calculate(string &input, int start, vector<int> &dp)
{
    if (start == input.size())
    {
        return 0;
    }

    int ans = INT_MAX;
    if (dp[start] != -1)
    {
        return dp[start];
    }

    for (int k = start; k < input.size(); k++)
    {
        if (ispalindrome(input, start, k))
        {
            int nextcall = calculate(input, k + 1, dp);
            int ans1 = 1 + nextcall;
            ans = min(ans, ans1);
        }
    }
    return dp[start] = ans;
}
int minCut(string s)
{

    int n = s.size();
    vector<int> dp(n + 1, -1);
    int result = calculate(s, 0, dp);

    return result - 1;
}

int main()
{
    string s;
    cin >> s;
    int result = minCut(s);
    cout << result;
    return 0;
}