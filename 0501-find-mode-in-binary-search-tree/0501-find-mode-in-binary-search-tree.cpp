/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, int> mp; // (val, freq)

    void preorder(TreeNode* root) {
        if (!root)
            return;
        mp[root->val]++;
        preorder(root->left);
        preorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        if (!root)
            return {};

        preorder(root);

        vector<pair<int, int>> vec(mp.begin(), mp.end());

        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        };
        sort(vec.begin(), vec.end(), cmp);
        vector<int> result;
        int maxVal = vec[0].second;
        result.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second == maxVal)
                result.push_back(vec[i].first);
            else
                break;
        }
        return result;
    }
};
