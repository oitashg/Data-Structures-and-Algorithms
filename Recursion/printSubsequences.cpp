#include<iostream>
#include<vector>
using namespace std;

//---------------------------By Recursion-------------------------------------------

void printSubsequences(int idx, int n, int arr[], vector<int>& v){
    //base case
    if(idx == n){
        for(auto i: v)
            cout<<i<<" ";

        if(v.size() == 0)
            cout<<"{}";

        cout<<endl;
        return;
    }

    //take
    v.push_back(arr[idx]);
    printSubsequences(idx+1, n, arr, v);

    //not take
    v.pop_back();
    printSubsequences(idx+1, n, arr, v);
}

//-------------------------By Power Set(TC- (2^n)*N)-------------------------------------------
//-------------------------------Note------------------------------
//To check whether ith bit of a number 'num' is set or not, we do -->
//(num & (1<<i)) --> If it comes 1 then the ith bit of num is set bit or 1 otherwise not

void print(int arr[], int n){
    for(int num=0; num<(1<<n); num++){
        for(int i=0; i<n; i++){
            //if bit is set, then take it, otherwise not
            if(num & (1<<i))
                cout<<arr[i]<<" ";
        }

        if(num == 0) cout<<"{}";
        cout<<endl;
    }
}

//----------------------------------------------------------------------------------

int main(){
    int n;
    cout<<"Enter the size of array -> ";
    cin>>n;

    int arr[100];
    cout<<"Enter the elements of array -> "<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    vector<int> v;

    // printSubsequences(0, n, arr, v);
    print(arr, n);
    return 0;
}