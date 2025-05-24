#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//----------------Fenwick Tree (Binary Indexed Tree) implementation-------------------
//---------------------T.C - O(log n) for both update and query-----------------------
//---------------------S.C - O(n) for storing the Fenwick Tree------------------------

// Fenwick Tree is a data structure that allows efficient updates and prefix sum queries
// in logarithmic time. It is particularly useful for problems involving cumulative frequency
// tables, such as range sum queries and point updates.

// The Fenwick Tree is often used in competitive programming and algorithm design due to its
// efficiency and simplicity. It is a powerful tool for solving problems that involve
// cumulative frequency tables, such as range sum queries and point updates.   

//For example, range of index 8 i.e arr[8] is {1,8} that means arr[8] contains sum of
// arr[1] to arr[8]. Similarly, range of index 7 i.e arr[7] is {5,7} that means arr[7]

//Find the range of any index i.e {l,r} ->
//r is simply the index i.e i
//to find l, we turn off the rightmost set bit of i and add 1 to it
//eg: range of 8 is {1,8} and range of 7 is {7,7}

//Suppose, we are updating the value of an index i by x, then we need to update all the
//indexes which are in the range of i. So, to find the next index from current index i, we do 3 steps ->
//1. Calculate 2's complement of i 
//2. AND it with i
//3. Add the result to i
//So, the next index will be i + (i & -i)

//If we want the sum of the range of index i, do the same steps as in updating the value just one change ->
//1. Calculate 2's complement of i 
//2. AND it with i
//3. Subtract the result from i
//So, the next index will be i - (i & -i)

//---------------------------------------------------------------------------------------

class FenwickTree {
private:
    vector<int> tree;
    int size;
public:
    // Constructor to initialize the Fenwick Tree with a given size
    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0); // Initialize tree with size n+1 (1-based index)
    }

    // Function to update the Fenwick Tree at index idx by adding value
    void update(int idx, int value) {
        while (idx <= size) {
            tree[idx] += value; // Add value to the current index
            idx += (idx & (-idx));   // Move to the next index
        }
    }

    // Function to get the prefix sum from 1 to idx
    int query(int idx) {
        int sum = 0;

        while (idx > 0) {
            sum += tree[idx]; // Add the value at the current index
            idx -= (idx & (-idx)); // Move to the parent index
        }
        return sum;
    }

    // Function to get the range sum from left to right (inclusive)
    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1); // Calculate range sum
    }
};

//----------------------------------------------------------------------------------------

int main() {
    int n = 10; // Size of the Fenwick Tree
    FenwickTree fenwickTree(n);

    // Example updates
    fenwickTree.update(1, 5); // Add 5 to index 1
    fenwickTree.update(2, 3); // Add 3 to index 2
    fenwickTree.update(3, 7); // Add 7 to index 3

    // Example queries
    cout << "Sum from 1 to 3: " << fenwickTree.query(3) << endl; // Output: 15
    cout << "Sum from 2 to 5: " << fenwickTree.rangeQuery(2, 5) << endl; // Output: 10

    return 0;
}