#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int size;
public:
    // Constructor to initialize the Fenwick Tree with a given size
    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0); // Initialize tree with size n+1 (1-based index)
    }

    // Function to find the lower bound of the prefix sum
    // This function finds the smallest index such that the prefix sum is greater than or equal to k
    int find(int k){
        int curr = 0, ans = 0, prevSum = 0;

        //here you can wrute 20 insteed of log2(size)
        //because log2(10^6) is almost 20
        for(int i=log2(size); i>=0; i--){
            if(tree[curr + (1<<i)] + prevSum < k){
                curr += (1<<i);
                prevSum += tree[curr];
            }
        }

        return (curr+1);
    }
};