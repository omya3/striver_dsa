#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        int n = prerequisites.size();

        // 1. Used standard 2D vector sized to numCourses instead of raw pointer arrays
        vector<vector<int>> graph(numCourses);

        for (int i = 0; i < n; i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            graph[a].push_back(b);
        }

        // 2. Fixed sizing to match vertex count 'numCourses' instead of edge count 'n'
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> list;

        // 3. Loop bounds updated to traverse up to numCourses
        for (int i = 0; i < numCourses; i++) {
            for (int next : graph[i])
                indegree[next]++;
        }

        // 4. Corrected to scan all courses up to numCourses
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Kahn’s Algorithm (BFS)
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            list.push_back(top);
            for (int next : graph[top]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // 5. Success means finding an ordering matching the total course count
        if (list.size() == numCourses)
            return true;

        return false;
    }
};
