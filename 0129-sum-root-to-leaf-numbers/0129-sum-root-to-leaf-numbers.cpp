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
    void getPathNumbers(TreeNode* node, int currentNumber,
                        vector<int>& result) {
        if (node == nullptr)
            return;

        currentNumber = currentNumber * 10 + node->val;

        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(currentNumber);
            return;
        }

        if (node->left)
            getPathNumbers(node->left, currentNumber, result);
        if (node->right)
            getPathNumbers(node->right, currentNumber, result);
    }

    int sumNumbers(TreeNode* root) {
        vector<int> result;
        getPathNumbers(root, 0, result);
        for (auto& num : result) {
            cout << num << " ";
        }
        int sum = 0;
        for (int num : result) {
            sum += num;
        }
        return sum;
    }
};