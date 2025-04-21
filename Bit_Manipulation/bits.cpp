#include<iostream>
using namespace std;

//--------------------Check if ith bit is set(1) or not-----------------
//-----------------------T.C and S.C - O(1)-----------------------------

bool checkSetBit(int n, int i){
    if((n & (1 << i)) != 0) return true;
    return false;
}

//-----------------Set the ith bit i.e if ith bit is 0 flip it to 1-------------------

int setBit(int n, int i){
    int ans = (n | (1 << i));
    return ans;
}

//-----------------Clear the ith bit i.e if ith bit is 1 flip it to 0-------------------

int clearBit(int n, int i){
    int ans = (n & ~(1 << i));
    return ans;
}

//----------Toggle the ith bit i.e if ith bit is 1 flip it to 0 and vice-versa---------

int toggleBit(int n, int i){
    int ans = (n ^ ~(1 << i));
    return ans;
}

//----------------------------Clear the last(rightmost) set bit-------------------------
// In (n-1) the righmost set bit of n flips to 0 and bits after that flips to 1
// Eg:- n = 16(10000) n-1 = 15(01111)

int clearLastSetBit(int n){
    int ans = (n & (n-1));
    return ans;
}

//-------------------------Check if the number is power of 2------------------------------
// If a number is power of 2, it will always have a single set bit
// Eg:- n = 16(10000) n = 8(1000)

bool checkPowerOf2(int n){
    if(n & (n-1) == 0) return true;
    else return false;
}

// An odd number always has the last bit as 1
// So, if(n & 1) returns 1 means n is an odd number else even number
// (n % 2) equivalent to (n & 1)
// (n/2) equivalent to (n >> 1)

//(a << n) == a*(2^n) -> Left shift
//(a >> n) == a/(2^n) -> Right shift

//--------------------------------------------------------------------------------------------

int main(){
    int a = 5; //integer
    int b = 2; //position

    //It returns the integer number after changing the bit
    int num = a & (1<<b);

    //It return the bit value at that position i.e 0 or 1
    int bit = (a>>b) & 1;

    //returns the number after setting the bit at that position(if not set)
    int ans = a | (1<<b);

    cout<<num<<" "<<bit<<" "<<ans;
}

//-----------------------------------------------------------------------------------------