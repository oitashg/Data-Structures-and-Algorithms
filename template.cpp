//--------------------Standard Template for competitive programming-----------------------------------

#include <bits/stdc++.h>
using namespace std;

// Speed up input and output
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// Macros for common functions
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())

// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// Debugging
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

// Utility functions
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Solve function
void solve() {
    // Write your logic here
}

int main() {
    ios; // Fast IO

    int t;
    cin >> t; // For multiple test cases

    while (t--) {
        solve();
    }
    
    return 0;
}
