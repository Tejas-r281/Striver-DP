#include<bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>> &matrix)
{
    int result = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (i > 0 && j > 0 && matrix[i][j] > 0)
                matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;

            result += matrix[i][j];
        }
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int result = countSquares(matrix);
    cout << result;
    return 0;
}