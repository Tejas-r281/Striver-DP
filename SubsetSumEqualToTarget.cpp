/*
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
*/
#include<bits/stdc++.h>
using namespace std;

/*
In recursive we are starting from index n-1 to 0 that is top down appraoch  .
f(n-1,target)=this will give the answer wether any subset available equal to target or not .

In subset or subsequence problem use  inclusion or exclusion method .
*/
int recursiveTarget(vector<int>&input,int n ,int target)
{
    if(target==0)
    {
        return 1;
    }
    if(n==0)
    {
        return input[n]==target?1:0;
        // Agar array in ek hi element hai to oo simply target ke hi equal hi hona chahiye otherwise return false
    }
    int taken=0;
    int notaken=0;
    // for any particular , we have two option wether we take or not take the element
    notaken=recursiveTarget(input,n-1,target);

    if(input[n]<=target)
    {
        taken=recursiveTarget(input,n-1,target-input[n]);
    }

    return taken||notaken;
}

int tabulationCheck(vector<int> &input, int target)
{
    int n=input.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    /*
    dp[i][j]= the will give the answer by taking index [0....i]. any subset equal to target(j) or not

   for base case
   if target ==0 , its is possible everywhere because empty subset .

   if(i==0) then dp[0][arr[0]]=true; because of only one element are there so that element will be only true.
    */
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    dp[0][input[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            bool nottaken = dp[i - 1][j];
            bool taken = false;
            if (input[i] <= j)
            {
                taken = dp[i - 1][j - input[i]];
            }
            dp[i][j] = taken || nottaken;
        }
    }
    return dp[n-1][target];
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
    int target;
    cin>>target;

    int ans1= recursiveTarget(input,n-1,target);
    cout<<ans1<<endl;
    int ans2= tabulationCheck(input,target);
    cout<<ans2<<endl;

}

/*
In recursion + memoization

time complexity: O(n*target)
Space complexity: O(n*target) + O(n) for recusion stack memory

In tabulation

time complexity: O(n*target)
Space complexity: O(n*target)


*/