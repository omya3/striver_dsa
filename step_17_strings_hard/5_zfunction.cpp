class Solution
{

private:
    vector<int> zfunction(string txt)
    {
        int l = 0, r = 0;
        int n = txt.length();
        vector<int> z(n);

        for (int i = 1; i < n; i++)
        {
            if (i <= r)
            {
                int k = i - l;
                z[i] = min(r - i + 1, z[k]);
            }

            while (i + z[i] < n && txt[z[i]] == txt[i + z[i]])
            {
                z[i] += 1;
            }

            // FIX 3: Corrected the condition to update the Z-box right boundary
            if (i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

public:
    vector<int> search(string &pat, string &txt)
    {
        string s = pat + "$" + txt;
        vector<int> z = zfunction(s);
        vector<int> pos;

        int m = pat.size();

        for (int i = m + 1; i < z.size(); i++)
        {
            if (z[i] == m)
            {
                // FIX 2: Store the index in the results vector instead of just printing it
                pos.push_back(i - m - 1);
            }
        }

        // FIX 1: Return the vector containing positions instead of integer 0
        return pos;
    }
};
