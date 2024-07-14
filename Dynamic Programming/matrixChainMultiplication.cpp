#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//-----------------dp function----------------------------------------

int matrixMultiplication(vector<int> &a, int N)
{
    vector<vector<int>> dp(N, vector<int>(N+1,0));
    
    for(int i=N-1; i>=1; i--){
        for(int j=i+1; j<N; j++){

            int mini = 1e9;
            for(int k=i; k<j; k++){
                int steps = (a[i-1]*a[j]*a[k]) + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][N-1];
}

//------------------------------------------------------------------