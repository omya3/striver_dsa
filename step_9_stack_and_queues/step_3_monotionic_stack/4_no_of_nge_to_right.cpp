#include <bits/stdc++.h>
using namespace std;

vector<int> find_num_nge(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nextIdx(n, -1);   // index of next greater element
    stack<int> st;                // store indices (monotonic stack)

    // Step 1: compute next greater index for each i
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            nextIdx[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    // Step 2: dp[i] = number of NGEs to the right of i
    vector<int> ngeCount(n, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        int j = nextIdx[i];
        if (j != -1) {
            ngeCount[i] = 1 + ngeCount[j];
        }
    }
    return ngeCount;
}
class Solution {
  public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> ans(indices.size());

        for (int qi = 0; qi < (int)indices.size(); ++qi) {
            int idx = indices[qi];
            int x = arr[idx];
            int cnt = 0;
            for (int j = idx + 1; j < n; ++j) {
                if (arr[j] > x) cnt++;
            }
            ans[qi] = cnt;
        }
        return ans;
    }
};

