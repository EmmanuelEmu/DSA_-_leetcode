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
    vector<vector<int>> solve(TreeNode* node, int currentSum, int targetSum,
                              vector<int>& currentPath,
                              vector<vector<int>>& result) {
        if (node == nullptr) {
            return result;
        }
        currentSum += node->val;
        currentPath.push_back(node->val);
        // Check if it's a leaf node
        if (node->left == nullptr && node->right == nullptr) {
            if (currentSum == targetSum) {
                result.push_back(currentPath);
            }
            currentPath.pop_back();
            return result;
        }
        // Recurse on left and right
        solve(node->left, currentSum, targetSum, currentPath, result);
        solve(node->right, currentSum, targetSum, currentPath, result);
        currentPath.pop_back();
        return result;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        return solve(root, 0, targetSum, currentPath, result);
    }
};