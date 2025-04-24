// https://www.geeksforgeeks.org/next-greater-element/

/*
we are given an array
arr = 1, 3, 2, 4
ans = 3, 2, 4, -1

this is what we have to do
*/


/*
IDENTIFY
    brute force is o(n^2) with j depending on i
    means that we need to use stacks

    to access the ith element it should have been inserted into the stack in n-i+1 th time
    thus in reverse manner traversal

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
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

void solve(){
    vector<int> arr = {1, 3, 2, 4};
    stack<int> st;
    vector<int> ans(arr.size(), -1);  // Initialize with -1 to handle cases where no greater element exists

    int n = arr.size();
    for(int i = 0; i < n; i++) {  // Corrected loop condition
        // Pop elements from the stack while the current element is greater than or equal to the stack's top
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is not empty, the top element is the next greater element
        if(!st.empty()) {
            ans[i] = st.top();
        }
        
        // Push the current element onto the stack
        st.push(arr[i]);
    }
 
    // Print the result
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}


int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    