/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode *sortedListToBSTUtil(vector<int> &values, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(values[mid]);
        node->left = sortedListToBSTUtil(values, start, mid - 1);
        node->right = sortedListToBSTUtil(values, mid + 1, end);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedListToBSTUtil(nums, 0, nums.size()-1);
    }
};