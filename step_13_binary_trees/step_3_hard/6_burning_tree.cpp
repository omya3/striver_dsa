#include <map>
#include <queue>
using namespace std;

/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution
{
private:
    int bfs(Node *root, map<Node *, Node *> &parent_map)
    {
        if (root == nullptr)
            return 0;

        int time = 0;
        queue<Node *> q;
        q.push(root);

        map<Node *, int> vis;
        vis[root] = 1; // Fix: Mark the starting node as visited

        while (!q.empty())
        {
            int size = q.size();
            bool fl = false;

            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();

                // Fix: Changed q->left to node->left
                if (node->left && !vis[node->left])
                {
                    q.push(node->left);
                    fl = true;
                    vis[node->left] = 1;
                }
                // Fix: Changed q->right to node->right
                if (node->right && !vis[node->right])
                {
                    q.push(node->right);
                    fl = true;
                    vis[node->right] = 1;
                }
                if (parent_map[node] && !vis[parent_map[node]])
                {
                    q.push(parent_map[node]);
                    fl = true;
                    vis[parent_map[node]] = 1;
                }
            }
            if (fl)
                time += 1;
        }
        return time;
    }

private:
    Node *parentLink(Node *root, int target, map<Node *, Node *> &parent_map)
    {
        if (root == nullptr)
            return nullptr;

        queue<Node *> q;
        q.push(root);
        Node *res = nullptr;

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            // Fix: Changed res = node to res = curr
            if (curr->data == target)
                res = curr;

            if (curr->left != nullptr)
            {
                parent_map[curr->left] = curr;
                q.push(curr->left); // Fix: Changed q->left to curr->left
            }

            if (curr->right != nullptr)
            {
                parent_map[curr->right] = curr;
                q.push(curr->right); // Fix: Changed q->right to curr->right
            }
        }
        return res;
    }

public:
    int minTime(Node *root, int target)
    {
        map<Node *, Node *> parent_map;
        Node *res = parentLink(root, target, parent_map);

        // Fix: Pass the found target node (res) instead of root
        int time = bfs(res, parent_map);
        return time;
    }
};
