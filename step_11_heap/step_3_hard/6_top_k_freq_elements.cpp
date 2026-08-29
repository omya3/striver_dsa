/// below is k logn solution

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        if (k > nums.size())
            return {};

        map<int, int> mp;

        for (auto it : nums)
        {
            if (mp.find(it) == mp.end())
            {
                mp[it] = 1;
            }
            else
            {
                mp[it] += 1;
            }
        }

        vector<pair<int, int>> in_count(mp.begin(), mp.end());

        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.second < b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;

        for (const auto &pairs : in_count)
        {
            cout << pairs.first << " " << pairs.second << endl;
            pq.push(pairs);
        }

        vector<int> output;
        for (int i = 0; i < k; i++)
        {
            cout << pq.top().first << " ";
            output.push_back(pq.top().first);
            pq.pop();
        }

        return output;
    }
};

/// below is linear solution

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Use unordered_map for O(1) average time complexity lookup
        unordered_map<int, int> mp;
        for (auto it : nums)
        {
            mp[it] += 1;
        }

        // Fix 1: Properly initialize the 2D bucket vector
        vector<vector<int>> count_store(n + 1);

        for (auto pair : mp)
        {
            count_store[pair.second].push_back(pair.first);
        }

        // Fix 2: Changed variable name from 'nums' to 'element_count' to avoid conflict
        int element_count = 0;
        vector<int> output;

        // Iterate backwards from the highest possible frequency (n) down to 0
        for (int i = count_store.size() - 1; i >= 0; i--)
        {
            // Fix 3: Removed the accidental semicolon inside brackets
            vector<int> counts = count_store[i];

            if (counts.size() > 0)
            {
                for (auto val : counts)
                {
                    if (element_count < k)
                    {
                        output.push_back(val);
                        element_count += 1;
                    }
                    else
                    {
                        break; // Optimization: Stop early if we have k elements
                    }
                }
            }

            if (element_count == k)
                break; // Optimization: Stop outer loop early
        }

        // Fix 4: Added missing return statement
        return output;
    }
};
