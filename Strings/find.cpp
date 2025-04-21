#include<iostream>
using namespace std;

int main(){
    string s1 = "oitash";
    string s2 = "tas";

    //There is a direct function to check the first and last occurrence of a substring in a string
    //find() -> first occurrence and rfind() -> last occurrence

    cout<<s1.find(s2)<<endl;
    cout<<s1.rfind(s2)<<endl;

    return 0;
}