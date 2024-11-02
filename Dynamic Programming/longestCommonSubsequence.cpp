#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:

    //----------------Memoization method---------------------------------
    //--------------------dp function------------------------------------

    int f(int i, int j, string &s1, string &s2, vector<vector<int>>& dp){
        //base case
        if(i < 0 || j < 0) return 0;

        
        //dp[i][j] stores the length of longest common subsequence upto 
        //ith index of text1 and jth index of text2
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
        else 
            return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
    }
    
    //-------------------------------------------------------------------------

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, text1, text2, dp);
    }

    //---------------------------Tabulation method--------------------------------

    int lcs(string &s, string &t){

        int n = s.size();
        int m = t.size();

        //dp[i][j] stores the length of longest common subsequence upto 
        //ith index of s and jth index of text2
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;

        int ans = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return ans;
    }

    //----------------------------------------------------------------------------
};