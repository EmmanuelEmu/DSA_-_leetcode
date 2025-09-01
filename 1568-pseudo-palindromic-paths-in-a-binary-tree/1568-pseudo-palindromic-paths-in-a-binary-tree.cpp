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
    bool isPalisndrome(map<int, int>& mp) {
        int oddCount = 0;
        for (auto it : mp) {
            if (it.second % 2 != 0)
                oddCount++;
        }
        return oddCount <= 1;
    }

    void solve(TreeNode* root, map<int, int>& mp, int& count) {
        if (root->left == NULL && root->right == NULL) {
            mp[root->val]++;
            if (isPalisndrome(mp))
                count++;
            mp[root->val]--;
            return;
        }
        mp[root->val]++;
        if (root->left) {
            solve(root->left, mp, count);
        }
        if (root->right) {
            solve(root->right, mp, count);
        }
        mp[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        map<int, int> mp;
        int count = 0;
        solve(root, mp, count);
        return count;
    }
};