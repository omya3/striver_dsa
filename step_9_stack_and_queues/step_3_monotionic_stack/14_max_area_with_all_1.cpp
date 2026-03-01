#include <bits/stdc++.h>
using namespace std;

int find_largest_area(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++)
    {
        int currHeight = (i == n ? 0 : heights[i]);

        while (!st.empty() && currHeight < heights[st.top()])
        {
            int idx = st.top();
            st.pop();
            int h = heights[idx];

            int leftIdx  = st.empty() ? -1 : st.top();
            int rightIdx = i;

            int width = rightIdx - leftIdx - 1;
            int area  = h * width;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }

    return maxArea;
}

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();

        vector<int> height(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            maxArea = max(maxArea, find_largest_area(height));
        }
        return maxArea;
    }
};
