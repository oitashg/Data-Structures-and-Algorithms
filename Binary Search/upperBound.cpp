#include<iostream>
#include <vector>
using namespace std;

//---------------Implementation of upper bound---------------------------
// smallest index where element at that index is greater than x
// arr[idx] > x

int upperBound(vector<int> &arr, int x, int n){
	int low = 0, high = n-1;
	int ans = n;

	while(low <= high){
		int mid = low + (high-low)/2;

		if(arr[mid] > x){
			//this might be an answer, so store it
			ans = mid;
			//but we have to look for smaller index
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	return ans;	
}

//----------------------------------------------------------------------------

// But in coding rounds we don't have to write the full upper code, instead we write -> 
// ub = upper_bound(arr.begin(), arr.end(), x) --> where from arr.begin() upto arr.end(), it is the search space and x is the number