# BT and BST Template Book

Use this section for active recall. For every template, first write the skeleton
without looking, then solve one representative problem and record the mistake.

## Common Node Definition

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};
```

## 1. Recursive Traversals

### Recognition clue

The problem asks to visit every node in a particular order. The difference
between preorder, inorder and postorder is when the current node is processed.

### Recursive idea/invariant

The function completely processes the subtree rooted at `node` according to
the selected order.

### Skeleton code

```cpp
void preorder(TreeNode* node, vector<int>& order) {
    if (node == nullptr) return;

    order.push_back(node->val);       // node, left, right
    preorder(node->left, order);
    preorder(node->right, order);
}

void inorder(TreeNode* node, vector<int>& order) {
    if (node == nullptr) return;

    inorder(node->left, order);
    order.push_back(node->val);       // left, node, right
    inorder(node->right, order);
}

void postorder(TreeNode* node, vector<int>& order) {
    if (node == nullptr) return;

    postorder(node->left, order);
    postorder(node->right, order);
    order.push_back(node->val);       // left, right, node
}
```

### Complexity

`O(n)` time and `O(h)` recursion stack space, where `h` is tree height.

### Common bugs

- Forgetting the null base case.
- Mixing the order of the recursive calls.
- Using `order` by value instead of by reference.
- Ignoring that inorder traversal of a BST is sorted.

### Representative problems

- Binary Tree Preorder Traversal
- Binary Tree Inorder Traversal
- Binary Tree Postorder Traversal
- Kth Smallest Element in a BST

## 2. Level-Order Traversal

### Recognition clue

The problem refers to levels, distance from the root, minimum number of edges,
or processing nodes breadth-first.

### Recursive idea/invariant

The queue contains nodes from the current frontier. Each outer-loop iteration
processes exactly one tree level.

### Skeleton code

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> answer;
    if (root == nullptr) return answer;

    queue<TreeNode*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        int levelSize = nodes.size();
        vector<int> level;

        while (levelSize--) {
            TreeNode* node = nodes.front();
            nodes.pop();

            level.push_back(node->val);

            if (node->left != nullptr) nodes.push(node->left);
            if (node->right != nullptr) nodes.push(node->right);
        }

        answer.push_back(level);
    }

    return answer;
}
```

### Complexity

`O(n)` time and `O(w)` space, where `w` is the maximum width of the tree.

### Common bugs

- Forgetting to save `levelSize` before processing the level.
- Pushing null children into the queue.
- Using a stack when the problem requires minimum distance by edges.

### Representative problems

- Binary Tree Level Order Traversal
- Binary Tree Zigzag Level Order Traversal
- Binary Tree Right Side View
- Minimum Depth of Binary Tree

## 3. Height, Diameter and Balanced Tree Recursion

### Recognition clue

The answer depends on information returned from both child subtrees, such as
height, diameter, balance, or a longest path.

### Recursive idea/invariant

The helper returns the height of the current subtree. While returning upward, it
uses the left and right heights to update the global answer.

### Skeleton code: diameter

```cpp
int diameter = 0;

int height(TreeNode* node) {
    if (node == nullptr) return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    diameter = 0;
    height(root);
    return diameter;
}
```

### Complexity

`O(n)` time and `O(h)` stack space.

### Common bugs

- Counting nodes when the question asks for edges.
- Recomputing height separately for every node, causing `O(n^2)` time.
- Forgetting to reset the global answer between test cases.

### Representative problems

- Maximum Depth of Binary Tree
- Diameter of Binary Tree
- Balanced Binary Tree
- Maximum Path Sum in a Binary Tree

## 4. Lowest Common Ancestor in a Binary Tree

### Recognition clue

Find the deepest node that is an ancestor of two given nodes in a general binary
tree. The tree is not necessarily a BST.

### Recursive idea/invariant

The function returns a target node found in this subtree, or the LCA if both
targets are found below it.

### Skeleton code

```cpp
TreeNode* lowestCommonAncestor(
    TreeNode* root,
    TreeNode* p,
    TreeNode* q
) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);

    if (leftResult != nullptr && rightResult != nullptr) {
        return root;
    }

    return leftResult != nullptr ? leftResult : rightResult;
}
```

### Complexity

`O(n)` time and `O(h)` stack space.

### Common bugs

- Applying BST ordering to an ordinary binary tree.
- Returning too early before checking both subtrees.
- Confusing node values with node pointers when duplicate values are possible.

### Representative problems

- Lowest Common Ancestor of a Binary Tree
- Lowest Common Ancestor of a BST
- All Nodes Distance K in Binary Tree

## 5. Root-to-Leaf Path DFS

### Recognition clue

The problem asks for paths, path sums, root-to-leaf sequences, or whether a
specific root-to-leaf condition exists.

### Recursive idea/invariant

`path` contains exactly the nodes on the current root-to-node route. Add before
recursion and remove after recursion to restore the parent state.

### Skeleton code

```cpp
void collectPaths(
    TreeNode* node,
    vector<int>& path,
    vector<vector<int>>& answer
) {
    if (node == nullptr) return;

    path.push_back(node->val);

    if (node->left == nullptr && node->right == nullptr) {
        answer.push_back(path);
    } else {
        collectPaths(node->left, path, answer);
        collectPaths(node->right, path, answer);
    }

    path.pop_back();
}
```

### Complexity

