class Solution
{
public:
    string shortestPalindrome(string s)
    {

        if (s.length() <= 1)
            return s;

        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());

        int n = s.size();

        string new_string = s + "$" + s_rev;

        vector<int> lps(new_string.length(), 0);

        int prev_lps = 0;
        int i = 1;

        while (i < new_string.length())
        {
            if (new_string[prev_lps] == new_string[i])
            {
                prev_lps += 1;
                lps[i] = prev_lps;
                i += 1;
            }
            else
            {
                if (prev_lps == 0)
                {
                    lps[i] = 0;
                    i += 1;
                }
                else
                {
                    prev_lps = lps[prev_lps - 1];
                }
            }
        }

        int pref_pall_len = lps.back();

        string suff_to_be_added = s.substr(pref_pall_len);

        reverse(suff_to_be_added.begin(), suff_to_be_added.end());

        string output_str = suff_to_be_added + s;
        return output_str;
    }
};