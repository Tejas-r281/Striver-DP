#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &histo)
{
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() and (i == n or histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width = 0;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int maxe = 0;

    int n = matrix.size();
    if (n == 0)
        return 0;
    int m = matrix[0].size();
    vector<int> vct(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '0')
            {
                vct[j] = 0;
            }
            else
            {
                vct[j] += 1;
            }
        }
        // for(int z=0;z<m;z++)
        // {
        //     cout<<vct[z]<<" ";
        // }
        // cout<<endl;
        maxe = max(maxe, largestRectangleArea(vct));
    }

    return maxe;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<char>> matrix(n, vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<maximalRectangle(matrix);
    return 0;
}