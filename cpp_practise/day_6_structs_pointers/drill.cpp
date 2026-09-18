// Day 6: placement-focused structs and pointers drill.
// Complete every TODO without opening solution.cpp.

#include <algorithm> // sort
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Candidate
{
    // TODO: Add string name and int score fields.
    string name;
    int score;
};

void candidate_reference_drill(vector<Candidate> &candidates)
{
    // MEMORY: const T& reads the original object without copying it.
    cout << "original:\n";
    for (const Candidate &candidate : candidates)
    {
        // Use dot (.) with an object or reference.
        cout << candidate.name << ' ' << candidate.score << '\n';
    }

    // MEMORY: T& can modify the original object.
    for (Candidate &candidate : candidates)
    {
        if (candidate.name == "Dev")
        {
            candidate.score = 81;
            cout << "updated=" << candidate.name << ' ' << candidate.score << '\n';
        }
    }
    cout << '\n';
}

void candidate_sort_drill(vector<Candidate> &candidates)
{
    // Comparator question: should cand1 appear before cand2?
    sort(candidates.begin(), candidates.end(), [](const Candidate &cand1, const Candidate &cand2)
         {
             if (cand1.score != cand2.score)
             {
                 return cand1.score > cand2.score; // Higher score first.
             }
             return cand1.name < cand2.name; // Tie: alphabetical name first.
         });

    cout << "sorted:\n";
    for (const Candidate &candidate : candidates)
    {
        cout << candidate.name << ' ' << candidate.score << '\n';
    }
    cout << '\n';
}

struct ListNode
{
    int val;
    ListNode *next;

    // MEMORY: initializer lists construct fields directly before the body runs.
    explicit ListNode(int node_value, ListNode *next_node = nullptr)
        : val(node_value), next(next_node)
    {
    }
};

void print_list(const ListNode *head)
{
    // const ListNode* = movable pointer, read-only node.
    // ListNode* const = fixed pointer, mutable node. Traversal needs the first form.
    const ListNode *ptr = head;
    while (ptr != nullptr)
    {
        // Use arrow (->) with a pointer: ptr->val means (*ptr).val.
        cout << ptr->val << ' ';
        ptr = ptr->next;
    }
    cout << '\n';
}

ListNode *reverse_list(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        // MEMORY: save -> reverse -> advance both pointers.
        ListNode *next_node = curr->next; // Save before overwriting curr->next.
        curr->next = prev;                // Reverse the link.
        prev = curr;                      // Advance prev.
        curr = next_node;                 // Advance curr.
    }

    // curr is nullptr; prev is now the new head.
    return prev;
}

void linked_list_drill()
{
    // Stack objects are cleaned up automatically; never delete their addresses.
    ListNode n1(10);
    ListNode n2(20);
    ListNode n3(30);

    // Ampersand (&) takes an object's address.
    n1.next = &n2;
    n2.next = &n3;

    ListNode *head = &n1;
    cout << "forward: ";
    print_list(head);

    head = reverse_list(head);
    cout << "reversed: ";
    print_list(head);
}

int main()
{
    vector<Candidate> candidates{
        {"Aman", 82}, {"Riya", 95}, {"Neha", 95}, {"Dev", 76}};

    candidate_reference_drill(candidates);
    candidate_sort_drill(candidates);
    linked_list_drill();
}
