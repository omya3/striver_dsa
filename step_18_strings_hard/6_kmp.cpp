#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
private:
    vector<int> longest_prefix_suffix(string pat)
    {
        int n = pat.size();
        vector<int> lps(n, 0);

        int i = 1;
        int prevLps = 0;

        while (i < n)
        {
            if (pat[prevLps] == pat[i])
            {
                lps[i] = prevLps + 1;
                prevLps += 1;
                i += 1;
            }
            else
            {
                if (prevLps == 0)
                {
                    lps[i] = 0;
                    i += 1;
                }
                else
                {
                    prevLps = lps[prevLps - 1];
                }
            }
        }
        return lps;
    }

public:
    vector<int> search(string &pat, string &txt)
    {
        int n = txt.size();
        int m = pat.size();

        vector<int> result; // Vector to store all starting indices

        // Edge case: Pattern is longer than the text
        if (m > n)
            return result;

        vector<int> lps = longest_prefix_suffix(pat);

        int i = 0; // Index for txt
        int j = 0; // Index for pat

        while (i < n)
        {
            if (txt[i] == pat[j])
            {
                i += 1;
                j += 1;
            }
            else
            {
                if (j == 0)
                {
                    i += 1;
                }
                else
                {
                    j = lps[j - 1];
                }
            }

            // A full match is found
            if (j == m)
            {
                // FIX 1 & 2: Push 0-based or 1-based index based on platform instructions.
                // GeeksforGeeks usually expects 1-based indexing: result.push_back(i - j + 1);
                result.push_back(i - j);

                // FIX 3: Reset j using the LPS array to handle potential overlapping matches
                j = lps[j - 1];
            }
        }
        return result; // Return the collected positions vector
    }
};
