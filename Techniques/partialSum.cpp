#include<iostream>
#include<vector>
using namespace std;

//----------------Add X to all elements in the index range(l,r), then find the final array------------------

vector<int> partialSum(vector<int>& arr, int l, int r, int x){
    int n = arr.size();

    //Step-1
    vector<int> p(n+1, 0);

    //Step-2
    p[l] += x;
    p[r+1] -= x;

    //Step-3(prefix sum to get the final array)
    for(int i=0; i<n; i++){
        if(i > 0) p[i] += p[i-1];
    }

    return p;
}

//-----------------------------------------------------------------------------------------------------------

int main(){
    int l = 1, r = 3, x = 5;
    vector<int> v = {1,3,7,4,9};

    vector<int> finalArray = partialSum(v, l, r, x);
    for(auto a: finalArray) cout<<a<<" ";

    return 0;
}