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
    TreeNode* construct(int start, int end, vector<int> const &postorder, int &rootIndex, unordered_map<int, int> &map){
        if (start > end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[rootIndex--]);
        int index = map[root->val];
        root->right = construct(index + 1, end, postorder, rootIndex, map);
        root->left = construct(start, index - 1, postorder, rootIndex, map);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        int rootIndex = n - 1;
        return construct(0, n - 1, postorder, rootIndex, map);
    }
};
