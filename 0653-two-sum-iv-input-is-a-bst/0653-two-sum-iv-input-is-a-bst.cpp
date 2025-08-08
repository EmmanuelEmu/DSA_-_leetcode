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
    bool isPresent(vector<int> v, int target) {
        int start = 0;
        int end = v.size() - 1;
        while (start < end) {
            if (v[start] + v[end] == target) {
                return true;
            } else if (v[start] + v[end] > target) {
                end--;
            } else {
                start++;
            }
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }
        sort(v.begin(), v.end());
        return isPresent(v, k);
    }
};