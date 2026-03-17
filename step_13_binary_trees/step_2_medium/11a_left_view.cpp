vector<int> leftView(Tree *node)
{
    vector<int> ans;
    if (node == NULL)
        return ans;

    map<int, int> mpp;                 // level -> first node data
    queue<pair<Tree*, int>> q;         // node, level
    q.push({node, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        Tree* curr = it.first;
        int level = it.second;

        // first node seen at this level -> left view
        if (mpp.find(level) == mpp.end())
            mpp[level] = curr->data;

        if (curr->left)
            q.push({curr->left, level + 1});
        if (curr->right)
            q.push({curr->right, level + 1});
    }

    for (auto &p : mpp)
        ans.push_back(p.second);
    return ans;
}
