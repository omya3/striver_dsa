#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

void print_values(const vector<int>& values)
{
    for (int value : values)
    {
        cout << value << ' ';
    }
    cout << '\n';
}

void sort_descending(vector<int>& values)
{
    sort(values.begin(), values.end(), greater<int>());
}

void reference_drill()
{
    vector<int> values{4, 1, 7, 2};

    cout << "original: ";
    print_values(values);

    sort_descending(values);
    cout << "descending: ";
    print_values(values);
    cout << '\n';
}

void graph_drill()
{
    const int vertex_count = 5;
    vector<pair<int, int>> edges{
        {0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}};
    vector<vector<int>> graph(vertex_count);

    for (const auto& [from, to] : edges)
    {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (vector<int>& neighbours : graph)
    {
        sort(neighbours.begin(), neighbours.end());
    }

    cout << "graph:\n";
    for (size_t vertex = 0; vertex < graph.size(); ++vertex)
    {
        cout << vertex << ": ";
        for (int neighbour : graph[vertex])
        {
            cout << neighbour << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int binary_search_index(const vector<int>& values, int target)
{
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;

    while (left <= right)
    {
        const int mid = left + (right - left) / 2;
        if (values[mid] == target)
        {
            return mid;
        }
        if (values[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void binary_search_drill()
{
    vector<int> sorted{1, 3, 5, 7, 9};
    cout << "index of 7=" << binary_search_index(sorted, 7) << '\n';
    cout << "index of 4=" << binary_search_index(sorted, 4) << "\n\n";
}

vector<int> top_k_frequent(const vector<int>& values, int k)
{
    unordered_map<int, int> frequency;
    for (int value : values)
    {
        ++frequency[value];
    }

    using Entry = pair<int, int>;
    priority_queue<Entry, vector<Entry>, greater<Entry>> min_heap;

    for (const auto& [value, count] : frequency)
    {
        min_heap.push({count, value});
        if (static_cast<int>(min_heap.size()) > k)
        {
            min_heap.pop();
        }
    }

    vector<int> result;
    while (!min_heap.empty())
    {
        result.push_back(min_heap.top().second);
        min_heap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

void top_k_drill()
{
    vector<int> values{1, 1, 1, 2, 2, 3, 3, 3, 3, 4};
    const vector<int> result = top_k_frequent(values, 2);

    cout << "top 2: ";
    print_values(result);
}

int main()
{
    reference_drill();
    graph_drill();
    binary_search_drill();
    top_k_drill();
}
