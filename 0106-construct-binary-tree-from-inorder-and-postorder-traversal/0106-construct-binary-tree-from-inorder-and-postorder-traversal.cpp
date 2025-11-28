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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int& postIndex, int inStart, int inEnd,
                    unordered_map<int, int>& inorderMap) {
        if (postIndex < 0 || inStart > inEnd) {
            return nullptr;
        }

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = inorderMap[rootVal];

        // Build right subtree first
        root->right = solve(inorder, postorder, postIndex, inorderIndex + 1,
                            inEnd, inorderMap);
        root->left = solve(inorder, postorder, postIndex, inStart,
                           inorderIndex - 1, inorderMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        return solve(inorder, postorder, postIndex, 0, inorder.size() - 1,
                     inorderMap);
    }
};