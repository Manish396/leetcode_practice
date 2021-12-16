/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
int size(TreeNode<int>* root)
{
    if (root == nullptr) {
        return 0;
    }
    return size(root->left) + 1 + size(root->right);
}
bool isBST(TreeNode<int>* node, int min, int max)
{
    if (node == nullptr) {
        return true;
    }
    if (node->data < min || node->data > max) {
        return false;
    }
    return isBST(node->left, min, node->data) &&
        isBST(node->right, node->data, max);
}
int largestBST(TreeNode<int>* root) 
{
    if (isBST(root, INT_MIN, INT_MAX)) {
        return size(root);
    }
    return max(largestBST(root->left), largestBST(root->right));
}

