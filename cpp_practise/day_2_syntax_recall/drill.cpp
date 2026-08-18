// Day 2 C++ syntax recall: deque, pair, max-heap, and min-heap.
// Complete every TODO without opening solution.cpp.

// TODO 1: Add all required standard-library headers.
#include <iostream>
#include <deque>
#include <utility>
#include <queue>
#include <vector>
#include <functional>
#include <string>
using namespace std;

void deque_drill()
{
    // TODO: Declare a deque<int>.
    deque<int> dq;
    // TODO: Use both ends to create: 10 20 30 40.
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.push_front(10);
    // TODO: Print front, back, and size.
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    cout << dq.size() << endl;
    // TODO: Remove one value from each end.
    dq.pop_front();
    dq.pop_back();
    // TODO: Print the remaining values with a range-based loop.
    for (int value : dq)
    {
        cout << value << " ";
    }
    cout << '\n';
    // TODO: Print whether the deque is empty using boolalpha.
    cout << boolalpha;
    cout << dq.empty();

    cout << '\n';
}

void pair_drill()
{
    // TODO: Declare pair<string, int> student containing "Omkar" and 80.
    pair<string, int> student = {"Omkar", 80};
    // TODO: Print student using .first and .second.
    cout << student.first << endl;
    cout << student.second << endl;
    // TODO: Change the score to 95 and print the pair again.
    student.second = 95;
    cout << student.first << " " << student.second << endl;
    // TODO: Create the pair "Aman", 72 using make_pair().
    auto student2 = make_pair("Aman", 72);
    // TODO: Use structured binding to read and print the second pair.
    auto [name, roll_no] = student2;
    cout << name << endl;
    cout << roll_no << endl;
    cout << '\n';
}

void heap_drill()
{
    vector<int> values{5, 1, 8, 3, 8};

    // TODO: Declare a default max-heap of integers.
    priority_queue<int> max_heap;
    // TODO: Declare a min-heap using vector<int> and greater<int>.
    priority_queue<int, vector<int>, greater<int>> min_heap;
    // TODO: Push every value into both heaps.
    for (auto it : values)
    {
        max_heap.push(it);
        min_heap.push(it);
    }
    // TODO: Repeatedly print top() and pop() from the max-heap.
    while (!max_heap.empty())
    {
        cout << max_heap.top() << endl;
        max_heap.pop();
    }
    // TODO: Repeatedly print top() and pop() from the min-heap.
    while (!min_heap.empty())
    {
        cout << min_heap.top() << endl;
        min_heap.pop();
    }
    cout << '\n';
}

void mixed_drill()
{
    // TODO: Declare deque<pair<string, int>> tasks.
    deque<pair<string, int>> dq;
    // TODO: Use both ends to create this order:
    //       email 2, coding 5, meeting 3

    dq.push_front({"email", 2});
    dq.push_back({"coding", 5});
    dq.push_back({"meeting", 3});
    // TODO: Print every task's name and priority.
    
    // for (auto item : container)        // Copy
    // for (const auto& item : container) // Read without copying
    // for (auto& item : container)       // Modify original

    for (const auto &task : dq)
    {
        cout << task.first << " " << task.second << endl;
    }
    // TODO: Push every priority into a max-heap.
    priority_queue<int> mp;
    for (const auto &task : dq)
    {
        mp.push(task.second);
    }
    // TODO: Print the priorities from highest to lowest.
    while (!mp.empty())
    {
        cout << mp.top() << endl;
        mp.pop();
    }
    cout << '\n';
}

int main()
{
    deque_drill();
    pair_drill();
    heap_drill();
    mixed_drill();
}
