#include <vector>

using namespace std;

class Solution
{
private:
    // Fixed: Changed return type to void
    void dfs_traversal(int s_r, int s_c, vector<vector<char>> &board, vector<vector<int>> &vis)
    {
        vis[s_r][s_c] = 1;
        vector<int> del_row = {-1, 0, 1, 0};
        vector<int> del_col = {0, 1, 0, -1};

        int n = board.size();
        int m = board[0].size();

        for (int k = 0; k < 4; k++)
        {
            int neigh_r = s_r + del_row[k];
            int neigh_c = s_c + del_col[k];

            if (neigh_r >= 0 && neigh_r < n && neigh_c >= 0 && neigh_c < m)
            {
                // Fixed: Changed numerical '0' to letter 'O'
                if (!vis[neigh_r][neigh_c] && board[neigh_r][neigh_c] == 'O')
                {
                    dfs_traversal(neigh_r, neigh_c, board, vis);
                }
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        if (board.empty() || board[0].empty())
            return;

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // 1. Traverse first and last rows
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && board[0][j] == 'O')
            {
                dfs_traversal(0, j, board, vis);
            }
            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
            {
                dfs_traversal(n - 1, j, board, vis);
            }
        }

        // 2. Traverse first and last columns
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && board[i][0] == 'O')
            {
                dfs_traversal(i, 0, board, vis);
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
            {
                dfs_traversal(i, m - 1, board, vis);
            }
        }

        // Note: The loop that used "mat[i][j] == 0" has been removed.

        // 3. Flip all unvisited 'O's to 'X's
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
