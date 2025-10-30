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
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, int> xtarget, ytarget;
        queue<TreeNode*> q;
        int level = 1;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(auto i=0; i<size; i++){
                TreeNode* front = q.front();
                TreeNode* parent = front;
                q.pop();
                if(front->left){
                    if(front->left->val == x){
                        xtarget = {level, parent->val};
                    } else if (front->left->val == y){
                        ytarget = {level, parent->val};
                    }
                    q.push(front->left);
                }
                if(front->right){
                    if(front->right->val == x){
                        xtarget = {level, parent->val};
                    } else if (front->right->val == y){
                        ytarget = {level, parent->val};
                    }
                    q.push(front->right);
                }
            }
            level++;
        }
        if(xtarget.first == ytarget.first && xtarget.second!=ytarget.second){
            return true;
        }
        return false;
    }
};