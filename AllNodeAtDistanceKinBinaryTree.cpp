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
    
    map<TreeNode*, TreeNode*> parents;
    set<TreeNode*> visited;
    
    void markParents(TreeNode* node) {
        if (node == NULL)
            return;
        
        if (node->left)
            parents[node->left] = node;
        markParents(node->left);
        
        if (node->right)
            parents[node->right] = node;
        markParents(node->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParents(root);
        
        vector<int> ans;
        queue<TreeNode*> q;
        
        q.push(target);
        while (k--) {
            int qSize = q.size();
            
            for (int i=0;i<qSize;i++) {
                TreeNode* currNode = q.front();
                visited.insert(currNode);
                q.pop();
                
                TreeNode* parent = parents[currNode];
                
                if (currNode->left && visited.find(currNode->left) == visited.end())
                    q.push(currNode->left);
                if (currNode->right && visited.find(currNode->right) == visited.end())
                    q.push(currNode->right);
                if (parent && visited.find(parent) == visited.end())
                    q.push(parent);
            }
        }
        
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
