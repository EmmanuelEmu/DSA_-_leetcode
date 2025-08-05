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
    vector<vector<int>> solve(TreeNode* root, vector<vector<int>>& paths,
                              vector<int>& path) {
        if (root->left == NULL && root->right == NULL) {
            paths.push_back(path);
        }
        if (root->left != NULL) {
            path.push_back(root->left->val);
            solve(root->left, paths, path);
            path.pop_back();
        }
        if (root->right != NULL) {
            path.push_back(root->right->val);
            solve(root->right, paths, path);
            path.pop_back();
        }
        return paths;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> paths;
        vector<int> path;
        vector<string> pathsStr;
        path.push_back(root->val);
        solve(root, paths, path);
        for (auto singlePathVec : paths) {
            string singlePath = "";
            for (int i = 0; i < singlePathVec.size(); ++i) {
                singlePath += to_string(singlePathVec[i]);
                if (i != singlePathVec.size() - 1) {
                    singlePath += "->";
                }
            }
            pathsStr.push_back(singlePath);
        }
        return pathsStr;
    }
};