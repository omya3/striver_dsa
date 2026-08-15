
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Node
{
    // Fix 1: Fixed from array-of-vectors to array-of-pointers
    Node *links[26] = {};
    bool end = false;

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

    void setEnd(bool flag)
    {
        end = flag;
    }

    bool isEnd()
    {
        return end;
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

    void insert(string word)
    {
        Node *node = root;
        int n = word.size();

        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd(true);
    }

    // Your custom prefix checker works beautifully!
    bool searchAllPrefix(string word)
    {
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                if (node->isEnd())
                {
                    continue;
                }
                return false;
            }
            else
            {
                return false;
            }
        }
        return node->isEnd();
    }
};

class Solution
{
public:
    string longestValidWord(vector<string> &words)
    {
        Trie t;

        // Insert all words into the prefix tree
        for (const string &s : words)
        {
            t.insert(s);
        }

        string longest_word = ""; // Fix 2: Track the actual string, not just an integer length

        for (const string &s : words)
        {
            if (t.searchAllPrefix(s))
            {
                // Fix 3: Handle tie-breaking logic (longer length OR same length but lexicographically smaller)
                if (s.size() > longest_word.size())
                {
                    longest_word = s;
                }
                else if (s.size() == longest_word.size() && s < longest_word)
                {
                    longest_word = s;
                }
            }
        }
        return longest_word;
    }
};
