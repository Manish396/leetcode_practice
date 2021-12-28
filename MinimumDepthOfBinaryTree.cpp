class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        if(l and r)
            return min(minDepth(l), minDepth(r)) + 1;
        return  l ? minDepth(l) + 1 : minDepth(r) + 1;
    }
};
