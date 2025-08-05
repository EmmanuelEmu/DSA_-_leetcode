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
    char numToChar(int val) { return 'a' + val; }

    string solve(TreeNode* root, string& path, string& smaller) {
        path.insert(0, 1, numToChar(root->val));
        if (root->left == NULL && root->right == NULL) {
            if (path < smaller || smaller == "") {
                smaller = path;
            }
        }
        if (root->left != NULL) {
            solve(root->left, path, smaller);
        }
        if (root->right != NULL) {
            solve(root->right, path, smaller);
        }
        path.erase(0, 1);
        return smaller;
    }

    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        string smaller = "";
        return solve(root, path, smaller);
    }
};