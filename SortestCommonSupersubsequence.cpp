#include<bits/stdc++.h>
using namespace std;

/*
  int lcs = LCS(input1,input2);
  int lengthOfSupersequence = input1.length() + input2.length() - lcs;
*/

string tabulationLcs(string input1, string input2)
{
    int n = input1.length();
    int m = input2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (input1[i - 1] == input2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int lcs= dp[n][m];
    int lengthOfSupersequence = input1.length() + input2.length() - lcs;
    cout<<lengthOfSupersequence<<endl;
    // Now printing supersubsequence from dp
    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (input1[i - 1] == input2[j - 1])
        {
            ans = input1[i - 1] + ans;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans=input1[i-1]+ans;
            i--;
        }
        else
        {
            ans = input2[j - 1] + ans;
            j--;
        }
    }
    while (i > 0)
    {
        ans = input1[i - 1] + ans;
        i--;
    }
    while (j > 0)
    {
        ans = input2[j - 1] + ans;
        j--;
    }


    return ans;
}
int main()
{
    string input1,input2;
    cin>>input1>>input2;

    string lcs = tabulationLcs(input1,input2);

    cout<<lcs<<endl;

}