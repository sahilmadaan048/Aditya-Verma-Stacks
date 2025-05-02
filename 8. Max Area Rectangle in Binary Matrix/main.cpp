// https://www.youtube.com/watch?v=St0Jf_VmG_g&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=8

/*

Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
Example:

Input :   0 1 1 0
          1 1 1 1
          1 1 1 1
          1 1 0 0

Output :  1 1 1 1
          1 1 1 1 . 

*/

#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())))
#define bin(x,y)  bitset<y>(x)
using namespace std;
int MOD=1e9+7;

void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}

template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

// Function to compute max area of histogram using left[] and right[] arrays
int maxHistArea(vi &heights) {
    int n = sz(heights);
    vi left(n), right(n);
    stack<int> st;

    // Fill left[] with index of previous smaller element
    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if(st.empty()) left[i] = -1;
        else left[i] = st.top();
        st.push(i);
    }

    // Clear stack for reuse
    while(!st.empty()) st.pop();

    // Fill right[] with index of next smaller element
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if(st.empty()) right[i] = n;
        else right[i] = st.top();
        st.push(i);
    }

    // Compute max area
    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

void solve() {
    // Input binary matrix
    vvi matrix = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    int rows = sz(matrix), cols = sz(matrix[0]);
    vi hist(cols, 0);
    int maxRect = 0;

    // Build histogram row by row
    fr(i, rows) {
        fr(j, cols) {
            if(matrix[i][j] == 0) hist[j] = 0;
            else hist[j] += 1;
        }

        // Get max rectangle area from this histogram
        maxRect = max(maxRect, maxHistArea(hist));
    }

    cout << "Maximum size rectangle of all 1's: " << maxRect << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
