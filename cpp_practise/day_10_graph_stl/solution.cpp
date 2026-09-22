// Day 10 solution: graph STL syntax for placement problem solving.

#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
using State = pair<long long, int>;

void add_undirected_edge(Graph &graph, int u, int v, int weight)
{
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}

void print_graph(const Graph &graph)
{
    cout << "adjacency list:\n";

    for (size_t node = 0; node < graph.size(); ++node)
    {
        cout << node << ':';
        for (const auto &[neighbor, weight] : graph[node])
        {
            cout << " (" << neighbor << ',' << weight << ')';
        }
        cout << '\n';
    }
}

vector<int> bfs_distance(const Graph &graph, int source)
{
    vector<int> distance(graph.size(), -1);
    queue<int> pending;

    distance[source] = 0;
    pending.push(source);

    while (!pending.empty())
    {
        const int node = pending.front();
        pending.pop();

        for (const auto &[neighbor, weight] : graph[node])
        {
            (void)weight;
            if (distance[neighbor] == -1)
            {
                distance[neighbor] = distance[node] + 1;
                pending.push(neighbor);
            }
        }
    }

    return distance;
}

vector<long long> dijkstra(const Graph &graph, int source)
{
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> distance(graph.size(), INF);
    priority_queue<State, vector<State>, greater<State>> min_heap;

    distance[source] = 0;
    min_heap.push({0, source});

    while (!min_heap.empty())
    {
        const auto [current_distance, node] = min_heap.top();
        min_heap.pop();

        if (current_distance != distance[node])
        {
            continue;
        }

        for (const auto &[neighbor, weight] : graph[node])
        {
            const long long candidate = current_distance + weight;
            if (candidate < distance[neighbor])
            {
                distance[neighbor] = candidate;
                min_heap.push({candidate, neighbor});
            }
        }
    }

    return distance;
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
    Graph graph(5);

    add_undirected_edge(graph, 0, 1, 4);
    add_undirected_edge(graph, 0, 2, 1);
    add_undirected_edge(graph, 2, 1, 2);
    add_undirected_edge(graph, 1, 3, 1);
    add_undirected_edge(graph, 2, 3, 5);
    add_undirected_edge(graph, 3, 4, 3);

    print_graph(graph);
    print_values("bfs distance: ", bfs_distance(graph, 0));
    print_values("dijkstra distance: ", dijkstra(graph, 0));
}
