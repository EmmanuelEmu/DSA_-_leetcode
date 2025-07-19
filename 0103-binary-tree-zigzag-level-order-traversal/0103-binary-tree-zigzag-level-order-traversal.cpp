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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int level = 1;
        while (!nodes.empty()) {
            int traverseSize = nodes.size();
            vector<int> result;
            for (int i = 0; i < traverseSize; i++) {
                TreeNode* currentNode = nodes.front();
                nodes.pop();

                if (currentNode->left != nullptr)
                    nodes.push(currentNode->left);
                if (currentNode->right != nullptr)
                    nodes.push(currentNode->right);
                result.push_back(currentNode->val);
            }
            if (level % 2 == 0) {
                reverse(result.begin(), result.end());
            }
            ans.push_back(result);
            level++;
        }
        return ans;
    }
};