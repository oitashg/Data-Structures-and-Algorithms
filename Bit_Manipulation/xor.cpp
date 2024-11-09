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

//-------------------------Swap 2 numbers----------------------------------

// int a, b;

// a = a ^ b;
// b = a ^ b = (a ^ b) ^ b = a;
// a = a ^ b = (a ^ b) ^ a = b;

//So, a = b and b = a. So, a and b are swapped

//-------------------------XOR from 1 to n---------------------------------
// 1 = 1
// 1^2 = 3
// 1^2^3 = 0
// 1^2^3^4 = 4

// 1^2^3^4^5 = 1
// 1^2^3^4^5^6 = 7
// 1^2^3^4^5^6^7 = 0
// 1^2^3^4^5^6^7^8 = 8

//This pattern will repeat for every 4 numbers

int xorFromOne(int n){
    if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n+1;
    else if(n % 4 == 3) return 0;
    else return n;
}

//------------------------XOR of a number in a given range------------------

int xorInRange(int l, int r){
    int left = xorFromOne(l-1);
    int right = xorFromOne(r);
    
    return (left ^ right);
}

//----------------------------------------------------------------------------