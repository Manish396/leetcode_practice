/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void createBst(vector<int>&arr, int s, int e, TreeNode* &root){
        if(s > e) 
            return;
        int mid = (s + e)/2;
        root = new TreeNode(arr[mid]);
        createBst(arr, s, mid - 1, root->left);
        createBst(arr, mid + 1, e, root->right);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }
        int n = arr.size();
        TreeNode *root = NULL;
        createBst(arr, 0, n-1, root);
        return root;
    }
};
