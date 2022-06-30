/*
   Ways to write recursive code

        1. try to represent the problem in a terms of index

        2.Do all possible stuffs on that index and accrodingly to the problem statement

        3. if question asking COUNT ALL WAYS == > Sum of all the stuffs if question asking MIN OR MAX ==
        > Then we will take max or
    min from the calculated stuffs
 */
#include<bits/stdc++.h>
using namespace std;

int recursiveSum(vector<int> &input, vector<int> &memo, int n)
{
   if(n==0)
   {
    //n==0 , only reach if we have not taken n=1 element , if we have taken then this will be -1 ;
    return input[0];
   }
   if(n<0)
   {
    return 0;
   }
    if(memo[n]!=-1)
    {
     return memo[n];
    }
    // taken
    int taken=0;
    int notTaken=0;

    taken= input[n]+recursiveSum(input,memo,n-2);
    notTaken= 0 + recursiveSum(input,memo,n-1);

    return memo[n]=max(taken,notTaken);

}

int countDp(vector<int>&input)
{
    int dp[input.size()];
    dp[0]=input[0];

    for(int i=1;i<input.size();i++)
    {
        dp[i]= max(dp[i-1],(i-2<0?0:dp[i-2])+input[i]);
    }
    return dp[input.size()-1];
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int>memo(n+1,-1);

    int ans1= recursiveSum(v,memo,n-1);
    int ans2= countDp(v);

    cout<<ans1<<" "<<ans2<<endl;

}

/*
In recusive + memoization

time complexity : O(n)
space complexity : O(n) for array  + O(n) because of recursion stack


In dp

time complexity : O(n)
space complexity : O(n)
*/
