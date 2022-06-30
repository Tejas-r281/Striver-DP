/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
#include<bits/stdc++.h>
using namespace std;

int BestTimeToBuyAndSellStock(vector<int>&prices)
{
    int n = prices.size();

    int maxe = prices[0];
    int mine = prices[0];

    int maxecost = 0;

    for (int i = 0; i < n; i++)
    {
        maxe = prices[i];

        maxecost = max(maxecost, maxe - mine);

        mine = min(mine, prices[i]);
    }

    return maxecost;
}

int main()
{
    int n;
    cin>>n;
    vector<int>input(n);
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    int ans=BestTimetoBuyandSellStock(input);
    cout<<ans;
}

/*
time complexity: O(n)
space complexity: O(1)
*/
