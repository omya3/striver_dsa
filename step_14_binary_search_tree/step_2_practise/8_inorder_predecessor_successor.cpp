/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* predecessor = nullptr;
        Node* successor = nullptr;
        
        Node* curr = root;
        
        while (curr != nullptr) {
            if (curr->data == key) {
                // If left child exists, predecessor is the maximum node in the left subtree
                if (curr->left != nullptr) {
                    Node* temp = curr->left;
                    while (temp->right != nullptr) {
                        temp = temp->right;
                    }
                    predecessor = temp;
                }
                
                // If right child exists, successor is the minimum node in the right subtree
                if (curr->right != nullptr) {
                    Node* temp = curr->right;
                    while (temp->left != nullptr) {
                        temp = temp->left;
                    }
                    successor = temp;
                }
                break; // Found the key and handled its subtrees, we can stop
            }
            else if (curr->data > key) {
                // Current node is a potential successor because it's greater than key
                successor = curr;
                curr = curr->left;
            }
            else {
                // Current node is a potential predecessor because it's smaller than key
                predecessor = curr;
                curr = curr->right;
            }
        }
        
        // Return a vector containing the two nodes as requested by the function signature
        return {predecessor, successor};
    }
};
