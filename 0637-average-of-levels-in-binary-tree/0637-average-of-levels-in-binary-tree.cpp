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
    vector<double> averageOfLevels(TreeNode* root) {
        int n = 0;
        vector<double> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currSize = q.size();
            double sum = 0;
            for (int i = 0; i < currSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();
                sum += currentNode->val;
                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }
            double average = sum / currSize;
            double roundedAverage =
                round(average * 10e5) / 10e5; // Round to 5 decimal places
            result.push_back(roundedAverage);
        }
        return result;
    }
};