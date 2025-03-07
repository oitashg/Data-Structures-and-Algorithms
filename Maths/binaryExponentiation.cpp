#include<iostream>
using namespace std;

int mod = 1e9 + 7;

//---------------------------------------------------------------

long long power(long long a, long long b, long long ans){
    //base case
    if(b == 0) return ans;

    //binary exponentiation
    if(b&1) return power(a, b-1, (ans*a) % mod);
    else return power((a*a) % mod, b/2, ans);
}

//--------------------------------------------------------------------