# Day 9 — Tree Repair and BST Search (30 Minutes)

Today follows a placement-style workflow:

1. Debug yesterday's code instead of abandoning it.
2. Reuse the corrected pointer syntax in binary-search-tree operations.

## Rules

1. Do not open either solution during the first 27 minutes.
2. Fix Day 8 before starting the new Day 9 file.
3. Compile after every small correction.
4. Read only the first compiler error each time.
5. Stop after 30 minutes.

## 0–12 minutes: Repair yesterday's Day 8 file

Open:

```text
../day_8_tree_mastery/drill.cpp
```

Fix these without opening its solution:

### Headers

Add explicit headers for algorithms, input/output, queue, stack, string, and
vector.

### Constructor

Make it possible to write `TreeNode node(8)` by initializing both child
pointers to `nullptr` automatically.

### Inorder

The order must be:

```text
inorder(left) -> record node -> inorder(right)
```

Do not call a tree function on the result vector.

### BFS

- Preserve `const` with `queue<const TreeNode*>`.
- A queue removes its front using `pop()`, not `pop_front()`.
- The pointer obtained from the queue must also be `const TreeNode*`.

### Node count

Both recursive calls must call `count_nodes()`. Do not use `tree_height()` to
count the right subtree.

### Iterative preorder

Preserve `const` with `stack<const TreeNode*>` and a `const TreeNode*` current
pointer.

### Output

Print inorder before overwriting its result vector. Verify:

```text
inorder: 1 3 6 8 10 14
level order: 8 3 10 1 6 14
height=3
nodes=6
iterative preorder: 8 3 1 6 10 14
```

Compile Day 8 with:

```sh
cd ../day_8_tree_mastery
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

Do not continue until it compiles.

## 12–15 minutes: Start today's BST file

Return to this directory and open `drill.cpp`.

1. Add the required headers.
2. Define `TreeNode` with a constructor that initializes its children.
3. Build this BST with stack-allocated nodes:

```text
        8
       / \
      3   10
     / \    \
    1   6    14
```

## 15–20 minutes: Iterative BST search

Implement:

```cpp
bool contains_bst(const TreeNode* root, int target);
```

Use the BST rule:

```text
target smaller -> move left
target larger  -> move right
```

Expected:

```text
contains 6=true
contains 5=false
```

## 20–25 minutes: Return the search path

Implement:

```cpp
vector<int> path_to_target(const TreeNode* root, int target);
```

Record each visited value. Return an empty vector if the target is absent.

Expected:

```text
path to 6: 8 3 6
path to 5: missing
```

## 25–28 minutes: Minimum and maximum

Implement:

```cpp
const TreeNode* minimum_node(const TreeNode* root);
const TreeNode* maximum_node(const TreeNode* root);
```

- Minimum: repeatedly follow `left`.
- Maximum: repeatedly follow `right`.
- Return `nullptr` for an empty tree.

Expected:

```text
minimum=1
maximum=14
```

## 28–30 minutes: Closed-book recall

Say or write:

1. Queue removal function.
2. Stack removal function.
3. Read-only node-pointer queue declaration.
4. Read-only node-pointer stack declaration.
5. BST decision for a smaller target.

## Compile today's file

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

