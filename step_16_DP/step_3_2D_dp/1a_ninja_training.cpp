class Solution
{

    int find_max_ninja_points(int day, int last, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            int maxi = INT_MIN;
            for (int task = 0; task < mat[0].size(); ++task)
            {
                if (task != last)
                    maxi = max(mat[0][task], maxi);
            }
            return maxi == INT_MIN ? 0 : maxi;
        }
        if (dp[day][last] != -1)
            return dp[day][last];
        int maxi = INT_MIN;
        int tasks = mat[0].size();
        for (int task = 0; task < tasks; ++task)
        {
            if (task == last)
                continue;
            int curr = mat[day][task] + find_max_ninja_points(day - 1, task, mat, dp);
            maxi = max(curr, maxi);
        }
        return dp[day][last] = maxi == INT_MIN ? 0 : maxi;
    }

public:
    int maximumPoints(vector<vector<int>> &mat)
    {
        // code here
        int days = mat.size(), tasks = mat[0].size();
        vector<vector<int>> dp(days, vector<int>(tasks + 1, -1)); // +1 for invalid last
        return find_max_ninja_points(days - 1, tasks, mat, dp);
    }
};