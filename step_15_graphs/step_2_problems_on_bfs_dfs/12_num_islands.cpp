class Solution {
private:
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited) {
        int n = grid.size();
        int m = grid[0].size(); // Fixed: grid[0].size() for columns
        
        queue<pair<int, int>> q;
        visited[i][j] = 1;
        q.push({i, j});

        // 4-directional offsets: Up, Right, Down, Left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Check all 4 directions
            for (int d = 0; d < 4; d++) {
                int curr_row = row + delRow[d];
                int curr_col = col + delCol[d];

                // Boundary verification
                if (curr_row >= 0 && curr_row < n && curr_col >= 0 && curr_col < m) {
                    // Check if cell is land ('1') and unvisited
                    if (!visited[curr_row][curr_col] && grid[curr_row][curr_col] == '1') {
                        q.push({curr_row, curr_col});
                        visited[curr_row][curr_col] = 1;
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size(); // Fixed: grid[0].size() for columns

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    count += 1;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};
