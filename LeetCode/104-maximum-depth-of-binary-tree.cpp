class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);
            
            int max = leftDepth > rightDepth ? leftDepth : rightDepth;
            return max + 1;
        }
    }
};