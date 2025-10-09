#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int col, int n, vector<int>& temp, vector<vector<int>>& ans, vector<int>& lr, vector<int>& ld, vector<int>& ud){
        //base case
        if(col == n){
            ans.push_back(temp);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(lr[row] == 0 and ld[row+col] == 0 and ud[n-1+col-row] == 0){
                temp.push_back(row+1);
                lr[row] = 1;
                ud[n-1+col-row] = 1;
                ld[row+col] = 1;
                solve(col+1,n,temp,ans,lr,ld,ud);
                ld[row+col] = 0;
                ud[n-1+col-row] = 0;
                lr[row] = 0;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> lr(n,0), ld(2*n-1,0), ud(2*n-1,0);
        
        solve(0,n,temp,ans,lr,ld,ud);
        
        return ans;
    }
};