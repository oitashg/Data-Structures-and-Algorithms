#include<iostream>
using namespace std;

//--------------------Check if ith bit is set(1) or not---------------------------------

bool checkSetBit(int n, int i){
    if((n & (1 << i)) != 0) return true;
    return false;
}

//--------------------------------------------------------------------------------------

int main(){
    bool ans = checkSetBit(11, 200);
    if(ans) cout<<"Yes";
    else cout<<"No";
    return 0;
}