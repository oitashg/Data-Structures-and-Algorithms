// Memset() is a C++ function that copies a single character for a specified number of times 
// to the given bytes of memory. It is useful for filling a number of bytes with a given value 
// starting from a specific memory location. 
// It is defined in <cstring> header file.

// C++ program to demonstrate memset
#include <cstring>
#include <iostream>
using namespace std;


int main()
{
    char str[] = "geeksforgeeks";
    // setting each byte of memory of str to 't' using memset
    memset(str, 't', sizeof(str));
  
    cout << str;
  
    return 0;
}