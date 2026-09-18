# Day 7 — Linked-List Revision and Tree Traversal (30 Minutes)

Today uses **spaced revision + one progression step**:

- revise yesterday's node, pointer, traversal, and reversal syntax
- define a binary-tree node
- build a tree with stack-allocated objects and pointers
- write recursive DFS traversals
- write queue-based BFS traversal

## Rules

1. Work only in `drill.cpp`.
2. Do not open Day 6 or `solution.cpp` during the first 27 minutes.
3. Compile after every section.
4. Fix one compiler error at a time.
5. Stop after 30 minutes and move to placement problems.

## Compile and run

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

## 0–8 minutes: Day 6 closed-book revision

Complete the `ListNode` section without looking at yesterday's code.

1. Define `ListNode` with `value`, `next`, and a constructor.
2. Implement `print_list(const ListNode* head)`.
3. Implement iterative `reverse_list(ListNode* head)`.
4. Create and connect `10 -> 20 -> 30` using stack objects.
5. Print the list before and after reversal.

Expected:

```text
list forward: 10 20 30
list reversed: 30 20 10
```

Memory cue:

```text
save next -> reverse link -> advance previous -> advance current
```

## 8–14 minutes: Define and build a binary tree

Define `TreeNode` with:

- `int value`
- `TreeNode* left`
- `TreeNode* right`
- a constructor that initializes both child pointers to `nullptr`

Build this tree using stack-allocated nodes:

```text
        1
       / \
      2   3
     / \   \
    4   5   6
```

Use dot syntax for the node objects and address-of syntax when assigning child
pointers:

```cpp
root.left = &node;
```

## 14–21 minutes: Recursive DFS

Implement:

```cpp
void preorder(const TreeNode* root, vector<int>& result);
void inorder(const TreeNode* root, vector<int>& result);
```

Both functions must begin with the recursion base case:

```cpp
if (root == nullptr)
    return;
```

Expected:

```text
preorder: 1 2 4 5 3 6
inorder: 4 2 5 1 3 6
```

Memory cues:

```text
preorder = node, left, right
inorder  = left, node, right
```

## 21–28 minutes: Queue-based BFS

Implement:

```cpp
vector<int> level_order(const TreeNode* root);
```

Requirements:

1. Return an empty vector for a null root.
2. Use `queue<const TreeNode*>`.
3. Push the root first.
4. While the queue is not empty, read `front()`, then `pop()`.
5. Add non-null children to the queue.
6. Return the traversal vector.

Expected:

```text
level order: 1 2 3 4 5 6
```

Memory cue:

```text
queue BFS = push root -> front -> pop -> push children
```

## 28–30 minutes: Placement recall test

Without looking upward, say or write:

1. The linked-list reversal pointer sequence.
2. The recursive base case.
3. Preorder's three operations.
4. Inorder's three operations.
5. The type of a queue holding read-only tree-node pointers.

## Scoring

- **Everything works closed-book:** begin tree placement problems.
- **DFS works but BFS fails:** repeat only queue syntax tomorrow.
- **Pointer construction fails:** repeat the Day 6 revision section tomorrow.

