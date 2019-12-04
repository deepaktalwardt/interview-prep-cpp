class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root || !root->left && !root->right) {
            return root;
        }
        TreeNode* tmp;
        tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;
        return root;
    }
};