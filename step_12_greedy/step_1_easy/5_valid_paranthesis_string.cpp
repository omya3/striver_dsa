#include <bits/stdc++.h>
using namespace std;

bool func_balance(string s)
{
    int min_count = 0;
    int max_count = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            min_count += 1;
            max_count += 1;
        }
        else if (s[i] == ')')
        {
            min_count -= 1;
            max_count -= 1;
        }
        else  // '*'
        {
            max_count += 1;          // treat '*' as '(' in worst case
            min_count -= 1;          // treat '*' as ')' in best case
        }

        if (max_count < 0)
            return false;            // too many ')'

        if (min_count < 0)
            min_count = 0;           // cannot have negative opens
    }

    return min_count == 0;
}

class Solution
{
public:
    bool checkValidString(string s)
    {
        return func_balance(s);
    }
};
