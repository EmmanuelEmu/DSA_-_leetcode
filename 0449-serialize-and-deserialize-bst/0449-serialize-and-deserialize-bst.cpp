/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";
        string result = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();
            if (currentNode) {
                result += to_string(currentNode->val) + ",";
                q.push(currentNode->left);
                q.push(currentNode->right);
            } else {
                result += "#,";
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data == "#")
            return nullptr;
        stringstream ss(data);
        string node;
        queue<TreeNode*> q;
        getline(ss, node, ',');
        TreeNode* root = new TreeNode(stoi(node));
        q.push(root);
        while (!q.empty()) {
            TreeNode* currentNode = q.front();
            q.pop();

            getline(ss, node, ',');
            if (node == "#") {
                currentNode->left = nullptr;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(node));
                currentNode->left = leftNode;
                q.push(leftNode);
            }
            getline(ss, node, ',');
            if (node == "#") {
                currentNode->right = nullptr;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(node));
                currentNode->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;