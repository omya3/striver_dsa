#include <bits/stdc++.h>
using namespace std;

string find_reverse_k(const string &s, int k)
{
    string st;  // use as stack of chars

    for (char c : s)
    {
        while (!st.empty() && k > 0 && st.back() > c)
        {
            st.pop_back();
            --k;
        }
        st.push_back(c);
    }

    // If still need to remove, pop from the end
    while (k > 0 && !st.empty())
    {
        st.pop_back();
        --k;
    }

    // Remove leading zeros
    int i = 0;
    while (i < (int)st.size() && st[i] == '0')
        ++i;

    string res = st.substr(i);
    if (res.empty())
        return "0";
    return res;
}

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        return find_reverse_k(num, k);
    }
};
