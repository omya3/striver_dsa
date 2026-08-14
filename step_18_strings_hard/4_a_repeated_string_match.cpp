#include <string>

using namespace std;

class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        // Step 1: Calculate the baseline count (ceiling division)
        int count = (b.size() + a.size() - 1) / a.size();

        // Build the initial repeated string
        string repeated_a = "";
        for (int i = 0; i < count; i++)
        {
            repeated_a += a;
        }

        // Step 2: Check the baseline repeated string
        if (repeated_a.find(b) != string::npos)
        {
            return count;
        }

        // Step 3: Check count + 1 (handles a single wrap-around)
        repeated_a += a;
        if (repeated_a.find(b) != string::npos)
        {
            return count + 1;
        }

        // Step 4: Check count + 2 (handles double overhangs on short 'b')
        repeated_a += a;
        if (repeated_a.find(b) != string::npos)
        {
            return count + 2;
        }

        // Step 5: If not found by now, it is mathematically impossible
        return -1;
    }
};