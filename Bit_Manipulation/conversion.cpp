#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

//------------------------Decimal to binary conversion--------------------------
//--------------------------------T.C. - O(logn)--------------------------------
//--------------------------------S.C. - O(logn)--------------------------------

string convertToBinary(int n){
    string ans = "";

    while(n > 0){
        ans += to_string(n % 2);
        n /= 2;
    }

    reverse(ans.begin(), ans.end());
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