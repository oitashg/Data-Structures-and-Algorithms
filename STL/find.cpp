// In C++, string find() is a library function used to find the 
// first occurrence of a sub-string in the given string.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Welcome to GfG!";
    string sub = "to";

    cout << s.find(sub);

    return 0;
}
