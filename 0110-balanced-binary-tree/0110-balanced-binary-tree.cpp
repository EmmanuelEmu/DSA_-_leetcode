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
    int checkHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = checkHeight(node->left);
        int rightDepth = checkHeight(node->right);
        if (leftDepth == -1 || rightDepth == -1 ||
            abs(leftDepth - rightDepth) > 1) {
            return -1; // Not balanced
        }
        return max(leftDepth, rightDepth) + 1;
    }

    bool isBalanced(TreeNode* root) { return checkHeight(root) != -1; }
};