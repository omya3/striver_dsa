class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> visit_time(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < times.size(); i++)
        {
            int s = times[i][0];
            int d = times[i][1];
            int t = times[i][2];

            adj[s].push_back({d, t});
        }

        visit_time[k] = 0;
        pq.push({0, k});

        while (!pq.empty())
        {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > visit_time[node])
                continue;

            for (auto &[neigh_node, t] : adj[node])
            {

                if (visit_time[neigh_node] > visit_time[node] + t)
                {
                    visit_time[neigh_node] = visit_time[node] + t;
                    pq.push({visit_time[node] + t, neigh_node});
                }
            }
        }

        int max_time = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (visit_time[i] == INT_MAX)
                return -1;
            max_time = max(max_time, visit_time[i]);
        }
        return max_time;
    }
};