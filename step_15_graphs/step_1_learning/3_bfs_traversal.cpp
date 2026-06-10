#include <iostream>
using namespace std;

vector<int> bfs(int v, vector<int> adj[])
{
    vector<int> visited(v, 0);
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;

    while (!q.empty())
    {   
        int node = q.front();
        q.pop();
        bfs.push_back(i);
        for (auto i : adj[node])
        {
            q.push(i);
            visited[i] = 1;
        }
    }
    return bfs;
}

int main()
{
    int v;
    cin >> v;
    vector<int> arr[v];
    bfs(v, arr);
}