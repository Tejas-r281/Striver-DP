/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
*/
#include<bits/stdc++.h>
using namespace std;
const bool static comp(string &input1, string &input2)
{
    return input1.size() < input2.size();
}
bool isvalid(string &larger, string &smaller)
{
    int nl = larger.size();
    int ns = smaller.size();
    if (abs(nl - ns) != 1)
    {
        return false;
    }

    int i = 0;
    int j = 0;
    while (i != nl)
    {
        if (larger[i] == smaller[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return j == ns;
}
int longestStrChain(vector<string> &words)
{

    sort(words.begin(), words.end(), comp);
    int n = words.size();

    vector<int> dp(n, 1);
    int maxe = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (isvalid(words[i], words[j]))
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        maxe = max(maxe, dp[i]);
    }
    return maxe;
}
int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    cout << longestStrChain(words) << endl;
    return 0;
}