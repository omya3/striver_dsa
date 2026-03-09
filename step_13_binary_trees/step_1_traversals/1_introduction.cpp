#include <iostream>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
};

vector<int> preInPostTravesal(Tree *root)
{
    stack<pair<Tree *, int>> st;
    st.push({root, 1});
    vector<int> pre, post, in;

    if (root == NULL)
        return;

    while (!st.empty())
    {
        auto it = st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }

        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->val);
        }
    }
}