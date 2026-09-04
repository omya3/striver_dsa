#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

void stack_queue_drill()
{
    vector<int> values{4, 1, 7, 2};
    stack<int> value_stack;
    queue<int> value_queue;

    for (int value : values)
    {
        value_stack.push(value);
        value_queue.push(value);
    }

    cout << "stack: ";
    while (!value_stack.empty())
    {
        cout << value_stack.top() << ' ';
        value_stack.pop();
    }
    cout << '\n';

    cout << "queue: ";
    while (!value_queue.empty())
    {
        cout << value_queue.front() << ' ';
        value_queue.pop();
    }
    cout << "\n\n";
}

void frequency_drill()
{
    vector<string> words{"apple", "banana", "apple", "orange",
                         "banana", "apple"};
    unordered_map<string, int> frequency;

    for (const string& word : words)
    {
        ++frequency[word];
    }

    cout << "apple=" << frequency.at("apple") << '\n';
    cout << "banana=" << frequency.at("banana") << '\n';
    cout << "kiwi="
         << (frequency.find("kiwi") == frequency.end() ? "missing" : "present")
         << "\n\n";
}

void bounds_drill()
{
    vector<int> data{4, 1, 7, 4, 2, 9, 4};
    sort(data.begin(), data.end());

    cout << "sorted: ";
    for (int value : data)
    {
        cout << value << ' ';
    }
    cout << '\n';

    const auto lower = lower_bound(data.begin(), data.end(), 4);
    const auto upper = upper_bound(data.begin(), data.end(), 4);
    cout << "lower=" << lower - data.begin()
         << " upper=" << upper - data.begin()
         << " count=" << upper - lower << '\n';

    cout << "contains 6=" << boolalpha
         << binary_search(data.begin(), data.end(), 6) << "\n\n";
}

void most_frequent_drill()
{
    vector<int> input{5, 2, 5, 3, 2, 5};
    queue<int> pending;
    for (int value : input)
    {
        pending.push(value);
    }

    unordered_map<int, int> frequency;
    while (!pending.empty())
    {
        ++frequency[pending.front()];
        pending.pop();
    }

    priority_queue<pair<int, int>> candidates;
    for (const auto& [value, count] : frequency)
    {
        candidates.push({count, value});
    }

    const auto& [count, value] = candidates.top();
    cout << "most_frequent=" << value << " count=" << count << '\n';
}

int main()
{
    stack_queue_drill();
    frequency_drill();
    bounds_drill();
    most_frequent_drill();
}
