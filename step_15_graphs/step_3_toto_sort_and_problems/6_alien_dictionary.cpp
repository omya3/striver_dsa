#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    string findOrder(vector<string>& words) {
        // 1. Identify all unique characters present across all words
        unordered_set<char> unique_chars;
        for (const string& word : words) {
            for (char ch : word) {
                unique_chars.insert(ch);
            }
        }
        int total_unique = unique_chars.size();

        // 2. Initialize adjacency list and in-degree map
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for (char ch : unique_chars) {
            indegree[ch] = 0;
        }

        // 3. Build the dependency graph by comparing adjacent words
        for (size_t i = 0; i < words.size() - 1; i++) {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];
            
            size_t len = min(w1.length(), w2.length());
            bool found_difference = false;

            for (size_t j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    char u = w1[j];
                    char v = w2[j];
                    
                    // Insert a directed edge: u -> v
                    if (adj[u].find(v) == adj[u].end()) {
                        adj[u].insert(v);
                        indegree[v]++;
                    }
                    found_difference = true;
                    break; // Only the first differing character dictates the order
                }
            }

            // Edge Case: Check if a longer word is written before its own shorter prefix
            if (!found_difference && w1.length() > w2.length()) {
                return ""; 
            }
        }

        // 4. Load all root characters (in-degree == 0) into the BFS queue
        queue<char> q;
        for (char ch : unique_chars) {
            if (indegree[ch] == 0) {
                q.push(ch);
            }
        }

        // 5. Run Kahn's Algorithm
        string order = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            order += curr;

            for (char neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 6. If the order length doesn't match total unique characters, a cycle exists
        if (order.length() == total_unique) {
            return order;
        }
        
        return "";
    }
};
