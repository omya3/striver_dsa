#include <iostream>
#include <vector> // FIX 1: Absolutely required to use vector containers
#include <string>
#include <algorithm>

using namespace std;

vector<int> manachers_box(string &s)
{
    int L = 0;
    int R = 0;

    string s_new = "^#";

    for (auto it : s)
    {
        s_new += it;
        s_new += '#';
    }

    s_new += "$";
    int n = s_new.size();

    vector<int> man_box(n, 0);

    // Process all positions bounded inside the front and back sentinels
    for (int i = 1; i < n - 1; i++)
    {
        if (i <= R)
        {
            // We are in the box so let's copy previous values safely ;)
            man_box[i] = max(0, min(R - i, man_box[L + R - i]));
        }

        while (s_new[i - (1 + man_box[i])] == s_new[i + (1 + man_box[i])])
        {
            man_box[i] += 1;
        }

        if (i + man_box[i] > R)
        {
            L = i - man_box[i];
            R = i + man_box[i];
        }
    }
    return man_box;
}


int main()
{
    // Fast I/O optimization for online judges
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s)
    {
        vector<int> ans = manachers_box(s);

        // Code executed successfully!
    }

        return 0;
}
