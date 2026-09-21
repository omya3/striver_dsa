# Mistakes to Revise — Days 8 and 9

Use this as a two-minute warm-up before the next tree or BST problem.

## 1. Include what you use

Do not depend on headers including other headers indirectly.

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
```

## 2. Constructor defaults

If you want to write `TreeNode node(8)`, child parameters must have defaults.
Use different parameter names to avoid accidentally initializing a field from
itself.

```cpp
explicit TreeNode(int node_value,
                  TreeNode* left_child = nullptr,
                  TreeNode* right_child = nullptr)
    : value(node_value), left(left_child), right(right_child)
{
}
```

## 3. Preserve `const`

If a function receives `const TreeNode*`, its local read-only pointers and
containers should preserve that promise.

```cpp
queue<const TreeNode*> nodes;
stack<const TreeNode*> nodes;
const TreeNode* current = root;
```

Memory cue: **const in, const through**.

## 4. Container adaptor operations

```text
queue:          front(), push(), pop()
stack:          top(),   push(), pop()
priority_queue: top(),   push(), pop()
```

`queue` does not provide `pop_front()`.

## 5. Call the correct recursive function

Small copy/paste mistakes change the algorithm:

```cpp
inorder(root->left, result);
inorder(root->right, result);

count_nodes(root->left);
count_nodes(root->right);
```

Check both the **argument** and the **function name** before moving on.

## 6. BST direction

```text
target < current value  -> left
target > current value  -> right
```

In the original path function, both branches moved right.

## 7. Null checks must return

This does nothing:

```cpp
if (root == nullptr)
    root;
```

Use:

```cpp
if (root == nullptr)
    return nullptr;
```

Memory cue: **a condition without an action changes nothing**.

## 8. Save returned values

Calling a function without saving its result discards the result:

```cpp
vector<int> path = path_to_target(root, target);
```

## 9. Print before replacing a result vector

If multiple traversals reuse one vector, print or clear it intentionally before
assigning a new traversal result.

## Two-minute recall

Retype these without looking:

```cpp
queue<const TreeNode*> pending;
stack<const TreeNode*> pending;

if (root == nullptr)
    return nullptr;

current = target < current->value
              ? current->left
              : current->right;
```
