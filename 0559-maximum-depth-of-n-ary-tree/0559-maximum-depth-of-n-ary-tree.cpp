/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int dfs(Node* node, int &depth, int &maxDepth){
        depth++;
        maxDepth = max(depth, maxDepth);
        for(auto child : node->children){
            dfs(child, depth, maxDepth);
            depth--;
        }
        return maxDepth;
    }

    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int depth = 0, maxDepth = INT_MIN;
        return dfs(root, depth, maxDepth);
    }
};