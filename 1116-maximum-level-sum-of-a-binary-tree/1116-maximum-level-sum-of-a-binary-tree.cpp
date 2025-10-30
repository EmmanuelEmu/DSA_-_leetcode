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
    int maxLevelSum(TreeNode* root) {
        int minLevel = -1;
        int maxSum = INT_MIN;
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sum=0;
            int size = q.size();
            for(auto i=0; i<size; i++){
                TreeNode* front = q.front();
                sum+=front->val;
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            if(sum > maxSum){
                maxSum = max(maxSum, sum);
                minLevel = level;
            }
            level++;
        }
        return minLevel;
    }
};