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
    bool solve(TreeNode* node, int currentSum, int targetSum) {
        if (node == nullptr)
            return false;

        currentSum += node->val;

        // Check if it's a leaf node
        if (node->left == nullptr && node->right == nullptr) {
            return currentSum == targetSum;
        }

        // Recurse on left and right
        return solve(node->left, currentSum, targetSum) ||
               solve(node->right, currentSum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, 0, targetSum);
    }
};