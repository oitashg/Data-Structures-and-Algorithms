#include<iostream>
using namespace std;

//-----------------------Algorithm behind pow(x,n) or x^n------------------
//-------------------------Optimal solution(T.C - logn)--------------------

int powerExp(int x, int n){
    int ans = 1;

    while(n > 0){
        if(n % 2){
            ans = ans * x;
            n--;
        }
        else{
            n /= 2;
            x *= x;
        }
    }

    return ans;
}

//----------------------------------------------------------------------------

int main(){
    int ans = powerExp(2,3);
    cout<<ans;
    return 0;
}
