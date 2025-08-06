/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        // vector<vector<Node*>> nodes;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<Node*> temp;
            Node* curr;
            for (int i = 0; i < n; i++) {
                curr = q.front();
                q.pop();
                curr->next = q.front();
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            curr->next = NULL;
            // nodes.push_back(temp);
        }
        return root;
    }
};