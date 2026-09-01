#include <vector>
#include <stack>
using namespace std;

/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int> merge(Node *r1, Node *r2) {
        vector<int> result;

        // Fix: Changed TreeNode* to Node* to match your template
        Node * curr1 = r1;
        Node * curr2 = r2;

        // Fix: Changed stack type from int to Node* to track pointers
        stack<Node*> s1;
        stack<Node*> s2;

        // Fix: Removed the initial s1.push(curr1) and s2.push(curr2) 
        // to prevent double-pushing bugs.

        // Fix: Renamed st1/st2 variables to s1/s2 to match declarations
        while(curr1 != nullptr || !s1.empty() || curr2 != nullptr || !s2.empty()) {

            while(curr1 != nullptr) {
                s1.push(curr1);
                curr1 = curr1->left;
            }

            while(curr2 != nullptr) {
                // Fix: Changed s2.push(curr1) to s2.push(curr2)
                s2.push(curr2);
                curr2 = curr2->left;
            }

            if(!s1.empty() && !s2.empty()) {
                // Fix: Access node data values through pointers for comparison
                if(s1.top()->data <= s2.top()->data) {
                    Node* temp = s1.top();
                    s1.pop();
                    result.push_back(temp->data);
                    curr1 = temp->right; // Fix: Pull right path from the popped node
                } else {
                    Node* temp = s2.top();
                    s2.pop();
                    result.push_back(temp->data);
                    curr2 = temp->right; // Fix: Pull right path from the popped node
                }
            }
            else if (!s1.empty()) {
                Node* temp = s1.top();
                s1.pop();
                result.push_back(temp->data);
                curr1 = temp->right;
            }
            else if (!s2.empty()) {
                Node* temp = s2.top();
                s2.pop();
                result.push_back(temp->data);
                curr2 = temp->right;
            }
        }
        return result;
    }
};
