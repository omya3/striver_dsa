#include <iostream>
using namespace std;

void solve(int row, int col, int n, vector<vector<int>> &maze, vector<string> &ans, string path, vector<vector<int>> &vis)
{
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // down
    if (row + 1 < n && !vis[row + 1][col] && maze[row + 1][col])
    {
        vis[row + 1][col] = 1;
        solve(row + 1, col, n, maze, ans, path + 'D', vis);
        vis[row + 1][col] = 0;
    }

    // left
    if (col - 1 >= 0 && !vis[row][col - 1] && maze[row][col - 1])
    {
        vis[row][col - 1] = 1;
        solve(row, col - 1, n, maze, ans, path + 'L', vis);
        vis[row][col - 1] = 0;
    }

    // right
    if (col + 1 < n && !vis[row][col + 1] && maze[row][col + 1])
    {
        vis[row][col + 1] = 1;
        solve(row, col + 1, n, maze, ans, path + 'R', vis);
        vis[row][col + 1] = 0;
    }

    // up
    if (row - 1 >= 0 && !vis[row - 1][col] && maze[row - 1][col])
    {
        vis[row - 1][col] = 1;
        solve(row-1, col, n, maze, ans, path + 'U', vis);
        vis[row - 1][col] = 0;
    }
}

class Solution
{
public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();
        vector<string> ans;

        if (n == 0 || maze[0][0] == 0)
            return ans; // no path

        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        solve(0, 0, n, maze, ans, "", vis);
        return ans;
    }
};
