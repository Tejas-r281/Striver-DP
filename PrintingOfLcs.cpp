#include<bits/stdc++.h>
using namespace std;

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
    // now printing of LCS from dp
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
            i--;
        }
        else
        {
            j--;
        }
    }

    return ans;
}

int main()
{
    string input1,input2;
    cin>>input1>>input2;

    string result= tabulationLcs(input1,input2);
    cout<<result<<endl;
}