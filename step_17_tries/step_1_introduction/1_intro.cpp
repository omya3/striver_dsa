#include <iostream>
#include <string>

using namespace std;

struct Node
{
    // Fix: Modern C++ syntax to perfectly zero-initialize all 26 pointers to nullptr
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

    bool search(string word)
    {
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) // Standard practice: renamed 'word' to 'prefix'
    {
        int n = prefix.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
