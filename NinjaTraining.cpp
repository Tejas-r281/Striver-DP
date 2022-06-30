/*
 question:
 Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

 You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your last is to calculate the maximum number of merit points that Ninja can earn.
input:
3
10 40 70
20 50 80
30 60 90

output=210

 */

#include<bits/stdc++.h>
using namespace std;


int recursiveTraining(vector<vector<int>>&input,int n,vector<vector<int>>&memo,int k)
{
    if(n==0)
    {
        int maxe=0;
        for(int i=0;i<3;i++)
        {
            if(k!=i)
            {
                maxe=max(maxe,input[n][i]);
            }
        }

        return maxe;
    }

    if(memo[n][k]!=-1)
    {
        return memo[n][k];
    }
    for(int i=0;i<3;i++)
    {
        // we can not take previosly taken activity
        if(k!=i)
        {
            memo[n][k]=max(memo[n][k],input[n][i]+recursiveTraining(input,n-1,memo,i));
        }
    }
    return memo[n][k];
}

int dpTraining(vector<vector<int>>&input)
{
    int n=input.size();
  vector<vector<int>>dp(n,vector<int>(4,0));

    dp[0][0]=max(input[0][1],input[0][2]);
    dp[0][1]=max(input[0][0],input[0][2]);
    dp[0][2]=max(input[0][0],input[0][1]);
    dp[0][3]=max({input[0][0],input[0][1],input[0][2]});

    for(int i=1;i<n;i++)
    {
        for(int last=0;last<4;last++)
        {
            for(int task=0;task<3;task++)
            {
                if(last!=task)
                {
                    dp[i][last]=max(dp[i][last],input[i][task]+dp[i-1][task]);
                }
            }
        }
    }

    return dp[n-1][3];
}
int main()
{
   int n;
   cin>>n;
   vector<vector<int>> v(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
         for(int j=0;j<3;j++)
         {
              cin>>v[i][j];
         }
    }

    vector<vector<int>> memo(n,vector<int>(4,-1));

    int ans1= recursiveTraining(v,n-1,memo,3);
    int ans2= dpTraining(v);
    cout<<ans1<<" "<<ans2<<endl;

}