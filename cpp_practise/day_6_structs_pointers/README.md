# Day 6 — Structs, Pointers, and Linked Lists (30 Minutes)

These are essential for linked-list, tree, graph-node, and custom-object
questions in placements.

Today covers:

- defining and constructing a `struct`
- `.` versus `->`
- `const T&`, `T&`, and pointer parameters
- sorting custom objects with a lambda
- traversing and reversing a singly linked list

## Rules

1. Work only in `drill.cpp`.
2. Do not open `solution.cpp` before minute 27.
3. Compile after each section.
4. Fix one compiler error at a time.
5. Stop after 30 minutes and begin solving placement problems.

## Compile and run

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic drill.cpp -o drill
./drill
```

## 0–3 minutes: Header recall

Add the headers required for input/output, strings, vectors, and sorting.

## 3–9 minutes: Define and use a struct

Define `Candidate` with:

```text
string name
int score
```

Complete `candidate_reference_drill()`:

1. Print every candidate using `const Candidate&` because printing is read-only.
2. Find `Dev` using a mutable `Candidate&` and change the score from 76 to 81.
3. Print `Dev` again to prove that the original object changed.

Expected:

```text
original:
Aman 82
Riya 95
Neha 95
Dev 76
updated=Dev 81
```

## 9–15 minutes: Sort custom objects

Complete `candidate_sort_drill()`.

Sort using a lambda with these rules:

1. Higher score first.
2. For equal scores, alphabetically smaller name first.
3. Print the sorted objects using `const Candidate&`.

Expected:

```text
sorted:
Neha 95
Riya 95
Aman 82
Dev 81
```

Comparator question: “Should `first` appear before `second`?”

## 15–21 minutes: Linked-list node and traversal

Define `ListNode` with:

- `int value`
- `ListNode* next`
- a constructor that receives the value and initializes `next` to `nullptr`

In `linked_list_drill()`:

1. Create three stack-allocated nodes containing `10`, `20`, and `30`.
2. Connect them using their addresses to form `10 -> 20 -> 30`.
3. Implement `print_list(const ListNode* head)` using pointer traversal.

Expected:

```text
forward: 10 20 30
```

Use `current->value` when `current` is a pointer. Use `node.value` when `node`
is an object.

## 21–28 minutes: Reverse the linked list

Implement:

```cpp
ListNode* reverse_list(ListNode* head)
```

Use three pointers:

- `previous`
- `current`
- `next_node`

After reversal, print the returned head.

Expected:

```text
reversed: 30 20 10
```

Your function must return the new head, not print from inside the reversal
logic.

## 28–30 minutes: Closed-book recall

Write these from memory, then comment them out:

1. A function receiving a read-only vector without copying.
2. A function receiving a pointer to a linked-list node.
3. Accessing a field through an object.
4. Accessing a field through a pointer.
5. Taking the address of an object.

Say aloud:

```text
dot for object, arrow for pointer, ampersand for address/reference
```

## Scoring

- **Everything works without the solution:** ready for linked-list problems.
- **Traversal works but reversal fails:** repeat only reversal tomorrow.
- **Struct or pointer syntax fails:** repeat this entire drill before trees.

