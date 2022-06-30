/*
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
*/
#include <bits/stdc++.h>
using namespace std;

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
           bool nottaken=dp[i-1][j];
           bool taken=false;
              if(input[i]<=j)
              {
                taken=dp[i-1][j-input[i]];
              }
            dp[i][j]=taken||nottaken;
        }
    }

    int ans = INT_MAX;
    target--;//we have already done target=sum+1; that is why we are decreasing it .


    for (int i = 0; i <= target / 2; i++)
    {
        if (dp[n - 1][i])
        {
            int s1=i;
            int s2=(target-i);
            ans= min(ans,abs(s1-s2));
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        sum += input[i];
    }
    /*
    As decribed above , we will use the last row in Dp table and out target will shift to sum+1; j++

    that means

    1. array will be there
    2. target= sum+1;

    */
   int target = sum + 1;

    int ans2 = tabulationCheck(input, target);
    cout << ans2 << endl;
}
