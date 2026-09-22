#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Tracks the total number of Strongly Connected Components (SCCs) found
    int num_components = 0;

private:
    void find_components(int node, vector<vector<int>> &adj, vector<int> &low, vector<int> &disc, vector<bool> &present_in_stack, stack<int> &mystack, int &time)
    {

        // 1. INITIALIZE NODE TIMESTAMPS
        // disc: The exact time we discovered this node.
        // low: The oldest ancestor this node can reach. Initially, it's itself.
        low[node] = disc[node] = time;
        time += 1;

        // Push the current node onto the stack and mark it as active
        mystack.push(node);
        present_in_stack[node] = true;

        // 2. EXPLORE ALL NEIGHBOURS
        for (auto neigh : adj[node])
        {

            // CASE A: Tree Edge (Neighbor hasn't been visited yet)
            // Strategy: Go explore it recursively. It forms the main skeleton of our components.
            if (disc[neigh] == -1)
            {
                find_components(neigh, adj, low, disc, present_in_stack, mystack, time);

                // Upon return, check if the neighbor found a path to an older ancestor
                low[node] = min(low[node], low[neigh]);
            }

            // CASE B: Back Edge (Neighbor is visited AND still active in the stack)
            // Strategy: We found a loop/cycle! This cycle binds these nodes into a component.
            // We use disc[neigh] to safely update our lowest reachable point.
            else if (present_in_stack[neigh])
            {
                low[node] = min(low[node], disc[neigh]);
            }

            // CASE C: Dead Cross Edge (Neighbor is visited but NOT in the stack)
            // Strategy: The neighbor belongs to an SCC that is already closed and popped.
            // Since they cannot route back to us, it cannot form a cycle. We IGNORE it completely.
        }

        // 3. ROOT OF COMPONENT FOUND
        // If low == disc, this node is the highest entry point ("Root") of a completed SCC.
        if (low[node] == disc[node])
        {
            num_components += 1; // Increment component counter

            // Pop all nodes belonging to this SCC from the stack
            while (mystack.top() != node)
            {
                int top_node = mystack.top();
                present_in_stack[top_node] = false; // Mark node as closed/inactive
                mystack.pop();
            }

            // Finally, pop the root node itself out of the stack
            present_in_stack[node] = false;
            mystack.pop();
        }
    }

public:
    int countSCC(int V, vector<vector<int>> &edges)
    {
        // Reset the counter for clean handling across multiple test cases
        num_components = 0;

        // Build the Adjacency List from the edge list
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        // State tracking arrays initialized to -1 (unvisited)
        vector<int> low(V, -1);
        vector<int> disc(V, -1);
        vector<bool> present_in_stack(V, false);
        stack<int> mystack;
        int time = 0;

        // Loop through all nodes to ensure we capture disconnected sub-graphs
        for (int i = 0; i < V; i++)
        {
            if (disc[i] == -1)
            {
                find_components(i, adj, low, disc, present_in_stack, mystack, time);
            }
        }

        return num_components;
    }
};
