#include <iostream>
using namespace std;

bool check_pallindrome(string s, int left, int right)
{
    while (left <= right)
    {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}

void func(int index, string s, vector<string> &path, vector<vector<string>> &res)
{
    if (index == s.size())
    {
        res.push_back(path);
    }

    for (int i = index; i < s.size(); i++)
    {
        if (check_pallindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            func(i + 1, s, path, res);
            path.pop_back();
        }
    }
}

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }
};