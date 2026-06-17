#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. Build the adjacency list tracking bi -> ai
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const auto& req : prerequisites) {
            int ai = req[0];
            int bi = req[1];
            // To take ai, you must take bi first. Edge: bi -> ai
            graph[bi].push_back(ai);
            indegree[ai]++;
        }

        // 2. Add all courses with an in-degree of 0 to the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // 3. Kahn's Algorithm to collect the order sequence
        vector<int> courseOrder;
        while (!q.empty()) {
            int currentCourse = q.front();
            q.pop();
            courseOrder.push_back(currentCourse);

            for (int nextCourse : graph[currentCourse]) {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // 4. If the order matches the total courses, return it; otherwise, a cycle exists
        if (courseOrder.size() == numCourses) {
            return courseOrder;
        }
        
        return {}; // Impossible to complete all courses
    }
};
