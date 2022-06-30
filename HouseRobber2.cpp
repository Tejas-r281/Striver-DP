
/*
question:

Mr. X is a skilled burglar who intends to loot houses along a street. Each home has a specific amount of money tucked away. All of the residences in this area are grouped in a circle. That is, the first home is next to the final one. Meanwhile, nearby houses are connected to a security system, which will immediately inform the police if two adjacent houses are broken into on the same night.

Given an integer array nums indicating the amount of money in each house. Return the greatest amount of money Mr. X can rob without notifying the cops.

Example:

Input:

[2, 3, 2]

Output:

3
*/

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

int recursiveRobber(vector<int>&input,int n,vector<int>&memo)
{
    if(n==0)
    {
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
    int taken=0;
    int notTaken=0;
    taken= input[n]+recursiveRobber(input,n-2,memo);
    notTaken= 0 + recursiveRobber(input,n-1,memo);
    return memo[n]=max(taken,notTaken);
}

int dpRobber(vector<int>&input)
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
    vector<int>input1;
    vector<int>input2;
    // due to circular nature , 1st and last can not include in the answer thats why need to call the function by taking 1st element and not taking last elmenet and vice versa
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(i!=0)
        {
            input1.push_back(v[i]);
        }
        if(i!=n-1)
        {
            input2.push_back(v[i]);
        }
    }
    vector<int>memo(n+1,-1);
    vector<int>memo1(n+1,-1);
    int ans1=max(recursiveRobber(input1,input1.size()-1,memo),recursiveRobber(input2,input2.size()-1,memo1));
    int ans2=max(dpRobber(input1),dpRobber(input2));

    cout<<ans1<<" "<<ans2<<endl;
}
/*

In recusive + memoization

time complexity: O(n)
space complexity: O(n) for array  + O(n) because of recursion stack

In dp
time complexity: O(n);
space complexity: O(n);
*/