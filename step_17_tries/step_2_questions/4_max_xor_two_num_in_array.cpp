#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    Node *links[2] = {}; // Binary Trie: only 0 and 1 paths

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

        // Fix 1: Traverse from MSB (31) down to LSB (0)
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

        // Fix 1: Traverse from MSB (31) down to LSB (0)
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            int opp_bit = 1 - bit; // The bit that maximizes XOR

            if (node->containsKey(opp_bit))
            {
                // Fix 2: Move the node pointer down to the opposite bit path
                node = node->get(opp_bit);
                maxNum = maxNum | (1 << i); // Set the i-th bit to 1 in the result
            }
            else
            {
                // Fallback: Must take the same bit path (XOR result bit becomes 0)
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie trie;
        for (auto &it : nums)
        {
            trie.insert(it);
        }

        int max_xor = 0;
        // Fix 3: Completed loop logic to check every number against the Trie
        for (int i = 0; i < nums.size(); i++)
        {
            max_xor = max(max_xor, trie.getMax(nums[i]));
        }

        return max_xor;
    }
};
