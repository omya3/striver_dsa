class Solution
{

private:
    int find_lcs_length(int l1, int l2, string &s1, string &s2)
    {
        if (l1 < 0 || l2 < 0)
            return 0;

        if (s1[l1] == s2[l2])
        {
            return 1 + find_lcs_length(l1 - 1, l2 - 1, s1, s2);
        }

        return 0 + max(find_lcs_length(l1 - 1, l2, s1, s2), find_lcs_length(l1, l2 - 1, s1, s2));
    }

public:
    int lcs(string &s1, string &s2)
    {
        // code here
        int l1 = s1.length();
        int l2 = s2.length();

        // vector<vector<int>> dp(l1, vector<int>(l2, 0));

        return find_lcs_length(l1 - 1, l2 - 1, s1, s2);
    }
};
