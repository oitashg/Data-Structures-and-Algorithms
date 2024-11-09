#include<iostream>
using namespace std;

//If no. of bits are given, then we can find the max integer formed of that number of bits
int bit = 4;
int mask = (1 << bit) - 1;   //max value of the integer

//To eliminate any number we apply xor of the expression with the same integer
int x;
int num = 3^5;
int result = (num ^ 3) ^ x;   //it will return 5 ^ x ^ 0

//Now (0 ^ anything) will return (anything) 
//So, result = x ^ 5

//In XOR, even no. of 1's -> 0 
//In XOR, odd no. of 1's -> 1

//----------------------Swap 2 numbers----------------------------------

// int a, b;

// a = a ^ b;
// b = a ^ b = (a ^ b) ^ b = a;
// a = a ^ b = (a ^ b) ^ a = b;

//So, a = b and b = a. So, a and b are swapped

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