#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        int start = 0, maxLen = 1;

        // All substrings of length 1 are palindromes
        for(int i=0; i<n; i++) dp[i][i] = true;

        // Check for sub-string of length 2
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;

                if(maxLen < 2){
                    maxLen = 2;
                    start = i;
                }
            }
        }

        // Check for lengths greater than 2
        // k is the length of palindrome
        for(int k=3; k<=n; k++){
            for(int i=0; i<=n-k; i++){
                int j = i+k-1;

                if(s[i] == s[j] and dp[i+1][j-1] == 1){
                    dp[i][j] = true;

                    if(maxLen < k){
                        maxLen = k;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start,maxLen);
    }
};