#include<iostream>
using namespace std;

//--------------Prime number function--------------------

bool isPrime(int num){
    if(num == 1) return false;
    
    for(int i=2; i<=sqrt(num); i++){
        if(num % i == 0) return false;
    }

    return true;
}

//----------------------------------------------------------