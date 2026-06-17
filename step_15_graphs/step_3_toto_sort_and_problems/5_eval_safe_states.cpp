class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<vector<int>> graph_rev;

        for (int i = 0; i < n; i++)
        {
            for (auto neigh : graph[i])
            {
                graph_rev[neigh].push_back(i);
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // 3. Kahn's Algorithm to collect the order sequence
        vector<int> safenodes;
        while (!q.empty())
        {
            int currentNode = q.front();
            q.pop();
            safenodes.push_back(currentNode);

            for (int nextCourse : graph[currentNode])
            {
                indegree[nextNode]--;
                if (indegree[nextNode] == 0)
                {
                    q.push(nextNode);
                }
            }
        }

        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};