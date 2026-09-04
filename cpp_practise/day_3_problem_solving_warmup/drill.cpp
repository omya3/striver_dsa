// Day 3: 30-minute C++ syntax warm-up before problem solving.
// Complete every TODO without opening solution.cpp.

// TODO 1: Add all required standard-library headers.
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void stack_queue_drill()
{
    vector<int> values{4, 1, 7, 2};

    // TODO: Declare a stack<int> and queue<int>.
    stack<int> st;
    queue<int> qu;
    // TODO: Push every value into both containers.
    for (auto it : values)
    {
        st.push(it);
        qu.push(it);
    }
    // TODO: Print and remove the stack values.
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        cout << x << endl;
    }
    // TODO: Print and remove the queue values.
    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        cout << x << endl;
    }
    cout << '\n';
}

void frequency_drill()
{
    vector<string> words{"apple", "banana", "apple", "orange",
                         "banana", "apple"};

    // TODO: Declare unordered_map<string, int> frequency.
    unordered_map<string, int> s_mp;
    // TODO: Count every word with operator[].
    for (auto s : words)
    {
        s_mp[s] += 1;
    }
    // TODO: Print apple and banana counts using .at().
    cout << s_mp.at("apple") << endl;
    cout << s_mp.at("banana") << endl;
    // TODO: Use .find() to print whether kiwi is present or missing.
    if (s_mp.find("kiwi") != s_mp.end())
    {
        cout << true << endl;
    }
    cout << '\n';
}

void bounds_drill()
{
    vector<int> data{4, 1, 7, 4, 2, 9, 4};

    // TODO: Sort data ascending and print it.
    sort(data.begin(), data.end());
    // TODO: Get lower_bound and upper_bound iterators for 4.
    auto lower = lower_bound(data.begin(), data.end(), 4);
    auto upper = upper_bound(data.begin(), data.end(), 4);
    // TODO: Print both zero-based positions and the count of 4.
    int position = lower - data.begin();
    cout << position << endl;

    int count = upper - lower;
    cout << count << endl;
    // TODO: Use binary_search to print whether 6 exists.
    int low = 0;
    int high = data.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low + 1) / 2;

        if (data[mid] == 6)
        {
            cout << "6 exists";
        }
        else if (data[mid] < 6)
        {
            low += 1;
        }
        else
        {
            high -= 1;
        }
    }
    cout << '\n';
}

void most_frequent_drill()
{
    vector<int> input{5, 2, 5, 3, 2, 5};

    // TODO: Push all input values into a queue<int>.
    queue<int> q;
    for (auto it : input)
    {
        q.push(it);
    }
    // TODO: Process the queue into unordered_map<int, int> frequency.
    unordered_map<int, int> mp;
    while (!q.empty())
    {
        int x = q.front();
        mp[x] += 1;
        q.pop();
    }
    // TODO: Declare a max-heap of pair<int, int>.
    priority_queue<pair<int, int>> max_heap;
    // TODO: Push {count, value} for every frequency-table entry.
    for (auto pairs : mp)
    {
        max_heap.push(pairs);
    }
    // TODO: Print the value and count stored at the heap top.
    auto top = max_heap.top();
    cout << top.first << " " << top.second << endl;
    cout << '\n';
}

int main()
{
    stack_queue_drill();
    frequency_drill();
    bounds_drill();
    most_frequent_drill();
}
