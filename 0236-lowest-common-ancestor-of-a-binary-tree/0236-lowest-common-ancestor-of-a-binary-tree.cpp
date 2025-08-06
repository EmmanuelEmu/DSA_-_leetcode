/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> getPathToNode(TreeNode* root, TreeNode* nodeToFind) {
        vector<TreeNode*> path;

        // Helper function using DFS
        function<bool(TreeNode*)> dfs = [&](TreeNode* node) -> bool {
            if (!node)
                return false;

            path.push_back(node);

            if (node == nodeToFind)
                return true;

            if (dfs(node->left) || dfs(node->right))
                return true;

            path.pop_back(); // backtrack
            return false;
        };

        dfs(root);
        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> result1 = getPathToNode(root, p);
        vector<TreeNode*> result2 = getPathToNode(root, q);
        int i = 0;
        TreeNode* result = nullptr;
        while (i < result1.size() && i < result2.size()) {
            if (result1[i] == result2[i]) {
                result = result1[i];
            }
            i++;
        }
        return result;
    }
};