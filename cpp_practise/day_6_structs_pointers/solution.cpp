#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Candidate
{
    string name;
    int score;
};

void candidate_reference_drill(vector<Candidate>& candidates)
{
    cout << "original:\n";
    for (const Candidate& candidate : candidates)
    {
        cout << candidate.name << ' ' << candidate.score << '\n';
    }

    for (Candidate& candidate : candidates)
    {
        if (candidate.name == "Dev")
        {
            candidate.score = 81;
            cout << "updated=" << candidate.name << ' ' << candidate.score << '\n';
        }
    }
    cout << '\n';
}

void candidate_sort_drill(vector<Candidate>& candidates)
{
    sort(candidates.begin(), candidates.end(),
         [](const Candidate& first, const Candidate& second)
         {
             if (first.score != second.score)
             {
                 return first.score > second.score;
             }
             return first.name < second.name;
         });

    cout << "sorted:\n";
    for (const Candidate& candidate : candidates)
    {
        cout << candidate.name << ' ' << candidate.score << '\n';
    }
    cout << '\n';
}

struct ListNode
{
    int value;
    ListNode* next;

    explicit ListNode(int node_value) : value(node_value), next(nullptr)
    {
    }
};

void print_list(const ListNode* head)
{
    const ListNode* current = head;
    while (current != nullptr)
    {
        cout << current->value << ' ';
        current = current->next;
    }
    cout << '\n';
}

ListNode* reverse_list(ListNode* head)
{
    ListNode* previous = nullptr;
    ListNode* current = head;

    while (current != nullptr)
    {
        ListNode* next_node = current->next;
        current->next = previous;
        previous = current;
        current = next_node;
    }

    return previous;
}

void linked_list_drill()
{
    ListNode first(10);
    ListNode second(20);
    ListNode third(30);

    first.next = &second;
    second.next = &third;

    cout << "forward: ";
    print_list(&first);

    ListNode* reversed_head = reverse_list(&first);
    cout << "reversed: ";
    print_list(reversed_head);
}

int main()
{
    vector<Candidate> candidates{
        {"Aman", 82}, {"Riya", 95}, {"Neha", 95}, {"Dev", 76}};

    candidate_reference_drill(candidates);
    candidate_sort_drill(candidates);
    linked_list_drill();
}
