#include <deque>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void deque_drill()
{
    deque<int> values;
    values.push_back(20);
    values.push_back(30);
    values.push_front(10);
    values.push_back(40);

    cout << "front=" << values.front()
         << " back=" << values.back()
         << " size=" << values.size() << '\n';

    values.pop_front();
    values.pop_back();

    cout << "after pops: ";
    for (int value : values)
    {
        cout << value << ' ';
    }
    cout << '\n';
    cout << "empty=" << boolalpha << values.empty() << "\n\n";
}

void pair_drill()
{
    pair<string, int> student{"Omkar", 80};
    cout << "student=" << student.first << ' ' << student.second << '\n';

    student.second = 95;
    cout << "updated=" << student.first << ' ' << student.second << '\n';

    pair<string, int> second_student = make_pair(string("Aman"), 72);
    const auto& [name, score] = second_student;
    cout << "second=" << name << ' ' << score << "\n\n";
}

void heap_drill()
{
    vector<int> values{5, 1, 8, 3, 8};
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int value : values)
    {
        max_heap.push(value);
        min_heap.push(value);
    }

    cout << "max-heap: ";
    while (!max_heap.empty())
    {
        cout << max_heap.top() << ' ';
        max_heap.pop();
    }
    cout << '\n';

    cout << "min-heap: ";
    while (!min_heap.empty())
    {
        cout << min_heap.top() << ' ';
        min_heap.pop();
    }
    cout << "\n\n";
}

void mixed_drill()
{
    deque<pair<string, int>> tasks;
    tasks.push_back({"coding", 5});
    tasks.push_front({"email", 2});
    tasks.push_back({"meeting", 3});

    priority_queue<int> priorities;
    cout << "tasks:\n";
    for (const auto& [name, priority] : tasks)
    {
        cout << name << ' ' << priority << '\n';
        priorities.push(priority);
    }

    cout << "priorities: ";
    while (!priorities.empty())
    {
        cout << priorities.top() << ' ';
        priorities.pop();
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
