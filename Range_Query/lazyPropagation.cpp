#include<bits/stdc++.h>
using namespace std;

int a[100005], seg[4*100005], lazy[4*100005];

// This function builds the segment tree in a bottom-up manner
// The segment tree is stored in a 1D array where the left child of node i is at 2*i + 1
// and the right child is at 2*i + 2. The parent of node i is at (i-1)/2.
// The segment tree is built by recursively dividing the array into halves
// and storing the maximum value in each segment in the segment tree.
// The segment tree is built in O(n) time complexity.

void build(int idx, int low, int high) {
    //leaf node
    if (low == high) {
        seg[idx] = a[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2*idx + 1, low, mid);
    build(2*idx + 2, mid + 1, high);
    seg[idx] = max(seg[2*idx + 1], seg[2*idx + 2]);
}

// This function queries the segment tree for updating the range [l, r]
// The update is done in a top-down manner by checking if the current segment
// is completely outside, completely inside, or partially inside the range [l, r].

void rangeUpdate(int idx, int low, int high, int l, int r, int val) {
    // If there is a pending update, apply it
    if(lazy[idx] != 0) {
        seg[idx] += (high-low+1) * lazy[idx]; // Update the current segment

        if (low != high) { // Not a leaf node
            lazy[2*idx + 1] += lazy[idx]; // Propagate to left child
            lazy[2*idx + 2] += lazy[idx]; // Propagate to right child
        }

        lazy[idx] = 0; // Clear the lazy value for this node
    }

    // If the current segment is completely outside the range [l, r], do nothing
    if (low > r || high < l) return;

    // If the current segment is completely inside the range [l, r], update it
    if (low >= l && high <= r) {
        // If there is a pending update, apply it
        seg[idx] += (high-low+1) * val; // Update the current segment
        
        if (low != high) { // Not a leaf node
            lazy[2*idx + 1] += lazy[idx]; // Propagate to left child
            lazy[2*idx + 2] += lazy[idx]; // Propagate to right child
        }
        
        return;
    }

    // Partial overlap case, we need to check both left and right children
    int mid = (low + high) / 2;
    rangeUpdate(2*idx + 1, low, mid, l, r, val);
    rangeUpdate(2*idx + 2, mid + 1, high, l, r, val);
    
    // After updating children, we need to recalculate the current node's value
    seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
}

// This function queries the segment tree for the sum in the range [l, r]
// The query is done in a top-down manner by checking if the current segment
// is completely outside, completely inside, or partially inside the range [l, r].

int querySumLazy(int idx, int low, int high, int l, int r) {
    // If there is a pending update, apply it
    if (lazy[idx] != 0) {
        seg[idx] += (high-low+1) * lazy[idx]; // Update the current segment

        if (low != high) { // Not a leaf node
            lazy[2*idx + 1] += lazy[idx]; // Propagate to left child
            lazy[2*idx + 2] += lazy[idx]; // Propagate to right child
        }

        lazy[idx] = 0; // Clear the lazy value for this node
    }

    // If the current segment is completely outside the range [l, r], return 0
    if (low > r || high < l) return 0;

    // If the current segment is completely inside the range [l, r], return its value
    if (low >= l && high <= r) return seg[idx];

    // Partial overlap case, we need to check both left and right children
    int mid = (low + high) / 2;
    int leftSum = querySumLazy(2*idx + 1, low, mid, l, r);
    int rightSum = querySumLazy(2*idx + 2, mid + 1, high, l, r);
    
    return (leftSum + rightSum); // Combine results
}

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    build(0, 0, n-1); // build the segment tree
    int q;
    cin>>q;

    while(q--) {
        int l, r;
        cin>>l>>r;
    }
}