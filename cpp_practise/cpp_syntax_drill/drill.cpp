// C++ STL syntax drill. Replace every TODO without opening solution.cpp.

// TODO 1: Add the standard-library headers needed by this file.
#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

void traversal_drill()
{
    vector<int> numbers{2, 4, 4, 1, 5};
    string text = "sequence";

    cout << "index loop: ";
    // TODO: Print numbers using an index-based loop.
    int n = numbers.size();
    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << '\n';

    cout << "range loop: ";
    // TODO: Print numbers using a range-based loop.
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << '\n';

    // TODO: Double every number. The loop variable must be a reference.
    cout << "doubled: ";
    // TODO: Print the doubled numbers.
    for (int num : numbers)
    {
        cout << 2 * num << " ";
    }
    cout << '\n';

    cout << "characters: ";
    // TODO: Traverse text with an iterator and print each character.
    for (char ch : text)
    {
        cout << ch << " ";
    }
    cout << '\n';

    int vowel_count = 0;
    // TODO: Count a, e, i, o, and u in text.
    set<char> vowel_set;
    vowel_set.insert('a');
    vowel_set.insert('e');
    vowel_set.insert('i');
    vowel_set.insert('o');
    vowel_set.insert('u');
    for (char ch : text)
    {
        if (vowel_set.find(ch) != vowel_set.end())
        {
            vowel_count += 1;
        }
    }
    cout << "vowels=" << vowel_count << "\n\n";
}

void frequency_drill()
{
    vector<string> words{"red", "blue", "red", "gold", "blue", "red"};
    // TODO: Declare an unordered_map<string, int> named frequency.
    unordered_map<string, int> freq;
    // TODO: Count every word with operator[].
    for (string str : words)
    {
        if (freq.find(str) != freq.end())
        {
            freq[str] += 1;
        }
        else
        {
            freq[str] = 1;
        }
    }
    // TODO: Print red's count using .at().
    cout << "red's frequency is :" << freq.at("red") << " ";
    // TODO: Use .find() to print whether green is present or missing.
    cout << freq.find("green") != freq.end() ? "green is present" : "green is absent";
    // TODO: Print all key/value pairs. Map iteration order is unspecified.
    for (auto &pair : freq)
    {
        cout << pair[0] << " : " << pair[1] << "\n";
    }
    cout << '\n';
}

void set_drill()
{
    vector<int> input{5, 1, 3, 3, 9, 7};
    // TODO: Declare a set<int> and insert all input values.
    set<int> int_set;
    for (int i : input)
    {
        int_set.insert(i);
    }
    // TODO: Insert 3 again and print the returned insertion boolean.
    bool ins_boolean = int_set.insert(3);
    cout << ins_boolean << "\n";

    // TODO: Find 7 and print whether it was found.
    if (int_set.find(7) != int_set.end())
    {
        cout << "7 was found";
    }
    else
    {
        cout << "7 was not found";
    }
    cout << "\n";
    // TODO: Erase 1, then print the set in sorted order.
    int_set.erase(1);
    vector<int> sorted_set(int_set.begin(), int_set.end());
    sort(int_set.begin(), int_set.end());
    for (int num : int_set)
    {
        cout << num << " ";
    }
    cout << '\n';
}

void deque_drill()
{
    // TODO: Declare a deque<int> and create 10 20 30 40 using both ends.
    dequeue<int> dq;
    dq.push_front(20);
    dq.push_back(30);
    dq.push_front(30);
    dq.push_back(40);
    // TODO: Print its front and back values.
    cout << "front val: " << dq.front() << " " << endl;
    cout << "back val: " << dq.back() << " " << endl;
    // TODO: Pop once from each end, then print the remaining values.
    dq.pop_front();
    dq.pop_back();

    for (int num : dq)
    {
        cout << num << " ";
    }
    cout << '\n';
}

void heap_drill()
{
    vector<int> values{4, 1, 9, 2, 7};
    // TODO: Declare a max-heap and a min-heap, then push every value to both.
    priority_queue<int> max_heap;
    for (int num : values)
    {
        max_heap.push(num);
    }

    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int num : values)
    {
        min_heap.push(num);
    }
    // TODO: Pop and print every max-heap value.
    while (max_heap.size())
    {
        int num = max_heap.top();
        max_heap.pop();
        cout << num << " ";
    }

    // TODO: Pop and print every min-heap value.
    while (min_heap.size())
    {
        int num = min_heap.top();
        min_heap.pop();
        cout << num << " ";
    }
    cout << '\n';
}

void algorithm_drill()
{
    vector<int> data{4, 1, 7, 4, 2, 9, 4};
    // TODO: Sort data ascending and print it.
    sort(data.begin(), data.end());
    for (int num : data)
    {
        cout << num << " ";
    }
    // TODO: Get lower_bound and upper_bound iterators for 4.
    
    // TODO: Print their zero-based positions and the count of 4.
    // TODO: Make a copy, sort it descending, and print it.
    cout << '\n';
}

int main()
{
    traversal_drill();
    frequency_drill();
    set_drill();
    deque_drill();
    heap_drill();
    algorithm_drill();
}
