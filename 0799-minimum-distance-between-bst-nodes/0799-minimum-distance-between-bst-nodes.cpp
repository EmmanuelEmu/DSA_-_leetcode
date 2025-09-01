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
    int minDiffInBST(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        vector<int> nodes;
        q.push(root);
        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();
            nodes.push_back(currNode->val);
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
        }
        sort(nodes.begin(), nodes.end());
        int minDistance = INT_MAX;
        int n = nodes.size();
        for(int i=1; i<n; i++){
            minDistance = min(minDistance, nodes[i]-nodes[i-1]);
        }

        return minDistance;
    }
};