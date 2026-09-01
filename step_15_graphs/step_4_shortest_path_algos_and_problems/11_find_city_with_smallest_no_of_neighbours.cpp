#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // Define a safe large value for infinity to prevent integer overflow during addition
        const int INF = 1e9;

        // Step 1: Initialize the distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        // Step 2: Populate direct edges into the grid
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            dist[u][v] = weight;
            dist[v][u] = weight;
        }

        // Step 3: Core Floyd-Warshall Algorithm (Find all-pairs shortest paths)
        for (int k = 0; k < n; k++)
        { // k is the intermediate/middleman city
            for (int i = 0; i < n; i++)
            { // i is the starting city
                for (int j = 0; j < n; j++)
                { // j is the destination city
                    if (dist[i][k] != INF && dist[k][j] != INF)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Step 4: Count reachable cities within threshold and find the best city ID
        int minReachableCount = n;
        int bestCity = -1;

        for (int i = 0; i < n; i++)
        {
            int currentReachableCount = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && dist[i][j] <= distanceThreshold)
                {
                    currentReachableCount++;
                }
            }

            // Condition: Smaller number of reachable cities,
            // OR if equal, pick the city with the GREATER index value (i >= bestCity)
            if (currentReachableCount <= minReachableCount)
            {
                minReachableCount = currentReachableCount;
                bestCity = i;
            }
        }

        return bestCity;
    }
};
