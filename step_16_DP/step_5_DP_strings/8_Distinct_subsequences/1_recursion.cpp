class Solution
{

private:
    int finder(int i, int j, string &s, string &t)
    {

        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (s[i] == t[j])
        {
            return finder(i - 1, j - 1, s, t) + finder(i - 1, j, s, t);
        }
        else
        {
            return finder(i - 1, j, s, t);
        }
    }

public:
    int numDistinct(string s, string t)
    {
        return finder(s.size() - 1, t.size() - 1, s, t);
    }
};