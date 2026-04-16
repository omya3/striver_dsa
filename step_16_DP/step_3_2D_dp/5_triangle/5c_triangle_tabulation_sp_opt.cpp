class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {

        int row = triangle.size();

        vector<int> prev(row, -1);

        for (int i = 0; i < row; i++)
            prev[i] = triangle[row - 1][i];

        for (int i = row - 2; i >= 0; i--)
        {
            vector<int> curr(row, -1);
            for (int j = i; j >= 0; j--)
            {

                long down = triangle[i][j] + prev[j];
                long diag = triangle[i][j] + prev[j + 1];

                curr[j] = min(down, diag);
            }
            prev = curr;
        }

        return prev[0];
    }
};