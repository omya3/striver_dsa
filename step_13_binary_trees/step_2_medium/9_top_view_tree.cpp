#include <bits/stdc++.h>
using namespace std;

class Tree {
public:
    int data;
    Tree *left;
    Tree *right;
};

vector<int> topView(Tree *node)
{
    vector<int> ans;
    if (node == NULL)  // FIX: comparison, not assignment
        return ans;

    map<int, int> mpp;                       // line -> first node data
    queue<pair<Tree*, int>> q;              // node, horizontal distance
    q.push({node, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        Tree* curr = it.first;
        int line = it.second;

        // record first node seen at this horizontal distance
        if (mpp.find(line) == mpp.end())
            mpp[line] = curr->data;

        if (curr->left)
            q.push({curr->left, line - 1});

        if (curr->right)
            q.push({curr->right, line + 1}); // FIX: semicolon
    }

    for (auto &p : mpp)
        ans.push_back(p.second);

    return ans;
}
