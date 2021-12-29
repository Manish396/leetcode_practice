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
    void flatten(TreeNode* root) {
        if(root==NULL) 
            return;
        TreeNode *head = NULL;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *t = s.top();
            s.pop();
            if(t->right != NULL){
                s.push(t->right);
            }
            if(t->left != NULL){
                s.push(t->left);
            }
            if(head == NULL){
                head = t;
                head->left = NULL;
            }
            else{
                t->left = NULL;
                head->right = t;
                head = head->right;
            }
        }
    }
};
