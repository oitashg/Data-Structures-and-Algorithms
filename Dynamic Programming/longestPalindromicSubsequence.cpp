#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//Note: Here the trick is that we take the given string as s1 and same string in reverse order as s2
//      Then apply longest common subsequence code here exactly with s1 and s2 which returns palindromic lcs

//Eg:- s1 = abbab s2 = babba , so lcs = abba which itself is a palindrome
//So lcs of s1 and reverse(s1) is alwways a palindrome

class Solution {
public:

    //-------------------------------------------------------------------------

    int f(int i, int j, string &s1, string &s2, vector<vector<int>>& dp){
        //base case
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
        else 
            return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
    }

    //-------------------------------------------------------------------------

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(n-1, n-1, s, t, dp);
    }
};