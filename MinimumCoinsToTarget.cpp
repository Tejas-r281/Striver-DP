/*
Bob went to his favourite bakery to buy some pastries. After picking up his favourite pastries his total bill was P cents. Bob lives in Berland where all the money is in the form of coins with denominations {1, 2, 5, 10, 20, 50, 100, 500, 1000}.

Bob is not very good at maths and thinks fewer coins mean less money and he will be happy if he gives minimum number of coins to the shopkeeper. Help Bob to find the minimum number of coins that sums to P cents (assume that Bob has an infinite number of coins of all denominations).
*/
#include<bits/stdc++.h>
using namespace std;

int recursiveCount(vector<int> &value, int target, int n,vector<vector<int>>&memo)
{
    // we are starting from last element then always think about first element for the base case ;
    if(n==0)
    {
      if(target%value[n]==0)
      {
        return target/value[n];
      }
      else
      {
        return 1e9;
      }
    }
     if(memo[n][target]!=-1)
    {
        return memo[n][target];
    }

    int taken=1e9;
    int notTaken=1e9;

    notTaken = recursiveCount(value, target, n-1,memo);
    if(value[n]<=target)
    {
        taken = recursiveCount(value, target - value[n], n,memo) + 1;
    }
    return memo[n][target]= min(taken,notTaken);
}
int tabulationCount(vector<int>&value,int target)
{
    int n = value.size();
    int dp[n][target+1];
    // think about the last element ;
    for(int i=0;i<=target;i++)
    {
        dp[0][i] = (i%value[0]==0)?(i/value[0]):1e9;
    }
    // we have already processed the 0th element then we need to start i==1
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            // After writing the different states of DP then just copy the recurrence relation
            int taken = 1e9;
            int notTaken = 1e9;

            notTaken = dp[i-1][j];
            if (value[i] <= j)
            {
                taken = dp[i][j-value[i]] + 1;
            }
            dp[i][j]= min(taken, notTaken);
        }
    }
    // due to bottom up result will store at (n-1) and target
    return dp[n-1][target];

}


int main()
{
    int target;
    cin>>target;

    vector<int>value{1, 2, 5, 10, 20, 50, 100, 500, 1000};
     int n= value.size();
    vector<vector<int>>memo(n,vector<int>(target+1,-1));
    int ans1= recursiveCount(value,target,n-1,memo);
    cout<<ans1<<endl;

    int ans2=tabulationCount(value,target);
    cout<<ans2<<endl;
}

/*
In recursion + memoization

time complexity : O(n*target);
space complexity : O(n*target) + recursion stack


In tabulation

time complexity : O(n*target);
space complexity : O(n*target)

*/