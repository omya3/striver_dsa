#include <bits/stdc++.h>
using namespace std;

// Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

bool isLeaf(Node *node) {
    return node && !node->left && !node->right;
}

void LeftBoundary(Node *root, vector<int> &res) {
    Node *curr = root->left;
    while (curr) {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void RightBoundary(Node *root, vector<int> &res) {
    vector<int> tmp;
    Node *curr = root->right;
    while (curr) {
        if (!isLeaf(curr))
            tmp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    // add in reverse
    for (int i = (int)tmp.size() - 1; i >= 0; --i)
        res.push_back(tmp[i]);
}

void addLeaves(Node *root, vector<int> &res) {
    if (!root) return;
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left)  addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
}

vector<int> boundaryTraversal(Node *root) {
    vector<int> total_boundary;
    if (!root) return total_boundary;

    if (!isLeaf(root))
        total_boundary.push_back(root->data);  // root

    LeftBoundary(root, total_boundary);        // left boundary (excluding leaves)
    addLeaves(root, total_boundary);           // all leaves
    RightBoundary(root, total_boundary);       // right boundary (excluding leaves)

    return total_boundary;
}

int main() {
    // Hardcoded Binary tree
    //            1
    //         /     \
    //       2         3
    //     /   \     /   \
    //    4     5   6     7
    //         / \
    //        8   9

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    vector<int> boundary = boundaryTraversal(root);

    for (int x : boundary)
        cout << x << " ";
    return 0;
}
