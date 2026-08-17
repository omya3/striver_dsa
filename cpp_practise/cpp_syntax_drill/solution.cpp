#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;

void traversal_drill() {
    vector<int> numbers{2, 4, 4, 1, 5};
    string text = "sequence";

    cout << "index loop: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << ' ';
    }
    cout << '\n';

    cout << "range loop: ";
    for (int number : numbers) {
        cout << number << ' ';
    }
    cout << '\n';

    for (int& number : numbers) {
        number *= 2;
    }
    cout << "doubled: ";
    for (int number : numbers) {
        cout << number << ' ';
    }
    cout << '\n';

    cout << "characters: ";
    for (string::const_iterator it = text.cbegin(); it != text.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';

    int vowel_count = 0;
    for (char character : text) {
        if (string("aeiou").find(character) != string::npos) {
            ++vowel_count;
        }
    }
    cout << "vowels=" << vowel_count << "\n\n";
}

void frequency_drill() {
    vector<string> words{"red", "blue", "red", "gold", "blue", "red"};
    unordered_map<string, int> frequency;
    for (const string& word : words) {
        ++frequency[word];
    }

    cout << "red=" << frequency.at("red") << '\n';
    cout << "green="
         << (frequency.find("green") != frequency.end() ? "present" : "missing")
         << '\n';
    cout << "frequencies: ";
    for (const auto& [word, count] : frequency) {
        cout << word << '=' << count << ' ';
    }
    cout << "\n\n";
}

void set_drill() {
    vector<int> input{5, 1, 3, 3, 9, 7};
    set<int> unique_values;
    for (int value : input) {
        unique_values.insert(value);
    }

    const auto [position, inserted] = unique_values.insert(3);
    (void)position;
    cout << "inserted duplicate 3=" << boolalpha << inserted << '\n';
    cout << "found 7=" << (unique_values.find(7) != unique_values.end()) << '\n';
    unique_values.erase(1);
    cout << "set: ";
    for (int value : unique_values) {
        cout << value << ' ';
    }
    cout << "\n\n";
}

void deque_drill() {
    deque<int> values;
    values.push_back(20);
    values.push_back(30);
    values.push_front(10);
    values.push_back(40);

    cout << "front=" << values.front() << " back=" << values.back() << '\n';
    values.pop_front();
    values.pop_back();
    cout << "deque: ";
    for (int value : values) {
        cout << value << ' ';
    }
    cout << "\n\n";
}

void heap_drill() {
    vector<int> values{4, 1, 9, 2, 7};
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int value : values) {
        max_heap.push(value);
        min_heap.push(value);
    }

    cout << "max-heap: ";
    while (!max_heap.empty()) {
        cout << max_heap.top() << ' ';
        max_heap.pop();
    }
    cout << '\n';

    cout << "min-heap: ";
    while (!min_heap.empty()) {
        cout << min_heap.top() << ' ';
        min_heap.pop();
    }
    cout << "\n\n";
}

void algorithm_drill() {
    vector<int> data{4, 1, 7, 4, 2, 9, 4};
    sort(data.begin(), data.end());
    cout << "ascending: ";
    for (int value : data) {
        cout << value << ' ';
    }
    cout << '\n';

    const auto first = lower_bound(data.begin(), data.end(), 4);
    const auto after_last = upper_bound(data.begin(), data.end(), 4);
    cout << "bounds=[" << distance(data.begin(), first) << ", "
         << distance(data.begin(), after_last) << ")\n";
    cout << "count=" << distance(first, after_last) << '\n';

    vector<int> descending = data;
    sort(descending.begin(), descending.end(), greater<int>());
    cout << "descending: ";
    for (int value : descending) {
        cout << value << ' ';
    }
    cout << "\n\n";
}

int main() {
    traversal_drill();
    frequency_drill();
    set_drill();
    deque_drill();
    heap_drill();
    algorithm_drill();
}
