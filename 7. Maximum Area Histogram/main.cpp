// https://www.youtube.com/watch?v=J2X70jj_I1o&list=PLwEApySc2G_k4Zl1gGgQdC2NfykPKCMwR&index=7

/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a
number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.

*/

// https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-using-stack/

#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define nl cout << "\n"
#define dbg(var) cout << #var << "=" << var << " "
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define srt(v) sort(v.begin(), v.end())         // sort
#define mxe(v) *max_element(v.begin(), v.end()) // find max element in vector
#define mne(v) *min_element(v.begin(), v.end()) // find min element in vector
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed
#define bin(x, y) bitset<y>(x)
using namespace std;
int MOD = 1e9 + 7; // Hardcoded, directly change from here for functions!

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }
// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================

void solve()
{
    vi heights = {5, 2, 4, 5, 3, 6, 6};
    int n = heights.size();
    vi leftSmaller(n, -1);  // Stores indices of first smaller element to the left
    vi rightSmaller(n, n);  // Stores indices of first smaller element to the right
    stack<int> st;

    // Compute left smaller indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (!st.empty()) {
            leftSmaller[i] = st.top();
        }
        st.push(i);
    }

    // Clear stack for right pass
    while (!st.empty()) st.pop();

    // Compute right smaller indices
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (!st.empty()) {
            rightSmaller[i] = st.top();
        }
        st.push(i);
    }

    // Calculate maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = rightSmaller[i] - leftSmaller[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    cout << maxArea << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}

/*

A building can be expanded into other buildings
when their height >= current building height

*/

// Here we are finding the nearest smallest to left and nearest smallest to right

/*

The key idea is to find for each bar, the first bar to the left and right
that is smaller than the current bar. The area for the current bar would then be:
height[i] * (rightSmaller[i] - leftSmaller[i] - 1)

*/

// The stack helps us efficiently find these boundaries in O(n) time