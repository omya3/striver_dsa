#include <bits/stdc++.h>
using namespace std;

vector<int> findNse(vector<int> &nums) {
    int n = nums.size();
    vector<int> nse(n, n);       // next smaller or equal index, default n
    stack<int> st;               // indices

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

vector<int> findPsee(vector<int> &nums) {
    int n = nums.size();
    vector<int> psee(n, -1);     // previous strictly smaller index, default -1
    stack<int> st;               // indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            psee[i] = st.top();
        }
        st.push(i);
    }
    return psee;
}

class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse = findNse(arr);
        vector<int> psee = findPsee(arr);

        long long total = 0;
        const int mod = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            long long left  = i - psee[i];
            long long right = nse[i] - i;
            long long contrib = (left * right) % mod;
            contrib = (contrib * arr[i]) % mod;
            total = (total + contrib) % mod;
        }
        return (int)total;
    }
};
