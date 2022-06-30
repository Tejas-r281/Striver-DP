/*
Question :
There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.
*/

/*
Ways to write recursive code

1. try to represent the problem in a terms of index

2.Do all possible stuffs on that index and accrodingly to the problem statement

3. if question asking  COUNT ALL WAYS ==> Sum of all the stuffs
   if question asking MIN OR MAX      ==>  Then we will take max or min from the calculated stuffs
*/
#include <bits/stdc++.h>
using namespace std;

// top down approach and here I am taking starting point as n-1th index;
int recursiveJump(vector<int> &input, int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MAX;
    }
    /*
     1. by considering n as the current index and as frog can jump only i+1 or i+2 stairs;

     2. By taking nth as the current index then we need to check only (n+1)th or (n+2)th stairs and minimum of both.

     3. Here we need to find the minimum energy required to reach the 0th stair. that is why i am taking minimum of all the stuff.
    */
    int oneStep = INT_MAX;
    int twoStep = INT_MAX;

    oneStep = recursiveJump(input, n - 1) + abs(input[n] - input[n - 1]);
    if (n - 2 >= 0)
    {
        twoStep = recursiveJump(input, n - 2) + abs(input[n] - input[n - 2]);
    }

    return min(oneStep, twoStep);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans1 = recursiveJump(v, n - 1);

    cout << ans1 << endl;
}
