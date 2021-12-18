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
    bool symmetric(TreeNode*a , TreeNode*b){
        if(a == NULL and b == NULL)
            return true;
        if(a and b and (a->val == b->val)){
            return symmetric(a->left, b->right) & symmetric(a->right, b->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        bool ans = symmetric(root->left, root->right);
        return ans;
    }
};
