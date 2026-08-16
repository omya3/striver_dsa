#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct Node
{
    Node *links[2] = {};

    bool containsKey(int bit)
    {
        return (links[bit] != nullptr);
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }

    Node *get(int bit)
    {
        return links[bit];
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            int opp_bit = 1 - bit;

            if (node->containsKey(opp_bit))
            {
                node = node->get(opp_bit);
                maxNum = maxNum | (1 << i);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

// FIX 1: Removed duplicate class declaration wrapper
class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int q_size = queries.size();
        vector<int> solution(q_size, -1); // Initialize with -1 to handle empty trie edge cases natively

        // Sort nums to sequentially insert matching values
        sort(nums.begin(), nums.end());

        // Create Offline Queries format: {xi, mi, original_index}
        vector<tuple<int, int, int>> offline_queries;
        for (int i = 0; i < q_size; i++)
        {
            offline_queries.push_back({queries[i][0], queries[i][1], i});
        }

        // Sort offline queries increasingly based on the limit mi
        sort(offline_queries.begin(), offline_queries.end(), [](const auto &a, const auto &b)
             { return get<1>(a) < get<1>(b); });

        Trie trie;
        int nums_idx = 0;

        // FIX 3: Fully implemented processing block
        for (const auto &q : offline_queries)
        {
            int x = get<0>(q);
            int m = get<1>(q);
            int original_idx = get<2>(q);

            // Step A: Insert all elements into Trie that are smaller than or equal to m
            while (nums_idx < n && nums[nums_idx] <= m)
            {
                trie.insert(nums[nums_idx]);
                nums_idx++;
            }

            // Step B: If no numbers were inserted, the Trie is empty (Answer remains -1)
            // If the Trie contains numbers, query for the maximum XOR value
            if (nums_idx > 0)
            {
                solution[original_idx] = trie.getMax(x);
            }
        }

        return solution;
    }
};
