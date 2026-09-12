// Day 4: 30-minute C++ syntax practice.
// Complete every TODO without opening solution.cpp.

// TODO 1: Add all required standard-library headers.
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void nested_vector_drill()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}};

    // TODO: Add the row {7, 8, 9}.
    matrix.push_back({7, 8, 9});

    // TODO: Print the first row using an index-based loop.
    for (auto it : matrix[0])
    {
        cout << it << " ";
    }
    cout << endl;

    // TODO: Print the matrix using nested range-based loops.
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
    }
    cout << endl;

    int sum = 0;
    // TODO: Calculate and print the sum of every element.
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            sum += matrix[i][j];
        }
    }
    cout << sum << '\n';
}

void string_drill()
{
    string text = "striver-dsa";

    // TODO: Find the position of '-'.
    cout << text.find('-') << endl;
    // TODO: Extract "striver" and "dsa" with substr().
    cout << text.substr(0, 7) << endl;
    cout << text.substr(9, 11) << endl;
    // TODO: Make and print a reversed copy of text.
    string rev_copy = text;
    reverse(rev_copy.begin(), rev_copy.end());
    // TODO: Use find() and string::npos to check for "cpp".
    if (text.find("cpp") != string::npos)
    {
        cout << "found cpp" << endl;
    }
    cout << '\n';
}

void pair_sort_drill()
{
    vector<pair<string, int>> scores{
        {"Aman", 75}, {"Zoya", 90}, {"Neha", 82}, {"Ravi", 90}};

    // TODO: Sort by descending score, then ascending name for equal scores.
    sort(scores.begin(), scores.end(), [](const pair<string, int> &s1, const pair<string, int> &s2)
         {
        if(s1.second>s2.second) return true;
        if(s1.second == s2.second) return s1.first<s2.first;
        return false; });

    // TODO: Print each pair using structured binding.
    for (const auto &entry : scores)
    {
        cout << entry.first << ": " << entry.second << "\n";
    }
    cout << '\n';
}

void graph_drill()
{
    const int vertex_count = 4;
    vector<pair<int, int>> edges{{0, 1}, {0, 2}, {1, 3}, {2, 3}};

    // TODO: Create an adjacency list with vertex_count rows.
    vector<int> adj[4];

    // TODO: Add each edge in both directions using structured binding.
    for (const auto &edge : edges)
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    // TODO: Sort every neighbour list.
    for (const auto &neigh : adj)
    {
        sort(neigh.begin(), neigh.end());
    }

    // TODO: Print each vertex number followed by its neighbours.
    for (int i = 0; i < adj.size(); i++)
    {
        cout << i << ": ";
        for (int neighbor : adj[i])
        {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
    cout << '\n';
}

int main()
{
    nested_vector_drill();
    string_drill();
    pair_sort_drill();
    graph_drill();
}
