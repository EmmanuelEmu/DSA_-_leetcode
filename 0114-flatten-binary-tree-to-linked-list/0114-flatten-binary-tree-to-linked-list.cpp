/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorder(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if (root == nullptr) {
            return result;
        }
        s.push(root);
        while (!s.empty()) {
            TreeNode* currentNode = s.top();
            s.pop();
            result.push_back(currentNode->val);
            if (currentNode->right != nullptr) {
                s.push(currentNode->right);
            }
            if (currentNode->left != nullptr) {
                s.push(currentNode->left);
            }
        }
        return result;
    }

    void flatten(TreeNode* root) {
        if (root == nullptr ||
            (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        TreeNode* temp = root;
        vector<int> result = preorder(temp);
        for (auto i = 1; i < result.size(); i++) {
            TreeNode* newNode = new TreeNode(result[i]);
            temp->left = nullptr;
            temp->right = newNode;
            temp = temp->right;
        }
        temp->left = nullptr;
        temp->right = nullptr;
        root = temp;
    }
};