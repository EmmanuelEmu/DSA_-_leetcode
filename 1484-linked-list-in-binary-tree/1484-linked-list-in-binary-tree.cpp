/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    //right approach to do 
    //using indexing of the ll values
    bool solve(TreeNode* root, vector<int>& hashLLVal, int ind) {
        if (ind >= hashLLVal.size()) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if (root->val == hashLLVal[ind]) {
            return solve(root->left, hashLLVal, ind + 1) ||
                   solve(root->right, hashLLVal, ind + 1);
        }
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> LLVal;
        ListNode* temp = head;
        while (temp) {
            LLVal.push_back(temp->val);
            temp = temp->next;
        }
        if(root == NULL){
            return false;
        }

        bool result = solve(root, LLVal, 0);
        if(root->left){
            result = isSubPath(head, root->left) || result;
        }
        if(root->right){
            result = isSubPath(head, root->right) || result;
        }
        return result;
    }
};