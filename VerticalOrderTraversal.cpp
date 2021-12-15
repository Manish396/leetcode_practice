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
    void verticalOrder(TreeNode* root, int x, int y, map<int, map<int, vector<int>>>&mp){
        if(root == NULL){
            return;
        }
        mp[x][y].push_back(root->val);
        verticalOrder(root->left, x-1, y+1, mp);
        verticalOrder(root->right, x+1, y+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        map<int, map<int, vector<int>>>mp;
        verticalOrder(root, 0, 0, mp);
        for (auto i: mp)
        {
            vector<int> temp;
            for(auto j : i.second)
            {
                sort(j.second.begin(), j.second.end());
                for(auto k : j.second)
                    temp.push_back(k);
            }
            res.push_back(temp);
        }
        return res;
    }
};
