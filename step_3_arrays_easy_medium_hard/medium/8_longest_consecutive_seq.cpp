#include <iostream>
#include <unordered_set>

using namespace std;

int longest_seq(vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    int num;
    int count = 1;
    int max_seq = 1;
    for (int x : s)
    {
        if (s.find(x - 1) != s.end())
        {
            count = 1;
            continue;
        }
        else
        {
            num = x + 1;
            while (s.find(num) != s.end())
            {
                count += 1;
                num += 1;
            }
            max_seq = max(count, max_seq);
        }
    }
    return max_seq;
}

int main()
{

    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}