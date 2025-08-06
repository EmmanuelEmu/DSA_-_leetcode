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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int result = INT_MIN;
        while (!q.empty()) {
            int qSize = q.size();
            int minIndex = q.front().second;
            int firstIndex, lastIndex;
            for (int i = 0; i < qSize; i++) {
                TreeNode* curr = q.front().first;
                int currIndex = q.front().second - minIndex;
                q.pop();
                if (i == 0) {
                    firstIndex = currIndex;
                }
                if (i == qSize - 1) {
                    lastIndex = currIndex;
                }
                if (curr->left) {
                    q.push({curr->left, currIndex * 2 + 1});
                }
                if (curr->right) {
                    q.push({curr->right, currIndex * 2 + 2});
                }
            }
            result = max(result, lastIndex - firstIndex + 1);
        }
        return result;
    }
};