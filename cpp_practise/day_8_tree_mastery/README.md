# Day 8 — Tree Syntax Mastery (30 Minutes)

Yesterday's remaining weakness was preserving `const` when placing tree-node
pointers into a queue. Today revises that exact point and adds two placement
patterns: recursive tree metrics and iterative DFS.

Today covers:

- tree construction with object addresses
- recursive inorder traversal
- BFS with `queue<const TreeNode*>`
- recursive height and node count
- iterative preorder with `stack<const TreeNode*>`

## Rules

1. Work only in `drill.cpp`.
2. Do not open `solution.cpp` before minute 27.
3. Compile after each section.
4. Keep every read-only tree function parameter `const TreeNode*`.
5. Stop after 30 minutes and begin placement problems.

## Compile and run

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

## The tree used today

```text
        8
       / \
      3   10
     / \    \
    1   6    14
```

## 0–5 minutes: Headers, node, and construction

1. Add headers for input/output, queue, stack, string, vector, and `max()`.
2. Define `TreeNode` with `value`, `left`, `right`, and a constructor.
3. In `tree_drill()`, create six stack-allocated nodes.
4. Connect them using addresses to match the diagram.

Memory cue:

```text
object.field = &other_object
pointer->field
```

## 5–10 minutes: Recursive inorder revision

Implement:

```cpp
void inorder(const TreeNode* root, vector<int>& result);
```

Expected:

```text
inorder: 1 3 6 8 10 14
```

Memory cue:

```text
base case -> left -> node -> right
```

## 10–16 minutes: Const-correct BFS revision

Implement:

```cpp
vector<int> level_order(const TreeNode* root);
```

You must use:

```cpp
queue<const TreeNode*> pending;
```

Expected:

```text
level order: 8 3 10 1 6 14
```

Why: a `const TreeNode*` cannot be placed in a `queue<TreeNode*>`, because that
would discard its read-only guarantee.

Memory cue:

```text
front -> pop -> record -> push children
```

## 16–22 minutes: Recursive return values

Implement:

```cpp
int tree_height(const TreeNode* root);
int count_nodes(const TreeNode* root);
```

Definitions:

- Empty tree height is `0`.
- Leaf height is `1`.
- Node count is one plus both subtree counts.

Expected:

```text
height=3
nodes=6
```

Memory cues:

```text
height = 1 + max(left height, right height)
count  = 1 + left count + right count
```

## 22–28 minutes: Iterative preorder with a stack

Implement:

```cpp
vector<int> iterative_preorder(const TreeNode* root);
```

Use:

```cpp
stack<const TreeNode*> pending;
```

Pop a node, record it, then push its **right child before its left child**.
Because a stack is LIFO, the left child will be processed first.

Expected:

```text
iterative preorder: 8 3 1 6 10 14
```

Memory cue:

```text
stack preorder = pop node -> push right -> push left
```

## 28–30 minutes: Closed-book recall

Write or say:

1. The null recursion base case.
2. The type of a queue containing read-only node pointers.
3. The type of a stack containing read-only node pointers.
4. The recursive formula for height.
5. Why iterative preorder pushes right before left.

## Scoring

- **Everything works with zero warnings:** ready for BST syntax tomorrow.
- **Recursion works but stack/queue fails:** repeat only iterative traversals.
- **Const mismatch returns:** retype both container declarations three times.

