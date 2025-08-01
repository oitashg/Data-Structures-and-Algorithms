#include<iostream>
using namespace std;

//---------------Count the total number of set bits(1) in a number-------------
//------------------A number n can have atmost log2(n) set bits----------------
int countSetBits(int n){
    if(n == 0) return 0;
    else return (n & 1) + countSetBits(n >> 1);
}

//----------------------T.C- O(no. of set bits)(fastest)-----------------------

int countSetBits2(int n){
    int cnt = 0;

    while(n > 0){
        //removes last set bit from current number
        n = n & (n-1);
        cnt++;
    }

    return cnt;
}

//----------------------------T.C - O(31)--------------------------------------

int countSetBits3(int n){
    int cnt = 0;

    for(int i=0; i<31; i++){
        if(n & (1 << i)) cnt++;
    }

    return cnt;
}

//-----------------------------------------------------------------------------

int countSetBit4(int n){
    int cnt = 0;

    while(n > 0){
        if(n & 1) cnt++;
        n = n >> 1;
    }

    return cnt;
}

//-------------------------------------------------------------------------------

//There is a built-in fucntion __builtin_popcount() which directly returns the number of set bits in an integer

int num = 7;
int cnt = __builtin_popcount(num);

long long num = 2345678876543;
int cnt = __builtin_popcountll(num);   //for long long

//--------------------------------------------------------------------------------

int main(){
    int ans = countSetBits(16);
    int ans2 = countSetBits2(16);
    int ans2 = countSetBits3(16);
    cout<<ans<<endl;
    cout<<ans2;
    return 0;
}    