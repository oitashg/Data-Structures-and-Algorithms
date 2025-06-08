#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

//------------------------Decimal to binary conversion--------------------------
//--------------------------------T.C. - O(logn)--------------------------------
//--------------------------------S.C. - O(logn)--------------------------------

int convertToBinary(int n){
    int ans = 0;
    int p = 1; // power of 10

    while(n > 0){
        int lastBit= n&1;
        ans += p*lastBit; // add the last bit to the answer
        
        p = p*10;
        n = n >> 1;
    }

    return ans;
}

//------------------------Binary to decimal conversion--------------------------
//--------------------------------T.C. - O(length of string)--------------------
//--------------------------------S.C. - O(1)-----------------------------------

int convertToDecimal(string s){
    int n = s.size();
    int ans = 0, p = 1;

    for(int i=n-1; i>=0; i--){
        if(s[i] == '1') ans += p;
        p *= 2;
    }

    return ans;
}

//--------------------------------------------------------------------------------

int main(){
    cout<<convertToBinary(23)<<endl;
    cout<<convertToDecimal("101");
    return 0;
}