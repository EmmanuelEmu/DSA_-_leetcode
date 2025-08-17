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
    void solve(TreeNode* root, vector<int>& v) {
        if (root == NULL) {
            return;
        }
        v.push_back(root->val);
        if (root->left != NULL) {
            solve(root->left, v);
        }

        if (root->right != NULL) {
            solve(root->right, v);
        }
        return;
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        solve(root, v);
        sort(v.begin(), v.end());
        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        int minDiff = INT_MAX;
        for (int i = 1; i < v.size(); i++) {
            minDiff = min(minDiff, v[i] - v[i - 1]);
        }
        return minDiff;
    }
};