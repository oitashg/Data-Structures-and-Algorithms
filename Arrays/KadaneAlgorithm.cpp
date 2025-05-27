#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //---------Maximum Subaray Sum------------------
    //---------Kadanes's Algorithm------------------

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, ans = INT_MIN;

        for(int i=0; i<n; i++){
            //adding elements in the window
            sum += nums[i];
            //if sum > ans---> update ans
            ans = max(ans, sum);
            //if current window sum comes negative, we will reinitialize sum to 0 as we want maximum sum
            if(sum < 0) sum = 0;
        }

        return ans;
    }

    //----------------------------------------------
};