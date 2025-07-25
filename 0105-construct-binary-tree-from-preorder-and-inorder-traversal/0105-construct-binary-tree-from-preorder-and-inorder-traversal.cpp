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
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                              vector<int>& inorder, int inStart, int inEnd,
                              map<int, int>& inMap) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRootIndex = inMap[root->val];
        int numsLeft = inRootIndex - inStart;
        root->left =
            buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                            inorder, inStart, inRootIndex - 1, inMap);
        root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                      inorder, inRootIndex + 1, inEnd, inMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0,
                               inorder.size() - 1, inMap);
    }
};