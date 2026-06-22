#include <vector>
#include <queue>

using namespace std;

// User function Template for C++

class Solution
{
public:
    // Changed the function name to minSteps to fix the compilation error
    int minSteps(vector<int> &arr, int start, int end)
    {
        if (start == end)
            return 0;

        // The problem description specifies modulo 1000
        int mod = 1000;

        queue<pair<int, int>> q;
        q.push({start, 0});

        // Since mod is 1000, there are exactly 1000 possible states (0 to 999)
        vector<int> dist(1000, 1e9);
        dist[start] = 0;

        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : arr)
            {
                // Explicitly casting to long long prevents unexpected overflows
                int num = ((long long)it * node) % mod;

                if (steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;
                    if (num == end)
                        return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};
