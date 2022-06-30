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
/*
this problem is extension of frogJump
*/

int recursiveJump(vector<int> &input, vector<int> &memo, int n, int k)
{
   if (n == 0)
   {
       return 0;
   }
   if(memo[n]!=-1)
   {
         return memo[n];
   }
   int minAns=INT_MAX;
//    we need to check for each k distance from the current index
   for(int i=1;i<=k;i++)
   {
         if(n-i>=0)
         {
              int ans=recursiveJump(input,memo,n-i,k)+abs(input[n]-input[n-i]);
              minAns=min(minAns,ans);
         }
   }
    return memo[n]= minAns;
}


int dpJump(vector<int>&input,int k)
{
    int dp[input.size()];
    dp[0]=0;
    for(int i=1;i<input.size();i++)
    {
        dp[i]=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                dp[i]=min(dp[i],dp[i-j]+abs(input[i]-input[i-j]));
            }
        }
    }
    return dp[input.size()-1];
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int>memo(n+1,-1);
    int ans1= recursiveJump(v,memo,n-1,k);
    int ans2= dpJump(v,k);
    cout<<ans1<<" "<<ans2<<endl;

}

/*
In recusive + memoization

time complexity: O(n*k)
space complexity: O(n) for array + O(n) for recursion stack

In DP

    time complexity: O(n*k)
    space complexity: O(n)


*/