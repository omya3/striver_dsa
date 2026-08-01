/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution
{

private:
    int findMin(Node *root)
    {
        if (root->left == NULL)
        {
            return root->data;
        }
        findMin(root->left);
    }

private:
    int findMax(Node *root)
    {
        if (root->right == NULL)
        {
            return root->data;
        }
        findMax(root->right);
    }

public:
    int minValue(Node *root)
    {
        // code here
        if (root == NULL)
            return -1;
        int min = findMin(root);
        return min;
    }
};