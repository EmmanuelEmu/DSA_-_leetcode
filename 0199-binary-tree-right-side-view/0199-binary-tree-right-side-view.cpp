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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currSize = q.size();
            for (int i = 0; i < currSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();
                if (i ==
                    currSize - 1) // Only add the last node of the current level
                {
                    result.push_back(currentNode->val);
                }
                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }
        }
        return result;
    }
};