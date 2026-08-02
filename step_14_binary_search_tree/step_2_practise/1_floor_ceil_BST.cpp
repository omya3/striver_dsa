/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution
{
public:
    int findMaxFork(Node *root, int k)
    {
        int floor = -1;

        while (root)
        {
            if (root->data == k)
            {
                floor = k;
                return floor;
            }

            if (k > root->data)
            {
                floor = root->data;
                root = root->right;
            }
            // FIXED: Changed from 'if' to 'else' to prevent checking a modified 'root'
            else
            {
                root = root->left;
            }
        }
        return floor;
    }
};

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
public:
    int findCeil(Node *root, int x)
    {
        // code here
        int ceil = -1;
        while (root)
        {
            if (root->data == x)
            {
                return x;
            }

            if (root->data > x)
            {
                ceil = root->data;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return ceil;
    }
};
