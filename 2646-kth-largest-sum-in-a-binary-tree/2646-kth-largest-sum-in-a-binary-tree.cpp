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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long long sum = 0;
            long long size = q.size();
            for (auto i = 0; i < size; i++) {
                TreeNode* front = q.front();
                sum += front->val;
                q.pop();
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            pq.push(sum);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.size() == k ? pq.top() : -1;
    }
};