#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// In C++, the count() is a built - in function used to find the number of occurrences 
// of an element in the given range.This range can be any STL container or an array.

int main() {
    vector<int> v = {2, 3, 2, 1, 5, 4, 2};

    // Count the occurrence of 2
    cout << count(v.begin(), v.end(), 2);
    return 0;
}