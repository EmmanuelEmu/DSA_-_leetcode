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
    void inorder(TreeNode* root, queue<int> &nodes){
        if (!root) return;
        if(root->left) inorder(root->left, nodes);
        nodes.push(root->val);
        if(root->right) inorder(root->right, nodes);
    }
    TreeNode* increasingBST(TreeNode* root) {
        queue<int> nodes;
        inorder(root, nodes);
        cout << endl;
        TreeNode* newRoot = new TreeNode(nodes.front());
        TreeNode* nextPointer = newRoot;
        nodes.pop();
        while(!nodes.empty()){
            TreeNode* nextNode = new TreeNode(nodes.front());
            nodes.pop();
            nextPointer->right = nextNode;
            nextPointer = nextPointer->right;
        }

        return newRoot;
    }
};