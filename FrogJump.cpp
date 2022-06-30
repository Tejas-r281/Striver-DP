/*
Ways to write recursive code

1. try to represent the problem in a terms of index

2.Do all possible stuffs on that index and accrodingly to the problem statement

3. if question asking  COUNT ALL WAYS ==> Sum of all the stuffs
   if question asking MIN OR MAX      ==>  Then we will take max or min from the calculated stuffs
*/

#include<bits/stdc++.h>
using namespace std;

int recursiveJump(vector<int>&input,vector<int>&memo,int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return INT_MAX;
    }

    if(memo[n]!=-1)
    {
        return memo[n];
    }

    int oneStep= recursiveJump(input,memo,n-1)+ abs(input[n]-input[n-1]);

    int twoStep= n-2>=0?recursiveJump(input,memo,n-2)+abs(input[n]-input[n-2]):INT_MAX;

    return min(oneStep,twoStep);
}

int dpJump(vector<int>&input)
{
    int dp[input.size()];
    dp[0]=0;
    for(int i=1;i<input.size();i++)
    {
        dp[i]=min(dp[i-1]+abs(input[i]-input[i-1]),i-2>=0?dp[i-2]+abs(input[i]-input[i-2]):INT_MAX);
    }
    return dp[input.size()-1];
}

int main()
{
    int n;
    cin>>n;
/*
6
30 10 60 10 60 50

output=40
*/
    vector<int>v(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int>memo(n+1,-1);
    int ans1= recursiveJump(v,memo,n-1);
    int ans2= dpJump(v);
    cout<<ans1<<" "<<ans2<<endl;
}


/*
In recusive + memoization
 time complexity: O(n)
 space complexity: O(n) for array  + O(n) because of recursion stack

In dp
    time complexity: O(n)
    space complexity: O(n)



*/