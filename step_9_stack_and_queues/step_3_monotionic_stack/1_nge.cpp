#include <iostream>
using namespace std;

vector<int> find_nge(vector<int> &nums)
{
    int i = nums.size() - 1;
    vector<int> nge(nums.size(), -1);
    stack<int> st;
    while (i >= 0)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            nge[i] = st.top();
        }
        st.push(nums[i]);
        i--;
    }
    return nge;
}

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nge2 = find_nge(nums2);

        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = nge2[i];
        }

        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++)
        {
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};