#include <iostream>
using namespace std;

int assign_cookies(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int m = g.size();
    int n = s.size();
    int l = 0;
    int r = 0;

    while (l < m && r < n)
    {
        if (g[l] <= s[r])
        {
            l += 1;
        }
        r += 1;
    }
    return l;
}

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        return assign_cookies(g, s);
    }
};