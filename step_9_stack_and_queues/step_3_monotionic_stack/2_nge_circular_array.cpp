#include <iostream>
using namespace std;

vector<int> find_nge_circular_array(vector<int> nums)
{
    int i = 2 * nums.size() - 1;
    stack<int> st;
    int n = nums.size();

    vector<int> nge(n, -1);
    while (i >= 0)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }
        if (i < n) // we place the element in nge array only if we are currently not opearting
        // in hypothetical array.
        {
            if (!st.empty())
            {
                nge[i] = st.top();
            }
        }
        st.push(nums[i % n]);
        i--;
    }

    return nge;
}

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> nge = find_nge_circular_array(nums);
        return nge;
    }
};