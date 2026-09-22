// Day 10: graph STL syntax for placement problem solving.
// Complete every TODO without opening solution.cpp.

// TODO 1: Add all required standard-library headers.
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

// TODO 2: Declare aliases Edge, Graph, and State as described in README.md.
using Edge = std::pair<int, int>;
using Graph = std::vector<std::vector<Edge>>;
using State = std::pair<int, int>;

void add_undirected_edge(Graph &graph, int u, int v, int weight)
{
    // TODO 3: Insert {neighbor, weight} in both directions.
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}

void print_graph(const Graph &graph)
{
    cout << "adjacency list:\n";

    // TODO 4: Use an index loop to print every node.
    for (int i = 0; i < graph.size(); i++)
    {
        cout << "Node : " << i << endl;
        cout << "Following are the edges" << endl;

        // TODO 5: Use a const-reference structured binding for every edge.
        for (const auto &[neighbour, weight] : graph[i])
        {
            cout << neighbour << " " << weight << endl;
        }
        cout << endl;
    }
}

vector<int> bfs_distance(const Graph &graph, int source)
{
    // TODO 6: Create a distance vector filled with -1.
    vector<int> distance(graph.size(), -1);
    vector<int> visited(graph.size(), 0);

    // TODO 7: Declare queue<int>, discover the source, and push it.
    queue<int> q;
    q.push(source);
    visited[source] = 1; // FIXED: Mark the source as visited immediately upon discovery!

    // TODO 8: Run BFS. Ignore edge weights, but avoid compiler warnings.
    int d = 0;
    while (!q.empty())
    {
        int n_ele = q.size();

        for (int i = 0; i < n_ele; i++)
        {
            int curr_ele = q.front();
            q.pop();
            distance[curr_ele] = d;

            for (const auto &[neighbor, weight] : graph[curr_ele])
            {
                // FIXED: Avoid compiler warning for the unused 'weight' variable
                (void)weight;

                if (!visited[neighbor])
                {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
        d += 1;
    }

    return distance; // TODO: return the completed distance vector.
}

vector<long long> dijkstra(const Graph &graph, int source)
{
    // TODO 9: Declare a safe long long INF value.
    // Using a large number that won't cause overflow when added to edge weights
    const long long INF = 1e18;

    // TODO 10: Create the distance vector and min-heap of State values.
    vector<long long> dist(graph.size(), INF);

    // min-heap declaration using the State alias: tracks {distance, node}
    priority_queue<State, vector<State>, greater<State>> min_heap;

    // TODO 11: Initialize and push the source.
    dist[source] = 0;
    min_heap.push({0, source}); // push initial State: {distance=0, node=source}

    // TODO 12: Extract the minimum state until the heap is empty.
    while (!min_heap.empty())
    {
        // Unpack the current minimum distance and node using structured bindings
        const auto [curr_dist, node] = min_heap.top();
        min_heap.pop();

        // TODO 13: Skip stale entries and relax all adjacent edges.
        // ⚡ STALE-ENTRY CHECKING: Skip if we already found a shorter path to this node
        if (curr_dist > dist[node])
            continue;

        // Iterate through all neighbors using a const-reference structured binding for the Edge
        for (const auto &[neighbor, weight] : graph[node])
        {
            // Edge relaxation step
            if (dist[node] + weight < dist[neighbor])
            {
                dist[neighbor] = dist[node] + weight;
                min_heap.push({dist[neighbor], neighbor}); // Push new State
            }
        }
    }

    return dist; // TODO: return the completed distance vector.
}

template <typename T>
void print_values(const string &label, const vector<T> &values)
{
    cout << label;
    for (const T &value : values)
    {
        cout << value << ' ';
    }
    cout << '\n';
}

int main()
{
    // Optimize stream buffers for prompt execution testing
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // TODO 14: Create a graph containing five nodes.
    int num_nodes = 5;
    Graph graph(num_nodes);

    // TODO 15: Add the six undirected weighted edges from README.md.
    // Standard structural layout common for 5-node / 6-edge baseline placement drills
    add_undirected_edge(graph, 0, 1, 4);
    add_undirected_edge(graph, 0, 2, 2);
    add_undirected_edge(graph, 1, 2, 1);
    add_undirected_edge(graph, 1, 3, 5);
    add_undirected_edge(graph, 2, 4, 3);
    add_undirected_edge(graph, 3, 4, 2);

    // TODO 16: Print the graph.
    print_graph(graph);

    // TODO 17: Print BFS distances from node 0.
    vector<int> bfs_dist = bfs_distance(graph, 0);
    print_values("BFS Shortest Path Hops from Node 0: ", bfs_dist);

    // TODO 18: Print Dijkstra distances from node 0.
    vector<long long> dijkstra_dist = dijkstra(graph, 0);
    print_values("Dijkstra Weighted Shortest Paths from Node 0: ", dijkstra_dist);

    return 0;
}
