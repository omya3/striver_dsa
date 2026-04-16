class Solution {

private:
    int find_min_path(int i, int j, int row, vector<vector<int>>& triangle,
                      vector<vector<int>>& dp) {

        if (i == row)
            return triangle[row][j]; // reached last row

        if (dp[i][j] != -1)
            return dp[i][j];

        long down = INT_MAX;
        long diag = INT_MAX;

        down = triangle[i][j] + find_min_path(i + 1, j, row, triangle, dp);
        diag = triangle[i][j] + find_min_path(i + 1, j + 1, row, triangle, dp);
        return dp[i][j] = min(down, diag);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int row = triangle.size();

        vector<vector<int>> dp(row, vector<int>(row, -1));
        return find_min_path(0, 0, row - 1, triangle, dp);
    }
};