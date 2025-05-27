#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //-------------------------T.C- O(logN)----------------------
    //--------------------Array should be sorted-----------------
    //--------------------------Iterative------------------------

    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) low = mid+1;
            else high = mid-1;
        }

        return -1;
    }

    //-------------------------Recursive-------------------------------

    int f(vector<int>& nums, int low, int high, int target){
        //base case
        if(low > high) return -1;

        int mid = low + (high-low)/2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) return f(nums, low, mid-1, target);
        else return f(nums, mid+1, high, target);
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        sort(nums.begin(), nums.end());

        return f(nums, low, high, target);
    }

    //---------------------------------------------------------------
};