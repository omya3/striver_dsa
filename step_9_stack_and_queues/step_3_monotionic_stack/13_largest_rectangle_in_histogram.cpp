#include <bits/stdc++.h>
using namespace std;

int find_largest_area(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st; // will store indices of bars in increasing height
    int maxArea = 0;

    for (int i = 0; i <= n; i++)
    {
        int currHeight = (i == n ? 0 : heights[i]); // sentinel 0 at the end

        while (!st.empty() && currHeight < heights[st.top()])
        {
            int idx = st.top();
            st.pop();
            int h = heights[idx];

            int leftIdx = st.empty() ? -1 : st.top(); // previous smaller
            int rightIdx = i;                         // next smaller is i

            int width = rightIdx - leftIdx - 1;
            int area = h * width;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }

    return maxArea;
}

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        return find_largest_area(heights);
    }
};
