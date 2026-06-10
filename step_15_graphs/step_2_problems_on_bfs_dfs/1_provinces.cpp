class Solution
{
private:
    int bfs(vector<vector<int>> &adj)
    {
        int v = adj.size();
        vector<int> visited(v, 0);
        int count = 0;

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                queue<int> q; // Inner queue handles the current component
                count += 1;
                visited[i] = 1;
                q.push(i);

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    // Changed 'i' to 'j' to avoid variable shadowing
                    for (int j = 0; j < v; j++)
                    {
                        if (adj[node][j] == 1 && !visited[j])
                        {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return count;
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        return bfs(isConnected);
    }
};
