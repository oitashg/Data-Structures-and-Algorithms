#include<iostream>
#include<vector>
using namespace std;

//---------------------------Print all subsequences with sum K-------------------------------------------

void printAllSubsequences(int idx, int n, int arr[], vector<int>& v, int sum, int k){
    //base case
    if(idx == n){
        if(sum == k){
            for(auto it: v) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }

    //take
    v.push_back(arr[idx]);
    sum += arr[idx];
    printAllSubsequences(idx+1, n, arr, v, sum, k);

    //not take
    v.pop_back();
    sum -= arr[idx];
    printAllSubsequences(idx+1, n, arr, v, sum, k);
}

//-----------------------------Print any one subsequence with sum K-------------------------------------

bool printOneSubsequence(int idx, int n, int arr[], vector<int>& v, int sum, int k){
    //base case
    if(idx == n){
        if(sum == k){
            for(auto it: v) cout<<it<<" ";
            return true;
        }

        return false;
    }

    //take
    v.push_back(arr[idx]);
    sum += arr[idx];
    if(printOneSubsequence(idx+1, n, arr, v, sum, k)) return true;

    //not take
    v.pop_back();
    sum -= arr[idx];
    if(printOneSubsequence(idx+1, n, arr, v, sum, k)) return true;

    //when both the above cases fails then finally it returns false
    return false;
}

//-----------------------------Count no of subsequences with sum K---------------------------------------

int countSubsequences(int idx, int n, int arr[], int sum, int k){
    //base case
    if(idx == n){
        if(sum == k) return 1;
        else return 0;
    }

    //take
    sum += arr[idx];
    int take = countSubsequences(idx+1, n, arr, sum, k);

    //not take
    sum -= arr[idx];
    int notTake = countSubsequences(idx+1, n, arr, sum, k);

    //finally returns the sum of 2 above cases...take and notTake
    return (take + notTake);
}

//---------------------------------------------------------------------------------------------------

int main(){
    int n;
    cout<<"Enter the size of array -> ";
    cin>>n;

    int arr[100];
    cout<<"Enter the elements of array -> "<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int k;
    cout<<"Enter the value of target -> ";
    cin>>k;

    int sum = 0;
    vector<int> v;

    printAllSubsequences(0, n, arr, v, sum, k);
    printOneSubsequence(0, n, arr, v, sum, k);
    cout<<countSubsequences(0, n, arr, sum, k);

    return 0;
}