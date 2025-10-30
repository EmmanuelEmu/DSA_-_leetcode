/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_find(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();
            if (currentNode->left) {
                parentMap[currentNode->left] = currentNode;
                q.push(currentNode->left);
            }
            if (currentNode->right) {
                parentMap[currentNode->right] = currentNode;
                q.push(currentNode->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        int currentLevel = 0;
        parent_find(root, parentMap);
        q.push(target);
        visited[target] = true;
        while (!q.empty()) {
            int size = q.size();
            if (currentLevel == k) {
                break;
            }
            currentLevel++;
            for (int i = 0; i < size; i++) {
                TreeNode* currentNode = q.front();
                q.pop();
                if (currentNode->left && !visited[currentNode->left]) {
                    q.push(currentNode->left);
                    visited[currentNode->left] = true;
                }
                if (currentNode->right && !visited[currentNode->right]) {
                    q.push(currentNode->right);
                    visited[currentNode->right] = true;
                }
                if (parentMap.find(currentNode) != parentMap.end() &&
                    !visited[parentMap[currentNode]]) {
                    q.push(parentMap[currentNode]);
                    visited[parentMap[currentNode]] = true;
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();
            result.push_back(currentNode->val);
        }
        return result;
    }
};