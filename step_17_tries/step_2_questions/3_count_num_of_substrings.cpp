#include <string>
#include <vector>

using namespace std;

// Minimalistic Node structure tailored for tracking node creation
struct Node
{
    Node *links[26] = {nullptr}; // Zero-initialize all pointers to nullptr
};

class Solution
{
public:
    int countSubs(string &s)
    {
        Node *root = new Node();
        int distinct_count = 0;
        int n = s.size();

        // Loop through every possible starting position of a substring
        for (int i = 0; i < n; i++)
        {
            Node *node = root;

            // Traverse from the starting position to the end of the string
            for (int j = i; j < n; j++)
            {
                int index = s[j] - 'a';

                // If this character link does not exist, a new unique substring is found
                if (node->links[index] == nullptr)
                {
                    node->links[index] = new Node();
                    distinct_count++; // Increment the distinct substring counter
                }

                // Advance the pointer down the branch
                node = node->links[index];
            }
        }

        return distinct_count;
    }
};
