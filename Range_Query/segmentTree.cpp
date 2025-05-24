#include<bits/stdc++.h>
using namespace std;

int a[100005], seg[4*100005];

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

// This function queries the segment tree for the maximum value in the range [l, r]
// The query is done in a top-down manner by checking if the current segment
// is completely outside, completely inside, or partially inside the range [l, r].
// If the current segment is completely outside the range, it returns INT_MIN.
// If it is completely inside the range, it returns the value stored in the segment tree.
// If it is partially inside the range, it recursively queries the left and right children
// and returns the maximum of the two results.
// The query is done in O(log n) time complexity.

int query(int idx, int low, int high, int l, int r) {
    if (low > r || high < l) return INT_MIN; // out of range
    if (low >= l && high <= r) return seg[idx]; // in range

    //partial overlap case, we need to check both left and right children
    int mid = (low + high) / 2;
    int left = query(2*idx + 1, low, mid, l, r);
    int right = query(2*idx + 2, mid + 1, high, l, r);
    return max(left, right); // combine results
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
        cout<<query(0, 0, n-1, l, r)<<endl; // query the segment tree
    }
}