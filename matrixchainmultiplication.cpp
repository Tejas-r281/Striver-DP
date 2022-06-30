#include<bits/stdc++.h>
using namespace std;

int calculate(int i, int j, int *input, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int leftans = calculate(i, k, input, dp);
        int rightans = calculate(k + 1, j, input, dp);
        int additionalans = input[i - 1] * input[k] * input[j];

        ans = min(ans, (leftans + rightans + additionalans));
    }
    return dp[i][j] = ans;
}
int matrixMultiplication(int n, int arr[])
{
    // code here

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int result = calculate(1, n - 1, arr, dp);

    return result;
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = matrixMultiplication(n, arr);
    cout << result;
    return 0;
}