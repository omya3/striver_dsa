#include <iostream>
using namespace std;

class Solution
{
public:
    bool get_path(Node *root, vector<int> &path, int x)
    {
        if (root == NULL)
        {
            return false;
        }

        arr.push_back(root->val);

        if (root->val == x)
            return true;

        if (get_path(root->left) || get_path(root->right))
        {
            return true;
        }
        else
        {
            arr.pop_back();
            false;
        }
    }
};

int main()
{
    
}
