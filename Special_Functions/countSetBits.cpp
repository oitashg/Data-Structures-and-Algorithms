#include<iostream>
using namespace std;

//---------------Count the total number of set bits(1) in a number-------------

int countSetBits(int n){
    if(n == 0) return 0;
    else return (n & 1) + countSetBits(n >> 1);
}

//-----------------------------------------------------------------------------

int main(){
    int ans = countSetBits(11);
    cout<<ans;
    return 0;
}