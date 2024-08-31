#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    //------------Applicable for both distinct as well as duplicate elements in array---------------

    //Don't pass v by reference otherwise it will disturb the sorted order of array
    //Because we are removing the duplicates using that sorted vector only

    void f(int idx, int n, vector<int>& nums, vector<int> v, vector<vector<int>>& ans){
        //base case
        if(idx == n){
            ans.push_back(v);
            return;
        }

        for(int i=idx; i<n; i++){
            if(i != idx && v[i] == v[idx]) continue;
        
            swap(v[i], v[idx]);
            f(idx+1, n, nums, v, ans);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        vector<vector<int>> ans;
        sort(v.begin(), v.end());

        f(0, n, nums, v, ans);
        return ans;
    }

    //-------------------------------------------------------------------------------------------
};