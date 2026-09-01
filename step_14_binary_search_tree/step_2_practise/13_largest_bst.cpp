#include <climits>
#include <algorithm>
using namespace std;

/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

// Fix: Renamed to avoid name conflicts with the tree Node class
class BSTInfo
{
public:
    int size;
    int minVal;
    int maxVal;

    BSTInfo(int size, int minVal, int maxVal)
    {
        this->size = size;
        this->minVal = minVal;
        this->maxVal = maxVal;
    }
};

class Solution
{
private:
    BSTInfo helper(Node *root)
    {
        // Base case: An empty tree is a valid BST of size 0
        // Fix: Inverted bounds ensure parent node validation always passes
        if (root == nullptr)
        {
            return BSTInfo(0, INT_MAX, INT_MIN);
        }

        // Post-order bottom-up traversal
        BSTInfo left = helper(root->left);
        BSTInfo right = helper(root->right);

        // Check if current node is a valid BST node extension
        if (left.maxVal < root->data && root->data < right.minVal)
        {
            // Valid BST: calculate current node bounds and total size
            int currentMin = min(root->data, left.minVal);
            int currentMax = max(root->data, right.maxVal);
            int currentSize = 1 + left.size + right.size;

            return BSTInfo(currentSize, currentMin, currentMax);
        }

        // Invalid BST: Pass the maximum size found in subtrees up,
        // but completely break the bounds so that any parent node fails validation
        return BSTInfo(max(left.size, right.size), INT_MIN, INT_MAX);
    }

public:
    int largestBst(Node *root)
    {
        // Start the bottom-up tracking process and return the ultimate max size
        BSTInfo result = helper(root);
        return result.size;
    }
};
