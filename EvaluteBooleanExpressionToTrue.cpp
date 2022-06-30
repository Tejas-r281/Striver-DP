/*
Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

Operands are only true and false.

Return the number of ways to evaluate the expression modulo 103 + 3.

Input Format:

The first and the only argument of input will contain a string, A.

The string A, may contain these characters:
    '|' will represent or operator
    '&' will represent and operator
    '^' will represent xor operator
    'T' will represent true operand
    'F' will false
*/
#include <bits/stdc++.h>
using namespace std;
long long calculate(string input, int start, int end, int istrue, vector<vector<vector<long long>>> &dp)
{
    if (start > end)
    {
        return 0;
    }
    if (start == end)
    {
        if (istrue)
        {
            return input[start] == 'T';
        }
        else
        {
            return input[start] == 'F';
        }
    }
    if (dp[start][end][istrue] != -1)
    {
        return dp[start][end][istrue];
    }
    int ways = 0;
    long long mode = 1e3 + 3;
    for (int k = start + 1; k <= end - 1; k += 2)
    {
        long long lefttrue = calculate(input, start, k - 1, 1, dp);
        long long leftfalse = calculate(input, start, k - 1, 0, dp);
        long long righttrue = calculate(input, k + 1, end, 1, dp);
        long long rightfalse = calculate(input, k + 1, end, 0, dp);

        // appan calculation
        if (input[k] == '&')
        {
            if (istrue)
                ways = (ways + (lefttrue * righttrue) % (mode)) % (mode);
            else
            {
                ways = (ways + (lefttrue * rightfalse) % (mode) + (leftfalse * righttrue) % (mode) + (leftfalse * rightfalse) % (mode)) % (mode);
            }
        }
        else if (input[k] == '|')
        {
            if (istrue)
            {
                ways = (ways + (lefttrue * righttrue) % (mode) + (lefttrue * rightfalse) % (mode) + (leftfalse * righttrue) % (mode)) % (mode);
            }
            else
            {
                ways = (ways + (leftfalse * rightfalse) % (mode)) % (mode);
            }
        }
        else
        {
            if (istrue)
            {
                ways = (ways + (lefttrue * rightfalse) % (mode) + (leftfalse * righttrue) % (mode)) % (mode);
            }
            else
            {
                ways = (ways + (lefttrue * righttrue) % (mode) + (leftfalse * rightfalse) % (mode)) % (mode);
            }
        }
    }
    return dp[start][end][istrue] = ways;
}

int cnttrue(string input)
{

    long long n = input.size();

    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(2, -1)));

    long long ans = calculate(input, 0, n - 1, 1, dp);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    string input;
    cin >> input;
    int result = cnttrue(input);
    cout << result;
    return 0;
}