Usually `O(n)` traversal time, plus the cost of storing returned paths.
Auxiliary recursion/path space is `O(h)`.

### Common bugs

- Forgetting `path.pop_back()`.
- Treating every node as a leaf instead of checking both children are null.
- Using a mutable path without backtracking.

### Representative problems

- Path Sum
- Path Sum II
- Sum Root to Leaf Numbers
- Binary Tree Paths

## 6. Validate a BST Using Bounds

### Recognition clue

The problem asks whether a binary tree satisfies the BST ordering property.

### Recursive idea/invariant

Every node in the current subtree must lie strictly inside `(lower, upper)`.
The bounds represent restrictions inherited from all ancestors, not only the
parent.

### Skeleton code

```cpp
bool isValid(TreeNode* node, long long lower, long long upper) {
    if (node == nullptr) return true;

    if (node->val <= lower || node->val >= upper) {
        return false;
    }

    return isValid(node->left, lower, node->val) &&
           isValid(node->right, node->val, upper);
}

bool isValidBST(TreeNode* root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
}
```

### Complexity

`O(n)` time and `O(h)` stack space.

### Common bugs

- Comparing only with the immediate left and right child.
- Using `int` bounds when node values may equal `INT_MIN` or `INT_MAX`.
- Allowing duplicates when the problem requires strict BST ordering.

### Representative problems

- Validate Binary Search Tree
- Recover Binary Search Tree
- Convert Sorted Array to Binary Search Tree

## 7. Kth Smallest Element in a BST

### Recognition clue

The tree is a BST and the problem asks for the kth smallest or kth largest
value.

### Recursive idea/invariant

Inorder traversal visits BST values in sorted order. Decrement `k` when a node is
visited; the node where `k` becomes zero is the answer.

### Skeleton code

```cpp
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> nodes;
    TreeNode* current = root;

    while (true) {
        while (current != nullptr) {
            nodes.push(current);
            current = current->left;
        }

        current = nodes.top();
        nodes.pop();

        if (--k == 0) return current->val;

        current = current->right;
    }
}
```

### Complexity

`O(h + k)` time and `O(h)` space.

### Common bugs

- Using preorder instead of inorder.
- Decrementing `k` while pushing instead of while visiting.
- Forgetting to move to the right subtree after visiting a node.

### Representative problems

- Kth Smallest Element in a BST
- Kth Largest Element in a BST
- BST Iterator

## 8. BST Search and Insert

### Recognition clue

The problem asks to search for, insert, or locate a value in a BST.

### Recursive idea/invariant

At every node, discard the half of the tree that cannot contain the target.

### Skeleton code

```cpp
TreeNode* searchBST(TreeNode* root, int target) {
    while (root != nullptr && root->val != target) {
        if (target < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return root;
}

TreeNode* insertIntoBST(TreeNode* root, int value) {
    if (root == nullptr) return new TreeNode(value);

    if (value < root->val) {
        root->left = insertIntoBST(root->left, value);
    } else {
        root->right = insertIntoBST(root->right, value);
    }

    return root;
}
```

### Complexity

`O(h)` time. Search uses `O(1)` iterative space; insertion uses `O(h)` stack
space in the recursive version.

### Common bugs

- Traversing both children as if the tree were an ordinary binary tree.
- Losing the returned child pointer during insertion.
- Not clarifying how duplicate values should be handled.

### Representative problems

- Search in a Binary Search Tree
- Insert into a Binary Search Tree
- Delete Node in a BST
- Inorder Successor in BST

## 9. Build a Tree from Traversals

### Recognition clue

The problem gives preorder/inorder or postorder/inorder traversals and asks you
to reconstruct the binary tree.

### Recursive idea/invariant

The first unused preorder value, or last unused postorder value, is the root of
the current subtree. Inorder divides the remaining values into left and right
subtrees.

### Skeleton code: preorder + inorder

```cpp
TreeNode* build(
    vector<int>& preorder,
    int& preorderIndex,
    int inorderLeft,
    int inorderRight,
    unordered_map<int, int>& inorderIndex
) {
    if (inorderLeft > inorderRight) return nullptr;

    int rootValue = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(rootValue);

    int split = inorderIndex[rootValue];

    root->left = build(
        preorder, preorderIndex,
        inorderLeft, split - 1, inorderIndex
    );

    root->right = build(
        preorder, preorderIndex,
        split + 1, inorderRight, inorderIndex
    );

    return root;
}
```

### Complexity

`O(n)` time and `O(n)` auxiliary space for the index map and recursion.

### Common bugs

- Creating the right subtree before the left subtree.
- Using a linear search for every inorder split, causing `O(n^2)` time.
- Forgetting that unique node values are normally required.

### Representative problems

- Construct Binary Tree from Preorder and Inorder Traversal
- Construct Binary Tree from Inorder and Postorder Traversal

## BT/BST Revision Checklist

Before marking this topic complete, reproduce these from memory:

```text
[ ] Recursive preorder, inorder and postorder
[ ] Level-order traversal
[ ] Height/diameter recursion
[ ] LCA in a binary tree
[ ] Root-to-leaf backtracking
[ ] Validate BST with bounds
[ ] Kth smallest using BST inorder
[ ] BST search and insertion
[ ] Build tree from preorder and inorder
```

Recommended spaced revision: Day 0, Day 2, Day 7 and Day 21.
