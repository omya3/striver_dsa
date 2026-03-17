vector<int> rightView(Tree *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    queue<Tree *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; ++i)
        {
            Tree *curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);

            // last node in this level -> right view
            if (i == sz - 1)
                ans.push_back(curr->data);
        }
    }
    return ans;
}
