#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:

    //normal recursion
    int fun1(int n){
        //base case
        if(n <= 1)
            return n;

        //recursion
        return fun1(n-1) + fun1(n-2);
    }

    //Memoization(top-down approach)
    int fun2(int n, vector<int>& dp){
        //base case
        if(n <= 1)
            return n;

        //checking if answer to that sub-problem already exists or not in the dp array
        if(dp[n] != -1)
            return dp[n];

        //recursion
        return dp[n] = fun2(n-1, dp) + fun2(n-2, dp);
    }

    //Tabulation method(bottom-up approach)
    int fun3(int n, vector<int>& dp){
        //base case
        dp[0] = 0, dp[1] = 1;

        //checking if answer to that sub-problem already exists or not in the dp array
        if(dp[n] != -1)
            return dp[n];

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    //Space optimization method(O(1))
    int fun4(int n){
        //base case
        int prev1 = 0, prev = 1;

        for(int i=2; i<=n; i++){
            int cur = prev + prev1;
            prev1 = prev;
            prev = cur;
        }

        return prev;
    }
};


int main(){
    int n;
    cout<<"Enter the number -> ";
    cin>>n;

    Solution s;
    cout<<"Answer is -> "<<s.fun1(n)<<endl;

    vector<int> dp(n+1, -1);

    cout<<"Answer is -> "<<s.fun2(n,dp)<<endl;
    cout<<"Answer is -> "<<s.fun3(n,dp)<<endl;
    cout<<"Answer is -> "<<s.fun4(n)<<endl;
}