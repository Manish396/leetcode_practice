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
    vector<vector<int>>result;
    void findPath(TreeNode* root, int target, vector<int>&temp){
        if(root == NULL){
            return;
        }
        if(root->left == NULL and root->right == NULL){
            if(root->val == target){
                temp.push_back(target);
                result.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        temp.push_back(root->val);
        findPath(root->left, target - root->val, temp);
        findPath(root->right, target - root->val, temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        findPath(root, targetSum, temp);
        return result;
    }
};
