#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    // Fix 1: Corrected type from vector array to standard pointer array
    Node *links[26] = {};
    int end_count = 0;
    int prefix_count = 0;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != nullptr);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void increaseEnd()
    {
        end_count += 1;
    }

    void increasePrefix()
    {
        prefix_count += 1;
    }

    void decreaseEnd()
    {
        end_count -= 1;
    }

    void decreasePrefix()
    {
        prefix_count -= 1;
    }
}; // Fix 2: Added missing semicolon

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        int n = word.size();

        // Fix 3: Standard practice updates root prefix count as well
        node->increasePrefix();

        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        int n = word.size();

        for (int i = 0; i < n; i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->end_count;
    }

    int countWordsStartingWith(string &word) // Fixed typo in name to match standard LeetCode syntax
    {
        Node *node = root;
        int n = word.size();

        for (int i = 0; i < n; i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->prefix_count;
    }

    void erase(string &word)
    {
        Node *node = root;
        int n = word.size();

        // Match the insert logic by decrementing root prefix count
        node->decreasePrefix();

        for (int i = 0; i < n; i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->decreasePrefix();
            }
            else
            {
                return;
            }
        }
        node->decreaseEnd();
    }
};
