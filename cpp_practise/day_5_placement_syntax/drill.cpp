// Day 5: placement-focused C++ syntax drill.
// Complete every TODO without opening solution.cpp.

// TODO 1: Add all required standard-library headers.
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// TODO: Write print_values(). It must read a vector without copying it.
void print_value(const vector<int> &vals)
{
    for (int it : vals)
    {
        cout << it << " ";
    }
    cout << endl;
}

// TODO: Write sort_descending(). It must modify the caller's vector.
void sort_descending(vector<int> &vals)
{

    sort(vals.begin(), vals.end(), greater<int>());
}

void reference_drill()
{
    vector<int> values{4, 1, 7, 2};

    // TODO: Print the original values.
    print_value(values);

    cout << endl;
    // TODO: Sort the original vector descending.
    // TODO: Print the modified values.
    print_value(values);

    cout << '\n';
}

void graph_drill()
{
    const int vertex_count = 5;
    vector<pair<int, int>> edges{
        {0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}};

    // TODO: Create vector<vector<int>> graph with vertex_count rows.
    vector<vector<int>> graph(vertex_count);
    // TODO: Add every edge in both directions using structured binding.
    for (const auto &[a, b] : edges)
    {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // TODO: Sort every neighbour list through a mutable reference.
    for (auto &neigh : graph)
    {
        sort(neigh.begin(), neigh.end());
    }

    // TODO: Print each vertex followed by its neighbours.
    for (int i = 0; i < vertex_count; i++)
    {
        if (graph[i].size() > 0)
        {
            cout << i << ": ";
            for (int it : graph[i])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    cout << '\n';
}

int binary_search_index(const vector<int> &values, int target)
{
    // TODO: Implement iterative binary search.
    int low = 0;
    int high = static_cast<int>(values.size()) - 1;
    // Hint: calculate mid as left + (right - left) / 2.
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (values[mid] == target)
        {
            return mid;
        }
        else if (values[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

void binary_search_drill()
{
    vector<int> sorted{1, 3, 5, 7, 9};

    // TODO: Print the returned index for targets 7 and 4.
    cout << binary_search_index(sorted, 7) << endl;
    cout << binary_search_index(sorted, 4) << endl;
    cout << '\n';
}

vector<int> top_k_frequent(const vector<int> &values, int k)
{
    // TODO: Build an unordered_map<int, int> frequency table.
    unordered_map<int, int> f_table;

    for (int val : values)
    {
        f_table[val] += 1;
    }
    // TODO: Declare a min-heap of pair<int, int> storing {count, value}.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_hp;
    for (const auto &[value, count] : f_table)
    {
        min_hp.push({count, value});
        if (static_cast<int>(min_hp.size()) > k)
        {
            min_hp.pop();
        }
    }
    // // TODO: Keep only k entries in the heap.
    // while (min_hp.size() > k)
    // {
    //     min_hp.pop();
    // }
    // TODO: Pop values into a result vector and reverse it.
    vector<int> result;
    while (!min_hp.empty())
    {
        pair<int, int> val = min_hp.top();
        min_hp.pop();
        result.push_back(val.second);
    }
    reverse(result.begin(), result.end());

    return result;
}

void top_k_drill()
{
    vector<int> values{1, 1, 1, 2, 2, 3, 3, 3, 3, 4};

    // TODO: Call top_k_frequent(values, 2) and print its result.
    vector<int> result = top_k_frequent(values, 2);

    cout << "top 2: ";
    for (int value : result)
    {
        cout << value << " ";
    }
    cout << '\n';
}

int main()
{
    reference_drill();
    graph_drill();
    binary_search_drill();
    top_k_drill();
}
