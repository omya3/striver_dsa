#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void nested_vector_drill()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}};
    matrix.push_back({7, 8, 9});

    cout << "first row: ";
    for (size_t index = 0; index < matrix[0].size(); ++index)
    {
        cout << matrix[0][index] << ' ';
    }
    cout << '\n';

    int sum = 0;
    cout << "matrix:\n";
    for (const vector<int>& row : matrix)
    {
        for (int value : row)
        {
            cout << value << ' ';
            sum += value;
        }
        cout << '\n';
    }
    cout << "sum=" << sum << "\n\n";
}

void string_drill()
{
    string text = "striver-dsa";
    const size_t dash = text.find('-');
    const string left = text.substr(0, dash);
    const string right = text.substr(dash + 1);

    cout << "left=" << left << " right=" << right << '\n';

    string reversed = text;
    reverse(reversed.begin(), reversed.end());
    cout << "reversed=" << reversed << '\n';

    cout << "cpp="
         << (text.find("cpp") == string::npos ? "missing" : "present")
         << "\n\n";
}

void pair_sort_drill()
{
    vector<pair<string, int>> scores{
        {"Aman", 75}, {"Zoya", 90}, {"Neha", 82}, {"Ravi", 90}};

    sort(scores.begin(), scores.end(),
         [](const pair<string, int>& first, const pair<string, int>& second)
         {
             if (first.second != second.second)
             {
                 return first.second > second.second;
             }
             return first.first < second.first;
         });

    cout << "scores:\n";
    for (const auto& [name, score] : scores)
    {
        cout << name << ' ' << score << '\n';
    }
    cout << '\n';
}

void graph_drill()
{
    const int vertex_count = 4;
    vector<pair<int, int>> edges{{0, 1}, {0, 2}, {1, 3}, {2, 3}};
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
}

int main()
{
    nested_vector_drill();
    string_drill();
    pair_sort_drill();
    graph_drill();
}
