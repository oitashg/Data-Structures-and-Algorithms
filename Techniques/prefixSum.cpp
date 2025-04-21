#include<iostream>
#include<vector>
using namespace std;

//-------------------Sum of elements in index range(l,r) odf a vector--------------

int prefixSumInRange(vector<int>& arr, int l, int r){
    int n = arr.size();
    vector<int> p(n, 0);

    //prefix sum
    for(int i=0; i<n; i++){
        //p[i] contains sum of elements of arr from index 0 to i
        p[i] += (arr[i] + p[i-1]);
    }

    int leftSum = p[l-1];
    int rightSum = p[r];

    return (rightSum - leftSum);
}

//--------------------------------------------------------------------------------

int main(){
    int l = 2, r = 3;
    vector<int> v = {1,3,7,4,9};

    int sum = prefixSumInRange(v, l, r);
    cout<<sum;

    return 0;
}